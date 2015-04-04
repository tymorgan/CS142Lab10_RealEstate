#include "Residential.h"


double const TAXRESOCC = 0.006;
double const TAXRESNOT = 0.009;

Residential::Residential(string address, bool rental, double value, bool occupied)
	: Property(address, rental, value)
{
	this->occupied = occupied;
	newValue = value;
}


Residential::~Residential()
{
}


string Residential::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (occupied)
	{
		ss << "occupied " << endl;
	}
	else
	{
		ss << "NOT occupied" << endl;
	}
	
	return ss.str();
}

string Residential::taxReport()
{
	stringstream ss;
	ss << Property::taxReport();
	double taxDue;
	if (occupied)
	{
		taxDue = newValue * TAXRESOCC;
	}
	else
	{
		taxDue = newValue * TAXRESNOT;
	}
	
	ss << "Taxes due on this property are: " << taxDue << endl;

	return ss.str();
}

