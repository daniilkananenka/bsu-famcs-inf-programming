#include <iostream>

enum class Month
{
	January = 1,
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

int main()
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

	int previousMonthDuration;
	int previousMonthNumber { month == 1 ? 12 : month - 1 };

	switch (static_cast<Month>(previousMonthNumber)) {
		case Month::January: case Month::March: case Month::May:
		case Month::July: case Month::August: case Month::October:
		case Month::December:
		{
			previousMonthDuration = 31;
			break;
		}
		case Month::April: case Month::June: case Month::September:
		case Month::November:
		{
			previousMonthDuration = 30;
			break;
		}
		case Month::February:
		{
			previousMonthDuration = isLeapYear ? 29 : 28;
			break;
		}
		default:
		{
			std::cout << "Incorrect month number!" << std::endl;

			return 0;
		}
	}

	int resultDay, resultMonth, resultYear;
	if (day > 1) {
		resultDay = day - 1;
		resultMonth = month;
		resultYear = year;
	} else {
		resultDay = previousMonthDuration;
		resultMonth = previousMonthNumber;
		resultYear = month == 1 ? year - 1 : year;
	}

	std::cout << "Yesterday was " << resultDay << "/" << resultMonth <<
		"/" << resultYear << std::endl;

	return 0;
}
