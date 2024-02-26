#include <iostream>

int main()
{
    int num, lower{}, upper{};
    std::cout << "Enter a natural number: ";
    std::cin >> num;
    _asm
    {
        mov eax, num
        mov ebx, 1
        mov ecx, 0
        loop_start:
        cmp eax, ebx
            jl loop_end
            mov lower, ecx
            inc ecx
            shl ebx, 1
            jmp loop_start
            loop_end :
        mov upper, ecx
    }
    std::cout << "The number is between 2^" << lower << " and 2^" << upper << std::endl;
    return 0;
}
