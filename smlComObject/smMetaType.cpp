
#include <cassert>
#include <sstream>

#include "smMetaType.h"
#include "smGUIDHelper.h"

namespace SmartLib
{

	smMetaType::smMetaType(const char* name, const GUID& guid) :
		_name{ name },
		_guid{ guid }
	{

	}

	const char* smMetaType::GetName() const
	{
		return _name;
	}

	const GUID& smMetaType::GetID() const
	{
		return _guid;
	}

	void smMetaType::AddCppBaseOffset(const smMetaType* mt, ptrdiff_t offset)
	{
		_cppBaseOffsets.emplace_back(mt, offset);
	}


	void smMetaType::SetCreateInstanceMethod(pfnCreateInstance ci)
	{
		_pfnCreateInstance = ci;
	}

	smIUnknown* smMetaType::CreateInstance() const
	{
		assert(_pfnCreateInstance);
		return _pfnCreateInstance();
	}




	ptrdiff_t smMetaType::FindCppOffset(const GUID& guid) const
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

	void smMetaType::EnumCppOffset(ptrdiff_t curoffset, std::unordered_map<GUID, ptrdiff_t, smGUIDHasher, smGUIDEqual>& cachedOffsets)
	{
		cachedOffsets.insert({ _guid, curoffset });
		for (auto [cppBase, offset] : _cppBaseOffsets)
		{
			const_cast<smMetaType*>(cppBase)->EnumCppOffset(curoffset + offset, cachedOffsets); //recursively
		}
	}

	void smMetaType::EnumCppOffset()
	{
		EnumCppOffset(0, _cachedOffsets);
	}

	void smMetaType::Print(int level, ptrdiff_t curOffset, std::ostream& out) const
	{
		for (int ii = 0; ii < level; ++ii) { out << '\t'; }
		out << _name << ", " << smGUIDToString::ToString(_guid) << ", @" << curOffset << "\r\n";
		for (const auto [cppbase, cppbaseOffset] : _cppBaseOffsets)
		{
			cppbase->Print(level + 1, curOffset + cppbaseOffset, out); //recursively
		}
	}

	void smMetaType::Print(int level, ptrdiff_t curOffset) const
	{
		Print(level, curOffset, std::cout);
	}


}//namespace SmartLib