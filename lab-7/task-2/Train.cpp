#include "Train.h"
#include <iostream>
#include <string>

Train::Train()
{
	this->setDestination("");
	this->setNumber(0);
	this->setIsExpress(false);
}

Train::Train(std::string destination, int number, bool isExpress)
{
	this->setDestination(destination);
	this->setNumber(number);
	this->setIsExpress(isExpress);
}

Train::Train(const Train& train)
{
	this->setDestination(train.getDestination());
	this->setNumber(train.getNumber());
	this->setIsExpress(train.getIsExpress());
}

std::string Train::getDestination() const
{
	return this->destination;
}

int Train::getNumber() const
{
	return this->number;
}

bool Train::getIsExpress() const
{
	return this->isExpress;
}

void Train::setDestination(std::string value)
{
	this->destination = value;
}

void Train::setNumber(int value)
{
	this->number = value;
}

void Train::setIsExpress(bool value)
{
	this->isExpress = value;
}

std::ostream& operator<<(std::ostream& stream, const Train& train)
{
	stream << "Number: " << train.getNumber() <<
		"; Destination: " << train.getDestination() <<
		"; Express: " << (train.getIsExpress() ? "YES" : "NO");

	return stream;
}

std::istream& operator>>(std::istream& stream, Train& train)
{
	std::string destination;
	int number;
	bool isExpress;

	stream >> destination >> number >> isExpress;

	train.setDestination(destination);
	train.setIsExpress(isExpress);
	train.setNumber(number);

	return stream;
}
