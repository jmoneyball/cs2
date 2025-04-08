/* Car class implementation */

/* preprocessor directives */
#include "Car.h"

/* constructor */
Car :: Car (string m, int y)
{
	make = m;
	year = y;
	speed = 0;
	num_recs = 0;

	//initializes array to all 0s
	for (int i = 0; i < SIZE; i++)
		maintenance[i] = 0;
}

//print(bool mR): prints info about given car from collection
//Arguments: bool mR | Returns: void
void Car :: print(bool mR)
{
	if (mR == true)
	{
		 cout << make << " | " << year << " | "
			  << speed << " mph | Maint: ";
		for (int i = 0; i < num_recs; i++)
			cout << maintenance[i] << " ";
		cout << endl;
	}
	else
	{
		cout << make << " | " << year << " | "
			 << speed << " mph\n";
	}
}
