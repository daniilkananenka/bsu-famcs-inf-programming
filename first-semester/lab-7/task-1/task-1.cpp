#include <iostream>
#include "Rational.h"

int main()
{
    Rational a, b;
    
    std::cout << "Inpupt first rational (format: numerator denumerator):" << std::endl;
    std::cin >> a;
    std::cout << "Inpupt second rational (format: numerator denumerator):" << std::endl;
    std::cin >> b;

    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << a << " == " << b << " = " << (a == b) << std::endl;
    std::cout << a << " > " << b << " = " << (a > b) << std::endl;
    std::cout << a << " < " << b << " = " << (a < b) << std::endl;

    return 0;
}
