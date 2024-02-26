#include <iostream>
using namespace std;

int main()
{
    int num, den;
    cout << "Enter the numerator and denominator of the fraction: ";
    cin >> num >> den;

    int gcd{};
    _asm
    {
        mov eax, num
        mov ebx, den
        mov ecx, eax
        loop_start :
            cmp eax, ebx
            je loop_end
            jg num_greater
            sub ebx, eax
            jmp loop_start
        num_greater :
            sub eax, ebx
            jmp loop_start
        loop_end :
            mov gcd, eax
            mov eax, ecx 
            cdq
            div gcd
            mov num, eax
            mov eax, den
            cdq
            div gcd
            mov den, eax
    }
    cout << "Reduced fraction: " << num << "/" << den << endl;

    return 0;
}
