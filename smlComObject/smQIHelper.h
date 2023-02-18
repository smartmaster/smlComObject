#pragma once


#include <atlbase.h>
#include "smMetaTypeHelpers.h"


namespace SmartLib
{
	class smQIHelper
	{
	public:
		template<typename TI>
		static CComPtr<TI> QI(IUnknown* unk)
		{
			CComPtr<TI> itf;
			unk->QueryInterface(smMetaTypeHelpers::UUID_OF<TI>(), (void**)(&itf));
			return itf;
		}

		template<typename TI>
		static TI* QIRaw(IUnknown* unk)
		{
			TI* itf = nullptr;
			unk->QueryInterface(smMetaTypeHelpers::UUID_OF<TI>(), (void**)(&itf));
			return itf;
		}
	};
}
