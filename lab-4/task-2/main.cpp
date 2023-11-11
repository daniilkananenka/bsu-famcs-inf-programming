#include <iostream>
#include <cstdlib>
#include <algorithm>

int main()
{
    int array[] = { 100, -100, -100, 2 };
    const int n = std::size(array);

    int max_mult = array[0] * array[1] * array[2];
    int a = array[0], b = array[1], c = array[2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            for (int x = 0; x < n; x++) {
                if (x == j || x == i) {
                    continue;
                }

                int mult = array[i] * array[j] * array[x];
                if (mult > max_mult) {
                    max_mult = mult;
                    a = array[i];
                    b = array[j];
                    c = array[x];
                }
            }
        }
    }
    std::cout << "Max mult: " << max_mult << std::endl;
    std::cout << "Nums: " << a << " " << b << " " << c << std::endl;

    return 0;
}
