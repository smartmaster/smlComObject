#pragma once




#include <iostream>
#include <vector>
#include <atlbase.h>

#include "smMetaType.h"
#include "smIObjectBase.h"
#include "smObjectBase.h"
#include "smMetaTypeHelpers.h"
#include "smIObjectBaseHelpers.h"
#include "smQIHelper.h"

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

//namespace
//{
	using namespace SmartLib;


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
//}

//#pragma endregion




#pragma region yyyyy

//namespace
//{
	using namespace SmartLib;


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

//}

#pragma endregion

