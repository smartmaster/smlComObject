#pragma once


//for "usage and example" go to below


#include <mutex>
#include "smCommDefs.h"
#include "smMetaType.h"
#include "smIUnknown.h"
#include "smMetaTypeHelpers.h"

namespace SmartLib
{
	class smIObjectBase : public smIUnknown
	{
	public:
		static const smMetaType* StaticMetaType();

	public:
		virtual const smMetaType* GetMetaTypeInner() const = 0;
		virtual smIObjectBase* GetImplInner() = 0;

	public:
		//virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		//	/* [in] */ REFIID riid,
		//	/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) = 0;

		//virtual ULONG STDMETHODCALLTYPE AddRef(void) = 0;

		//virtual ULONG STDMETHODCALLTYPE Release(void) = 0;

		virtual HRESULT QueryInterfaceInner(
			const GUID& riid,
			void** ppvObject) = 0;
		virtual ULONG AddRefInner(void) = 0;
		virtual ULONG ReleaseInner(void) = 0;

		virtual void SetOutter(smIObjectBase* outter) = 0;
		virtual HRESULT Aggragate(smIObjectBase*&& inner) = 0;
		virtual HRESULT AggragateComBase(smIObjectBase*&& comBaseInner) = 0;

		virtual smIObjectBase* GetImplOutter() = 0;
		
		virtual const bool InnerIsMetaType(const GUID& clsid) const = 0;
		virtual const bool InnerIsMetaTypeOf(const GUID& clsid) const = 0;

		virtual void Print() const = 0;
	};
}


//usage and example
#if false

namespace
{
	//for interface 
	//multiple inheritance for interface is supported
	class yyyInterface :
		public smIObjectBase,
		public xIB,	//to change...
		public xIC,	//to change...
		public xID	//to change...
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<yyyInterface, smIObjectBase, xIB, xIC, xID> //to change...
				(
					SM_NAME_OF(yyyInterface),//to change...
					GUID{ GUID_NULL }//to change...
			);
		}

	public:
		//pure virtual methods
		//virtual void foo() = 0;
	};


	//for class
	//yyyObject should and must be singly inherited by smObjectBase<...>
	class yyyObject :
		public smObjectBase<xIB, xIC, xID> //to change...
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<yyyObject, smObjectBase<xIB, xIC, xID>> //to change...
				(
					SM_NAME_OF(yyyObject), //to change...
					GUID{ GUID_NULL } //to change...
			);
		}

		virtual const smMetaType* GetMetaTypeInner()  override
		{
			return StaticMetaType();
	}

	public:
		//impls for pure virtual methods
		//virtual void foo() override {}
};
}

#endif