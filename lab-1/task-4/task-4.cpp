#include <iostream>

int main ()
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

	bool numberIsFound = false;
	int maxEvenNum = 0;
	if (firstNum % 2 == 0) {
		numberIsFound = true;
		maxEvenNum = firstNum;
	}
	if (secondNum % 2 == 0) {
		if (!numberIsFound) {
			numberIsFound = true;
			maxEvenNum = secondNum;
		} else {
			if (secondNum > maxEvenNum) {
				numberIsFound = true;
				maxEvenNum = secondNum;
			}
		}
	}
	if (thirdNum % 2 == 0) {
		if (!numberIsFound) {
			numberIsFound = true;
			maxEvenNum = thirdNum;
		} else {
			if (thirdNum > maxEvenNum) {
				numberIsFound = true;
				maxEvenNum = thirdNum;
			}
		}
	}
	if (forthNum % 2 == 0) {
		if (!numberIsFound) {
			numberIsFound = true;
			maxEvenNum = forthNum;
		} else {
			if (forthNum > maxEvenNum) {
				numberIsFound = true;
				maxEvenNum = forthNum;
			}
		}
	}

	if (numberIsFound) {
		std::cout << "Max. even number is " << maxEvenNum << std::endl;
	} else {
		std::cout << "Not found!" << std::endl;
	}

	return 0;
}
