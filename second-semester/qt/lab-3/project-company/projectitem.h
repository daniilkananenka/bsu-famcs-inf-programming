#ifndef PROJECTITEM_H
#define PROJECTITEM_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QDate>

struct Date {
    struct Pretty {};

    uint day;
    uint month;
    uint year;

    friend std::istream& operator>>(std::istream&, Date&);
    friend std::ostream& operator<<(std::ostream&, const Date&);

    Date() = default;
    Date(QDate);

    bool operator<(const Date&) const;

    std::string ToString(Pretty) const;
    std::string ToString() const;
};

class ProjectItem
{
public:
    ProjectItem() = default;
    ~ProjectItem() = default;

    std::string Title() const {return title_;}
    std::string Task() const {return task_;}
    std::string Performer() const {return performer_;}
    std::string Supervisor() const {return supervisor_;}
    Date IssueDate() const {return issue_date_;}
    Date DueDate() const {return due_date_;}
    Date Deadline() const {return deadline_;}

    ProjectItem& SetTitle(const std::string& val) {title_=val; return *this;}
    ProjectItem& SetTask(const std::string& val) {task_=val; return *this;}
    ProjectItem& SetPerformer(const std::string& val) {performer_=val; return *this;}
    ProjectItem& SetSupervisor(const std::string& val) {supervisor_=val; return *this;}
    ProjectItem& SetIssueDate(const Date& val) {issue_date_=val; return *this;}
    ProjectItem& SetDueDate(const Date& val) {due_date_=val; return *this;}
    ProjectItem& SetDeadline(const Date& val) {deadline_=val; return *this;}

    std::string ToString() const;

    friend std::istream& operator>>(std::istream&, ProjectItem&);
    friend std::ostream& operator<<(std::ostream&, const ProjectItem&);

private:
    std::string title_;
    std::string task_;
    std::string performer_;
    std::string supervisor_;
    Date issue_date_;
    Date due_date_;
    Date deadline_;
};

#endif // PROJECTITEM_H
