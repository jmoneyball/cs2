/*
 _______________________
 	 	Rectangle
 _______________________
 - lenght: int
 - width: int
 _______________________
 + Rectangle(l: int, w: int)
 + displayArea(): void
 + morphToSquare(sq: Square): void
 _______________________
*/

/* preprocessor directives */
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;

/* class declaration */
class Rectangle
{
	private:
		int length;
		int width;
	public:
		Rectangle(int l, int w)
		{ length = l; width = w; }
		void displayArea()
		{ cout << "\t> Area of rectangle -- " << length * width << endl; }
		void morphToSquare(Square sq)
		{ length = width = sq.sideLength; }
};

#endif /* RECTANGLE_H */
