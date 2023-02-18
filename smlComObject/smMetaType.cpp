
#include <cassert>
#include "smMetaType.h"



SmartLib::smMetaType::smMetaType(const char* name, const GUID& guid) :
	_name{ name },
	_guid{ guid }
{

}

void SmartLib::smMetaType::AddCppBaseOffset(const smMetaType* mt, ptrdiff_t offset)
{
	_cppBaseOffsets.emplace_back(mt, offset);
}

void SmartLib::smMetaType::AddComBase(const smMetaType* mt)
{
	_comBases.emplace_back(mt);
}

void SmartLib::smMetaType::SetCreateInstanceMethod(pfnCreateInstance ci)
{
	_pfnCreateInstance = ci;
}

IUnknown* SmartLib::smMetaType::CreateInstance() const
{
	assert(_pfnCreateInstance);
	return _pfnCreateInstance();
}

const SmartLib::smMetaType* SmartLib::smMetaType::FindComMetaType(const GUID& guid) const
{
	const smMetaType* mt = nullptr;
	if (::IsEqualGUID(guid, _guid))
	{
		mt = this;
	}
	else
	{
		for (auto comBase : _comBases)
		{
			mt = comBase->FindComMetaType(guid); //recursively
			if (mt)
			{
				break;
			}
		}
	}
	return mt;
}

ptrdiff_t SmartLib::smMetaType::FindCppOffset(const GUID& guid, ptrdiff_t currentOffset) const
{
	ptrdiff_t offset = -1; //<0 means not found

	if (::IsEqualGUID(guid, _guid))
	{
		offset = currentOffset;
	}
	else
	{
		for (auto [baseMT, baseOff] : _cppBaseOffsets)
		{
			offset = baseMT->FindCppOffset(guid, currentOffset + baseOff); //recursively
			if (offset >= 0)
			{
				break;
			}
		}
	}
	return offset;
}
