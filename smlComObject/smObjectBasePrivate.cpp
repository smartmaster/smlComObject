#include <algorithm>
#include <iostream>

#include "smObjectBasePrivate.h"


namespace SmartLib
{
	smObjectBasePrivate::smObjectBasePrivate()
	{
		smObjectInstanceCounter::SingleInstance()->AddInstance(this);
	}

	smObjectBasePrivate::~smObjectBasePrivate()
	{
		for (auto inner : _inners)
		{
			inner->ReleaseInner();
		}
		_inners.clear();

		for (auto comBaseInner : _comBaseInners)
		{
			comBaseInner->ReleaseInner();
		}
		_comBaseInners.clear();

		smObjectInstanceCounter::SingleInstance()->RemoveInstance(this);
	}

	void smObjectBasePrivate::SetOffsetBias(ptrdiff_t offsetBias)
	{
		assert(offsetBias >= 0);
		_offsetBias = offsetBias;
	}

	HRESULT __stdcall smObjectBasePrivate::QueryInterface(REFIID riid, void** ppvObject)
	{
		assert(ppvObject);

		return _outter ?
			_outter->QueryInterface(riid, ppvObject) :
			smObjectBasePrivate::QueryInterfaceInner(riid, ppvObject);
	}

	ULONG __stdcall smObjectBasePrivate::AddRef(void)
	{
		return _outter ?
			_outter->AddRef() :
			smObjectBasePrivate::AddRefInner();
	}

	ULONG __stdcall smObjectBasePrivate::Release(void)
	{
		return _outter ?
			_outter->Release() :
			smObjectBasePrivate::ReleaseInner();
	}

	HRESULT smObjectBasePrivate::QueryInterfaceInner(const GUID& riid, void** ppvObject)
	{
		HRESULT hr = E_NOINTERFACE;
		const smMetaType* const mt = GetMetaTypeInner();
		ptrdiff_t offset = mt->FindCppOffset(riid); //neg _offsetBias
		if (offset >= 0)
		{
			*ppvObject = smPtrHelpers::PtrAdvance(this, offset - _offsetBias);
			hr = S_OK;
			if (SUCCEEDED(hr) && *ppvObject)
			{
				smObjectBasePrivate::AddRef(); //call AddRef() not AddRefInner()
			}
		}
		else
		{
			for (auto inner : _inners) //QI extension
			{
				hr = inner->QueryInterfaceInner(riid, ppvObject); //recursively
				if (SUCCEEDED(hr) && *ppvObject)
				{
					break;
				}
			}

			if (FAILED(hr) || nullptr == *ppvObject) //QI com base
			{
				for (auto comBaseInner : _comBaseInners)
				{
					hr = comBaseInner->QueryInterfaceInner(riid, ppvObject); //recursively
					if (SUCCEEDED(hr) && *ppvObject)
					{
						break;
					}
				}
			}
		}

		return hr;

	}

	ULONG smObjectBasePrivate::AddRefInner(void)
	{
		ULONG rc = ++_refCount;
		return rc;
	}

	ULONG smObjectBasePrivate::ReleaseInner(void)
	{
		ULONG rc = --_refCount;
		if (0 == rc)
		{
			delete this;
		}
		return rc;
	}

	void smObjectBasePrivate::SetOutter(smIObjectBase* outter)
	{
		_outter = outter;
	}

	//the life time of inner is managed by outter
	//all PostAggragate() after calling it

	HRESULT smObjectBasePrivate::Aggragate(smIObjectBase*&& inner)
	{
		assert(inner);
		assert(std::find(_inners.begin(), _inners.end(), inner) == _inners.end());

		inner->AddRef();
		ULONG refCount = inner->Release();
		assert(1 == refCount);

		inner->SetOutter(static_cast<smIObjectBase*>(this));
		_inners.emplace_back(inner);
		inner = nullptr; //ownership transfered
		return S_OK;
	}

	//the life time of inner is managed by outter
	//all PostAggragate() after calling it

	HRESULT smObjectBasePrivate::AggragateComBase(smIObjectBase*&& comBaseInner)
	{
		assert(comBaseInner);
		assert(std::find(_comBaseInners.begin(), _comBaseInners.end(), comBaseInner) == _comBaseInners.end());
		
		comBaseInner->AddRef();
		ULONG refCount = comBaseInner->Release();
		assert(1 == refCount);

		comBaseInner->SetOutter(static_cast<smIObjectBase*>(this));
		_comBaseInners.emplace_back(comBaseInner);
		comBaseInner = nullptr; //ownership transfered
		return S_OK;
	}

	const bool smObjectBasePrivate::InnerIsMetaType(const GUID& clsid) const
	{
		const auto* mt = GetMetaTypeInner();
		return IsEqualGUID(mt->GetID(), clsid);
	}

	const bool smObjectBasePrivate::InnerIsMetaTypeOf(const GUID& clsid) const
	{
		//assert(false);
		//return false;

		bool found = InnerIsMetaType(clsid);
		if (!found)
		{
			for (auto* combase : _comBaseInners)
			{
				found = combase->InnerIsMetaTypeOf(clsid); //recursively
				if (found)
				{
					break;
				}
			}
		}
		return found;
	}




	smIObjectBase* smObjectBasePrivate::GetImplOutter()
	{
		return _outter ?
			_outter->GetImplOutter() //recursively 
			: GetImplInner(); //cannot call smObjectBasePrivate::GetImplInner
	}

	void smObjectBasePrivate::Print() const
	{
		auto* mt = GetMetaTypeInner();

		std::cout << "CPP hierarchy:" << "\r\n";
		mt->Print(0, 0);
		std::cout << "\r\n";

		std::cout << "Horizontal extensions" << "\r\n";
		for (auto inner : _inners)
		{
			auto* mt = inner->GetMetaTypeInner();
			mt->Print(0, 0);
			std::cout << "\r\n";
		}

		std::cout << "Vertical extensions" << "\r\n";
		for (auto cbinner : _comBaseInners)
		{
			auto* mt = cbinner->GetMetaTypeInner();
			mt->Print(0, 0);
			std::cout << "\r\n";
		}

		std::cout << std::endl;
	}


}//namespace SmartLib