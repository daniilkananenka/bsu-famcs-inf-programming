#include <iostream>

extern "C" float* _fastcall HeronSqrt(int a, int n);

int main()
{
    int a, n;
    std::cout << "Inpuit a, n: ";
    std::cin >> a >> n;
    float* resultPtr = nullptr;

    _asm {
        xor ecx, ecx
        xor edx, edx
        mov ecx, a;
        mov edx, n;
        call HeronSqrt;
        mov resultPtr, eax
    }

    if (resultPtr == nullptr) {
        std::cout << "Something went wrong!!!" << std::endl;
        return 0;
    }
    float result = *resultPtr;
    std::cout << "Sqrt is " << *resultPtr << std::endl;
    return 0;
}

