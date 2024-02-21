#include "vector.h"

#include <iostream>

template <class T>
void PrintStack(Vector<T>& arr) {
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "========" << std::endl;
}

int main() {
    Vector<int> arr = {1, 2, 3, 4, 5};
    arr.Erase(0);
    PrintStack(arr);
    arr.Insert(34, 3);
    PrintStack(arr);
    arr.Resize(10);
    PrintStack(arr);
    arr.PushBack(10);
    PrintStack(arr);
    std::cout << arr.Front() << " " << arr.Back() << std::endl;
    arr.Front() = 99;
    std::cout << arr.Front() << " " << arr.Back() << std::endl;
    arr.Erase(5);
    PrintStack(arr);
    arr.Erase(arr.Size() - 1);
    PrintStack(arr);

    return 0;
}