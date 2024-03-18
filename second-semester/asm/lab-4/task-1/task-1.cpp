#include <iostream>

void randomizeArray(int arr[15]) {
    for (int i{}; i < 15; ++i) {
        arr[i] = std::rand() % 30 - 10;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    int arr[15];
    randomizeArray(arr);
    int sum = 0;
    int count = 0;
    int result = 0;

    _asm {
        mov ecx, 15;
        mov esi, 0;
        lea edi, arr

           iterate:
            cmp[edi][esi * 4], 0
            jl continue_
                mov eax, [edi][esi * 4]
                add sum, eax
                inc count
            continue_:
            inc esi
            loop iterate
        mov eax, sum;
        cdq
            idiv count
            mov result, eax;
    }
    std::cout << "Average is " << result << std::endl;
    return 0;
}
