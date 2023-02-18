#pragma once

#include <atomic>
#include <algorithm>

#include "smIObjectBase.h"
#include "smMetaType.h"
#include "smMetaTypeHelpers.h"

namespace SmartLib
{
	template<typename... TIBases>
	class smObjectBase :
		public smIObjectBase,
		public TIBases...
	{
	private:
		smIObjectBase* _outter{ nullptr };
		std::vector<smIObjectBase*> _inners;
		std::vector<smIObjectBase*> _comBases;
		std::atomic<ULONG> _refCount;

	public:

		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<smObjectBase, smIObjectBase, TIBases...>(
				SM_NAME_OF(smObjectBase),
				// {D23257E5-A355-43AF-BBB4-6CB0A9D5EADA}
				GUID{ 0xd23257e5, 0xa355, 0x43af, { 0xbb, 0xb4, 0x6c, 0xb0, 0xa9, 0xd5, 0xea, 0xda } }
			);
		}

		virtual const smMetaType* GetMetaType()  override
		{
			return StaticMetaType();
		}

		virtual const bool IsMetaType(const GUID& clsid) const override
		{
			assert(false);
			return false;

			//auto* mt = GetMetaType();
			//return IsEqualGUID(mt->GetID(), clsid);
		}

		virtual const bool IsMetaTypeOf(const GUID& clsid)  const override
		{
			assert(false);
			return false;

			//bool found = IsMetaType(clsid);
			//if (!found)
			//{
			//	for (auto* combase : _comBases)
			//	{
			//		found = combase->IsMetaTypeOf(clsid); //recursiely
			//		if (found)
			//		{
			//			break;
			//		}
			//	}
			//}
			//return found;
		}

	public:

		virtual ~smObjectBase()
		{
			for (auto inner : _inners)
			{
				inner->ReleaseInner();
			}
			_inners.clear();
		}

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(
			/* [in] */ REFIID riid,
			/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override
		{
			return _outter ?
				_outter->QueryInterface(riid, ppvObject) :
				QueryInterfaceInner(riid, ppvObject);

		}

		virtual ULONG STDMETHODCALLTYPE AddRef(void) override
		{
			return _outter ?
				_outter->AddRef() :
				AddRefInner();
		}

		virtual ULONG STDMETHODCALLTYPE Release(void) override
		{
			return _outter ?
				_outter->Release() :
				ReleaseInner();
		}

		virtual HRESULT QueryInterfaceInner(
			const GUID& riid,
			void** ppvObject) override
		{
			HRESULT hr = E_NOINTERFACE;
			const smMetaType* const mt = GetMetaType();
			ptrdiff_t offset = mt->FindCppOffset(riid, 0);
			if (offset >= 0)
			{
				*ppvObject = smPtrHelpers::PtrAdvance(this, offset);
				hr = S_OK;
				if (SUCCEEDED(hr) && *ppvObject)
				{
					AddRef(); //call AddRef() not AddRefInner()
				}
			}
			else
			{
				for (auto inner : _inners)
				{
					hr = inner->QueryInterfaceInner(riid, ppvObject); //recursively
					if (SUCCEEDED(hr) && *ppvObject)
					{
						break;
					}
				}
			}

			return hr;

		}

		virtual ULONG AddRefInner(void) override
		{
			ULONG rc = ++_refCount;
			return rc;
		}

		virtual ULONG ReleaseInner(void) override
		{
			ULONG rc = --_refCount;
			if (0 == rc)
			{
				delete this;
			}
			return rc;
		}

		virtual void SetOutter(smIObjectBase* outter) override
		{
			_outter = outter;
		}

		//the life time of inner is managed by outter
		//should all PostAggragate() afterwards
		virtual HRESULT Aggragate(smIObjectBase* inner) override
		{
			assert(inner);
			assert(std::find(_inners.begin(), _inners.end(), inner) == _inners.end());
			//inner->SetOutter(nullptr);
			//inner->AddRef(); //must AddRef first (before SetOutter)
			//inner->AddRefInner();
			inner->SetOutter(static_cast<smIObjectBase*>(this));
			_inners.emplace_back(inner);
			return S_OK;
		}
	};
}