#include <iostream>

int main ()
{
	int firstNum, secondNum;
	std::cout << "Input first number (int):" << std::endl;
	std::cin >> firstNum;
	std::cout << "Input second number (int):" << std::endl;
	std::cin >> secondNum;

	std::cout << "First is " << firstNum <<
		"; Second is " << secondNum << std::endl;

	if (firstNum > secondNum) {
		std::cout << "YES";
	} else {
		int subNum = firstNum;
		firstNum = secondNum;
		secondNum = subNum;

		std::cout << "First is " << firstNum <<
			"; Second is " << secondNum << std::endl;
	}

	return 0;
}
