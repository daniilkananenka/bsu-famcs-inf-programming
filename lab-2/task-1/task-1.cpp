#include <iostream>

int main ()
{
    int n;

    std::cout << "Input n(int, n > 0):" << std::endl;
    std::cin >> n;

    int counterPowerOfTwo = 1;
    while (counterPowerOfTwo < n) {
        counterPowerOfTwo *= 2;
    }

    if (n == counterPowerOfTwo) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
