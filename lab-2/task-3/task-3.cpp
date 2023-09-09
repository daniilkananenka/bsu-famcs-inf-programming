#include <iostream>

int main ()
{
    int n;

    std::cout << "Input n(int, n > 0):" << std::endl;
    std::cin >> n;

    int digitsSum = 0;
    while (n != 0) {
        digitsSum += n % 10;
        n /= 10;
    }

    std::cout << "Sum of digits is " << digitsSum << std::endl;

    return 0;
}
