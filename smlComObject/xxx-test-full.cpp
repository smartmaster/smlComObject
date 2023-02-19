
#include <atlbase.h>

#include <vector>

#include <iostream>
#include <vector>
#include <atlbase.h>

#include "smMetaType.h"
#include "smIObjectBase.h"
#include "smObjectBase.h"
#include "smMetaTypeHelpers.h"
#include "smIObjectBaseHelpers.h"
#include "smQIHelper.h"

#include "xx-test-itf.h"

#include "smMetaTypeHelpers.h"
#include "smIObjectBase.h"
#include "smIObjectBaseHelpers.h"

extern std::vector<const SmartLib::smMetaType*> TestActivateInterface();
extern std::vector<const SmartLib::smMetaType*> TestActivateClass();


namespace {
	template<typename TTT>
	static void TestComReg()
	{
		auto* comReg = smComRegistry::SingleInstance();
		auto* modName = smModuleHelper::GetCurrentModuleName();

		const GUID& guid = smMetaTypeHelpers::UUID_OF<TTT>();
		const smMetaType* mt0 = TTT::StaticMetaType();
		auto* mt1 = comReg->Find(modName, guid);
		auto* mt2 = comReg->Find(guid);

		assert(mt0 == mt1 && mt0 == mt2);
	}

	static void DoTestAllQI(IUnknown* unk)
	{
		{
			auto [ptr, sp] = smQIHelper::QIRaw<smIUnknown>(unk);
			assert(ptr);
			TestComReg<smIUnknown>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<smIObjectBase>(unk);
			assert(ptr);
			TestComReg<smIObjectBase>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxIA0>(unk);
			assert(ptr);
			TestComReg<xxxIA0>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxIA1>(unk);
			assert(ptr);
			TestComReg<xxxIA1>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxIA2>(unk);
			assert(ptr);
			TestComReg<xxxIA2>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxIB>(unk);
			assert(ptr);
			TestComReg<xxxIB>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxIC>(unk);
			assert(ptr);
			TestComReg<xxxIC>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxID>(unk);
			assert(ptr);
			TestComReg<xxxID>();
		}
	}


	static void DoTestSmoke(IUnknown* unk);
	static void yyyDoTestSmoke(IUnknown* unk);

	static void DoTestAllQI(IUnknown* unk);
	static void yyyDoTestAllQI(IUnknown* unk);

	static void TestAllQI(IUnknown* unk)
	{
		DoTestAllQI(unk);
		yyyDoTestAllQI(unk);
	}

	static void yyyTestAllQI(IUnknown* unk)
	{
		DoTestAllQI(unk);
		yyyDoTestAllQI(unk);
	}

	static void DoTestSmoke(IUnknown* unk)
	{

		{
			CComPtr<smIUnknown> unkTemp = smQIHelper::QI<smIUnknown>(unk);
			assert(unkTemp);
			TestAllQI(unkTemp);

			CComPtr<smIObjectBase> obTemp = smQIHelper::QI<smIObjectBase>(unk);
			assert(obTemp);
			TestAllQI(obTemp);
		}


		{
			CComPtr<xxxIA0> ptr = smQIHelper::QI<xxxIA0>(unk);
			assert(ptr);

			TestAllQI(ptr);

			const char* fname0 = ptr->f0_xxxIA0();
			const char* fname1 = ptr->f1_xxxIA0();
			const char* fname2 = ptr->f2_xxxIA0();

			assert(strstr(fname0, SM_NAME_OF(f0_xxxIA0)));
			assert(strstr(fname1, SM_NAME_OF(f1_xxxIA0)));
			assert(strstr(fname2, SM_NAME_OF(f2_xxxIA0)));
		}


		{
			CComPtr<xxxIA1> ptr = smQIHelper::QI<xxxIA1>(unk);
			assert(ptr);

			TestAllQI(ptr);

			const char* fname0 = ptr->f0_xxxIA1();
			const char* fname1 = ptr->f1_xxxIA1();
			const char* fname2 = ptr->f2_xxxIA1();

			assert(strstr(fname0, SM_NAME_OF(f0_xxxIA1)));
			assert(strstr(fname1, SM_NAME_OF(f1_xxxIA1)));
			assert(strstr(fname2, SM_NAME_OF(f2_xxxIA1)));
		}

		{
			CComPtr<xxxIA2> ptr = smQIHelper::QI<xxxIA2>(unk);
			assert(ptr);

			TestAllQI(ptr);

			const char* fname0 = ptr->f0_xxxIA2();
			const char* fname1 = ptr->f1_xxxIA2();
			const char* fname2 = ptr->f2_xxxIA2();

			assert(strstr(fname0, SM_NAME_OF(f0_xxxIA2)));
			assert(strstr(fname1, SM_NAME_OF(f1_xxxIA2)));
			assert(strstr(fname2, SM_NAME_OF(f2_xxxIA2)));
		}

		{
			xxxID* ptr = nullptr;
			CComPtr<smIObjectBase> scope;
			scope.Attach(ptr);
		}


		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxIB>(unk);
			assert(ptr);

			TestAllQI(sp);

			const char* fname0 = ptr->f0_xxxIB();
			const char* fname1 = ptr->f1_xxxIB();
			const char* fname2 = ptr->f2_xxxIB();

			assert(strstr(fname0, SM_NAME_OF(f0_xxxIB)));
			assert(strstr(fname1, SM_NAME_OF(f1_xxxIB)));
			assert(strstr(fname2, SM_NAME_OF(f2_xxxIB)));
		}

		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxIC>(unk);
			assert(ptr);

