// smlComObject.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>
#include <cassert>

#include "smObjectInstanceCounter.h"

void TestFull();
void TestSmoke();
void yyyTestSmoke();
void Test_smGetMoudleName();
void TestVecHash();
void TestFullRaw();
void TestFullRawAgg();
void Test_zzz_example();
void Test_zzz_aggragation_vertical_example();
void Test_zzz_aggragation_horizontal_example();

int main(int argc, char** argv)
{
	
	using namespace ::std;
	using namespace ::SmartLib;

	int testCase = 99999;
	if (argc > 1)
	{
		testCase = stoi(argv[1]);
	}

	switch (testCase)
	{
	


	case 99999:
	{
		//all test at once
		Test_zzz_example();
		Test_zzz_aggragation_vertical_example();
		Test_zzz_aggragation_horizontal_example();
		TestFullRawAgg();
		TestFullRaw();
		TestFull();
		TestVecHash();
		Test_smGetMoudleName();
		TestFull();
		yyyTestSmoke();
		TestSmoke();
	}
	break;

	case 6:
	{
		Test_zzz_example();
		Test_zzz_aggragation_vertical_example();
		Test_zzz_aggragation_horizontal_example();
	}
	break;
	case 5:
	{
		TestFullRawAgg();
	}
	break;

	case 4:
	{
		TestFullRaw();
	}
	break;

	case 3:
	{
		TestFull();
	}
	break;
	case 2:
	{
		TestVecHash();
	}
	break;

	case 1:
	{
		Test_smGetMoudleName();
	}
	break;

	case 0:
	{
		TestFull();
		yyyTestSmoke();
		TestSmoke();
	}
	break;

	default:
	{
		cout << "Please input a valid test case number!" << endl;
	}
	break;
	}

	assert(0 == smObjectInstanceCounter::SingleInstance()->Count());

	return 0;
}
