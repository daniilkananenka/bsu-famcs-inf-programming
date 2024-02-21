#pragma once
#include <string>
#include <iostream>

class Train
{
private:
	std::string destination;
	int number;
	bool isExpress;
public:	
	Train();
	Train(std::string, int, bool);
	Train(const Train&);

	std::string getDestination() const;
	int getNumber() const;
	bool getIsExpress() const;

	void setDestination(std::string);
	void setNumber(int);
	void setIsExpress(bool);

	friend std::ostream& operator<<(std::ostream&, const Train&);
	friend std::istream& operator>>(std::istream&, Train&);
};

