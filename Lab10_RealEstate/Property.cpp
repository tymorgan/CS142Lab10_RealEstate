#include "Property.h"
#include <sstream>


int Property::counter = 0;

Property::Property(string address, bool rental, double value)
{
	this->address = address;
	this->rental = rental;
	this->value = value;
	propertyID = counter;
	counter++;
}


Property::~Property()
{
}


string Property::toString()
{
	stringstream ss;
	ss << "Property id: " << propertyID << " ";
	ss << "Address: " << address << " ";
	if (rental)
	{
		ss << "Rental ";
	}
	else if (rental == false)
	{
		ss << "NOT rental ";
	}
	ss << "Estimated value: " << value << " ";
	
	return ss.str();
}

string Property::taxReport()
{
	stringstream ss;
	ss << "** Taxes due for the property at: " << address << endl;
	ss << "Property id: " << propertyID << endl;
	ss << "This property has an estimated value of: " << value << endl;
	

	return ss.str();
}