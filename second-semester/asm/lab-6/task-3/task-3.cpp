#include <iostream>

extern "C" float* _fastcall IntegralCount(int);

int main()
{
	int N = 1000;
	float* result_ptr = nullptr;

	std::cout << "------Count integral------" << "\n";
	_asm {
		; XOR
		xor ecx, ecx

		; CALL FUNCTION
		mov ecx, N
		call IntegralCount

		; GET RESULT
		mov result_ptr, eax
	}

	if (result_ptr == nullptr) {
		std::cout << "ERROR!" << "\n";
		return 0;
	}

	std::cout << "Integral of (x^2 + sin(x)) [0,2pi]: " << *result_ptr << "\n";
	return 0;
}