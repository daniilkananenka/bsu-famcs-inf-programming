#include <iostream>

int getGCD (int a, int b)
{
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}

	return a + b;
}

int main ()
{
	int maxDenominator;

	std::cout << "Input max denominator:" << std::endl;
	std::cin >> maxDenominator;

	int denominator = 2;
	int numerator;

	std::cout << "Fractions:" << std::endl;

	while (denominator < maxDenominator) {
		numerator = 1;
		while (numerator < denominator) {
			if (getGCD (numerator, denominator) == 1) {
				std::cout << numerator << "/" << denominator << "; ";
			}
			numerator++;
		}
		denominator++;

		std::cout << std::endl;
	}

	return 0;
}
