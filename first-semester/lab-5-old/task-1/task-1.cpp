#include <iostream> 
#include <vector>

struct Polynomial
{
	std::vector<int> coefficients;
	int length {};
	int power {};

	int begin();
	int size();
};

void InputPolynomialCoefficients(Polynomial&);
void PrintPolynomial(Polynomial&);
void GetPolynomialSum(Polynomial&, Polynomial&, Polynomial&);
void GetPolynomialMult(Polynomial&, Polynomial&, Polynomial&);

int main()
{
	Polynomial firstPolynomial, secondPolynomial;

	std::cout << "Input first polynomial power:" << std::endl;
	std::cin >> firstPolynomial.power;
	std::cout << "Input second polynomial power:" << std::endl;
	std::cin >> secondPolynomial.power;

	firstPolynomial.length = firstPolynomial.power + 1;
	secondPolynomial.length = secondPolynomial.power + 1;

	int maxPolynomialPower = std::max(firstPolynomial.power, secondPolynomial.power);
	int maxPolynomialLength = std::max(firstPolynomial.length, secondPolynomial.length);

	firstPolynomial.coefficients = std::vector<int>(maxPolynomialLength, 0);
	secondPolynomial.coefficients = std::vector<int>(maxPolynomialLength, 0);

	std::cout << "Input first polynomial coefficients:" << std::endl;
	InputPolynomialCoefficients(firstPolynomial);

	std::cout << "Input second polynomial coefficients:" << std::endl;
	InputPolynomialCoefficients(secondPolynomial);

	Polynomial polynomialSum {
		std::vector<int>(maxPolynomialLength, 0),
		maxPolynomialLength,
		maxPolynomialPower
	};
	Polynomial polynomialMult {
		std::vector<int>(firstPolynomial.power + secondPolynomial.power + 1, 0),
		firstPolynomial.power + secondPolynomial.power + 1,
		firstPolynomial.power + secondPolynomial.power
	};

	GetPolynomialSum(firstPolynomial, secondPolynomial, polynomialSum);
	GetPolynomialMult(firstPolynomial, secondPolynomial, polynomialMult);

	std::cout << "Polynomial sum:" << std::endl;
	PrintPolynomial(polynomialSum);

	std::cout << "Polynomial mult:" << std::endl;
	PrintPolynomial(polynomialMult);

	return 0;
}

void InputPolynomialCoefficients(Polynomial& polynomial)
{
	for (int i = polynomial.begin(); i < polynomial.size(); i++) {
		std::cin >> polynomial.coefficients[i];
	}
}

void PrintPolynomial(Polynomial& polynomial)
{
	for (int i = polynomial.begin(); i < polynomial.size(); i++) {
		std::cout << polynomial.coefficients[i]; 
		
		if (i < polynomial.size() - 1) {
			std::cout << "x^" << (polynomial.size() - 1 - i);
			std::cout << " + ";
		}
	}

	std::cout << std::endl;
}

void GetPolynomialSum(Polynomial& firstPolynomial,
	Polynomial& secondPolynomial,
	Polynomial& polynomialSum)
{
	for (int i = 0; i < polynomialSum.coefficients.size(); i++) {
		polynomialSum.coefficients[i] = firstPolynomial.coefficients[i] +
			secondPolynomial.coefficients[i];
	}
}

void GetPolynomialMult(Polynomial& firstPolynomial,
	Polynomial& secondPolynomial,
	Polynomial& polynomialMult)
{
	for (int i = firstPolynomial.begin(); i < firstPolynomial.size(); i++) {
		for (int j = secondPolynomial.begin(); j < secondPolynomial.size(); j++) {
			int power = (firstPolynomial.size() - 1 - i) + (secondPolynomial.size() - 1 - j);
			polynomialMult.coefficients[polynomialMult.size() - power - 1] += firstPolynomial.coefficients[i] *
				secondPolynomial.coefficients[j];
		}
	}
}

int Polynomial::begin()
{
	return coefficients.size() - length;
}

int Polynomial::size()
{
	return coefficients.size();
}
