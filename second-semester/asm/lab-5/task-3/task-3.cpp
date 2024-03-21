#include <iostream>

extern "C" void _cdecl NOD(int a, int b);

int main()
{
    int a, b;
    std::cout << "Input numerator: ";
    std::cin >> a;
    std::cout << "Input denumerator: ";
    std::cin >> b;

    int nod;
    _asm {
        push b
        push a
        call NOD
        mov nod, eax
        pop eax;
        pop eax;
    }
    std::cout << "Result: " << (a/nod) << "/" << (b/nod) << std::endl;

    return 0;
}

