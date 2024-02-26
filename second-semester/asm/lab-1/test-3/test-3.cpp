#include <iostream>

int main()
{
	int a, b;
	std::cout << "Input a, b for (ax + b = 0):" << std::endl;
	std::cin >> a >> b;
	if (a == 0 && b == 0) {
		std::cout << "Infinity count of solutions" << std::endl;
		return 0;
	}
	else if (a == 0 && b != 0) {
		std::cout << "No solutions" << std::endl;
		return 0;
	}

	int x{};
	_asm {
		mov eax, b
		neg eax
		cdq
		idiv a
		mov x, eax
	}
	std::cout << "Solution is " << x << std::endl;

	return 0;
}
