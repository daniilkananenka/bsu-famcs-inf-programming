#include <iostream>

int main()
{
    int num, sum{}, even{};
    std::cout << "Input num: ";
    std::cin >> num;

    _asm
    {
        mov eax, num 
        mov ebx, 10
        mov ecx, 0 
        loop_start: 
        cmp eax, 0 
            je loop_end 
            mov edx, 0 
            div ebx 
            add sum, edx
            and edx, 1 
            cmp edx, 0 
            je even_inc 
            inc ecx 
            jmp loop_start 
        even_inc : 
            inc even 
            inc ecx 
            jmp loop_start 
        loop_end :
    }

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Even count: " << even << std::endl;

    return 0;
}
