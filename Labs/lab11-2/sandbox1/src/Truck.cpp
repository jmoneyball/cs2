/* Sedan class implementation */

/* preprocessor directives */
#include "Truck.h"

Truck :: Truck() : Vehicle()
{
	towingCapacity = 0;
	numAxles = 0;
}

Truck :: Truck(string name, int year, int mileage, int towingCapacity, int numAxles) : Vehicle(name, year, mileage)
{
	if (towingCapacity >= 0)
		this->towingCapacity = towingCapacity;
	else
	{
		cout << "\t> Invalid towing capacity" << endl;
		exit(EXIT_FAILURE);
	}
	if (numAxles >= 0)
		this->numAxles = numAxles;
	else
	{
		cout << "\t> Invalid number of axles" << endl;
		exit(EXIT_FAILURE);
	}
}

void Truck :: printVehicle()
{
	Vehicle :: print();
	cout << "\t> Towing capacity: " << towingCapacity << " pounds" << endl;
	cout << "\t> Number of axles: " << numAxles << endl;
}
