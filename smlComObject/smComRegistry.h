#pragma once

#include <unordered_map>
#include <string>

#include <mutex>
#include <shared_mutex>

#include <cassert>

#include "smMetaType.h"
#include "smGUIDHelper.h"

namespace SmartLib
{
	class smComRegistry
	{
	private:
		using MOD_GUID_META_MAP = std::unordered_map<
			std::string, 
			std::unordered_map<GUID, const smMetaType*, smGUIDHasher, smGUIDEqual>
		>;
		MOD_GUID_META_MAP _maps;

		using MOD_GUID_META_MMAP = std::unordered_map<
			std::string,
			std::unordered_multimap<GUID, const smMetaType*, smGUIDHasher, smGUIDEqual>
		>;
		MOD_GUID_META_MAP _mmaps;


		mutable std::shared_mutex _rwMtx;
		
	public:
		void Add(const char* modName, const smMetaType* mt);
		
		const smMetaType* Find(const char* modName, const GUID& guid);
		const smMetaType* Find(const GUID& guid) const;
		
		void ClearModule(const char* modName);

	public:
		static smComRegistry* SingleInstance();
	};
}