			TestAllQI(sp);

			const char* fname0 = ptr->f0_xxxIC();
			const char* fname1 = ptr->f1_xxxIC();
			const char* fname2 = ptr->f2_xxxIC();

			assert(strstr(fname0, SM_NAME_OF(f0_xxxIC)));
			assert(strstr(fname1, SM_NAME_OF(f1_xxxIC)));
			assert(strstr(fname2, SM_NAME_OF(f2_xxxIC)));
		}


		{
			auto [ptr, sp] = smQIHelper::QIRaw<xxxID>(unk);
			assert(ptr);

			TestAllQI(sp);

			const char* fname0 = ptr->f0_xxxID();
			const char* fname1 = ptr->f1_xxxID();
			const char* fname2 = ptr->f2_xxxID();

			assert(strstr(fname0, SM_NAME_OF(f0_xxxID)));
			assert(strstr(fname1, SM_NAME_OF(f1_xxxID)));
			assert(strstr(fname2, SM_NAME_OF(f2_xxxID)));
		}
	}

	template<typename TTT>
	static void yyyTestComReg()
	{
		auto* comReg = smComRegistry::SingleInstance();
		auto* modName = smModuleHelper::GetCurrentModuleName();

		const GUID& guid = smMetaTypeHelpers::UUID_OF<TTT>();
		const smMetaType* mt0 = TTT::StaticMetaType();
		auto* mt1 = comReg->Find(modName, guid);
		auto* mt2 = comReg->Find(guid);

		assert(mt0 == mt1 && mt0 == mt2);
	}

	static void yyyDoTestAllQI(IUnknown* unk)
	{
		{
			auto [ptr, sp] = smQIHelper::QIRaw<smIUnknown>(unk);
			assert(ptr);
			yyyTestComReg<smIUnknown>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<smIObjectBase>(unk);
			assert(ptr);
			yyyTestComReg<smIObjectBase>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyIA0>(unk);
			assert(ptr);
			yyyTestComReg<yyyIA0>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyIA1>(unk);
			assert(ptr);
			yyyTestComReg<yyyIA1>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyIA2>(unk);
			assert(ptr);
			yyyTestComReg<yyyIA2>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyIB>(unk);
			assert(ptr);
			yyyTestComReg<yyyIB>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyIC>(unk);
			assert(ptr);
			yyyTestComReg<yyyIC>();
		}
		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyID>(unk);
			assert(ptr);
			yyyTestComReg<yyyID>();
		}
	}

	static void yyyDoTestSmoke(IUnknown* unk)
	{

		{
			CComPtr<smIUnknown> unkTemp = smQIHelper::QI<smIUnknown>(unk);
			assert(unkTemp);
			yyyTestAllQI(unkTemp);

			CComPtr<smIObjectBase> obTemp = smQIHelper::QI<smIObjectBase>(unk);
			assert(obTemp);
			yyyTestAllQI(obTemp);
		}


		{
			CComPtr<yyyIA0> ptr = smQIHelper::QI<yyyIA0>(unk);
			assert(ptr);

			yyyTestAllQI(ptr);

			const char* fname0 = ptr->f0_yyyIA0();
			const char* fname1 = ptr->f1_yyyIA0();
			const char* fname2 = ptr->f2_yyyIA0();

			assert(strstr(fname0, SM_NAME_OF(f0_yyyIA0)));
			assert(strstr(fname1, SM_NAME_OF(f1_yyyIA0)));
			assert(strstr(fname2, SM_NAME_OF(f2_yyyIA0)));
		}


		{
			CComPtr<yyyIA1> ptr = smQIHelper::QI<yyyIA1>(unk);
			assert(ptr);

			yyyTestAllQI(ptr);

			const char* fname0 = ptr->f0_yyyIA1();
			const char* fname1 = ptr->f1_yyyIA1();
			const char* fname2 = ptr->f2_yyyIA1();

			assert(strstr(fname0, SM_NAME_OF(f0_yyyIA1)));
			assert(strstr(fname1, SM_NAME_OF(f1_yyyIA1)));
			assert(strstr(fname2, SM_NAME_OF(f2_yyyIA1)));
		}

		{
			CComPtr<yyyIA2> ptr = smQIHelper::QI<yyyIA2>(unk);
			assert(ptr);

			yyyTestAllQI(ptr);

			const char* fname0 = ptr->f0_yyyIA2();
			const char* fname1 = ptr->f1_yyyIA2();
			const char* fname2 = ptr->f2_yyyIA2();

			assert(strstr(fname0, SM_NAME_OF(f0_yyyIA2)));
			assert(strstr(fname1, SM_NAME_OF(f1_yyyIA2)));
			assert(strstr(fname2, SM_NAME_OF(f2_yyyIA2)));
		}

		{
			yyyID* ptr = nullptr;
			CComPtr<smIObjectBase> scope;
			scope.Attach(ptr);
		}


		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyIB>(unk);
			assert(ptr);

			yyyTestAllQI(sp);

			const char* fname0 = ptr->f0_yyyIB();
			const char* fname1 = ptr->f1_yyyIB();
			const char* fname2 = ptr->f2_yyyIB();

			assert(strstr(fname0, SM_NAME_OF(f0_yyyIB)));
			assert(strstr(fname1, SM_NAME_OF(f1_yyyIB)));
			assert(strstr(fname2, SM_NAME_OF(f2_yyyIB)));
		}

