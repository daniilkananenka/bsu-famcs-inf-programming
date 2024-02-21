#include <iostream>
#include <cmath>

bool isPerfectNumber(int n)
{
	int divisorSum = -n;
	for (int i = 1; i <= std::sqrt(n); i++) {
		if (n % i == 0) {
			divisorSum += i;

			if (i != std::sqrt(n)) {
				divisorSum += n / i;
			}
		}
	}

	return divisorSum == n;
}

int main()
{
	int n;

	std::cout << "Input n (int):" << std::endl;
	std::cin >> n;
    
	std::cout << "Perfect numbers:" << std::endl;

	int nSource = n;
	bool hasAnyPerfectNumber {};
	while (n > 2) {
		n--;
		if (isPerfectNumber(n)) {
			hasAnyPerfectNumber = true;
			std::cout << n << std::endl;
		}
	}

	if (!hasAnyPerfectNumber) {
		std::cout << "There aren`t any perfect numbers less than n=" << nSource << std::endl;
	}

	return 0;	
}
