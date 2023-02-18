#include "smModuleHelper.h"

#include <iostream>

void Test_smGetMoudleName()
{
	using namespace std;
	using namespace SmartLib;
	auto* name = smModuleHelper::GetCurrentModuleName();
	cout << "The current module name is: " << name << endl;
}