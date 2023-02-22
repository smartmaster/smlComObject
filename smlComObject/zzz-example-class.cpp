
#include "smObjectBase.h"
#include "smMetaTypeHelpers.h"
#include "smPtrHelpers.h"
#include "smObjectInstanceCounter.h"

#include "zzz-example-interface.h"

namespace SmartLib
{
	class zzzObject : public smObjectBase<zzzIA, zzzIB, zzzIC>
	{
	public:

		using BASE_CLASS = smObjectBase<zzzIA, zzzIB, zzzIC>;

		static const smMetaType* StaticMetaType()
		{
			// {19D7CC2D-B4A5-44A6-A2D7-50AF089DB9A9}
			return smMetaTypeMaker::Make<zzzObject, BASE_CLASS>(
				SM_NAME_OF(zzzObject),
				GUID{ 0x19d7cc2d, 0xb4a5, 0x44a6, { 0xa2, 0xd7, 0x50, 0xaf, 0x8, 0x9d, 0xb9, 0xa9 } }
			);
		}

		virtual const smMetaType* GetMetaTypeInner() const override
		{
			return StaticMetaType();
		}

		zzzObject()
		{
			BASE_CLASS::SetOffsetBias(smPtrHelpers::BaseOffset<zzzObject, BASE_CLASS>());
			smObjectInstanceCounter::SingleInstance()->AddInstance(this);
		}

		virtual ~zzzObject()
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


	const smMetaType* StaticMetaType_zzzObject()
	{
		return zzzObject::StaticMetaType();
	}
}