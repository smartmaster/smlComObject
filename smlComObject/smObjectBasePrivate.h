#pragma once

#include <atomic>

#include "smIObjectBase.h"
#include "smMetaType.h"
#include "smMetaTypeHelpers.h"
#include "smGUIDHelper.h"
#include "smObjectInstanceCounter.h"

namespace SmartLib
{
	class smObjectBasePrivate :
		public smIObjectBase
	{
	private:
		smIObjectBase* _outter{ nullptr };
		std::vector<smIObjectBase*> _inners;		//horizontal extensions
		std::vector<smIObjectBase*> _comBaseInners; //vertical extensions
		std::atomic<ULONG> _refCount;

		ptrdiff_t _offsetBias{ 0 };

	public:

		static const smMetaType* StaticMetaType();

		//should be re-implemented by smObjectBase
		virtual const smMetaType* GetMetaTypeInner() const override;

		//should be re-implemented by smObjectBase
		virtual smIObjectBase* GetImplInner() override;

	public:

		smObjectBasePrivate();

		virtual ~smObjectBasePrivate();

		void SetOffsetBias(ptrdiff_t offsetBias);

		virtual HRESULT STDMETHODCALLTYPE QueryInterface(
			/* [in] */ REFIID riid,
			/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

		virtual ULONG STDMETHODCALLTYPE AddRef(void) override;

		virtual ULONG STDMETHODCALLTYPE Release(void) override;

		virtual HRESULT QueryInterfaceInner(
			const GUID& riid,
			void** ppvObject) override;

		virtual ULONG AddRefInner(void) override;

		virtual ULONG ReleaseInner(void) override;

		virtual void SetOutter(smIObjectBase* outter) override;

		//the life time of inner is managed by outter
		//all PostAggragate() after calling it
		virtual HRESULT Aggragate(smIObjectBase*&& inner) override;


		//the life time of inner is managed by outter
		//all PostAggragate() after calling it
		virtual HRESULT AggragateComBase(smIObjectBase*&& comBaseInner) override;

		virtual const bool InnerIsMetaType(const GUID& clsid) const override;

		virtual const bool InnerIsMetaTypeOf(const GUID& clsid)  const override;

		virtual smIObjectBase* GetImplOutter()  override;

		virtual void Print() const override;
	};
}