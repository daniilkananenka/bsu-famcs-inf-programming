#include <iostream>

int gcd(int, int);
int gcd_recursive(int, int);
int lcm(int, int);

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << "Least common multiple: " << lcm(a, b) << std::endl;
    std::cout << "Greatest commom divisor: " << gcd(a, b) << std::endl;
    std::cout << "Greatest commom divisor (recursive function): " << gcd_recursive(a, b) << std::endl;

    return 0;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int gcd(int a, int b)
{
    while (a != 0 && b != 0) {
        a > b ? a %= b : b %= a;
    }

    return a + b;
}

int gcd_recursive(int a, int b)
{
    if (a == 0 || b == 0) {
        return a + b;
    }

    if (a > b) {
        return gcd_recursive(a % b, b);
    } else {
        return gcd_recursive(a, b % a);
    }
}
