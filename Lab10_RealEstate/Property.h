#pragma once
#include <string>
#include <sstream>

using namespace std;

class Property
{
public:
	Property(string address, bool rental, double value);
	~Property();
	virtual string toString();
	virtual string taxReport();


private:
	string address;
	bool rental;
	double value;
	static int counter;
	int propertyID;
};

