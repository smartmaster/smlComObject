

#include <iostream>
#include <atlbase.h>

#include "smMetaType.h"
#include "smIObjectBase.h"
#include "smObjectBase.h"
#include "smMetaTypeHelpers.h"
#include "smIObjectBaseHelpers.h"
#include "smQIHelper.h"

namespace
{
	using namespace SmartLib;


	class xIA0 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417900}
			return smMetaTypeMaker::Make<xIA0, smIObjectBase>(
				SM_NAME_OF(xIA0),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x00 } }
			);
		}

	public:
		virtual const char* f0_xIA0() = 0;
		virtual const char* f1_xIA0() = 0;
		virtual const char* f2_xIA0() = 0;
	};

	class xIA1 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417900}
			return smMetaTypeMaker::Make<xIA1, smIObjectBase>(
				SM_NAME_OF(xIA1),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x01 } }
			);
		}

	public:
		virtual const char* f0_xIA1() = 0;
		virtual const char* f1_xIA1() = 0;
		virtual const char* f2_xIA1() = 0;
	};

	class xIA2 : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xIA2, smIObjectBase>(
				SM_NAME_OF(xIA2),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x02 } }
			);
		}

	public:
		virtual const char* f0_xIA2() = 0;
		virtual const char* f1_xIA2() = 0;
		virtual const char* f2_xIA2() = 0;
	};


	class xIB :
		public smIObjectBase,
		public xIA0,
		public xIA1,
		public xIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xIB, smIObjectBase, xIA0, xIA1, xIA2>(
				SM_NAME_OF(xIB),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x03 } }
			);
		}

	public:
		virtual const char* f0_xIB() = 0;
		virtual const char* f1_xIB() = 0;
		virtual const char* f2_xIB() = 0;
	};

	class xIC :
		public smIObjectBase,
		public xIA0,
		public xIA1,
		public xIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xIC, smIObjectBase, xIA0, xIA1, xIA2>(
				SM_NAME_OF(xIC),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x04 } }
			);
		}

	public:
		virtual const char* f0_xIC() = 0;
		virtual const char* f1_xIC() = 0;
		virtual const char* f2_xIC() = 0;
	};

	class xID :
		public smIObjectBase,
		public xIA0,
		public xIA1,
		public xIA2
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {2B5945A9-9A50-4C0E-A67B-24288A417902}
			return smMetaTypeMaker::Make<xID, smIObjectBase, xIA0, xIA1, xIA2>(
				SM_NAME_OF(xID),
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x05 } }
			);
		}

	public:
		virtual const char* f0_xID() = 0;
		virtual const char* f1_xID() = 0;
		virtual const char* f2_xID() = 0;
	};

	class xObject : public smObjectBase<xIB, xIC, xID>
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			return smMetaTypeMaker::Make<xObject, smObjectBase<xIB, xIC, xID>>(
				SM_NAME_OF(xObject),
				// {D23257E5-A355-43AF-BBB4-6CB0A9D5EADA}
				GUID{ 0x2b5945a9, 0x9a50, 0x4c0e, { 0xa6, 0x7b, 0x24, 0x28, 0x8a, 0x41, 0x79, 0x06 } }
			);
		}

		virtual const smMetaType* GetMetaType()  override
		{
			return StaticMetaType();
		}

	public:

		virtual ~xObject()
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
		}

		virtual const char* f0_xIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xIA0() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}


		virtual const char* f0_xIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xIA1() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_xIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xIA2() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}


		virtual const char* f0_xIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xIB() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_xIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xIC() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}

		virtual const char* f0_xID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f1_xID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
		virtual const char* f2_xID() override
		{
			using namespace ::std;
			cout << __FUNCTION__ << endl;
			return __FUNCTION__;
		}
	};
}

