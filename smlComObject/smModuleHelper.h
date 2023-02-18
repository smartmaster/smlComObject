#pragma once

//statically linked into seperate modules

namespace SmartLib
{
	class smModuleHelper
	{
	public:
		static const char* GetCurrentModuleName();
	};
}