#if true
		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyIC>(unk);
			assert(ptr);

			yyyTestAllQI(sp);

			const char* fname0 = ptr->f0_yyyIC();
			const char* fname1 = ptr->f1_yyyIC();
			const char* fname2 = ptr->f2_yyyIC();

			assert(strstr(fname0, SM_NAME_OF(f0_yyyIC)));
			assert(strstr(fname1, SM_NAME_OF(f1_yyyIC)));
			assert(strstr(fname2, SM_NAME_OF(f2_yyyIC)));
		}


		{
			auto [ptr, sp] = smQIHelper::QIRaw<yyyID>(unk);
			assert(ptr);

			yyyTestAllQI(sp);

			const char* fname0 = ptr->f0_yyyID();
			const char* fname1 = ptr->f1_yyyID();
			const char* fname2 = ptr->f2_yyyID();

			assert(strstr(fname0, SM_NAME_OF(f0_yyyID)));
			assert(strstr(fname1, SM_NAME_OF(f1_yyyID)));
			assert(strstr(fname2, SM_NAME_OF(f2_yyyID)));
		}
#endif
	}

	static void TestSmoke(IUnknown* outter)
	{
		DoTestSmoke(outter);
		yyyDoTestSmoke(outter);
	}

	static void yyyTestSmoke(IUnknown* outter)
	{
		DoTestSmoke(outter);
		yyyDoTestSmoke(outter);
	}

} //namespace {



