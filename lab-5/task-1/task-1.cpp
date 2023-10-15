#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib> 
#include <ctime> 

void FullfillMatrix(std::vector<std::vector<int>>& matrix);
void PrintMatrix(std::vector<std::vector<int>>& matrix);
std::vector<std::vector<int>> MatrixMult(std::vector<std::vector<int>>& lhs, std::vector<std::vector<int>>& rhs);

int main()
{
    srand(time(NULL));

    int n_lhs, m_lhs;
    int n_rhs, m_rhs;

    std::cout << "Input first matrix `n`(row count) and `m`(column count):" << std::endl;
    std::cin >> n_lhs >> m_lhs;
    std::cout << "Input second matrix `n`(row count) and `m`(column count):" << std::endl;
    std::cin >> n_rhs >> m_rhs;
    std::vector<std::vector<int>> lhs(n_lhs, std::vector<int>(m_lhs)),
        rhs(n_rhs, std::vector<int>(m_rhs));

    FullfillMatrix(lhs);
    FullfillMatrix(rhs);

    std::cout << "Matrix 1: " << std::endl;
    PrintMatrix(lhs);
    std::cout << "Matrix 2: " << std::endl;
    PrintMatrix(rhs);

    if (m_lhs != n_rhs) {
        std::cout << "Can`t mult matrix!" << std::endl;
        return 0;
    }
    std::vector<std::vector<int>> result = MatrixMult(lhs, rhs);

    std::cout << "Matrix multiplication: " << std::endl;
    PrintMatrix(result);

    return 0;
}

void FullfillMatrix(std::vector<std::vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = (rand() % 25) - 10;
        }
    }
}

void PrintMatrix(std::vector<std::vector<int>>& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> MatrixMult(std::vector<std::vector<int>>& lhs, std::vector<std::vector<int>>& rhs)
{
    int n = lhs.size();
    int m = rhs[0].size();
    int k = rhs.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                result[i][j] += lhs[i][x] * rhs[x][j];
            }
        }
    }

    return result;
}
