#include <iostream>

void get_all_digits(int);

int main()
{
    int n;
    std::cin >> n;

    std::cout << "Digits (starting with first):" << std::endl;
    get_all_digits(n);

    return 0;
}

void get_all_digits(int n)
{
    while (n != 0) {
        int digit = n % 10;
        // Any digit processing
        std::cout << digit << " ";

        n /= 10;
    }
}
