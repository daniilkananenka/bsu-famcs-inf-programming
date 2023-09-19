#include <iostream>
#include <cstdlib>
#include <algorithm>

int main()
{
    int array[] = { 1, 2, 3, 4, 5, 5, 2, 1, 1, 3, 4 };

    std::sort(std::begin(array), std::end(array));

    int arraySize { std::size(array) };
    int result = array[arraySize - 1] * array[arraySize - 2] * array[arraySize - 3];

    return 0;
}
