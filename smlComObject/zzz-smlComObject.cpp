// smlComObject.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <string>

void TestFull();
void TestSmoke();
void yyyTestSmoke();
void Test_smGetMoudleName();
void TestVecHash();
void TestFullRaw();

int main(int argc, char** argv)
{
	using namespace ::std;

	int testCase = 3;
	if (argc > 1)
	{
		testCase = stoi(argv[1]);
	}

	switch (testCase)
	{
		//case xxx:
		//{
		//	Test_xxx();
		//}
		//break;

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

	return 0;
}
