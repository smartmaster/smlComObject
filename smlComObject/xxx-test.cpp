

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

/************************

//inheritance

xIA0
	+smIObjectBase

xIA1
	+smIObjectBase

xIA2
	+smIObjectBase


xIB
	+smIObjectBase
	+xIA0
	+xIA1
	+xIA2

xIC
	+smIObjectBase
	+xIA0
	+xIA1
	+xIA2

xID
	+smIObjectBase
	+xIA0
	+xIA1
	+xIA2


smObjectBase<xIB, xIC, xID>
	+smIObjectBase
	+xIB
	+xIC
	+xID


xObject
	+smObjectBase<xIB, xIC, xID>


//full hierachy
xObject
	+smObjectBase<xIB, xIC, xID>
		++smIObjectBase
		++xIB
				+++smIObjectBase
				+++xIA0
					++++smIObjectBase
				+++xIA1
					++++smIObjectBase
				+++xIA2
					++++smIObjectBase
		++xIC
				+++smIObjectBase
				+++xIA0
					++++smIObjectBase
				+++xIA1
					++++smIObjectBase
				+++xIA2
					++++smIObjectBase
		++xID
				+++smIObjectBase
				+++xIA0
					++++smIObjectBase
				+++xIA1
					++++smIObjectBase
				+++xIA2
					++++smIObjectBase
************************/


#pragma region xxx

namespace
{
	using namespace SmartLib;

#if false

	class xxxIA0 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417900}
			return smMetaTypeMaker::Make<xxxIA0, smIObjectBase>(
				SM_NAME_OF(xxxIA0),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x00 } }
			);
		}

	public:
		virtual const char* f0_xxxIA0() = 0;
		virtual const char* f1_xxxIA0() = 0;
		virtual const char* f2_xxxIA0() = 0;
	};

	class xxxIA1 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417900}
			return smMetaTypeMaker::Make<xxxIA1, smIObjectBase>(
				SM_NAME_OF(xxxIA1),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x01 } }
			);
		}

	public:
		virtual const char* f0_xxxIA1() = 0;
		virtual const char* f1_xxxIA1() = 0;
		virtual const char* f2_xxxIA1() = 0;
	};

	class xxxIA2 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xxxIA2, smIObjectBase>(
				SM_NAME_OF(xxxIA2),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x02 } }
			);
		}

	public:
		virtual const char* f0_xxxIA2() = 0;
		virtual const char* f1_xxxIA2() = 0;
		virtual const char* f2_xxxIA2() = 0;
	};


	class xxxIB :
		public smIObjectBase,
		public xxxIA0,
		public xxxIA1,
		public xxxIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xxxIB, smIObjectBase, xxxIA0, xxxIA1, xxxIA2>(
				SM_NAME_OF(xxxIB),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x03 } }
			);
		}

	public:
		virtual const char* f0_xxxIB() = 0;
		virtual const char* f1_xxxIB() = 0;
		virtual const char* f2_xxxIB() = 0;
	};

	class xxxIC :
		public smIObjectBase,
		public xxxIA0,
		public xxxIA1,
		public xxxIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xxxIC, smIObjectBase, xxxIA0, xxxIA1, xxxIA2>(
				SM_NAME_OF(xxxIC),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x04 } }
			);
		}

	public:
		virtual const char* f0_xxxIC() = 0;
		virtual const char* f1_xxxIC() = 0;
		virtual const char* f2_xxxIC() = 0;
	};

	class xxxID :
		public smIObjectBase,
		public xxxIA0,
		public xxxIA1,
		public xxxIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xxxID, smIObjectBase, xxxIA0, xxxIA1, xxxIA2>(
				SM_NAME_OF(xxxID),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x05 } }
			);
		}

	public:
		virtual const char* f0_xxxID() = 0;
		virtual const char* f1_xxxID() = 0;
		virtual const char* f2_xxxID() = 0;
	};
#endif

	class xxxObject : public smObjectBase<xxxIB, xxxIC, xxxID>
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<xxxObject, smObjectBase<xxxIB, xxxIC, xxxID>>(
				SM_NAME_OF(xxxObject),
				// {D23257E5-A355-43AF-BBB4-6CB0A9D5EADA}
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x06 } }
			);
		}

		virtual const smMetaType* GetMetaType()  override
		{
			return StaticMetaType();
		}

	public:

		virtual ~xxxObject()
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
		}

		virtual const char* f0_xxxIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xxxIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xxxIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}


		virtual const char* f0_xxxIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xxxIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xxxIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_xxxIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xxxIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xxxIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}


		virtual const char* f0_xxxIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xxxIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xxxIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_xxxIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xxxIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xxxIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_xxxID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xxxID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xxxID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
	};


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

	static void TestAllQI(IUnknown* unk)
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
}

#pragma endregion

void TestSmoke()
{
	CComPtr<IUnknown> unk;
	unk.Attach(xxxObject::StaticMetaType()->CreateInstance());
	TestAllQI(unk);

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

#if true
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
#endif
}


#pragma region yyyyy

namespace
{
	using namespace SmartLib;

#if false

