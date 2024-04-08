#include <iostream>
#include <iomanip>

extern "C" float* _fastcall FindLn(int, float*);

int main()
{
	int N;
	float delta{};
	float* delta_ptr = &delta;
	float* result_ptr = nullptr;

	std::cout << "-------Find LN(2)-------" << "\n";
	N = 10000;
	_asm {
		; XOR
		xor ecx, ecx
		xor edx, edx

		; CALL FUNCTION
		mov ecx, N
		mov edx, delta_ptr
		call FindLn

		; RESULT
		mov result_ptr, eax
	}

	if (result_ptr == nullptr) {
		std::cout << "ERROR!" << "\n";
		return 0;
	}

	std::cout << std::setprecision(20) << "LN(2): " << *result_ptr << "\n";
	std::cout << "DIF: " << delta << "\n";
}

