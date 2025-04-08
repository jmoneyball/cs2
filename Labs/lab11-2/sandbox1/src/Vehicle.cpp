/* Vehicle class implementation */

/* preprocessor directives */
#include "Vehicle.h"

Vehicle :: Vehicle()
{
	name = "";
	year = 0;
	mileage = 0;
}

Vehicle :: Vehicle(string name, int year, int mileage)
{
	this->name = name;
	if (year >= 1920)
		this->year = year;
	else
	{
		cout << "\t> Invalid year" << endl;
		exit(EXIT_FAILURE);
	}
	if (mileage >= 0)
		this->mileage = mileage;
	else
	{
		cout << "\t> Invalid mileage" << endl;
		exit(EXIT_FAILURE);
	}
}

void Vehicle :: print()
{
	cout << "\t> Year: " << year << endl;
	cout << "\t> Mileage: " << mileage << endl;
}
