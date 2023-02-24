

#include <mutex>

#include "smMetaType.h"

#include "smCommDefs.h"
#include "smIUnknown.h"

#include "smComRegistry.h"
#include "smModuleHelper.h"
#include "smGUIDHelper.h"

namespace SmartLib
{

	const smMetaType* smIUnknown::StaticMetaType()
	{
		static smMetaType mt{ SM_NAME_OF(smIUnknown), __uuidof(IUnknown)};

		static std::once_flag onceflag;
		std::call_once(onceflag, []() {
			auto* comReg = smComRegistry::SingleInstance();
		auto* modName = smModuleHelper::GetCurrentModuleName();
		comReg->Add(modName, &mt);
			});

		return &mt;
	}

}


