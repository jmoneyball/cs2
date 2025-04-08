/* Vehicle class header */

/* 	----------------------------
	Vehicle
	----------------------------
	- name: string
	- year : int
	- mileage : int
	----------------------------
	+ Vehicle()
	+ Vehicle(string, int, int)
	+ setName(string): void
	+ getName(): string
	+ setYear(int) : void
	+ getYear() : int
	+ setMileage(int) : void
	+ getMileage() : int
	+ print() : void
	----------------------------
 */

/* preprocessor directives */
#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle
{
	private:
		string name;
		int year;
		int mileage;
	public:
		Vehicle();
		Vehicle(string name, int year, int mileage);
		void setName(string n)
			{ name = n; }
		string getName()
			{ return name; }
		void setYear(int y)
			{ year = y; }
		int getYear()
			{ return year; }
		void setMileage(int m)
			{ mileage = m; }
		int getMileage()
			{ return mileage; }
		void print();
};

#endif
