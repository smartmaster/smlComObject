
#include <cassert>
#include <sstream>

#include "smMetaType.h"
#include "smGUIDHelper.h"


SmartLib::smMetaType::smMetaType(const char* name, const GUID& guid) :
	_name{ name },
	_guid{ guid }
{

}

const char* SmartLib::smMetaType::GetName() const
{
	return _name;
}

const GUID& SmartLib::smMetaType::GetID() const
{
	return _guid;
}

void SmartLib::smMetaType::AddCppBaseOffset(const smMetaType* mt, ptrdiff_t offset)
{
	_cppBaseOffsets.emplace_back(mt, offset);
}

#if false
void SmartLib::smMetaType::AddComBase(const smMetaType* mt)
{
	_comBaseInners.emplace_back(mt);
}
#endif

void SmartLib::smMetaType::SetCreateInstanceMethod(pfnCreateInstance ci)
{
	_pfnCreateInstance = ci;
}

IUnknown* SmartLib::smMetaType::CreateInstance() const
{
	assert(_pfnCreateInstance);
	return _pfnCreateInstance();
}


#if false
const SmartLib::smMetaType* SmartLib::smMetaType::FindComMetaType(const GUID& guid) const
{
	const smMetaType* mt = nullptr;
	if (::IsEqualGUID(guid, _guid))
	{
		mt = this;
	}
	else
	{
		for (auto comBase : _comBaseInners)
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
#endif


ptrdiff_t SmartLib::smMetaType::FindCppOffset(const GUID& guid) const
{
	ptrdiff_t offset = -1; //<0 means not found
	auto iter = _cachedOffsets.find(guid);
	if (iter != _cachedOffsets.end())
	{
		offset = iter->second;
		assert(offset >= 0);
	}
	return offset;
}

void SmartLib::smMetaType::EnumCppOffset(ptrdiff_t curoffset, std::unordered_map<GUID, ptrdiff_t, smGUIDHasher, smGUIDEqual>& cachedOffsets)
{
	cachedOffsets.insert({ _guid, curoffset });
	for (auto [cppBase, offset] : _cppBaseOffsets)
	{
		const_cast<smMetaType*>(cppBase)->EnumCppOffset(curoffset + offset, cachedOffsets); //recursively
	}
}

void SmartLib::smMetaType::EnumCppOffset()
{
	EnumCppOffset(0, _cachedOffsets);
}

void SmartLib::smMetaType::Print(int level, ptrdiff_t curOffset, std::ostream& out) const
{
	for (int ii = 0; ii < level; ++ ii) { out << '\t';}
	out << _name << ", " << smGUIDToString::ToString(_guid) << ", @" << curOffset << "\r\n";
	for (const auto [cppbase, cppbaseOffset] : _cppBaseOffsets)
	{
		cppbase->Print(level + 1, curOffset + cppbaseOffset, out); //recursively
	}
}

void SmartLib::smMetaType::Print(int level, ptrdiff_t curOffset) const
{
	Print(level, curOffset, std::cout);
}
