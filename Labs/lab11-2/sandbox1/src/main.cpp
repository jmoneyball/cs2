/*
Program Name: lab 11-2
Author: Jordan Johnson
IDE Used: Eclipse
Program description: demo of vehicle objects from multiple classes using heirarchy inheritance
*/

/* preprocessor directives */
#include "Truck.h"
#include "Sedan.h"

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	//vehicle objects
	Vehicle car("Car", 2000, 40000);
	Vehicle boat("Boat", 2002, 10000);
	Vehicle dozer("Bulldozer", 2007, 250);
	//sedan objects
	Sedan ion("Saturn Ion", 2006, 90000, 4, false);
	Sedan fit("Honda Fit", 2007, 130000, 4, true);
	Sedan a4("Audi A4", 2004, 67000, 4, false);
	//truck objects
	Truck s10("Chevy S10", 1995, 350000, 5200, 2);
	Truck silverado("Chevy Silverado", 2010, 100000, 13200, 2);
	Truck ram("Dodge Ram 1500", 2020, 15000, 12750, 2);

	//printing vehicle objects
	cout << "Information about Vehicle " << '"' << car.getName() << '"' << ':' << endl;
	car.print();
	cout << "Information about Vehicle " << '"' << boat.getName() << '"' << ':' << endl;
	boat.print();
	cout << "Information about Vehicle " << '"' << dozer.getName() << '"' << ':' << endl;
	dozer.print();
	cout << endl;
	//printing sedan objects
	cout << "Information about Sedan " << '"' << ion.getName() << '"' << ':' << endl;
	ion.printVehicle();
	cout << "Information about Sedan " << '"' << fit.getName() << '"' << ':' << endl;
	fit.printVehicle();
	cout << "Information about Sedan " << '"' << a4.getName() << '"' << ':' << endl;
	a4.printVehicle();
	cout << endl;
	//printing truck objects
	cout << "Information about Truck " << '"' << s10.getName() << '"' << ':' << endl;
	s10.printVehicle();
	cout << "Information about Truck " << '"' << silverado.getName() << '"' << ':' << endl;
	silverado.printVehicle();
	cout << "Information about Truck " << '"' << ram.getName() << '"' << ':' << endl;
	ram.printVehicle();

	/* ends program */
	plagiarismPledge();
	return(0);
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
