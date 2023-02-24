#pragma once


#include <atlbase.h>
#include <tuple>
#include <cassert>

#include "smIObjectBase.h"
#include "smMetaTypeHelpers.h"


namespace SmartLib
{
	class smQIHelper
	{
	public:
		template<typename TI>
		static CComPtr<TI> QI(smIUnknown* unk)
		{
			assert(unk);
			CComPtr<TI> itf;
			unk->QueryInterface(smMetaTypeHelpers::UUID_OF<TI>(), (void**)(&itf));
			return itf;
		}

		//the lifetime of CComPtr<smIObjectBase> is same as TI*
		//this is used when multiple inheritances, or method call will be ambiguous
		template<typename TI>
		static std::tuple<TI*, CComPtr<smIObjectBase>>  QIRaw(smIUnknown* unk)
		{
			assert(unk);

			CComPtr<smIObjectBase> sp;
			TI* itf = nullptr;
			
			unk->QueryInterface(smMetaTypeHelpers::UUID_OF<TI>(), (void**)(&itf));
			
			sp.Attach(static_cast<smIObjectBase*>(itf));

			return std::make_tuple(itf, std::move(sp));

		}
	};
}
