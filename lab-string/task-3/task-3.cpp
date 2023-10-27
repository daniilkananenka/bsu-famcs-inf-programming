#include <iostream> 
#include <fstream> 
#include <string>  
#include <vector> 
#include <cmath> 

int FindMaxCountKeywordIndex(std::vector<int>& keyword_count);
void CountKeywords(std::string& current_line, std::vector<std::string>& keywords, std::vector<int>& keyword_count);
void PrintKeywordStatistics(std::vector<std::string>& keywords, std::vector<int>& keyword_count, std::ofstream& fout);
void DeleteKeyword(std::string keyword_to_delete, std::ofstream& fout_code, std::ifstream& fin);

int main()
{
    std::ifstream fin("task-3.cpp");
    std::ofstream fout("output.txt");
    std::ofstream fout_code("code_output.txt");

    std::vector<std::string> keywords{ 
        "int", "for", "if", "const", "return", "break", 
            "continue", "while", "switch" 
    };
    std::vector<int> keyword_count(keywords.size(), 0);

    if (!fin.is_open())
    {
        std::cout << "Error file open\n";

        return 1;
    }

    std::string current_line{};
    while (std::getline(fin, current_line)) {
        CountKeywords(current_line, keywords, keyword_count);
    }

    PrintKeywordStatistics(keywords, keyword_count, fout);

    const int max_count_index = FindMaxCountKeywordIndex(keyword_count);
    const std::string keyword_to_delete = keywords[max_count_index];

    DeleteKeyword(keyword_to_delete, fout_code, fin);

    return 0;
}

int FindMaxCountKeywordIndex(std::vector<int>& keyword_count)
{
    int max {}, max_index {};
    for (int i = 0; i < keyword_count.size(); i++) {
        if (keyword_count[i] > max) {
            max = keyword_count[i];
            max_index = i;
        }
    }

    return max_index;
}

void CountKeywords(std::string& current_line, 
    std::vector<std::string>& keywords, 
    std::vector<int>& keyword_count)
{
    for (int i = 0; i < keywords.size(); i++) {
        int current_find_pos {};
        int count {};

        while (current_find_pos != std::string::npos) {
            current_find_pos = current_line.find(keywords[i], current_find_pos);
            if (current_find_pos == std::string::npos) {
                break;
            }

            count++;
            current_find_pos += keywords[i].length();
        }

        keyword_count[i] += count;
    }
}

void PrintKeywordStatistics(std::vector<std::string>& keywords, std::vector<int>& keyword_count, std::ofstream& fout)
{
    for (int i = 0; i < keywords.size(); i++) {
        fout << keywords[i] << " - " << keyword_count[i] << std::endl;
    }
}

void DeleteKeyword(std::string keyword_to_delete, std::ofstream& fout_code, std::ifstream& fin)
{
    fin.close();
    fin.open("task-3.cpp");
    std::string current_line{};
    while (std::getline(fin, current_line)) {
        int current_find_pos {};

        while (current_find_pos != std::string::npos) {
            current_find_pos = current_line.find(keyword_to_delete, current_find_pos);
            if (current_find_pos == std::string::npos) {
                break;
            }

            current_line.erase(current_find_pos, keyword_to_delete.length());
        }
        fout_code << current_line << std::endl;
    }
}
