/* Sedan class header */

/* 	----------------------------
	Sedan :: Vehicle
	----------------------------
	- doors : int
	- hatchback : bool
	----------------------------
	+ Sedan()
	+ Sedan(int, int, int, bool)
	+ setDoors(int) : void
	+ getDoors() : int
	+ setHatchback(bool) : void
	+ getHatchback() : bool
	+ printVehicle() : void
	----------------------------
 */

/* preprocessor directives */
#ifndef SEDAN_H
#define SEDAN_H
#include "Vehicle.h"

class Sedan: public Vehicle
{
	private:
		int doors;
		bool hatchback;
	public:
		Sedan();
		Sedan(string name, int year, int mileage, int doors, bool hatcback);
		void setDoors(int d)
			{ doors = d; }
		int getDoors()
			{ return doors; }
		void setHatchback(bool hb)
			{ hatchback = hb; }
		bool getHatchback()
			{ return hatchback; }
		void printVehicle();
};

#endif
