// Chair.h
/*--------------------
 *	Chair: Furniture
 *--------------------
 *- legs: int
 *- color: string
 *--------------------
 *+ Chair(): Furniture()
 *+ Chair(b: string, y: int, l: int, c: string): Furniture(b, y)
 *+ printChair(): void
 *-------------------
 */

#ifndef CHAIR_H
#define CHAIR_H
#include "Furniture.h"

class Chair: public Furniture
{
	private:
		int legs;
		string color;
	public:
		//constructors
		Chair() : Furniture()
			{ legs = 0; color = ""; }
		Chair(string b, int y, int l, string c) : Furniture(b, y)
			{ legs = l; color = c; }
		//other methods
		void printChair()
			{ Furniture::print(); cout << "Legs: " << legs << "\nColor: " << color << endl; }
};
#endif
