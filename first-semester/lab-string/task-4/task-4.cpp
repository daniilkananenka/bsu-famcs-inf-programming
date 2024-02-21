#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

std::string getEnding(int n);

int main()
{
    double n;
    std::cout << "Input money: ";
    std::cin >> n;

    double n_floor = std::floor(n);
    double rational_part = (n - n_floor) * 100;
    std::string rational_part_str = std::to_string(rational_part);

    int integer_part = n_floor;
    std::string integer_part_str{};
    while (integer_part != 0) {
        integer_part_str = std::to_string(integer_part % 1000) + " " + integer_part_str;
        integer_part /= 1000;
    }
    std::cout << integer_part_str << "rubl" << getEnding(n_floor) << " " << std::setw(0) << rational_part << " kop." << std::endl;

    return 0;
}

std::string getEnding(int n)
{
    std::string wordEnding;
    switch (n % 10) {
        case 1:
        {
            if (n % 100 == 11) {
                wordEnding = "ey";
            } else {
                wordEnding = "";
            }
            break;
        }
        case 2:
        case 3:
        case 4:
        {
            if (n % 100 == 12 ||
                n % 100 == 13 ||
                n % 100 == 14) {
                wordEnding = "ey";
            } else {
                wordEnding = "ia";
            }
            break;
        }
        default:
        {
            wordEnding = "ey";
            break;
        }
    }
    return wordEnding;
}
