#pragma once

#include <type_traits>
#include <cassert>
#include <mutex>

#include "smMetaType.h"
#include "smPtrHelpers.h"
#include "smIObjectBaseHelpers.h"
#include "smComRegistry.h"
#include "smModuleHelper.h"

namespace SmartLib
{

	class smMetaTypeHelpers
	{
	public:
		template<typename T>
		static const GUID& UUID_OF()
		{
			return T::StaticMetaType()->GetID();
		}
	};

	template<typename TClass, typename TBase, typename... TBases>
	class smMetaCppBase
	{
	public:
		static void Add(smMetaType* mt)
		{
			//assert(mt == TClass::StaticMetaType()); //deadlock itself when in std::call_once

			mt->AddCppBaseOffset(TBase::StaticMetaType(), smPtrHelpers::BaseOffset<TClass, TBase>());
			if constexpr (sizeof...(TBases))
			{
				smMetaCppBase<TClass, TBases...>::Add(mt);
			}
		}
	};
	

	class smMetaTypeMaker
	{
	public:
		template<typename TClass, typename... TBases>
		static const smMetaType* Make(const char* name, const GUID& guid)
		{
			static smMetaType mt{name, guid};

			static std::once_flag onceflag;
			std::call_once(onceflag, []() {
				smMetaCppBase<TClass, TBases...>::Add(&mt);
				mt.EnumCppOffset();
				if constexpr (!std::is_abstract_v<TClass>)
				{
					mt.SetCreateInstanceMethod(smIObjectBaseHelpers::CreateInstance<TClass>);
				}
				auto* comReg = smComRegistry::SingleInstance();
				auto* modName = smModuleHelper::GetCurrentModuleName();
				comReg->Add(modName, &mt);
			});

			//assert(TClass::StaticMetaType() == &mt);

			return &mt;
		}
	};
}