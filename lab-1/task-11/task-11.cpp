#include <iostream>
#include <windows.h>
#include <string>

int main ()
{
    SetConsoleOutputCP (1251);
    SetConsoleCP (1251);

    int mashroomNumber;
    std::string wordEnding;

    std::cout << "Введите количество грибов:" << std::endl;
    std::cin >> mashroomNumber;

    switch (mashroomNumber % 10) {
        case 1:
        {
            if (mashroomNumber % 100 == 11) {
                wordEnding = "ов";
            } else {
                wordEnding = "";
            }
            break;
        }
        case 2:
        case 3:
        case 4:
        {
            if (mashroomNumber % 100 == 12 ||
                mashroomNumber % 100 == 13 ||
                mashroomNumber % 100 == 14) {
                wordEnding = "ов";
            } else {
                wordEnding = "а";
            }
            break;
        }
        default:
        {
            wordEnding = "ов";
            break;
        }
    }

    std::cout << "Мы нашли " << mashroomNumber <<
        " гриб" << wordEnding << " в лесу" << std::endl;

    return 0;
}
