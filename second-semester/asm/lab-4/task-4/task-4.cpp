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
    int max = -100;
    int n = 15;

    _asm {
        mov ecx, 15;
        mov esi, 0;
        mov edx, 0
            mov ebx, 0
            lea edi, arr

         iterate :
            mov eax, [edi][esi * 4]
            cmp eax, max
            jl continue_
            mov max, eax
            mov ebx, esi
        continue_ :
            inc esi
            loop iterate
        inc ebx
        mov eax, 0
        iterate_to_zeroes:
            cmp n, ebx
            jle end_
            
            mov [edi][ebx*4], eax
                inc ebx
            jmp iterate_to_zeroes
         end_:
    }
    std::cout << "Result: " << std::endl;
    printArray(arr);
    return 0;
}
