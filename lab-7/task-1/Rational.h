#pragma once
#include <iostream>

class Rational
{
private:
	int numerator;
	int denominator;
	
	int getGCD(int, int) const;
	int getLCM(int, int) const;
	std::pair<int, int> getMultiplierPair(int, int) const;
public:
	Rational();
	Rational(int, int);
	Rational(const Rational&);


	int getNumerator() const;
	int getDenominator() const;

	void setNumerator(int);
	void setDenominator(int);

	void reduce();
	void multByNumber(int);

	Rational operator +(Rational&) const;
	Rational operator *(Rational&) const;
	Rational operator /(Rational&) const;
	bool operator ==(Rational&) const;
	bool operator >(Rational&) const;
	bool operator <(Rational&) const;

	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);
};

