#include <iostream>

extern "C" int _cdecl SmallWordSize(char* s, int sz);

int main()
{
    char s[] = "Hello world from me";
    int sz = 19;
    int result;
    _asm {
        push sz
        lea eax, s
        push eax
        call SmallWordSize
        mov result, eax
        pop eax
        pop eax
    }
    std::cout << "Size: " << result <<std::endl;
    return 0;
}
