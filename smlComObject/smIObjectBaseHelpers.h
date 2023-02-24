#pragma once

#include <atlbase.h>

#include "smMetaType.h"
#include "smIUnknown.h"


namespace SmartLib
{
	class smIObjectBaseHelpers
	{
	public:
		//caller release the pointer
		template<typename T>
		static smIUnknown* CreateInstance()
		{
			HRESULT hr = E_FAIL;
			smIUnknown* unk = nullptr;
			auto ptr = new T{};
			if (ptr)
			{
				hr = ptr->QueryInterface(smIUnknown::StaticMetaType()->GetID(), (void**)(&unk));
				if (FAILED(hr) || nullptr == unk)
				{
					unk = nullptr;
					delete ptr;
					ptr = nullptr;
				}
			}

			return unk;
		}

		
	};


	template<typename TI>
	class smPostAggrageOp
	{
	public:
		static void PostAggrate(TI*& ptr)
		{
			ptr = nullptr;
		}
	};


	template<typename TI>
	class smPostAggrageOp<CComPtr<TI>>
	{
	public:
		static void PostAggrate(CComPtr<TI>& ptr)
		{
			ptr.Detach();
		}
	};
}
