#include <iostream>

int main()
{
    int base, power, result;
    std::cout << "Enter the base and power: ";
    std::cin >> base >> power;
    _asm
    {
        mov eax, 1
        mov ecx, power
        loop_start :
            cmp ecx, 0
            je loop_end
            mul base
            dec ecx
            jmp loop_start
        loop_end :
            mov result, eax
    }
    std::cout << "Result of exponentiation: " << result << std::endl;
    return 0;
}
