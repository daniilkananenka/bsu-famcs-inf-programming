#include <iostream>

extern "C" void _cdecl SumNumber(int n);
extern "C" void _cdecl IsSemit(int n);
extern "C" void _cdecl ChetCount(int n);

int main()
{
    int n;
    std::cout << "Input n: ";
    std::cin >> n;

    // Simmetrical
    int is_simet;
    _asm {
        mov eax, n;
        push eax;
        call IsSemit
        mov is_simet, eax
        pop eax;
    }
    std::cout << "Simmetrical: " << (is_simet ? "YES" : "NO") <<std::endl;

    // Number sum
    int sum_number{};
    _asm {
        mov eax, n
        push eax
        call SumNumber
        mov sum_number, eax
        pop eax
    }
    std::cout << "Number sum: " << sum_number << std::endl;

    // Chet count
    int chet_count{};
    _asm {
        mov eax, n
        push eax
        call ChetCount
        mov chet_count, eax
        pop eax
    }
    std::cout << "Chet count: " << chet_count << std::endl;

    return 0;
}

