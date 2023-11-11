#include <iostream>
#include <cstdlib>
#include <algorithm>

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 5, 2, 1, 1, 3, 4 };

	std::sort(std::begin(array), std::end(array));

	int result {};
	int arraySize { std::size(array) };
	int curNumber { array[0] };
	int numberCount { 1 };
	bool numberWasFound {};
	for (int i = 1; i < arraySize; i++) {
		if (array[i] == curNumber) {
			numberCount++;
		} else {
			if (numberCount % 2 != 0) {
				result = curNumber;
				numberWasFound = true;
				break;
			}
			curNumber = array[i];
			numberCount = 1;
		}
	}

	if (!numberWasFound) {
		result = array[arraySize - 1];
	}

	std::cout << "Result: " << result << std::endl;

	return 0;
}
