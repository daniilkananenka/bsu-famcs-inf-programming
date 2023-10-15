#include <iostream>
#include <vector>
#include <iomanip>

void InsertRow(std::vector<std::vector<int>>& arr, std::vector<int>& row, int index);
void InsertColumn(std::vector<std::vector<int>>& arr, std::vector<int>& column, int index);
void RemoveRow(std::vector<std::vector<int>>& arr, int index);
void RemoveColumn(std::vector<std::vector<int>>& arr, int index);

void Fullfill(std::vector<std::vector<int>>& arr);
void Print(std::vector<std::vector<int>>& arr);

int main()
{
    int n, m;
    std::cout << "Input `n`(row count) and `m`(column count):" << std::endl;
    std::cin >> n >> m;
    std::vector<std::vector<int> > arr(n, std::vector<int>(m));

    Fullfill(arr);

    std::cout << "Array: " << std::endl;
    Print(arr);

    int row_index;
    int col_index;
    // row - insert
    std::cout << "Input index to row inserting:" << std::endl;
    std::cin >> row_index;

    std::vector<int> row_to_add(arr[0].size(), 0);
    InsertRow(arr, row_to_add, row_index);
    std::cout << "Add row (" << row_index << "):" << std::endl;
    Print(arr);

    // column - insert
    std::cout << "Input index to column inserting:" << std::endl;
    std::cin >> col_index;

    std::vector<int> column_to_add(arr.size(), 0);
    InsertColumn(arr, column_to_add, col_index);
    std::cout << "Add column (" << col_index << "):" << std::endl;
    Print(arr);

    // row - remove
    std::cout << "Input index to row remove:" << std::endl;
    std::cin >> row_index;

    RemoveRow(arr, row_index);
    std::cout << "Remove row:" << std::endl;
    Print(arr);

    // column - remove
    std::cout << "Input index to column remove:" << std::endl;
    std::cin >> col_index;

    RemoveColumn(arr, col_index);
    std::cout << "Remove column:" << std::endl;
    Print(arr);
}


void InsertRow(std::vector<std::vector<int>>& arr, std::vector<int>& row, int index)
{
    arr.insert(arr.begin() + index, row);
}

void InsertColumn(std::vector<std::vector<int>>& arr, std::vector<int>& column, int index)
{
    for (int i = 0; i < arr.size(); i++) {
        arr[i].insert(arr[i].begin() + index, column[i]);
    }
}

void RemoveRow(std::vector<std::vector<int>>& arr, int index)
{
    arr.erase(arr.begin() + index);
}

void RemoveColumn(std::vector<std::vector<int>>& arr, int index)
{
    for (int i = 0; i < arr[0].size(); i++) {
        arr[i].erase(arr[i].begin() + index);
    }
}

void Fullfill(std::vector<std::vector<int>>& arr)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = (rand() % 25) - 10;
        }
    }
}

void Print(std::vector<std::vector<int>>& arr)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << std::setw(5) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
