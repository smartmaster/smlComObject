#include "smPtrHelpers.h"

void* SmartLib::smPtrHelpers::PtrAdvance(void* ptr, ptrdiff_t offset)
{
	return (void*)((char*)(ptr)+offset);
}

ptrdiff_t SmartLib::smPtrHelpers::PtrDiff(const void* p1, const void* p2)
{
	return (ptrdiff_t)((const char*)(p1)-(const char*)(p2));
}
