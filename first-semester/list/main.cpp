#include "list.h"

#include <iostream>

template <class T>
void PrintList(List<T>& arr) {
    for (auto i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl << "========" << std::endl;
}

int main() {
    List<int> arr;
    arr.PushBack(5);
    arr.PushBack(6);
    arr.PushBack(7);
    PrintList(arr);
    arr.PushFront(4);
    arr.PushFront(2);
    PrintList(arr);
    arr.PopFront();
    PrintList(arr);

    return 0;
}