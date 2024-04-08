#include <iostream>
#include <string>

extern "C" float* _fastcall FirstCount(float*, float*);
extern "C" float* _fastcall SecondCount(float*, float*);
extern "C" float* _fastcall ThirdCount(float*, float*);

void PrintResults(std::string heading, float cpp_result, float asm_result) {
    std::cout << "Count: " << heading << std::endl;
    std::cout << "Cpp result: " <<cpp_result << std::endl;
    std::cout << "Assembler result: " << asm_result << "\n\n";
}

int main()
{
    float x = 1.2;
    float y = -2.4;
    
    PrintResults(
        "x * x * tan(x / y) + y * y * (1 / tan(x / y))", 
        x * x * tan(x / y) + y * y * (1 / tan(x / y)), 
        *FirstCount(&x, &y)
    );
    PrintResults(
        "(x * y + y * log2(x)) / (atan(x / y))",
        (x * y + y * log2(x)) / (atan(x / y)),
        *SecondCount(&x, &y)
    );
    PrintResults(
        "abs(x - y) * cos(x / y + y / x)",
        abs(x - y) * cos(x / y + y / x),
        *ThirdCount(&x, &y)
    );
    return 0;
}

