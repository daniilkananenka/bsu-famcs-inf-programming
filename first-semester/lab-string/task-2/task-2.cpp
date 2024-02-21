#include <iostream>
#include <fstream>
#include <string>

void ToLower(std::string& str);
void ReplaceWeWithThey(std::string& str);

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    if (!fin.is_open()) {
        std::cout << "Error file open\n";

        return 1;
    }

    std::string current_line;
    while (std::getline(fin, current_line)) {
        ToLower(current_line);
        ReplaceWeWithThey(current_line);

        fout << current_line << std::endl;
    }

    return 0;
}

void ToLower(std::string& str)
{
    for (auto& c : str) {
        c = std::tolower(c);
    }
}

void ReplaceWeWithThey(std::string& str)
{
    size_t current_index = str.find(" we");
    while (current_index != std::string::npos) {
        if (current_index + 3 < str.length() && str[current_index + 3] < 'a') {
            str.replace(current_index, 3, " they");
        }
        
        current_index = str.find(" we", current_index + 5);
    }
}
