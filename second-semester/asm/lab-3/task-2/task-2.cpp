#include <iostream>

int main()
{
    int n, max{};

    std::cout << "Enter natural number: ";
    std::cin >> n;

    _asm {
        mov eax, n
        mov ebx, 10
        loop_start:
            cmp eax, 0 
            je loop_end
            cdq
            div ebx
            cmp edx, max
            jle skip
            mov max, edx
        skip :
            jmp loop_start
        loop_end :
    }

    std::cout << "Max number: " << max << std::endl;
    return 0;
}
