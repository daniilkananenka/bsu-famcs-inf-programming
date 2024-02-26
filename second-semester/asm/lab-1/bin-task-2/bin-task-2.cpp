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

    int result{};
    int counter{1};
    for (int i = 0; i < 32; i++) {
        _asm {
            mov eax, a
            and eax, counter
            jz Exit
            inc result
            
            Exit:
                shl counter, 1
        }
    }

    std::cout << "Count of 1: " << result << std::endl;

    return 0;
}

