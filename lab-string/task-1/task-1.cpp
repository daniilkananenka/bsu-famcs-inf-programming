#include <iostream>
#include <fstream>
#include <string>

void InsertUnsignedWord(std::string& str);

int main()
{
    std::ifstream fin("task-1.cpp");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) {
        std::cout << "Error file open\n";

        return 1;
    }

    std::string current_line;
    while (std::getline(fin, current_line)) {
        InsertUnsignedWord(current_line);

        fout << current_line << std::endl;
    }

    return 0;
}

void InsertUnsignedWord(std::string& str)
{
    size_t current_index = str.find("char");
    while (current_index != std::string::npos) {
        str.insert(current_index, "unsigned ");

        current_index = str.find("char", current_index + 10);
    }
}
