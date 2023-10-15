#include <iostream>
#include <vector>
#include <algorithm>

void InputVector(std::vector<int>&);
void PrintVector(std::vector<int>&);
void SortVector(std::vector<int>&);
void ConcatVectorsByCommon(std::vector<int>&, std::vector<int>&, std::vector<int>&);

int main()
{
	int M, N;

	std::cout << "Input M:" << std::endl;
	std::cin >> M;
	std::cout << "Input N:" << std::endl;
	std::cin >> N;

	std::vector<int> A(M);
	std::vector<int> B(N);


	std::cout << "Input A elements:" << std::endl;
	InputVector(A);
	std::cout << "Input B elements:" << std::endl;
	InputVector(B);

	std::vector<int> result;
	ConcatVectorsByCommon(A, B, result);
	PrintVector(A);
	PrintVector(B);
	PrintVector(result);

	return 0;
}

void InputVector(std::vector<int>& array)
{
	for (int i = 0; i < array.size(); i++) {
		std::cin >> array[i];
	}
}

void PrintVector(std::vector<int>& array)
{
	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}

void SortVector(std::vector<int>& array)
{
	std::sort(array.begin(), array.end());
}

void ConcatVectorsByCommon(std::vector<int>& A,
	std::vector<int>& B,
	std::vector<int>& result)
{
	SortVector(A);
	SortVector(B);

	int minSize = std::min(A.size(), B.size());
	int AStartIndex {}, BStartIndex {};

	while (AStartIndex < A.size() && BStartIndex < B.size()) {
		if (A[AStartIndex] >= B[BStartIndex]) {
			if (A[AStartIndex] == B[BStartIndex]) {
				AStartIndex++;
				BStartIndex++;
			} else {
				result.push_back(B[BStartIndex]);
				BStartIndex++;
			}
		} else {
			result.push_back(A[AStartIndex]);
			AStartIndex++;
		}
	}
	while(AStartIndex < A.size()) {
		result.push_back(A[AStartIndex]);
		AStartIndex++;
	}
	while (BStartIndex < B.size()) {
		result.push_back(B[BStartIndex]);
		BStartIndex++;
	}
}

