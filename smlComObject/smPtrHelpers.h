#pragma once

#include <cstddef>

namespace SmartLib
{
	class smPtrHelpers
	{
	public:
		static void* PtrAdvance(void* ptr, ptrdiff_t offset);

		static ptrdiff_t PtrDiff(const void* p1, const void* p2);

		template<typename UClass, typename UBase>
		constexpr static ptrdiff_t BaseOffset()
		{
			const UClass* self = (const UClass*)(1 << 20);
			return PtrDiff(static_cast<const UBase*>(self), self);
		}
	};
}

