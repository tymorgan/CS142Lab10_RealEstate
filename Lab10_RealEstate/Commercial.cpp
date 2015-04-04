#include "Commercial.h"

double const TAXCOMRENT = 0.012;
double const TAXCOMNOT = 0.01;

Commercial::Commercial(string address, bool rental, double value, bool isDiscounted, double discount)
	: Property(address, rental, value)
{
	this->discount = discount;
	newValue = value;
	newRental = rental;
}


Commercial::~Commercial()
{
}

string Commercial::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (isDiscounted == true)
	{
		ss << "Discounted ";
		ss << "Discount " << discount << endl;
	}
	else
	{
		ss << "NOT discounted" << endl;
	}



	return ss.str();
}

string Commercial::taxReport()
{
	stringstream ss;
	ss << Property::taxReport();
	
	double taxDue;
	if (isDiscounted == true)
	{
		newValue = newValue * (1 - discount);

		if (newRental)
		{
			taxDue = newValue * TAXCOMRENT;
		}
		else
		{
			taxDue = newValue * TAXCOMNOT;
		}
	}
	else
	{
		if (newRental)
		{
			taxDue = newValue * TAXCOMRENT;
		}
		else
		{
			taxDue = newValue * TAXCOMNOT;
		}
	}
	

	ss << "Taxes due on this property are: " << taxDue << endl;

	return ss.str();
}
