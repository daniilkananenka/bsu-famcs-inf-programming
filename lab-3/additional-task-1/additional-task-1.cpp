#include <iostream>

int getNumberSize(int n)
{
    int result = 0;
    while (n != 0) {
        result++;
        n /= 10;
    }

    return result;
}

int getNumberWithSameDigits(int digit, int digitCount)
{
    int result = 0;
    for (int i = 0; i < digitCount; i++) {
        result *= 10;
        result += digit;
    }

    return result;
}

int main()
{
    int k;

    std::cout << "Input k (int):" << std::endl;
    std::cin >> k;

    int kSize = getNumberSize(k);
    int numberWithSameDigits {};
    for (int digitCount = kSize;; digitCount++) {
        for (int digit = 1; digit < 10; digit++) {
            numberWithSameDigits = getNumberWithSameDigits(digit, digitCount);
            if (numberWithSameDigits % k == 0) {
                std::cout << "Result is " << numberWithSameDigits << std::endl;

                return 0;
            }
        }
    }

    return 0;
}
