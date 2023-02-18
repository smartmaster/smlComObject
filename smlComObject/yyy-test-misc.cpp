
#include <type_traits>
#include <vector>
#include <string>


void TestVecHash()
{

	{
		std::hash<std::string> hasher;

		std::string str{"hello world!"};
		size_t hv = hasher(str);

	}

#if false
	{
		using ULL_T = unsigned long long;

		std::hash<std::vector<ULL_T>> hasher;

		std::vector<ULL_T> vec({ 100, 200 });
		size_t hv = hasher(vec);
	}

	{
		using ULL_T = int;

		std::hash<std::vector<ULL_T>> hasher;

		std::vector<ULL_T> vec({ 100, 200 });
		size_t hv = hasher(vec);
	}
#endif
}