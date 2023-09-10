#include <iostream>
#include <cmath>

int getSumOfDivisors(int n)
{
	int sumOfDivisors = 0;
	for (int i = 1; i <= std::sqrt(n); i++) {
		if (n % i == 0) {
			sumOfDivisors += i;

			if (i != std::sqrt(n)) {
				sumOfDivisors += n / i;
			}
		}
	}

	return sumOfDivisors;
}

int main()
{
	int a, b;

	std::cout << "Input a (int):" << std::endl;
	std::cin >> a;
	std::cout << "Input b (int):" << std::endl;
	std::cin >> b;
	
	int sumOfDivisors {};
	int numWithMaxSumOfDivisors {};
	int maxSumOfDivisors {};
	for (int i = a; i <= b; i++) {
		sumOfDivisors = getSumOfDivisors(i);
		if (sumOfDivisors > maxSumOfDivisors) {
			maxSumOfDivisors = sumOfDivisors;
			numWithMaxSumOfDivisors = i;
		}
	}

	std::cout << "Num with max sum of divisors is " << numWithMaxSumOfDivisors << 
		" and sum is " << maxSumOfDivisors << std::endl;

	return 0;
}
