#pragma once

#include <unordered_map>
#include <Unknwn.h>

namespace SmartLib
{
	class smGUIDHasher
	{
	public:
		size_t operator()(const GUID& guid) const
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
	};

	class smGUIDEqual
	{
	public:
		size_t operator()(const GUID& guid1, const GUID& guid2) const
		{
			return IsEqualGUID(guid1, guid2);
		}
	};
}