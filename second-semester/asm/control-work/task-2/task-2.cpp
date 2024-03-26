#include <iostream>  
#include<ctime>  
const int ROWS = 5;
const int COLS = 5;

extern "C" int _cdecl RowMaxSum(int nums[ROWS][COLS], int rows, int cols);

int main() {
	int A[ROWS][COLS];
	// RANDOMIZE ARRAY
	srand(time(0));
	std::cout << "Array of numbers:" << std::endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			A[i][j] = rand() % 10;
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// CALL ASM MODULE FOR SEARCHING MAX ROW SUM
	int result{};
	int resultIndex{};
	_asm {
		push COLS
		push ROWS
		lea eax, A
		push eax
		call RowMaxSum
		mov result, eax
		mov resultIndex, edx
		pop eax
		pop eax
		pop eax
	}

	std::cout << "Max row sum: " << result << std::endl;
	std::cout << "Row index: " << resultIndex << std::endl;
	std::cout << "Row: ";
	for (int i = 0; i < COLS; ++i) {
		std::cout << A[resultIndex][i] << " ";
	}
	std::cout << std::endl;

	return 0;
}