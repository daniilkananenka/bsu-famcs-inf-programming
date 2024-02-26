#include <iostream>
using namespace std;

int main()
{
    int base, power, result;
    cout << "Enter the base and power: ";
    cin >> base >> power;
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
    cout << "Result of exponentiation: " << result << endl;
    return 0;
}
