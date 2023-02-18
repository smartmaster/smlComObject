#include "smComRegistry.h"




void SmartLib::smComRegistry::Add(const char* modName, const smMetaType* mt)
{
	std::string strMod = modName;
	const GUID& guid = mt->GetID();

	std::unique_lock<std::shared_mutex> lockWriter{ _rwMtx };
	auto&& modMap = _maps[strMod];

	auto iter = modMap.find(guid);
	assert(iter == modMap.end());
	modMap.insert({ guid, mt });
}

const SmartLib::smMetaType* SmartLib::smComRegistry::Find(const char* modName, const GUID& guid)
{
	const smMetaType* mt = nullptr;

	std::shared_lock<std::shared_mutex> lockReader{ _rwMtx };

	auto iterMod = _maps.find(std::string{ modName });
	if (iterMod != _maps.end())
	{
		auto iterID = iterMod->second.find(guid);
		if (iterID != iterMod->second.end())
		{
			mt = iterID->second;
		}
	}

	return mt;
}

const SmartLib::smMetaType* SmartLib::smComRegistry::Find(const GUID& guid) const
{
	const smMetaType* mt = nullptr;

	std::shared_lock<std::shared_mutex> lockReader{ _rwMtx };

	for (const auto& [modName, modMap] : _maps)
	{
		auto iterID = modMap.find(guid);
		if (iterID != modMap.end())
		{
			mt = iterID->second;
			break;
		}
	}

	return mt;
}

void SmartLib::smComRegistry::ClearModule(const char* modName)
{
	std::unique_lock<std::shared_mutex> lockWriter{ _rwMtx };

	auto iterMod = _maps.find(std::string{ modName });
	if (iterMod != _maps.end())
	{
		_maps.erase(iterMod);
	}
}

SmartLib::smComRegistry* SmartLib::smComRegistry::SingleInstance()
{
	static smComRegistry comReg;
	return &comReg;
}


