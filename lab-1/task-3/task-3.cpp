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

	int firstSecondSum { firstNum + secondNum },
		firstThirdSum { firstNum + thirdNum },
		secondThirdSum { secondNum + thirdNum };
	if (firstSecondSum >= firstThirdSum && firstSecondSum >= secondThirdSum) {
		std::cout << "Max. sum is " << firstSecondSum <<
			" (first + second; " << firstNum << " + " << secondNum << ")" << std::endl;
	} else if (firstThirdSum >= firstSecondSum && firstThirdSum >= secondThirdSum) {
		std::cout << "Max. sum is " << firstThirdSum <<
			" (first + third; " << firstNum << " + " << thirdNum << ")" << std::endl;
	} else {
		std::cout << "Max. sum is " << secondThirdSum <<
			" (second + third; " << secondNum << " + " << thirdNum << ")" << std::endl;
	}

	return 0;
}
