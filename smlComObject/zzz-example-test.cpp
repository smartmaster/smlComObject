
#include <cassert>
#include <cstring>

#include "smCommDefs.h"
#include "smQIHelper.h"

#include "zzz-example-interface.h"


void Test_zzz_example()
{
	using namespace ::SmartLib;

	const smMetaType* mt = StaticMetaType_zzzObject();

	CComPtr<IUnknown> unk;
	unk.Attach(mt->CreateInstance());


	{
		CComPtr<zzzIA> spia = smQIHelper::QI<zzzIA>(unk);
		assert(strstr(spia->fa_zzzIA(),	SM_NAME_OF(fa_zzzIA) ));
		assert(strstr(spia->fb_zzzIA(),	SM_NAME_OF(fb_zzzIA) ));
		assert(strstr(spia->fc_zzzIA(),	SM_NAME_OF(fc_zzzIA) ));
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