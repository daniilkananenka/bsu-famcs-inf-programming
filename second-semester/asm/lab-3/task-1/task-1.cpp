#include <iostream>

int ReverseNumber(int num) {
    int rev, subv;
    _asm {
        mov eax, num
        mov ebx, 0
        loop1:
            mov edx, 0
            mov ecx, 10
            div ecx
            add ebx, edx
            cmp eax, 0
            je endloop
            mov subv, eax
            mov eax, ebx
            mul ecx
            mov ebx, eax
            mov eax, subv
            jmp loop1
        endloop:
            mov rev, ebx
    }
    return rev;
}

int main()
{
    int num;
    std::cout << "Enter number: ";
    std::cin >> num;

    int result_reversed{};
    int subv{};
    _asm {
        mov eax, num
        mov ecx, 10
        mov ebx, 0
        loop1:
            cdq
            div ecx
            cmp edx, 6
            je skip
            cmp edx, 3
            je skip
            add ebx, edx
            cmp eax, 0
            je endloop
            mov subv, eax
            mov eax, ebx
            mul ecx
            mov ebx, eax
            mov eax, subv
            jmp loop1
        skip:
            jmp loop1
        endloop:
            mov result_reversed, ebx
    }
    std::cout << "Result: " << ReverseNumber(result_reversed) << std::endl;
}

