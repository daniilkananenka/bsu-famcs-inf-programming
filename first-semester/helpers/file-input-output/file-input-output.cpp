#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int age;
    std::string name;

    fin >> age;
    fin.ignore();
    std::getline(fin, name);

    fout << "Age is " << age << ". Name is " << name << ".\n";

    return 0;
}

