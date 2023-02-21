#pragma once

#include <atomic>
#include <algorithm>
#include <iostream>

#include "smIObjectBase.h"
#include "smMetaType.h"
#include "smMetaTypeHelpers.h"
#include "smGUIDHelper.h"
#include "smObjectInstanceCounter.h"

namespace SmartLib
{
	template<typename... TIBases>
	class smObjectBase :
		public smIObjectBase,
		public TIBases...
	{
	private:
		smIObjectBase* _outter{ nullptr };
		std::vector<smIObjectBase*> _inners;		//horizontal extensions
		std::vector<smIObjectBase*> _comBaseInners; //vertical extensions
		std::atomic<ULONG> _refCount;

		std::unordered_map<GUID, void*, smGUIDHasher, smGUIDEqual> _cachedQI;

		size_t _hitCount{ 0 };
		size_t _missingCount{ 0 };
		size_t _validQICount{ 0 };

	private:
#if false
		void Print(std::ostream& out) const //do not export as having std:: prarams
		{
			auto* mt = GetMetaTypeInner();

			out << "CPP hierarchy:" << "\r\n";
			mt->Print(0, out);
			out << "\r\n";

			out << "Horizontal extensions" << "\r\n";
			for (auto inner : _inners)
			{
				auto* mt = inner->GetMetaTypeInner();
				mt->Print(0, out);
				out << "\r\n";
			}

			out << "Vertical extensions" << "\r\n";
			for (auto cbinner : _comBaseInners)
			{
				auto* mt = cbinner->GetMetaTypeInner();
				mt->Print(0, out);
				out << "\r\n";
			}
		}
#endif

	public:

		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<smObjectBase, smIObjectBase, TIBases...>(
				SM_NAME_OF(smObjectBase),
				// {D23257E5-A355-43AF-BBB4-6CB0A9D5EADA}
				GUID{ 0xd23257e5, 0xa355, 0x43af, { 0xbb, 0xb4, 0x6c, 0xb0, 0xa9, 0xd5, 0xea, 0xda } }
			);
		}

		virtual const smMetaType* GetMetaTypeInner() const override
		{
			return StaticMetaType();
		}

		virtual smIObjectBase* GetImplInner() override
		{
			return static_cast<smIObjectBase*>(this);
		}

	public:

		smObjectBase()
		{
			smObjectInstanceCounter::SingleInstance()->AddInstance(this);
		}

		virtual ~smObjectBase()
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

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(
			/* [in] */ REFIID riid,
			/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override
		{
			assert(ppvObject);

			HRESULT hr = E_NOINTERFACE;

			//enable cache optimization in QueryInterface (not in QueryInterfaceInner to save memory??)
			//test cache first
			auto iter = _cachedQI.find(riid);
			if (iter != _cachedQI.end())
			{
				++_hitCount;
				*ppvObject = iter->second;
				assert(*ppvObject);
				AddRef();
				hr = S_OK;
			}
			else
			{
				++_missingCount;
				hr = _outter ?
					_outter->QueryInterface(riid, ppvObject) :
					QueryInterfaceInner(riid, ppvObject);

				//add to cache here
				if (SUCCEEDED(hr) && *ppvObject)
				{
					++_validQICount;
					_cachedQI.insert({ riid, *ppvObject });
				}
			}

			return hr;
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
			const smMetaType* const mt = GetMetaTypeInner();
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
		//all PostAggragate() after calling it
		virtual HRESULT Aggragate(smIObjectBase*&& inner) override
		{
			assert(inner);
			assert(std::find(_inners.begin(), _inners.end(), inner) == _inners.end());
			inner->SetOutter(static_cast<smIObjectBase*>(this));
			_inners.emplace_back(inner);
			inner = nullptr; //ownership transfered
			return S_OK;
		}


		//the life time of inner is managed by outter
		//all PostAggragate() after calling it
		virtual HRESULT AggragateComBase(smIObjectBase*&& comBaseInner) override
		{
			assert(comBaseInner);
			assert(std::find(_comBaseInners.begin(), _comBaseInners.end(), comBaseInner) == _comBaseInners.end());
			comBaseInner->SetOutter(static_cast<smIObjectBase*>(this));
			_comBaseInners.emplace_back(comBaseInner);
			comBaseInner = nullptr; //ownership transfered
			return S_OK;
		}

		virtual const bool InnerIsMetaType(const GUID& clsid) const override
		{
			const auto* mt = GetMetaTypeInner();
			return IsEqualGUID(mt->GetID(), clsid);
		}

		virtual const bool InnerIsMetaTypeOf(const GUID& clsid)  const override
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


		

		virtual smIObjectBase* GetImplOutter()  override
		{
			return _outter ?
				_outter->GetImplOutter() //recursively 
				: GetImplInner();
		}

		virtual void Print() const override
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
	};
}