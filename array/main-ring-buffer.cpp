#include "ring-buffer.h"

#include <iostream>

template <class T>
void PrintRing(RingBuffer<T>& arr) {
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "========" << std::endl;
}

int main() {
    RingBuffer<int> arr(10);
    arr.TryPush(10);
    arr.TryPush(5);
    int result{};
    arr.TryPop(&result);
    std::cout << result << std::endl;
    arr.TryPop(&result);
    std::cout << result << std::endl;

    return 0;
}