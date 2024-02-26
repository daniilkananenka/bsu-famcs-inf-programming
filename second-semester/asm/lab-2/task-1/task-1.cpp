#include <iostream>
using namespace std;

int main()
{
    int num, sum{}, even{};
    cout << "Input num: ";
    cin >> num; 

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

    cout << "Sum: " << sum << endl; 
    cout << "Even count: " << even << endl;

    return 0;
}
