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

std::string dateToString(Date& date)
{
	std::string result = std::to_string(date.Day) + "/" +
		std::to_string(date.Month) + "/" + std::to_string(date.Year);

	return result;
}

bool checkIsLeapYear(int year)
{
	if (year % 4 == 0) {
		if (year % 400 == 0) {
			return true;
		} else if (year % 100 == 0) {
			return false;
		} else {
			return true;
		}
	}

	return false;
}

int getMonthDuration(int month, bool isLeapYear)
{
	switch (static_cast<Month>(month)) {
		case Month::January: case Month::March: case Month::May:
		case Month::July: case Month::August: case Month::October:
		case Month::December:
		{
			return 31;
		}
		case Month::April: case Month::June: case Month::September:
		case Month::November:
		{
			return 30;
		}
		case Month::February:
		{
			return isLeapYear ? 29 : 28;
		}
		default:
		{
			std::cout << "Incorrect month number!" << std::endl;

			return 0;
		}
	}
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
