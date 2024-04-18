#include "projectitem.h"

Date::Date(QDate date) : day(date.day()), month(date.month()), year(date.year()) {
}

std::string ProjectItem::ToString() const {
    std::stringstream str_input;
    str_input << title_ << " " << task_ << " " << performer_ << " " << supervisor_ << " " <<
        issue_date_.ToString(Date::Pretty{}) << " " << due_date_.ToString(Date::Pretty{}) << " "
              << deadline_.ToString(Date::Pretty{});
    return str_input.str();
}

std::string Date::ToString() const {
    return std::to_string(day) + " " + std::to_string(month) + " " + std::to_string(year);
}

std::string Date::ToString(Date::Pretty) const {
    return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
}

std::istream& operator>>(std::istream& in, Date& date) {
    in >> date.day >> date.month >> date.year;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.ToString();
    return out;
}

std::istream& operator>>(std::istream& in, ProjectItem& item) {
    in >> item.title_ >> item.task_ >> item.performer_ >> item.supervisor_ >>
        item.issue_date_ >> item.due_date_ >> item.deadline_;
    return in;
}

std::ostream& operator<<(std::ostream& out, const ProjectItem& item) {
    out << item.title_ << " " << item.task_ << " " << item.performer_ << " " << item.supervisor_ << " " <<
        item.issue_date_ << " " << item.due_date_ << " " << item.deadline_ << "\n";
    return out;
}
