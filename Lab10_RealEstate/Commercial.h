#include "Property.h"
#pragma once
#include <string>
#include <sstream>
using namespace std;

class Commercial : public Property
{
public:
	Commercial(string address, bool rental, double value, bool isDiscounted, double discount);
	~Commercial();
	string toString();
	string taxReport();

private:
	double discount;
	bool isDiscounted;
	double newValue;
	double newRental;

};

