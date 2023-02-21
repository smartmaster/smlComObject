#include "smGUIDHelper.h"

size_t SmartLib::smGUIDHasher::operator()(const GUID& guid) const
{
	/**********************
	* refer to
	* C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Tools\MSVC\14.34.31933\include\type_traits
	**********************/
	const size_t* ull = reinterpret_cast<const size_t*>(&guid);

#if defined(_WIN64)
	constexpr size_t _FNV_offset_basis = 14695981039346656037ULL;
	constexpr size_t _FNV_prime = 1099511628211ULL;
#else // defined(_WIN64)
	constexpr size_t _FNV_offset_basis = 2166136261U;
	constexpr size_t _FNV_prime = 16777619U;
#endif // defined(_WIN64)

	size_t hv = _FNV_offset_basis;
	for (int ii = 0; ii < sizeof(GUID) / sizeof(size_t); ++ii)
	{
		hv ^= static_cast<size_t>(ull[ii]);
		hv *= _FNV_prime;
	}
	return hv;
}

size_t SmartLib::smGUIDEqual::operator()(const GUID& guid1, const GUID& guid2) const
{
	return IsEqualGUID(guid1, guid2);
}

std::string SmartLib::smGUIDToString::ToString(const GUID& guid)
{
	char guid_string[64] = { 0 }; //>  32 hex chars + 4 hyphens + 2 brackets + null terminator
	snprintf(
		guid_string, sizeof(guid_string),
		"{%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2],
		guid.Data4[3], guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]);
	return std::string{ guid_string };
}