	class yyyIA0 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417900}
			return smMetaTypeMaker::Make<yyyIA0, smIObjectBase>(
				SM_NAME_OF(yyyIA0),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x00, 0x00 } }
			);
		}

	public:
		virtual const char* f0_yyyIA0() = 0;
		virtual const char* f1_yyyIA0() = 0;
		virtual const char* f2_yyyIA0() = 0;
	};

	class yyyIA1 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417900}
			return smMetaTypeMaker::Make<yyyIA1, smIObjectBase>(
				SM_NAME_OF(yyyIA1),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x01, 0x01 } }
			);
		}

	public:
		virtual const char* f0_yyyIA1() = 0;
		virtual const char* f1_yyyIA1() = 0;
		virtual const char* f2_yyyIA1() = 0;
	};

	class yyyIA2 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<yyyIA2, smIObjectBase>(
				SM_NAME_OF(yyyIA2),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x02, 0x02 } }
			);
		}

	public:
		virtual const char* f0_yyyIA2() = 0;
		virtual const char* f1_yyyIA2() = 0;
		virtual const char* f2_yyyIA2() = 0;
	};


	class yyyIB :
		public smIObjectBase,
		public yyyIA0,
		public yyyIA1,
		public yyyIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<yyyIB, smIObjectBase, yyyIA0, yyyIA1, yyyIA2>(
				SM_NAME_OF(yyyIB),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x03, 0x03 } }
			);
		}

	public:
		virtual const char* f0_yyyIB() = 0;
		virtual const char* f1_yyyIB() = 0;
		virtual const char* f2_yyyIB() = 0;
	};

	class yyyIC :
		public smIObjectBase,
		public yyyIA0,
		public yyyIA1,
		public yyyIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<yyyIC, smIObjectBase, yyyIA0, yyyIA1, yyyIA2>(
				SM_NAME_OF(yyyIC),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x04, 0x04 } }
			);
		}

	public:
		virtual const char* f0_yyyIC() = 0;
		virtual const char* f1_yyyIC() = 0;
		virtual const char* f2_yyyIC() = 0;
	};

	class yyyID :
		public smIObjectBase,
		public yyyIA0,
		public yyyIA1,
		public yyyIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<yyyID, smIObjectBase, yyyIA0, yyyIA1, yyyIA2>(
				SM_NAME_OF(yyyID),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x05, 0x05 } }
			);
		}

	public:
		virtual const char* f0_yyyID() = 0;
		virtual const char* f1_yyyID() = 0;
		virtual const char* f2_yyyID() = 0;
	};

#endif

	class yyyObject : public smObjectBase<yyyIB, yyyIC, yyyID>
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<yyyObject, smObjectBase<yyyIB, yyyIC, yyyID>>(
				SM_NAME_OF(yyyObject),
				// {D23257E5-A355-43AF-BBB4-6CB0A9D5EADA}
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x06, 0x06 } }
			);
		}

		virtual const smMetaType* GetMetaType()  override
		{
			return StaticMetaType();
		}

	public:

		virtual ~yyyObject()
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
		}

		virtual const char* f0_yyyIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_yyyIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_yyyIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}


		virtual const char* f0_yyyIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_yyyIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_yyyIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_yyyIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_yyyIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_yyyIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}


		virtual const char* f0_yyyIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_yyyIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_yyyIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_yyyIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_yyyIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_yyyIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_yyyID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_yyyID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_yyyID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
	};


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

	static void yyyTestAllQI(IUnknown* unk)
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
}

void yyyTestSmoke()
{
	CComPtr<IUnknown> unk;
	unk.Attach(yyyObject::StaticMetaType()->CreateInstance());
	yyyTestAllQI(unk);

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

std::vector<const smMetaType*> TestActivateInterface()
{
	std::vector<const smMetaType*> vec;
	vec.emplace_back(xxxIA0::StaticMetaType());
	vec.emplace_back(xxxIA1::StaticMetaType());
	vec.emplace_back(xxxIA2::StaticMetaType());
	vec.emplace_back(xxxIB::StaticMetaType());
	vec.emplace_back(xxxIC::StaticMetaType());
	vec.emplace_back(xxxID::StaticMetaType());


	vec.emplace_back(yyyIA0::StaticMetaType());
	vec.emplace_back(yyyIA1::StaticMetaType());
	vec.emplace_back(yyyIA2::StaticMetaType());
	vec.emplace_back(yyyIB::StaticMetaType());
	vec.emplace_back(yyyIC::StaticMetaType());
	vec.emplace_back(yyyID::StaticMetaType());

	return vec;
}


std::vector<const smMetaType*> TestActivateClass()
{
	std::vector<const smMetaType*> vecClass;
	vecClass.emplace_back(xxxObject::StaticMetaType());
	vecClass.emplace_back(yyyObject::StaticMetaType());
	return vecClass;
}

#pragma endregion

#if true

//usage and example

namespace
{
	//for interface 
	//multiple inheritance for interface is supported
	class zzzInterface :
		public smIObjectBase,
		public xxxIB,	//to change...
		public xxxIC,	//to change...
		public xxxID	//to change...
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<zzzInterface, smIObjectBase, xxxIB, xxxIC, xxxID> //to change...
				(
					SM_NAME_OF(zzzInterface),//to change...
					GUID{ GUID_NULL }//to change...
			);
		}

	public:
		//pure virtual methods
		//virtual void foo() = 0;
	};


	//for class
	//zzzObject should and must be singly inherited by smObjectBase<...>
	class zzzObject :
		public smObjectBase<xxxIB, xxxIC, xxxID> //to change...
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<zzzObject, smObjectBase<xxxIB, xxxIC, xxxID>> //to change...
				(
					SM_NAME_OF(zzzObject), //to change...
					GUID{ GUID_NULL } //to change...
			);
		}

		virtual const smMetaType* GetMetaType()  override
		{
			return StaticMetaType();
		}

	public:
		//impls for pure virtual methods
		//virtual void foo() override {}
	};
}

#endif