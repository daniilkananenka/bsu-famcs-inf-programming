#include<iostream> 

constexpr int TEST_START = -10;
constexpr int TEST_END = 10;

int PerformAsm(int a) {
	int result = a;
	_asm {
		mov eax, a
		mul a
		mul a
		mul a
		sub eax, 2
		mov edx, a
		sub edx, 4
		mov a, edx
		cdq;
		idiv a
		mov result, eax
	}
	return result;
}

int PerformCpp(int a) {
	return (a*a*a*a - 2)/(a - 4);
}

static void TestAction() {
	for (int i{ TEST_START }; i <= TEST_END; ++i) {
		if (i == 4) {
			continue;
		}
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
	if (a == 4) {
		std::cout << "DIVISION BY ZERO" << std::endl;
		return 0;
	}
	std::cout << PerformAsm(a) << std::endl;

	return 0;
}