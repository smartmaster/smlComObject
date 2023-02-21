#pragma once
#include <mutex>
#include <unordered_map>

namespace SmartLib
{
	class smObjectInstanceCounter
	{
	private:
		mutable std::recursive_mutex _mtx;
		size_t _seqNumer{ 0 };
		std::unordered_map<const void*, size_t> _cont;

	public:
		void AddInstance(const void* inst);
		void RemoveInstance(const void* inst);
		size_t Count() const;

	public:
		static smObjectInstanceCounter* SingleInstance();
	};
}