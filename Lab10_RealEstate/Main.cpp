#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

void check_cin(int& input)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		input = 0;
	}
}


int main()
{
	vector<Property*> Properties;
	// Collects input
	string filename;
	string line;
	cout << "Enter File Name to Upload: ";
	cin >> filename;
	cout << endl;
	ifstream myfile(filename.c_str());
	
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int i = 0;
			while (isalpha(line[i]))
			{
				i++;
			}
			string type = line.substr(0, i);
			if (type == "Residential")
			{
				while (isspace(line[i]))
				{
					i++;
				}
				int j = i; //to determine the starting place for the rental digit
				while (!isspace(line[i]))
				{
					i++;
				}
				string rental = line.substr(j, i - j); //RENTAL - collecting what should be one digit either 0 or 1
				if (rental.size() > 1)
				{
					string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
					cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
				}
				else
				{
					while (isspace(line[i]))//this is looping through what should be one space with no characters present 
					{
						i++;
					}
					int k = i;
					if (!isdigit(line[i]))
					{
						string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
						cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
					}
					else
					{
						while (isdigit(line[i]))//this should loop through what the value of the property is
						{
							i++;
						}
						string value = line.substr(k, i - k); //collecting what should be the value of the property
						while (isspace(line[i]))//this is looping through what should be one space with no characters present
						{
							i++;
						}
						int l = i;
						if (!isdigit(line[i]))
						{
							string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
							cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
						}
						else
						{
							while (!isspace(line[i]))//determining vacancy
							{
								i++;
							}
							string vacant = line.substr(l, i - l);
							if (vacant.size() > 1)
							{
								//ERROR
								string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
								cout << "Ignoring bad RESIDENTIAL in input file: " << errorLine << endl;
							}
							else
							{
								while (isspace(line[i]))//this is looping through what should be one space with no characters present
								{
									i++;
								}
								string address = line.substr(i);
								// Change rental and vacant to Booleans
								bool bRental;
								bool occupied;
								if (rental == "0")
								{
									bRental = false; //NOT a rental
								}
								else if (rental == "1")
								{
									bRental = true; //means it's a rental
								}
								if (vacant == "0")
								{
									occupied = false;
								}
								else if (vacant == "1")
								{
									occupied = true; //means it's occupied
								}
								// change value from string to a double
								double dValue;
								stringstream st;
								st << value;
								st >> dValue;
								//Creates a Residential Property
								Properties.push_back(new Residential(address, bRental, dValue, occupied));
							}
						}
					}
				}
			}
			else if (type == "Commercial")
			{
				while (isspace(line[i]))
				{
					i++;
				}
				int j = i; //to determine the starting place for the rental digit
				while (!isspace(line[i]))
				{
					i++;
				}
				string rental = line.substr(j, i - j); //collecting what should be one digit either 0 or 1
				if (rental.size() > 1)
				{
					//ERROR
					string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
					cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
				}
				else
				{
					while (isspace(line[i]))//this is looping through what should be one space with no characters present 
					{
						i++;
					}
					int k = i;
					if (!isdigit(line[i]))
					{
						//ERROR
						string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
						cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
					}
					else
					{
						while (isdigit(line[i]))//this should loop through what the value of the property is
						{
							i++;
						}
						string value = line.substr(k, i - k); //collecting what should be the value of the property
						while (isspace(line[i]))//this is looping through what should be one space with no characters present
						{
							i++;
						}
						int l = i;
						if (!isdigit(line[i]))
						{
							//ERROR
							string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
							cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
						}
						else
						{
							while (!isspace(line[i]))//determining vacancy
							{
								i++;
							}
							string vacant = line.substr(l, i - l);
							if (vacant.size() > 1)
							{
								//ERROR
								string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
								cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
							}
							else
							{
								while (isspace(line[i]))//this is looping through what should be one space with no characters present
								{
									i++;
								}
								if (!isdigit(line[i]))
								{
									//ERROR
									string errorLine = line.substr(0); //Get the whole line and print it as an ERROR
									cout << "Ignoring bad COMMERCIAL in input file: " << errorLine << endl;
								}
								else
								{
									int m = i;
									while (!isspace(line[i]))//determining vacancy
									{
										i++;
									}
									string discount = line.substr(m, i - m);
									while (isspace(line[i]))//this is looping through what should be one space with no characters present
									{
										i++;
									}
									string address = line.substr(i);
									// Change rental and vacant to Booleans
									bool bRental;
									if (rental == "0")
									{
										bRental = false; //NOT a rental
									}
									else if (rental == "1")
									{
										bRental = true; //means it's a rental
									}
									bool isDiscounted;
									if (vacant == "1")
									{
										isDiscounted = true;
									}
									else
									{
										isDiscounted = false; //means it's occupied
									}
									// change value from string to a double
									double dValue;
									stringstream st;
									st << value;
									st >> dValue;
									// change discount from string to a int
									double dDiscount;
									stringstream st2;
									st2 << discount;
									st2 >> dDiscount;
									Properties.push_back(new Commercial(address, bRental, dValue, isDiscounted, dDiscount));
								}
							}
						}
					}
				}
			}
			else
			{

				string entireLine = line;
				cout << "Ignoring unknown types of properties appearing in the input file: " << entireLine << endl << endl;
			}
		}


		//Print out Properties vector
		cout << "All valid properties:" << endl;
		for (int i = 0; i < Properties.size(); i++)
		{
			cout << Properties[i]->toString();
		}
		cout << endl << endl;

		//Print out TAX stuff
		cout << "NOW PRINTING TAX REPORT:" << endl;
		for (int i = 0; i < Properties.size(); i++)
		{
			cout << Properties[i]->taxReport();
		}
		cout << endl << endl;



	}
	else
	{
		cout << "Not able to open file." << endl;
	}

	

	system("pause");
	return 0;
}