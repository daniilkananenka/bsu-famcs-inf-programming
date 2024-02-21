#include <iostream>
#include <string>

int main()
{
	int monthNumber;
	std::string season;

	std::cout << "Input month number:" << std::endl;
	std::cin >> monthNumber;

	switch (monthNumber) {
		case 12:
		case 1:
		case 2:
		{
			season = "Winter";
			break;
		}
		case 3:
		case 4:
		case 5:
		{
			season = "Spring";
			break;
		}
		case 6:
		case 7:
		case 8:
		{
			season = "Summer";
			break;
		}
		case 9:
		case 10:
		case 11:
		{
			season = "Autumn";
			break;
		}
	}

	if (season != "") {
		std::cout << "Season is " << season << std::endl;
	} else {
		std::cout << "Incorrect month number!" << std::endl;
	}

	return 0;
}
