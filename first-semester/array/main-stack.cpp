#include "stack.h"
#include "vector.h"

#include <iostream>

template <class T>
void PrintStack(Stack<T>& arr) {
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "========" << std::endl;
}

int main() {
    Stack<int> arr = {1, 2, 3, 4, 5};
    PrintStack(arr);
    arr.Push(10);
    PrintStack(arr);
    std::cout << "Back - " << arr.Back() << std::endl;
    arr.Pop();
    PrintStack(arr);

    return 0;
}