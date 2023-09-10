#include <iostream>
#include <string>

int main ()
{
	bool firstBool, secondBool;
	bool operationResult { false };
	int operationNumber;
	std::string operationStr;

	std::cout << "Input first boolean:" << std::endl;
	std::cin >> firstBool;
	std::cout << "Input second boolean:" << std::endl;
	std::cin >> secondBool;

	std::cout << "Choose operation:" << std::endl <<
		"\t0 - && (and)" << std::endl <<
		"\t1 - || (or)" << std::endl <<
		"\t2 - == (equals)" << std::endl <<
		"\t3 - != (not eqauls)" << std::endl;
	std::cin >> operationNumber;

	if (operationNumber > 3 || operationNumber < 0) {
		std::cout << "Incorrect operation number!" << std::endl;

		return 0;
	}

	switch (operationNumber) {
		case 0:
		{
			operationResult = firstBool && secondBool;
			operationStr = "&&";
			break;
		}
		case 1:
		{
			operationResult = firstBool || secondBool;
			operationStr = "||";
			break;
		}
		case 2:
		{
			operationResult = firstBool == secondBool;
			operationStr = "==";
			break;
		}
		case 3:
		{
			operationResult = firstBool != secondBool;
			operationStr = "!=";
			break;
		}
	}

	std::cout << firstBool << " " << operationStr << " " << secondBool << " => " <<
		operationResult << std::endl;

	return 0;
}