void TestFullRaw()
{
	using namespace ::std;
	using namespace ::SmartLib;

	auto vecitf = TestActivateInterface();
	auto vecClass = TestActivateClass();

	CComPtr<IUnknown> outter;
	vector<IUnknown*> objects(vecClass.size());
	for (size_t ii = 0; ii < objects.size(); ++ii)
	{
		objects[ii] = vecClass[ii]->CreateInstance();
	}
	outter.Attach(objects[0]);

	for (size_t ii = 0; ii < objects.size() - 1; ++ii)
	{
		smIObjectBase* outter = static_cast<smIObjectBase*>(objects[ii]);
		smIObjectBase* inner = static_cast<smIObjectBase*>(objects[ii + 1]);
		outter->Aggragate(inner);
		//smIObjectBaseHelpers::PostAggrate(objects[ii + 1]);
	}

	for (size_t ii = 0; ii < objects.size() - 1; ++ii)
	{
		smPostAggrageOp<IUnknown>::PostAggrate(objects[ii + 1]);
	}


	TestSmoke(outter);
	yyyTestSmoke(outter);
}


template<typename T>
static void TestIsTypeOf(T& ptr, const GUID& derivedGUID, const GUID& baseGUID)
{
	//smObjectBase* ptr = nullptr;
	assert(ptr->GetImplOutter()->InnerIsMetaType(derivedGUID));
	assert(ptr->GetImplOutter()->InnerIsMetaTypeOf(derivedGUID));
	assert(ptr->GetImplOutter()->InnerIsMetaTypeOf(baseGUID));
}

