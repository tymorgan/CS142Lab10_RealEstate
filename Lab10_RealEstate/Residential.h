#include "Property.h"
#pragma once
#include <string>
using namespace std;

class Residential : public Property
{
public:
	Residential(string address, bool rental, double value, bool occupied);
	~Residential();
	string toString();
	string taxReport();

private:
	bool occupied;
	double newValue;
};

