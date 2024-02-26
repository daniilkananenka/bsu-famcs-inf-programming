#include<iostream> 

constexpr int TEST_START = -10;
constexpr int TEST_END = 10;

int PerformAsm(int a) {
	int result = a;
	_asm {
		mov eax, a
		mul a
		mul a
		add result, eax
		mul a
		mul a
		add result, eax
	}
	return result;
}

int PerformCpp(int a) {
	return a * a * a * a * a + a * a * a + a;
}

static void TestAction() {
	for (int i{ TEST_START }; i <= TEST_END; ++i) {
		if (PerformAsm(i) != PerformCpp(i)) {
			std::cout << "ERROR: " << i << std::endl;
			break;
		}
	}
}

int main()
{
	int a, result{};
	std::cin >> a;
	std::cout << PerformAsm(a) << std::endl;

	return 0;
}