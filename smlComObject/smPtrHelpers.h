#pragma once


namespace SmartLib
{
	class smPtrHelpers
	{
	public:
		static void* PtrAdvance(void* ptr, ptrdiff_t offset)
		{
			return (void*)((char*)(ptr)+offset);
		}

		static ptrdiff_t PtrDiff(const void* p1, const void* p2)
		{
			return (ptrdiff_t)((const char*)(p1)-(const char*)(p2));
		}

		template<typename UClass, typename UBase>
		static ptrdiff_t BaseOffset()
		{
			const UClass* self = (const UClass*)(1 << 20);
			return PtrDiff(static_cast<const UBase*>(self), self);
		}
	};
}

