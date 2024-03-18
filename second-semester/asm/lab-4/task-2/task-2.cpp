#include <iostream>

void randomizeArray(int arr[10]) {
    for (int i{}; i < 10; ++i) {
        arr[i] = std::rand() % 30 - 10;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    int arr[10];
    randomizeArray(arr);
    int max = -100;

    _asm {
        mov ecx, 10;
        mov esi, 0;
        mov edx, 0
        lea edi, arr

        iterate :
            cmp esi, edx
            jl continue_
            mov eax, [edi][esi * 4]
            cmp eax, max
            jl skip_max
            mov max, eax
        skip_max:
            add edx, 2
        continue_ :
            inc esi
            loop iterate
    }
    std::cout << "Max is " << max << std::endl;
    return 0;
}
