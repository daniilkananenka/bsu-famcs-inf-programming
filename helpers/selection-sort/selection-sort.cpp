#include <iostream>
#include <vector>

template<class T>
void PrintArray(std::vector<T>&);

template<class T>
void SelectionSort(std::vector<T>&);

int main()
{
    std::vector<int> arr { 1, 34, 23, 100, 25, 5, 10, 4, 31, 90 };

    std::cout << "Array before sorting:" << std::endl;
    PrintArray(arr);

    SelectionSort(arr);

    std::cout << "Array after selection sorting:" << std::endl;
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
void SelectionSort(std::vector<T>& arr)
{
    int maxElementIndex {}, maxElement {};
    for (int i = 0; i < arr.size(); i++) {
        maxElementIndex = 0;
        maxElement = arr[0];

        for (int j = 0; j < arr.size() - i; j++) {
            if (arr[j] > maxElement) {
                maxElement = arr[j];
                maxElementIndex = j;
            }
        }

        std::swap(arr[maxElementIndex], arr[arr.size() - i - 1]);
    }
}