void TestSmoke()
{
	CComPtr<IUnknown> unk;
	unk.Attach(xObject::StaticMetaType()->CreateInstance());

	{
		CComPtr<smIUnknown> unk1 = smQIHelper::QI<smIUnknown>(unk);
		assert(unk1);

		CComPtr<smIObjectBase> ob = smQIHelper::QI<smIObjectBase>(unk);
		assert(ob);
	}


	{
		CComPtr<xIA0> ptr = smQIHelper::QI<xIA0>(unk);
		assert(ptr);
		
		const char* fname0 = ptr->f0_xIA0();
		const char* fname1 = ptr->f1_xIA0();
		const char* fname2 = ptr->f2_xIA0();

		assert(strstr(fname0, SM_NAME_OF(f0_xIA0)));
		assert(strstr(fname1, SM_NAME_OF(f1_xIA0)));
		assert(strstr(fname2, SM_NAME_OF(f2_xIA0)));
	}


	{
		CComPtr<xIA1> ptr = smQIHelper::QI<xIA1>(unk);
		assert(ptr);

		const char* fname0 = ptr->f0_xIA1();
		const char* fname1 = ptr->f1_xIA1();
		const char* fname2 = ptr->f2_xIA1();

		assert(strstr(fname0, SM_NAME_OF(f0_xIA1)));
		assert(strstr(fname1, SM_NAME_OF(f1_xIA1)));
		assert(strstr(fname2, SM_NAME_OF(f2_xIA1)));
	}

	{
		CComPtr<xIA2> ptr = smQIHelper::QI<xIA2>(unk);
		assert(ptr);

		const char* fname0 = ptr->f0_xIA2();
		const char* fname1 = ptr->f1_xIA2();
		const char* fname2 = ptr->f2_xIA2();

		assert(strstr(fname0, SM_NAME_OF(f0_xIA2)));
		assert(strstr(fname1, SM_NAME_OF(f1_xIA2)));
		assert(strstr(fname2, SM_NAME_OF(f2_xIA2)));
	}

	{
		xID* ptr = nullptr;
		CComPtr<smIObjectBase> scope;
		scope.Attach(ptr);
	}


	{
		xIB* ptr = smQIHelper::QIRaw<xIB>(unk);
		assert(ptr);

		CComPtr<smIObjectBase> scope; //release xIB when out of scope
		scope.Attach(ptr);

		const char* fname0 = ptr->f0_xIB();
		const char* fname1 = ptr->f1_xIB();
		const char* fname2 = ptr->f2_xIB();

		assert(strstr(fname0, SM_NAME_OF(f0_xIB)));
		assert(strstr(fname1, SM_NAME_OF(f1_xIB)));
		assert(strstr(fname2, SM_NAME_OF(f2_xIB)));
	}

#if true
	{
		xIC* ptr = smQIHelper::QIRaw<xIC>(unk);
		assert(ptr);

		CComPtr<smIObjectBase> scope; //release xIB when out of scope
		scope.Attach(ptr);

		const char* fname0 = ptr->f0_xIC();
		const char* fname1 = ptr->f1_xIC();
		const char* fname2 = ptr->f2_xIC();

		assert(strstr(fname0, SM_NAME_OF(f0_xIC)));
		assert(strstr(fname1, SM_NAME_OF(f1_xIC)));
		assert(strstr(fname2, SM_NAME_OF(f2_xIC)));
	}


	{
		xID* ptr = smQIHelper::QIRaw<xID>(unk);
		assert(ptr);

		CComPtr<smIObjectBase> scope; //release xIB when out of scope
		scope.Attach(ptr);

		const char* fname0 = ptr->f0_xID();
		const char* fname1 = ptr->f1_xID();
		const char* fname2 = ptr->f2_xID();

		assert(strstr(fname0, SM_NAME_OF(f0_xID)));
		assert(strstr(fname1, SM_NAME_OF(f1_xID)));
		assert(strstr(fname2, SM_NAME_OF(f2_xID)));
	}
#endif
}
