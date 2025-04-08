/*
 _______________________
 	 	Square
 _______________________
 - sideLength: int
 _______________________
 + Square(l: int)
 + friend class Rectangle
 + displayArea(): void
 _______________________
*/

/* preprocessor directives */
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
using namespace std;

/* class declaration */
class Square
{
	private:
		int sideLength;
	public:
		Square(int l)
		{ sideLength = l; }
		friend class Rectangle;
		void displayArea()
		{ cout << "\t> Area of square -- " << sideLength * sideLength << endl; }
};

#endif /* SQUARE_H */
