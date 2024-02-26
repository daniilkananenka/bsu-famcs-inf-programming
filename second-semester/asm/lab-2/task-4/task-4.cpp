#include <iostream>
using namespace std;

int main()
{
    int num, lower{}, upper{};
    cout << "Enter a natural number: ";
    cin >> num;
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
    cout << "The number is between 2^" << lower << " and 2^" << upper << endl;
    return 0;
}
