#include <iostream>
#include <string>

int main ()
{
	int weekDayNum;
	std::string weekDayName;

	std::cout << "Input week day number (1 - 7):" << std::endl;
	std::cin >> weekDayNum;

	switch (weekDayNum) {
		case 1:
		{
			weekDayName = "Monday";
			break;
		}
		case 2:
		{
			weekDayName = "Tuesday";
			break;
		}
		case 3:
		{
			weekDayName = "Wednesday";
			break;
		}
		case 4:
		{
			weekDayName = "Thursday";
			break;
		}
		case 5:
		{
			weekDayName = "Friday";
			break;
		}
		case 6:
		{
			weekDayName = "Saturday";
			break;
		}
		case 7:
		{
			weekDayName = "Sunday";
			break;
		}
		default:
		{
			weekDayName = "";
			break;
		}
	}

	if (weekDayName == "") {
		std::cout << "Incorrect week day number!" << std::endl;
	} else {
		std::cout << "Week day - " << weekDayName << std::endl;
	}

	return 0;
}
