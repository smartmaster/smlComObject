
#include "smObjectInstanceCounter.h"

void SmartLib::smObjectInstanceCounter::AddInstance(const void* inst)
{
	std::lock_guard lock{ _mtx };
	_cont.insert({ inst, _seqNumer++ });
}

void SmartLib::smObjectInstanceCounter::RemoveInstance(const void* inst)
{
	std::lock_guard lock{ _mtx };
	_cont.erase(inst);
}

size_t SmartLib::smObjectInstanceCounter::Count() const
{
	std::lock_guard lock{ _mtx };
	return _cont.size();
}

SmartLib::smObjectInstanceCounter* SmartLib::smObjectInstanceCounter::SingleInstance()
{
	static smObjectInstanceCounter instance;
	return &instance;
}
