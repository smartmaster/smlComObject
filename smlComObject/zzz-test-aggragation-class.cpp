
#include "smObjectBase.h"
#include "smMetaTypeHelpers.h"
#include "smPtrHelpers.h"
#include "smObjectInstanceCounter.h"

#include "zzz-example-interface.h"

namespace SmartLib
{
	class zzzObjectA : public smObjectBase<zzzIA>
	{
	public:

		using BASE_CLASS = smObjectBase<zzzIA>;

		static const smMetaType* StaticMetaType()
		{
			// {19D7CC2D-B4A5-44A6-A2D7-50AF089DB9A9}
			return smMetaTypeMaker::Make<zzzObjectA, BASE_CLASS>(
				SM_NAME_OF(zzzObjectA),
				GUID{ 0x19d7cc2d, 0xb4a5, 0x44a6, { 0xa2, 0xd7, 0x50, 0xaf, 0x8, 0x9d, 0xb9, 0xAA } }
			);
		}

		virtual const smMetaType* GetMetaTypeInner() const override
		{
			return StaticMetaType();
		}

		zzzObjectA()
		{
			BASE_CLASS::SetOffsetBias(smPtrHelpers::BaseOffset<zzzObjectA, BASE_CLASS>());
			smObjectInstanceCounter::SingleInstance()->AddInstance(this);
		}

		virtual ~zzzObjectA()
		{
			smObjectInstanceCounter::SingleInstance()->RemoveInstance(this);
		}

	public:

		virtual const char* fa_zzzIA() override
		{
			return __FUNCTION__;
		}
		virtual const char* fb_zzzIA() override
		{
			return __FUNCTION__;
		}
		virtual const char* fc_zzzIA() override
		{
			return __FUNCTION__;
		}
	};


	class zzzObjectB : public smObjectBase<zzzIB>
	{
	public:

		using BASE_CLASS = smObjectBase<zzzIB>;

		static const smMetaType* StaticMetaType()
		{
			// {19D7CC2D-B4A5-44A6-A2D7-50AF089DB9A9}
			return smMetaTypeMaker::Make<zzzObjectB, BASE_CLASS>(
				SM_NAME_OF(zzzObjectB),
				GUID{ 0x19d7cc2d, 0xb4a5, 0x44a6, { 0xa2, 0xd7, 0x50, 0xaf, 0x8, 0x9d, 0xb9, 0xBB } }
			);
		}

		virtual const smMetaType* GetMetaTypeInner() const override
		{
			return StaticMetaType();
		}

		zzzObjectB()
		{
			BASE_CLASS::SetOffsetBias(smPtrHelpers::BaseOffset<zzzObjectB, BASE_CLASS>());
			smObjectInstanceCounter::SingleInstance()->AddInstance(this);
		}

		virtual ~zzzObjectB()
		{
			smObjectInstanceCounter::SingleInstance()->RemoveInstance(this);
		}

	public:
		virtual  const char* fa_zzzIB() override
		{
			return __FUNCTION__;
		}

		virtual  const char* fb_zzzIB() override
		{
			return __FUNCTION__;
		}
		virtual  const char* fc_zzzIB() override
		{
			return __FUNCTION__;
		}
	};


	class zzzObjectC : public smObjectBase<zzzIC>
	{
	public:

		using BASE_CLASS = smObjectBase<zzzIC>;

		static const smMetaType* StaticMetaType()
		{
			// {19D7CC2D-B4A5-44A6-A2D7-50AF089DB9A9}
			return smMetaTypeMaker::Make<zzzObjectC, BASE_CLASS>(
				SM_NAME_OF(zzzObjectC),
				GUID{ 0x19d7cc2d, 0xb4a5, 0x44a6, { 0xa2, 0xd7, 0x50, 0xaf, 0x8, 0x9d, 0xb9, 0xCC} }
			);
		}

		virtual const smMetaType* GetMetaTypeInner() const override
		{
			return StaticMetaType();
		}

		zzzObjectC()
		{
			BASE_CLASS::SetOffsetBias(smPtrHelpers::BaseOffset<zzzObjectC, BASE_CLASS>());
			smObjectInstanceCounter::SingleInstance()->AddInstance(this);
		}

		virtual ~zzzObjectC()
		{
			smObjectInstanceCounter::SingleInstance()->RemoveInstance(this);
		}

	public:

		virtual  const char* fa_zzzIC() override
		{
			return __FUNCTION__;
		}
		virtual  const char* fb_zzzIC() override
		{
			return __FUNCTION__;
		}
		virtual  const char* fc_zzzIC() override
		{
			return __FUNCTION__;
		}
	};


	const smMetaType* StaticMetaType_zzzObjectA()
	{
		return zzzObjectA::StaticMetaType();
	}

	const smMetaType* StaticMetaType_zzzObjectB()
	{
		return zzzObjectB::StaticMetaType();
	}

	const smMetaType* StaticMetaType_zzzObjectC()
	{
		return zzzObjectC::StaticMetaType();
	}


}