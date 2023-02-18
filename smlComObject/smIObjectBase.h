#pragma once

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
			static smMetaType mt{ SM_NAME_OF(smIUnknown), __uuidof(IUnknown)};
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
			void ** ppvObject) = 0;
		virtual ULONG AddRefInner(void) = 0;
		virtual ULONG ReleaseInner(void) = 0;

		virtual void SetOutter(smIObjectBase* outter) = 0;
		virtual HRESULT Aggragate(smIObjectBase* inner) = 0;

		virtual const smMetaType* GetMetaType() = 0;
	};
}