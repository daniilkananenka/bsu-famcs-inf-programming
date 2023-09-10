#include <iostream>
#include <string>

struct Date
{
	int Day;
	int Month;
	int Year;
};

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

std::string dateToString(Date& date)
{
	std::string result = std::to_string(date.Day) + "/" +
		std::to_string(date.Month) + "/" + std::to_string(date.Year);

	return result;
}

bool checkIsLeapYear(int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0 && year % 400 != 0) {
			return true;
		} else if (year % 100 == 0 && year % 400 == 0) {
			return false;
		} else {
			return true;
		}
	} else {
		return false;
	}
}

int getMonthDuration(int month, bool isLeapYear)
{
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

	return monthDayDuration;
}

int getDateDistanceInDays(Date& firstDate, Date& secondDate)
{
	int result {};
	for (int i = firstDate.Year + 1; i < secondDate.Year; i++) {
		result += checkIsLeapYear(i) ? 366 : 365;
	}

	bool isFirstDateLeapYear = checkIsLeapYear(firstDate.Year);
	bool isSecondDateLeapYear = checkIsLeapYear(secondDate.Year);

	if (firstDate.Year != secondDate.Year) {
		result += getMonthDuration(firstDate.Month, isFirstDateLeapYear) - firstDate.Day;
		result += secondDate.Day;

		for (int i = firstDate.Month + 1; i <= 12; i++) {
			result += getMonthDuration(i, isFirstDateLeapYear);
		}
		for (int i = 1; i < secondDate.Month; i++) {
			result += getMonthDuration(i, isSecondDateLeapYear);
		}
	} else {
		if (firstDate.Month != secondDate.Month) {
			result += getMonthDuration(firstDate.Month, isFirstDateLeapYear) - firstDate.Day;
			result += secondDate.Day;
		} else {
			result += secondDate.Day - firstDate.Day;
		}

		for (int i = firstDate.Month + 1; i < secondDate.Month; i++) {
			result += getMonthDuration(i, isFirstDateLeapYear);
		}
	}
	
	return result;
}

int main()
{
	Date firstDate;
	Date secondDate;

	std::cout << "Input first date (format: day month year):" << std::endl;
	std::cin >> firstDate.Day >> firstDate.Month >> firstDate.Year;
	std::cout << "Input second date (format: day month year):" << std::endl;
	std::cin >> secondDate.Day >> secondDate.Month >> secondDate.Year;

	int dateDistance = getDateDistanceInDays(firstDate, secondDate);

	std::cout << "Distance between " << dateToString(firstDate) <<
		" and " << dateToString(secondDate) << " is " << dateDistance << " days";

	return 0;
}
