// Furniture.h
/*---------------------
 *		Furniture
 *---------------------
 *- brand: string
 *- yearMade: int
 *--------------------
 *+ Furniture()
 *+ Furniture(b: string, y: int)
 *+ setYear(y: int): void
 *+ setBrand(b: string): void
 *+ print(): void
 *-------------------
 */

#ifndef FURNITURE_H_
#define FURNITURE_H_
#include <iostream>
#include <iomanip>
using namespace std;

class Furniture
{
	private:
		string brand;
		int yearMade;

	public:
		//constructors
		Furniture()
			{ brand = ""; yearMade = 0; }
		Furniture(string b, int y)
			{ brand = b; yearMade = y; }
		//mutator methods
		void setYear(int y)
			{yearMade = y;}
		void setBrand(string b)
			{brand = b;}
		//other methods
		void print()
			{ cout << "Brand: " << brand << "\nYear made: " << yearMade << endl; }
};
#endif
