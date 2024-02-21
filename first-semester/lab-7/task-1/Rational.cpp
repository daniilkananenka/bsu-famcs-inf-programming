#include "Rational.h"
#include <iostream>

int Rational::getGCD(int a, int b) const
{
	int gcd { 1 };
	while (a % b != 0 && b % a != 0) {
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}

	if (a % b == 0) {
		gcd = b;
	}
	if (b % a == 0) {
		gcd = a;
	}

	return gcd;
}

int Rational::getLCM(int a, int b) const
{
	return (a * b) / this->getGCD(a, b);
}

std::pair<int, int> Rational::getMultiplierPair(int firstDenominator, 
	int secondDenominator) const
{
	int lcm { getLCM(firstDenominator, secondDenominator) };
	int firstMultiplier = lcm / firstDenominator;
	int secondMultiplier = lcm / secondDenominator;

	std::pair<int, int> result = 
		std::make_pair(firstMultiplier, secondMultiplier);

	return result;
}

Rational::Rational()
{
	this->numerator = 1;
	this->denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

Rational::Rational(const Rational& rational)
{
	this->numerator = rational.getNumerator();
	this->denominator = rational.getDenominator();
}

int Rational::getNumerator() const
{
	return this->numerator;
}

int Rational::getDenominator() const
{
	return this->denominator;
}

void Rational::setNumerator(int value)
{
	this->numerator = value;
}

void Rational::setDenominator(int value)
{
	this->denominator = value;
}

void Rational::reduce()
{
	int gcd { this->getGCD(this->getNumerator(), this->getDenominator()) };

	int numerator { this->getNumerator() / gcd };
	int denominator { this->getDenominator() / gcd };

	this->setNumerator(numerator);
	this->setDenominator(denominator);
}

void Rational::multByNumber(int number)
{
	this->numerator *= number;
	this->denominator *= number;
}

Rational Rational::operator+(Rational& operand) const
{
	int numeratorResult = this->getNumerator() * operand.getDenominator() +
		operand.getNumerator() * this->getDenominator();
	int denominatorResult = this->getDenominator() * operand.getDenominator();

	Rational result { numeratorResult, denominatorResult };
	result.reduce();

	return result;
}

Rational Rational::operator*(Rational& operand) const
{
	int numeratorResult = this->getNumerator() * operand.getNumerator();
	int denominatorResult = this->getDenominator() * operand.getDenominator();

	Rational result { numeratorResult, denominatorResult };
	result.reduce();

	return result;
}

Rational Rational::operator/(Rational& operand) const
{
	int numeratorResult = this->getNumerator() * operand.getDenominator();
	int denominatorResult = this->getDenominator() * operand.getNumerator();

	Rational result { numeratorResult, denominatorResult };
	result.reduce();

	return result;
}

bool Rational::operator==(Rational& operand) const
{
	std::pair<int, int> multipliers = this->getMultiplierPair(this->getDenominator(), 
		operand.getDenominator());

	return this->getNumerator() * multipliers.first ==
		operand.getNumerator() * multipliers.second;
}

bool Rational::operator>(Rational& operand) const
{
	std::pair<int, int> multipliers = this->getMultiplierPair(this->getDenominator(), 
		operand.getDenominator());

	return this->getNumerator() * multipliers.first >
		operand.getNumerator() * multipliers.second;
}

bool Rational::operator<(Rational& operand) const
{
	std::pair<int, int> multipliers = this->getMultiplierPair(this->getDenominator(), 
		operand.getDenominator());

	return this->getNumerator() * multipliers.first <
		operand.getNumerator() * multipliers.second;
}

std::ostream& operator<<(std::ostream& stream, const Rational& rational)
{
	stream << "(" << rational.getNumerator() << "/" <<
		rational.getDenominator() << ")";

	return stream;
}

std::istream& operator>>(std::istream& stream, Rational& rational)
{
	int numerator, denominator;

	stream >> numerator >> denominator;
	rational.setNumerator(numerator);
	rational.setDenominator(denominator);

	return stream;
}
