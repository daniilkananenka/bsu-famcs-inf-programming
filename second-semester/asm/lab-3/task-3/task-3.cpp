#include <iostream>
#include <cmath>

bool IsPower(int a, int n) {
    if (a == 1 || n == 1) {
        return true;
    }
    
    int b = 2;
    int c{};
    n -= 1;
    while (b <= sqrt(a)) {
        _asm {
            mov eax, b
            mov ecx, n
            mov edx, 1
            loop_power :
                mul b
                dec ecx
                jnz loop_power
                mov c, eax
        }
        if (c == a) {
            return true;
        }
        b++;
    }
    return false;
}

int main()
{
    int a, n;
    std::cout << "Enter a, n: ";
    std::cin >> a >> n;
    std::cout << (IsPower(a, n) ? "YES" : "NO") << std::endl;

    return 0;
}
