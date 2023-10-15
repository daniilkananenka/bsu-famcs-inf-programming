#include <iostream>
#include <algorithm>

int FindMinAndSort(int[], int);

int main()
{
    int array[] = { 3, 10, 5, 1, 44, 23, 45, 76, 53, 21, 2, 8 };

    const int n = std::size(array);
    int min_index = FindMinAndSort(array, n);

    std::cout << "Sorted by rule array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << "Min element index: " << min_index << std::endl;

    return 0;
}

int FindMinAndSort(int array[], int len)
{
    int min = array[0], min_index = 0;
    for (int i = 0; i < len; i++) {
        if (array[i] < min) {
            min = array[i];
            min_index = i;
        }
    }

    std::sort(array, array + min_index);
    std::sort(array + min_index, array + len);

    return min_index;
}
