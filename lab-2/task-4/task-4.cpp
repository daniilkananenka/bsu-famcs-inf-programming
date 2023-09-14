#include <iostream>

enum class Month
{
    January=1,
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

int main ()
{
    int day, month, year;

    std::cout << "Input date (in format - day month year):" << std::endl;
    std::cin >> day >> month >> year;

    bool isLeapYear {};
    if (year % 4 == 0) {
        if (year % 400 == 0) {
            isLeapYear = true;
        } else if (year % 100 == 0) {
            isLeapYear = false;
        } else {
            isLeapYear = true;
        }
    }

    int monthDayDuration;
    switch (static_cast<Month>(month)) {
        case Month::January: case Month::March: case Month::May: 
        case Month::July: case Month::August: case Month::October: 
        case Month::December:
        {
            monthDayDuration = 31;
            break;
        }
        case Month::April: case Month::June: case Month::September:
        case Month::November:
        {
            monthDayDuration = 30;
            break;
        }
        case Month::February:
        {
            monthDayDuration = isLeapYear ? 29 : 28;
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
