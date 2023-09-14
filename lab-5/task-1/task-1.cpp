#include <iostream> 
#include <vector>

void inputPolynomial(std::vector<int>& polynomial)
{
	for (int i = 0; i < polynomial.size(); i++) {
		std::cin >> polynomial[i];
	}
}

void printPolynomial(std::vector<int>& polinomial)
{

}

void getPolynomialSum(std::vector<int>& firstPolynomial,
	std::vector<int>& secondPolynomial,
	std::vector<int>& polynomialSum)
{
	
}

int main()
{
	int polinomialPower;
	std::cout << "Input polynomial power:" << std::endl;
	std::cin >> polinomialPower;

	std::vector<int> firstPolynomial(polinomialPower);
	std::vector<int> secondPolynomial(polinomialPower);

	std::cout << "Input first polynomial coefficient:" << std::endl;
	inputPolynomial(firstPolynomial);
	
	std::cout << "Input second polynomial coefficient:" << std::endl;
	inputPolynomial(secondPolynomial);
	

	return 0;
}