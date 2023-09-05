#include <iostream>

int main()
{
    int firstNum, secondNum, thirdNum;

	std::cout << "Input first number (int):" << std::endl;
	std::cin >> firstNum;
	std::cout << "Input second number (int):" << std::endl;
	std::cin >> secondNum;
	std::cout << "Input third number (int):" << std::endl;
	std::cin >> thirdNum;

	int maxNum = firstNum;
	if (secondNum > maxNum) {
		maxNum = secondNum;
	}
	if (thirdNum > maxNum) {
		maxNum = thirdNum;
	}

	std::cout << "Max. number is " << maxNum;

	return 0;
}

