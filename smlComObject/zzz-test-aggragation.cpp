
#include <cassert>
#include <cstring>

#include "smCommDefs.h"
#include "smQIHelper.h"
#include "smMetaTypeHelpers.h"
#include "smIObjectBaseHelpers.h"

#include "zzz-example-interface.h"


template<typename T>
static void Test_zzz_aggragation_example(T&& unk)
{
	using namespace ::SmartLib;
	{
		CComPtr<zzzIA> spia = smQIHelper::QI<zzzIA>(unk);
		assert(strstr(spia->fa_zzzIA(), SM_NAME_OF(fa_zzzIA)));
		assert(strstr(spia->fb_zzzIA(), SM_NAME_OF(fb_zzzIA)));
		assert(strstr(spia->fc_zzzIA(), SM_NAME_OF(fc_zzzIA)));
	}


	{
		CComPtr<zzzIB> spib = smQIHelper::QI<zzzIB>(unk);
		assert(strstr(spib->fa_zzzIB(), SM_NAME_OF(fa_zzzIB)));
		assert(strstr(spib->fb_zzzIB(), SM_NAME_OF(fb_zzzIB)));
		assert(strstr(spib->fc_zzzIB(), SM_NAME_OF(fc_zzzIB)));
	}


	{
		CComPtr<zzzIC> spic = smQIHelper::QI<zzzIC>(unk);
		assert(strstr(spic->fa_zzzIC(), SM_NAME_OF(fa_zzzIC)));
		assert(strstr(spic->fb_zzzIC(), SM_NAME_OF(fb_zzzIC)));
		assert(strstr(spic->fc_zzzIC(), SM_NAME_OF(fc_zzzIC)));
	}
}


void Test_zzz_aggragation_horizontal_example()
{
	using namespace ::SmartLib;

	const smMetaType* mtA = StaticMetaType_zzzObjectA();
	const smMetaType* mtB = StaticMetaType_zzzObjectB();
	const smMetaType* mtC = StaticMetaType_zzzObjectC();

	smIUnknown* unkA = mtA->CreateInstance();
	smIUnknown* unkB = mtB->CreateInstance();
	smIUnknown* unkC = mtC->CreateInstance();

	static_cast<smIObjectBase*>(unkB)->Aggragate(static_cast<smIObjectBase*>(unkC));
	smPostAggrageOp<smIUnknown>::PostAggrate(unkC);

	static_cast<smIObjectBase*>(unkA)->Aggragate(static_cast<smIObjectBase*>(unkB));
	smPostAggrageOp<smIUnknown>::PostAggrate(unkB);

	CComPtr<smIUnknown> spa;
	spa.Attach(unkA);
	unkA = nullptr;

	CComPtr<zzzIC> spc = smQIHelper::QI<zzzIC>(spa);
	smIObjectBase* obmain = spc->GetImplOutter();

	assert(obmain->InnerIsMetaType(mtA->GetID()));
	assert(!obmain->InnerIsMetaType(mtB->GetID()));
	assert(!obmain->InnerIsMetaType(mtC->GetID()));

	assert(obmain->InnerIsMetaTypeOf(mtA->GetID()));
	assert(!obmain->InnerIsMetaTypeOf(mtB->GetID()));
	assert(!obmain->InnerIsMetaTypeOf(mtC->GetID()));
	

	Test_zzz_aggragation_example(spc);
}


void Test_zzz_aggragation_vertical_example()
{
	using namespace ::SmartLib;

	const smMetaType* mtA = StaticMetaType_zzzObjectA();
	const smMetaType* mtB = StaticMetaType_zzzObjectB();
	const smMetaType* mtC = StaticMetaType_zzzObjectC();

	smIUnknown* unkA = mtA->CreateInstance();
	smIUnknown* unkB = mtB->CreateInstance();
	smIUnknown* unkC = mtC->CreateInstance();

	static_cast<smIObjectBase*>(unkB)->AggragateComBase(static_cast<smIObjectBase*>(unkC));
	smPostAggrageOp<smIUnknown>::PostAggrate(unkC);

	static_cast<smIObjectBase*>(unkA)->AggragateComBase(static_cast<smIObjectBase*>(unkB));
	smPostAggrageOp<smIUnknown>::PostAggrate(unkB);

	CComPtr<smIUnknown> spa;
	spa.Attach(unkA);
	unkA = nullptr;

	CComPtr<zzzIC> spc = smQIHelper::QI<zzzIC>(spa);
	smIObjectBase* obmain = spc->GetImplOutter();

	assert(obmain->InnerIsMetaType(mtA->GetID()));
	assert(!obmain->InnerIsMetaType(mtB->GetID()));
	assert(!obmain->InnerIsMetaType(mtC->GetID()));

	assert(obmain->InnerIsMetaTypeOf(mtA->GetID()));
	assert(obmain->InnerIsMetaTypeOf(mtB->GetID()));
	assert(obmain->InnerIsMetaTypeOf(mtC->GetID()));

	Test_zzz_aggragation_example(spc);
}