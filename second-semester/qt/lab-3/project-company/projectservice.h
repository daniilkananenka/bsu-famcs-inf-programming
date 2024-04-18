#ifndef PROJECTSERVICE_H
#define PROJECTSERVICE_H

#include <vector>
#include <string>
#include <functional>
#include "projectitem.h"

using ProjectVector = std::vector<ProjectItem>;
using ProjectItemConditional = std::function<bool(const ProjectItem&)>;
using ProjectItemComparator = std::function<bool(const ProjectItem&, const ProjectItem&)>;
using ProjectSequence = std::pair<ProjectVector::const_iterator, ProjectVector::const_iterator>;

class ProjectService
{
public:
    ProjectService() = default;
    ~ProjectService() = default;

    void ReadFromFile(const std::string);
    void PrintInFile(const std::string) const;

    void Add(ProjectItem& item);
    ProjectSequence FindAll(ProjectItemConditional, ProjectItemComparator);
    void Sort(ProjectItemComparator);

    std::string ToString() const;
    static std::string ToString(ProjectSequence);

private:
    std::vector<ProjectItem> items;
};

#endif // PROJECTSERVICE_H
