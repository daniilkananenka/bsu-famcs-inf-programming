#include <iostream>

int main ()
{
	int firstNum, secondNum, thirdNum;

	std::cout << "Input first number (int):" << std::endl;
	std::cin >> firstNum;
	std::cout << "Input second number (int):" << std::endl;
	std::cin >> secondNum;
	std::cout << "Input third number (int):" << std::endl;
	std::cin >> thirdNum;

	if (firstNum == secondNum || firstNum == thirdNum || secondNum == thirdNum) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
	}

	return 0;
}
