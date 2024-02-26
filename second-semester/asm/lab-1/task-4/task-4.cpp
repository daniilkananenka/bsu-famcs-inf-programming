#include <iostream>

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;

    std::cout << "Input first moment in format: hh MM ss" << std::endl;
    std::cin >> h1 >> m1 >> s1;
    std::cout << "Input second moment in format: hh MM ss" << std::endl;
    std::cin >> h2 >> m2 >> s2;
    int result{};
    int cnt = 60;
    _asm {
        mov eax, h1
        mul cnt
        mul cnt
        mov ebx, eax
        mov eax, m1
        mul cnt
        add ebx, eax
        add ebx, s1
        
        mov result, ebx

        mov eax, h2
        mul cnt
        mul cnt
        mov ebx, eax
        mov eax, m2
        mul cnt
        add ebx, eax
        add ebx, s2
  
        sub ebx, result
        mov result, ebx
    }

    std::cout << "Interval is " << result << std::endl;
    return 0;
}

