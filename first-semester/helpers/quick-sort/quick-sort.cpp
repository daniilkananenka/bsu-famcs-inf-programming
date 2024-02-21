#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
void PrintArray(std::vector<T>&);

template<class T>
void QuickSort(std::vector<T>&, int, int);

int main()
{
    std::vector<int> arr { 1, 34, 23, 100, 25, 5, 10, 4, 31, 90 };

    std::cout << "Array before sorting:" << std::endl;
    PrintArray(arr);

    QuickSort(arr, 0, arr.size() - 1);

    std::cout << "Array after quick sorting:" << std::endl;
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
void QuickSort(std::vector<T>& arr, int low, int high)
{
    if (low >= high) {
        return;
    }

    int divisionIndex = low;
    int count = 0;
    for (int i = low + 1; i <= high; i++) {
        if (arr[i] <= arr[divisionIndex])
            count++;
    }

    divisionIndex = low + count;
    std::swap(arr[divisionIndex], arr[low]);
    int i = 0, j = high;

    while (i < divisionIndex && j > divisionIndex) {
        while (arr[i] <= arr[divisionIndex]) {
            i++;
        }
        while (arr[j] > arr[divisionIndex]) {
            j--;
        }

        if (i < divisionIndex && j > divisionIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    QuickSort(arr, low, divisionIndex - 1);
    QuickSort(arr, divisionIndex + 1, high);
}
