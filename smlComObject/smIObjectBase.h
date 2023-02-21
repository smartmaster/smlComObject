#pragma once


//for "usage and example" go to below

#include <Unknwn.h>
#include <mutex>
#include "smCommDefs.h"
#include "smMetaType.h"
#include "smMetaTypeHelpers.h"

namespace SmartLib
{
	class smIUnknown : public IUnknown
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			static smMetaType mt{ SM_NAME_OF(smIUnknown), __uuidof(IUnknown) };

			static std::once_flag onceflag;
			std::call_once(onceflag, []() {
				auto* comReg = smComRegistry::SingleInstance();
				auto* modName = smModuleHelper::GetCurrentModuleName();
				comReg->Add(modName, &mt);
				});

			return &mt;
		}
	};

	class smIObjectBase : public smIUnknown
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<smIObjectBase, smIUnknown>(
				SM_NAME_OF(smIObjectBase),
				GUID{ 0xd647181d, 0xe29d, 0x4afc, { 0x96, 0x6d, 0x50, 0xf5, 0xce, 0x49, 0x94, 0xbf } }
			);
		}

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

		virtual const smMetaType* GetMetaTypeInner() const = 0;

		virtual smIObjectBase* GetImplInner() = 0;
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