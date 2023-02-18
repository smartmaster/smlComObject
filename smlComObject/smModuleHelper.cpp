#include <windows.h>
#include <mutex>
#include <string>
#include <cassert>
#include "smModuleHelper.h"
#include "smComRegistry.h"


static std::string DoGetCurrentModuleNameWin()
{
	std::string strRV; //in the form of "exeName!moduleName"

	MEMORY_BASIC_INFORMATION mbi = { 0 };
	SIZE_T Size = VirtualQuery(
		(LPVOID)(DoGetCurrentModuleNameWin),//_In_opt_  LPCVOID lpAddress,
		&mbi,//_Out_     PMEMORY_BASIC_INFORMATION lpBuffer,
		sizeof(MEMORY_BASIC_INFORMATION)//_In_      SIZE_T dwLength
	);
	if (Size)
	{
		HMODULE hModuleTemp = (HMODULE)(mbi.AllocationBase);

		//////////////////////////////////////////////////////////////////////////
		char ExeName[MAX_PATH] = { 0 };
		DWORD dwgmfn = GetModuleFileNameA(
			NULL,//_In_opt_  HMODULE hModule,
			ExeName,//_Out_     LPTSTR lpFilename,
			_countof(ExeName)//_In_      DWORD nSize
		);
		assert(dwgmfn);
		const char* pExe = strrchr(ExeName, '\\');
		if (pExe)
		{
			++pExe;
		}
		
		//////////////////////////////////////////////////////////////////////////
		char ModName[MAX_PATH] = { 0 };
		dwgmfn = GetModuleFileNameA(
			hModuleTemp,//_In_opt_  HMODULE hModule,
			ModName,//_Out_     LPTSTR lpFilename,
			_countof(ModName)//_In_      DWORD nSize
		);
		assert(dwgmfn);
		const char* pMod = strrchr(ModName, '\\');
		if (pMod)
		{
			++pMod;
		}

		//////////////////////////////////////////////////////////////////////////
		if (pExe && pMod)
		{
			strRV = pExe;
			strRV += '!';
			strRV += pMod;
		}
	}

	return strRV;
}

const char* SmartLib::smModuleHelper::GetCurrentModuleName()
{
	static std::string s_modName;

	static std::once_flag onceFlag;
	std::call_once(onceFlag, []() {
		s_modName = DoGetCurrentModuleNameWin();
		});

	return s_modName.c_str();
}

namespace 
{
	class smModCleanup
	{
	public:
		~smModCleanup()
		{
			using namespace SmartLib;
			auto* comReg = smComRegistry::SingleInstance();
			auto* modName = smModuleHelper::GetCurrentModuleName();
			comReg->ClearModule(modName);
		}
	};

	//static smModCleanup modCleanup;
}