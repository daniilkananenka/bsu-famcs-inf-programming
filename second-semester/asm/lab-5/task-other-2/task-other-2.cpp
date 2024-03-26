#include <iostream>

extern "C" int _cdecl FirstIn(char* s, int sz, char substr, int sz_substr);

int main()
{
    char s[] = "Hello world from me";
    int sz = 19;
    char substr[] = "me";
    int sz_substr = 2;
    int result;
    _asm {
        push sz_substr
        lea eax, substr
        push eax
        push sz
        lea eax, s
        push eax
        call FirstIn
        mov result, eax
        pop eax
        pop eax
    }
    std::cout << "Index of substr: " << result << std::endl;
    return 0;
}