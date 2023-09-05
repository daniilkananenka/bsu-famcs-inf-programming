#include <iostream>

int main()
{
	int firstNum, secondNum, thirdNum, forthNum;

	std::cout << "Input first number (int):" << std::endl;
	std::cin >> firstNum;
	std::cout << "Input second number (int):" << std::endl;
	std::cin >> secondNum;
	std::cout << "Input third number (int):" << std::endl;
	std::cin >> thirdNum;
	std::cout << "Input forth number (int):" << std::endl;
	std::cin >> forthNum;

	if (firstNum > 5 && secondNum > 5 && thirdNum % 6 == 0 && forthNum % 3 != 0) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
	}

	return 0;
}
