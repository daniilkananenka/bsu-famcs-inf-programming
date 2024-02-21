#include <iostream>

int main()
{
    int number;

    std::cout << "Input number(int):" << std::endl;
    std::cin >> number;

    int lesserPowerOfTwo = 1;
    int greaterPowerOfTwo = 2;
    while (!(number >= lesserPowerOfTwo && number <= greaterPowerOfTwo)) {
        lesserPowerOfTwo <<= 1;
        greaterPowerOfTwo <<= 1;
    }

    std::cout << lesserPowerOfTwo << " <= " << number << 
        " => " << greaterPowerOfTwo << std::endl;

    return 0;
}