static void DoTestSmokeAgg(IUnknown* unk, const GUID& derivedGUID, const GUID& baseGUID)
{

	{
		CComPtr<smIUnknown> unkTemp = smQIHelper::QI<smIUnknown>(unk);
		assert(unkTemp);
		TestAllQI(unkTemp);
		//TestIsTypeOf(unkTemp, derivedGUID, baseGUID);
		//TestIsTypeOf(unkTemp, derivedGUID, baseGUID);

		CComPtr<smIObjectBase> obTemp = smQIHelper::QI<smIObjectBase>(unk);
		assert(obTemp);
		TestAllQI(obTemp);
		TestIsTypeOf(obTemp, derivedGUID, baseGUID);
	}


	{
		CComPtr<xxxIA0> ptr = smQIHelper::QI<xxxIA0>(unk);
		assert(ptr);

		TestAllQI(ptr);
		TestIsTypeOf(ptr, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_xxxIA0();
		const char* fname1 = ptr->f1_xxxIA0();
		const char* fname2 = ptr->f2_xxxIA0();

		assert(strstr(fname0, SM_NAME_OF(f0_xxxIA0)));
		assert(strstr(fname1, SM_NAME_OF(f1_xxxIA0)));
		assert(strstr(fname2, SM_NAME_OF(f2_xxxIA0)));
	}


	{
		CComPtr<xxxIA1> ptr = smQIHelper::QI<xxxIA1>(unk);
		assert(ptr);

		TestAllQI(ptr);
		TestIsTypeOf(ptr, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_xxxIA1();
		const char* fname1 = ptr->f1_xxxIA1();
		const char* fname2 = ptr->f2_xxxIA1();

		assert(strstr(fname0, SM_NAME_OF(f0_xxxIA1)));
		assert(strstr(fname1, SM_NAME_OF(f1_xxxIA1)));
		assert(strstr(fname2, SM_NAME_OF(f2_xxxIA1)));
	}

	{
		CComPtr<xxxIA2> ptr = smQIHelper::QI<xxxIA2>(unk);
		assert(ptr);

		TestAllQI(ptr);
		TestIsTypeOf(ptr, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_xxxIA2();
		const char* fname1 = ptr->f1_xxxIA2();
		const char* fname2 = ptr->f2_xxxIA2();

		assert(strstr(fname0, SM_NAME_OF(f0_xxxIA2)));
		assert(strstr(fname1, SM_NAME_OF(f1_xxxIA2)));
		assert(strstr(fname2, SM_NAME_OF(f2_xxxIA2)));
	}

	{
		xxxID* ptr = nullptr;
		CComPtr<smIObjectBase> scope;
		scope.Attach(ptr);
	}


	{
		auto [ptr, sp] = smQIHelper::QIRaw<xxxIB>(unk);
		assert(ptr);

		TestAllQI(sp);
		TestIsTypeOf(sp, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_xxxIB();
		const char* fname1 = ptr->f1_xxxIB();
		const char* fname2 = ptr->f2_xxxIB();

		assert(strstr(fname0, SM_NAME_OF(f0_xxxIB)));
		assert(strstr(fname1, SM_NAME_OF(f1_xxxIB)));
		assert(strstr(fname2, SM_NAME_OF(f2_xxxIB)));
	}

	{
		auto [ptr, sp] = smQIHelper::QIRaw<xxxIC>(unk);
		assert(ptr);

		TestAllQI(sp);
		TestIsTypeOf(sp, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_xxxIC();
		const char* fname1 = ptr->f1_xxxIC();
		const char* fname2 = ptr->f2_xxxIC();

		assert(strstr(fname0, SM_NAME_OF(f0_xxxIC)));
		assert(strstr(fname1, SM_NAME_OF(f1_xxxIC)));
		assert(strstr(fname2, SM_NAME_OF(f2_xxxIC)));
	}


	{
		auto [ptr, sp] = smQIHelper::QIRaw<xxxID>(unk);
		assert(ptr);

		TestAllQI(sp);
		TestIsTypeOf(sp, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_xxxID();
		const char* fname1 = ptr->f1_xxxID();
		const char* fname2 = ptr->f2_xxxID();

		assert(strstr(fname0, SM_NAME_OF(f0_xxxID)));
		assert(strstr(fname1, SM_NAME_OF(f1_xxxID)));
		assert(strstr(fname2, SM_NAME_OF(f2_xxxID)));
	}
}

void TestFull()
{
	using namespace ::std;
	using namespace ::SmartLib;

	auto vecitf = TestActivateInterface();
	auto vecClass = TestActivateClass();

	vector<CComPtr<IUnknown>> objects(vecClass.size());
	for (size_t ii = 0; ii < objects.size(); ++ii)
	{
		objects[ii].Attach(vecClass[ii]->CreateInstance());
	}

	for (size_t ii = 0; ii < objects.size() - 1; ++ii)
	{
		smIObjectBase* outter = static_cast<smIObjectBase*>(objects[ii].p);
		smIObjectBase* inner = static_cast<smIObjectBase*>(objects[ii + 1].p);
		outter->Aggragate(inner);
		//smIObjectBaseHelpers::PostAggrate(objects[ii + 1]);
	}

	for (size_t ii = 0; ii < objects.size() - 1; ++ii)
	{
		smPostAggrageOp<CComPtr<IUnknown>>::PostAggrate(objects[ii + 1]);
	}


	TestSmoke(objects[0]);
	yyyTestSmoke(objects[0]);

}



static void yyyDoTestSmokeAgg(IUnknown* unk, const GUID& derivedGUID, const GUID& baseGUID)
{

	{
		CComPtr<smIUnknown> unkTemp = smQIHelper::QI<smIUnknown>(unk);
		assert(unkTemp);
		yyyTestAllQI(unkTemp);
		//TestIsTypeOf(unkTemp, derivedGUID, baseGUID);

		CComPtr<smIObjectBase> obTemp = smQIHelper::QI<smIObjectBase>(unk);
		assert(obTemp);
		yyyTestAllQI(obTemp);
		TestIsTypeOf(obTemp, derivedGUID, baseGUID);
	}


	{
		CComPtr<yyyIA0> ptr = smQIHelper::QI<yyyIA0>(unk);
		assert(ptr);

		yyyTestAllQI(ptr);
		TestIsTypeOf(ptr, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_yyyIA0();
		const char* fname1 = ptr->f1_yyyIA0();
		const char* fname2 = ptr->f2_yyyIA0();

		assert(strstr(fname0, SM_NAME_OF(f0_yyyIA0)));
		assert(strstr(fname1, SM_NAME_OF(f1_yyyIA0)));
		assert(strstr(fname2, SM_NAME_OF(f2_yyyIA0)));
	}


	{
		CComPtr<yyyIA1> ptr = smQIHelper::QI<yyyIA1>(unk);
		assert(ptr);

		yyyTestAllQI(ptr);
		TestIsTypeOf(ptr, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_yyyIA1();
		const char* fname1 = ptr->f1_yyyIA1();
		const char* fname2 = ptr->f2_yyyIA1();

		assert(strstr(fname0, SM_NAME_OF(f0_yyyIA1)));
		assert(strstr(fname1, SM_NAME_OF(f1_yyyIA1)));
		assert(strstr(fname2, SM_NAME_OF(f2_yyyIA1)));
	}

	{
		CComPtr<yyyIA2> ptr = smQIHelper::QI<yyyIA2>(unk);
		assert(ptr);

		yyyTestAllQI(ptr);
		TestIsTypeOf(ptr, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_yyyIA2();
		const char* fname1 = ptr->f1_yyyIA2();
		const char* fname2 = ptr->f2_yyyIA2();

		assert(strstr(fname0, SM_NAME_OF(f0_yyyIA2)));
		assert(strstr(fname1, SM_NAME_OF(f1_yyyIA2)));
		assert(strstr(fname2, SM_NAME_OF(f2_yyyIA2)));
	}

	{
		yyyID* ptr = nullptr;
		CComPtr<smIObjectBase> scope;
		scope.Attach(ptr);
	}


	{
		auto [ptr, sp] = smQIHelper::QIRaw<yyyIB>(unk);
		assert(ptr);

		yyyTestAllQI(sp);
		TestIsTypeOf(sp, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_yyyIB();
		const char* fname1 = ptr->f1_yyyIB();
		const char* fname2 = ptr->f2_yyyIB();

		assert(strstr(fname0, SM_NAME_OF(f0_yyyIB)));
		assert(strstr(fname1, SM_NAME_OF(f1_yyyIB)));
		assert(strstr(fname2, SM_NAME_OF(f2_yyyIB)));
	}

#if true
	{
		auto [ptr, sp] = smQIHelper::QIRaw<yyyIC>(unk);
		assert(ptr);

		yyyTestAllQI(sp);
		TestIsTypeOf(sp, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_yyyIC();
		const char* fname1 = ptr->f1_yyyIC();
		const char* fname2 = ptr->f2_yyyIC();

		assert(strstr(fname0, SM_NAME_OF(f0_yyyIC)));
		assert(strstr(fname1, SM_NAME_OF(f1_yyyIC)));
		assert(strstr(fname2, SM_NAME_OF(f2_yyyIC)));
	}


	{
		auto [ptr, sp] = smQIHelper::QIRaw<yyyID>(unk);
		assert(ptr);

		yyyTestAllQI(sp);
		TestIsTypeOf(sp, derivedGUID, baseGUID);

		const char* fname0 = ptr->f0_yyyID();
		const char* fname1 = ptr->f1_yyyID();
		const char* fname2 = ptr->f2_yyyID();

		assert(strstr(fname0, SM_NAME_OF(f0_yyyID)));
		assert(strstr(fname1, SM_NAME_OF(f1_yyyID)));
		assert(strstr(fname2, SM_NAME_OF(f2_yyyID)));
	}
#endif
}


void TestFullRawAgg()
{
	using namespace ::std;
	using namespace ::SmartLib;

	auto vecitf = TestActivateInterface();
	auto vecClass = TestActivateClass();

	CComPtr<IUnknown> outter;
	vector<IUnknown*> objects(vecClass.size());
	for (size_t ii = 0; ii < objects.size(); ++ii)
	{
		objects[ii] = vecClass[ii]->CreateInstance();
	}
	outter.Attach(objects[0]);

	for (size_t ii = 0; ii < objects.size() - 1; ++ii)
	{
		smIObjectBase* outter = static_cast<smIObjectBase*>(objects[ii]);
		smIObjectBase* inner = static_cast<smIObjectBase*>(objects[ii + 1]);
		outter->AggragateComBase(inner);
		//smIObjectBaseHelpers::PostAggrate(objects[ii + 1]);
	}

	for (size_t ii = 0; ii < objects.size() - 1; ++ii)
	{
		smPostAggrageOp<IUnknown>::PostAggrate(objects[ii + 1]);
	}

	const GUID& derivedGUID = vecClass[0]->GetID();
	const GUID& baseGUID = vecClass[1]->GetID();

	DoTestSmokeAgg(outter, derivedGUID, baseGUID);
	yyyDoTestSmokeAgg(outter, derivedGUID, baseGUID);
}

