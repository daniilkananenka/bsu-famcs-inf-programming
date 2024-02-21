#include <iostream>
#include <vector>
#include <algorithm>

void InputVector(std::vector<int>&);
void PrintVector(std::vector<int>&);
void UniqueElementsOnly(std::vector<int>&, std::vector<int>&);
void ConcatVectors(std::vector<int>&, std::vector<int>&, std::vector<int>&);
void SortVector(std::vector<int>&);

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


	std::vector<int> AandB(A.size() + B.size(), 0);
	ConcatVectors(A, B, AandB);
	
	std::vector<int> result;
	UniqueElementsOnly(AandB, result);
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

void UniqueElementsOnly(std::vector<int>& all, std::vector<int>& result)
{
	SortVector(all);
	result.push_back(all[0]);
	for (int i = 1; i < all.size(); i++) {
		if (all[i] != result.back()) {
			result.push_back(all[i]);
		}
	}
}

void ConcatVectors(std::vector<int>& a, std::vector<int>& b, std::vector<int>& result)
{
	std::move(a.begin(), a.end(), result.begin());
	std::move(b.begin(), b.end(), result.begin() + a.size());
}

void SortVector(std::vector<int>& array)
{
	std::sort(array.begin(), array.end());
}

