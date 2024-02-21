#include <iostream>

int main ()
{
    int n;
    std::cout << "Input n (int, n > 0):" << std::endl;
    std::cin >> n;

    double result = 1;
    double denominator = 1;
    double counter = 1;
    while (counter <= n) {
        result += 1 / denominator;
        counter++;
        denominator *= counter;
    }

    std::cout << "Result is " << result << std::endl;

    return 0;
}
