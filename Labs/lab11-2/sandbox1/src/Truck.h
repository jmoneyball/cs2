/* Truck class header */

/* 	----------------------------
	Truck :: Vehicle
	----------------------------
	- towingCapacity : int
	- numAxles : int
	----------------------------
	+ Truck()
	+ Truck(int, int, int, int)
	+ setTC(int): void
	+ getTC(): int
	+ setNA(int): void
	+ getNA(): int
	+ printVehicle() : void
	----------------------------
 */

/* preprocessor directives */
#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

class Truck: public Vehicle
{
	private:
		int towingCapacity;
		int numAxles;
	public:
		Truck();
		Truck(string name, int year, int mileage, int towingCapacity, int numAxles);
		void setTC(int tc)
			{ towingCapacity = tc; }
		int getTC()
			{ return towingCapacity; }
		void setNA(int na)
			{ numAxles = na; }
		int getNA()
			{ return numAxles; }
		void printVehicle();
};

#endif
