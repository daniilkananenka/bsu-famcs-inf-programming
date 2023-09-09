#include <iostream>

enum class Month
{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

enum class MonthDayDuration
{
    January = 31,
    FebruaryDefault = 28,
    FebruaryLeapYear = 29,
    March = 31,
    April = 30,
    May = 31,
    June = 30,
    July = 31,
    August = 31,
    September = 30,
    October = 31,
    November = 30,
    December = 31
};

int main ()
{
    int day, month, year;

    std::cout << "Input date (in format - day month year):" << std::endl;
    std::cin >> day >> month >> year;



    bool isLeapYear {};
    if (year % 4 == 0) {
        if (year % 100 == 0 && year % 400 != 0) {
            isLeapYear = true;
        } else if (year % 100 == 0 && year % 400 == 0) {
            isLeapYear = false;
        } else {
            isLeapYear = true;
        }
    }

    int monthDayDuration;
    switch (static_cast<Month>(month - 1)) {
        case Month::January:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::January);
            break;
        }
        case Month::February:
        {
            monthDayDuration = static_cast<int>(isLeapYear ? MonthDayDuration::FebruaryLeapYear :
                MonthDayDuration::FebruaryDefault);
            break;
        }
        case Month::March:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::March);
            break;
        }
        case Month::April:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::April);
            break;
        }
        case Month::May:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::May);
            break;
        }
        case Month::June:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::June);
            break;
        }
        case Month::July:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::July);
            break;
        }
        case Month::August:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::August);
            break;
        }
        case Month::September:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::September);
            break;
        }
        case Month::October:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::October);
            break;
        }
        case Month::November:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::November);
            break;
        }
        case Month::December:
        {
            monthDayDuration = static_cast<int>(MonthDayDuration::December);
            break;
        }
        default:
        {
            std::cout << "Incorrect month number!" << std::endl;

            return 0;
        }
    }

    if (day > monthDayDuration) {
        std::cout << "Incorrect day!" << std::endl;

        return 0;
    }

    int resultDay, resultMonth, resultYear;
    if (day < monthDayDuration) {
        resultDay = day + 1;
        resultMonth = month;
        resultYear = year;
    } else {
        resultDay = 1;
        resultMonth = month == 12 ? 1 : month + 1;
        resultYear = month == 12 ? year + 1 : year;
    }

    std::cout << "Tomorrow is " << resultDay << "/" << resultMonth <<
        "/" << resultYear << std::endl;

    return 0;
}
