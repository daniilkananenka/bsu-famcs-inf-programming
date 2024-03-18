#include <iostream>

void randomizeArray(int arr[15]) {
    for (int i{}; i < 15; ++i) {
        arr[i] = std::rand() % 30 - 10;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printArray(int arr[15]) {
    for (int i{}; i < 15; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    int arr[15];
    randomizeArray(arr);
    int min = 100;

    _asm {
        mov ecx, 15;
        mov esi, 0;
        mov edx, 0
        mov ebx, 0
        lea edi, arr

            iterate :
            mov eax, [edi][esi * 4]
            cmp min, eax
            jl continue_
            mov min, eax
            mov ebx, esi
          continue_:
            inc esi
            loop iterate
        mov eax, [edi][ebx * 4]
        mov edx, [edi][0]
        mov [edi][ebx * 4], edx
        mov [edi][0], eax
    }
    std::cout << "Result: " << std::endl;
    printArray(arr);
    return 0;
}
