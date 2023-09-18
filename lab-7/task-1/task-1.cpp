#include <iostream>
#include "Rational.h"

int main()
{
    Rational a { 5, 6 };
    Rational b { 18, 9 };

    Rational sum { a + b };

    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << a << " == " << b << " = " << (a == b) << std::endl;
    std::cout << a << " > " << b << " = " << (a > b) << std::endl;
    std::cout << a << " < " << b << " = " << (a < b) << std::endl;

    return 0;
}
