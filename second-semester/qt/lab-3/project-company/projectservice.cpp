#include "projectservice.h"

void ProjectService::ReadFromFile(const std::string file_name) {
    items.clear();
    std::ifstream fin(file_name);
    ProjectItem item;
    while (fin >> item) {
        items.push_back(item);
    }
}

void ProjectService::PrintInFile(const std::string file_name) const {
    std::ofstream fout(file_name);
    for (auto& i : items) {
        fout << i;
    }
}

void ProjectService::Add(ProjectItem& item) {
    items.push_back(item);
}

std::string ProjectService::ToString() const {
    std::string result{};
    for (auto& i : items) {
        result += i.ToString() + "\n";
    }
    return result;
}

std::string ProjectService::ToString(ProjectSequence sequance) {
    std::string result{};
    auto item_it = sequance.first;
    while (item_it != sequance.second) {
        result += (*item_it).ToString() + "\n";
        ++item_it;
    }
    return result;
}

ProjectSequence ProjectService::FindSequence(ProjectItemConditional condition, ProjectItemComparator comparator) {
    Sort(comparator);
    auto begin = std::find_if(items.begin(), items.end(), condition);
    auto not_condition = [condition](const ProjectItem& item){
        return !condition(item);
    };
    auto end = std::find_if(begin, items.end(), not_condition);
    return std::make_pair(begin, end);
}

void ProjectService::Sort(ProjectItemComparator comparator) {
    std::sort(items.begin(), items.end(), comparator);
}

ProjectVector ProjectService::Where(ProjectItemConditional condition) {
    ProjectVector result;
    for (auto& item : items) {
        if (condition(item)) {
            result.push_back(item);
        }
    }
    return result;
}
