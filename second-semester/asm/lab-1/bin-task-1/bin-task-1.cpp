#include <iostream>

int main()
{	
	int n;
	std::cout << "Input n:" << std::endl;
	std::cin >> n;
	int8_t a = static_cast<int8_t>(n);
	if (a == 0) { std::cout << 1; return 0; }
	--a;
	int result{ 2 };
	_asm {
		mov cl, a
		shl result, cl
	}

	std::cout << "Result is " << result;

	return 0;
}
