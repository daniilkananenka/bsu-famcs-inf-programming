#include <iostream>
#include <bitset>

static void PrintBits(int a) {
    std::bitset<32> b(a);
    for (int i = 31; i >= 0; i--) {
        std::cout << b[i];
    }
    std::cout << std::endl;
}

int main()
{
    int a;
    std::cout << "Input number (>=0):" << std::endl;
    std::cin >> a;
    std::cout << "Bits of a: ";
    PrintBits(a);

    int result{ 31 };
    int counter{ 1073741824 };
    bool foundFirst{};
    for (int i = 0; i < 32; i++) {
        _asm {
            mov eax, a
            and eax, counter
            jz Exit
            mov foundFirst, 1

            Exit:
            dec result
            shr counter, 1
        }
        if (foundFirst) {
            break;
        }
    }

    std::cout << "The eldest bit index (from 0): " << result << std::endl;

    return 0;
}

