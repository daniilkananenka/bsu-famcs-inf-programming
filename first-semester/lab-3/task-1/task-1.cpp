#include <iostream>

bool checkIsAutomorphicNumber(int n)
{
	int nSqr = n * n;
	while (n != 0) {
		if (n % 10 != nSqr % 10) {
			return false;
		}
		n /= 10;
		nSqr /= 10;
	}

	return true;
}

int main()
{
	int n;

	std::cout << "Input n (int):" << std::endl;
	std::cin >> n;

	std::cout << "Automorphic numbers:" << std::endl;

	int nSource = n;
	bool hasAnyAutomorphicNumbers {};
	while (n > 1) {
		n--;
		if (checkIsAutomorphicNumber(n)) {
			hasAnyAutomorphicNumbers = true;
			std::cout << n << std::endl;
		}
	}
	
	if (!hasAnyAutomorphicNumbers) {
		std::cout << "There aren`t any automorphic numbers less than n=" << nSource << std::endl;
	}

	return 0;
}
