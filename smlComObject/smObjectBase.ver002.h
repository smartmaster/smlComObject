#pragma once

#include <atomic>
#include <algorithm>
#include <iostream>

#include "smIObjectBase.h"
#include "smMetaType.h"
#include "smMetaTypeHelpers.h"
#include "smGUIDHelper.h"
#include "smObjectInstanceCounter.h"
#include "smObjectBasePrivate.h"
#include "smPtrHelpers.h"

namespace SmartLib
{
	template<typename... TIBases>
	class smObjectBase :
		public smIObjectBase,
		public TIBases...,
		public smObjectBasePrivate
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<smObjectBase, smIObjectBase, TIBases..., smObjectBasePrivate>(
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
			smObjectBasePrivate::SetOffsetBias(smPtrHelpers::BaseOffset<smObjectBase, smObjectBasePrivate>());
			smObjectInstanceCounter::SingleInstance()->AddInstance(this);
		}

		virtual ~smObjectBase()
		{	
			smObjectInstanceCounter::SingleInstance()->RemoveInstance(this);
		}

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(
			/* [in] */ REFIID riid,
			/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override
		{
			return smObjectBasePrivate::QueryInterface(riid, ppvObject);
		}

		virtual ULONG STDMETHODCALLTYPE AddRef(void) override
		{
			return smObjectBasePrivate::AddRef();
		}

		virtual ULONG STDMETHODCALLTYPE Release(void) override
		{
			return smObjectBasePrivate::Release();
		}

		virtual HRESULT QueryInterfaceInner(
			const GUID& riid,
			void** ppvObject) override
		{
			return smObjectBasePrivate::QueryInterfaceInner(riid, ppvObject);
		}

		virtual ULONG AddRefInner(void) override
		{
			return smObjectBasePrivate::AddRefInner();
		}

		virtual ULONG ReleaseInner(void) override
		{
			return smObjectBasePrivate::ReleaseInner();
		}

		virtual void SetOutter(smIObjectBase* outter) override
		{
			return smObjectBasePrivate::SetOutter(outter);
		}

		//the life time of inner is managed by outter
		//all PostAggragate() after calling it
		virtual HRESULT Aggragate(smIObjectBase*&& inner) override
		{
			return smObjectBasePrivate::Aggragate(std::move(inner));
		}


		//the life time of inner is managed by outter
		//all PostAggragate() after calling it
		virtual HRESULT AggragateComBase(smIObjectBase*&& comBaseInner) override
		{
			return smObjectBasePrivate::AggragateComBase(std::move(comBaseInner));
		}

		virtual const bool InnerIsMetaType(const GUID& clsid) const override
		{
			return smObjectBasePrivate::InnerIsMetaType(clsid);
		}

		virtual const bool InnerIsMetaTypeOf(const GUID& clsid)  const override
		{
			return smObjectBasePrivate::InnerIsMetaTypeOf(clsid);
		}

		virtual smIObjectBase* GetImplOutter()  override
		{
			return smObjectBasePrivate::GetImplOutter();
		}

		virtual void Print() const override
		{
			return smObjectBasePrivate::Print();
		}
	};
}