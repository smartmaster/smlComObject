#pragma once

#include <Unknwn.h>
#include <atlbase.h>



namespace SmartLib
{
	class smIObjectBaseHelpers
	{
	public:
		//caller release the pointer
		template<typename T>
		static IUnknown* CreateInstance()
		{
			HRESULT hr = E_FAIL;
			IUnknown* unk = nullptr;
			auto ptr = new T{};
			if (ptr)
			{
				hr = ptr->QueryInterface(__uuidof(IUnknown), (void**)(&unk));
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
}
