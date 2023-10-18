#include <iostream>
#include <vector>

template<class T>
void PrintArray(std::vector<T>&);

template<class T>
void InsertionSort(std::vector<T>&);

int main()
{
    std::vector<int> arr { 1, 34, 23, 100, 25, 5, 10, 4, 31, 90 };

    std::cout << "Array before sorting:" << std::endl;
    PrintArray(arr);

    InsertionSort(arr);

    std::cout << "Array after insertion sorting:" << std::endl;
    PrintArray(arr);
}

template<class T>
void PrintArray(std::vector<T>& arr)
{
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
void InsertionSort(std::vector<T>& arr)
{
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}
