/* Sedan class implementation */

/* preprocessor directives */
#include "Sedan.h"

Sedan :: Sedan() : Vehicle()
{
	doors = 0;
	hatchback = false;
}

Sedan :: Sedan(string name, int year, int mileage, int doors, bool hatchback) : Vehicle(name, year, mileage)
{
	if (doors >= 0)
		this->doors = doors;
	else
	{
		cout << "\t> Invalid number of doors" << endl;
		exit(EXIT_FAILURE);
	}
	this->hatchback = hatchback;
}

void Sedan :: printVehicle()
{
	Vehicle :: print();
	cout << "\t> Doors: " << doors << endl;
	cout << "\t> Hatchback: ";
	if (hatchback == true)
		cout << "yes" << endl;
	else cout << "no" << endl;
}
