#pragma once

#include "smIUnknown.h"

#include <unordered_map>
#include <string>


namespace SmartLib
{
	class smGUIDHasher
	{
	public:
		size_t operator()(const GUID& guid) const;
	};

	class smGUIDEqual
	{
	public:
		size_t operator()(const GUID& guid1, const GUID& guid2) const;
	};

	class smGUIDToString
	{
	public:
		static std::string ToString(const GUID& guid);
	};
}