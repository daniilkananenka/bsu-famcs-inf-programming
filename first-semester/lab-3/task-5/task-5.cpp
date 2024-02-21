#include <iostream>

int power(int num, int powerNum)
{
	int result = 1;
	for (int i = 0; i < powerNum; i++) {
		result *= num;
	}

	return result;
}

int getNumberSize(int n)
{
	int result = 0;
	while (n != 0) {
		result++;
		n /= 10;
	}

	return result;
}

bool isArmstrongNumber(int number)
{
	int numberSource = number;

	int numberSize = getNumberSize(number);
	int digitPowerSum = 0;
	int digit {};
	while (number != 0) {
		digit = number % 10;
		digitPowerSum += power(digit, numberSize);
		number /= 10;
	}

	return digitPowerSum == numberSource;
}

int main()
{
	int n;

	std::cout << "Input n (int):" << std::endl;
	std::cin >> n;
	
	std::cout << "Armstrong numbers:" << std::endl;
	int nSource = n;
	bool hasAnyArmstrongNumber {};
	while (n > 1) {
		n--;
		if (isArmstrongNumber(n)) {
			hasAnyArmstrongNumber = true;
			std::cout << n << std::endl;
		}
	}

	if (!hasAnyArmstrongNumber) {
		std::cout << "There aren`t any perfect numbers less than n=" << nSource << std::endl;
	}

	return 0;
}
