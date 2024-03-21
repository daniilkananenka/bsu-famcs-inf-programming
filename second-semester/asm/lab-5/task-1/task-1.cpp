#include <iostream>

// Change places of maximum and last
extern "C" void _cdecl ChangeLastAndMax(int arr[15]);

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
    int arr[15];
    randomizeArray(arr);
    _asm {
        lea eax, arr
        push eax
        call ChangeLastAndMax
        pop eax
    }
    printArray(arr);
    return 0;
}

