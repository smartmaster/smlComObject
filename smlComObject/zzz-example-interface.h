#pragma once

#include "smIObjectBase.h"

namespace SmartLib
{
	class zzzIA : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {7452374F-DFD8-4F7B-BCDC-FCD5AB2763AA}
			return smMetaTypeMaker::Make<zzzIA, smIObjectBase>(
				SM_NAME_OF(zzzIA),
				GUID{ 0x7452374f, 0xdfd8, 0x4f7b, { 0xbc, 0xdc, 0xfc, 0xd5, 0xab, 0x27, 0x63, 0xaa } }
			);
		}


	public:
		virtual const char* fa_zzzIA() = 0;
		virtual const char* fb_zzzIA() = 0;
		virtual const char* fc_zzzIA() = 0;
	};

	class zzzIB : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {7452374F-DFD8-4F7B-BCDC-FCD5AB2763BB}
			return smMetaTypeMaker::Make<zzzIB, smIObjectBase>(
				SM_NAME_OF(zzzIB),
				GUID{ 0x7452374f, 0xdfd8, 0x4f7b, { 0xbc, 0xdc, 0xfc, 0xd5, 0xab, 0x27, 0x63, 0xbb } }
			);
		}


	public:
		virtual  const char* fa_zzzIB() = 0;
		virtual  const char* fb_zzzIB() = 0;
		virtual  const char* fc_zzzIB() = 0;
	};

	class zzzIC : public smIObjectBase
	{
	public:
		static const smMetaType* StaticMetaType()
		{
			// {7452374F-DFD8-4F7B-BCDC-FCD5AB2763CC}
			return smMetaTypeMaker::Make<zzzIC, smIObjectBase>(
				SM_NAME_OF(zzzIC),
				GUID{ 0x7452374f, 0xdfd8, 0x4f7b, { 0xbc, 0xdc, 0xfc, 0xd5, 0xab, 0x27, 0x63, 0xcc } }
			);
		}


	public:
		virtual  const char* fa_zzzIC() = 0;
		virtual  const char* fb_zzzIC() = 0;
		virtual  const char* fc_zzzIC() = 0;
	};


	extern const smMetaType* StaticMetaType_zzzObject();
}