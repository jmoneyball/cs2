/* Box class header */

/*
 _______________________
           Box
 _______________________
 - length: double
 - width: double
 - height: double
 _______________________
 + Box(l: double, w: double, h: double)
 + volume(): double
 + getLength(): double
 + getWidth(): double
 + getHeight(): double
 + operator ==(b: Box): bool
 + operator >(b: Box): bool
 + operator <(b: Box): bool
 + operator >=(b: Box): bool
 + operator <=(b: Box): bool
 */

/* preprocessor directives */
#ifndef BOX_H
#define BOX_H
#include <iostream>
using namespace std;

class Box
{
	private:
		double length;
		double width;
		double height;
	public:
		Box(double l = 2.0, double w = 2.0, double h = 2.0)
			{ length = l; width = w; height = h; }
		double volume()
			{ return length * width * height; }
		double getLength()
			{ return length; }
		double getWidth()
			{ return width; }
		double getHeight()
			{ return height; }
		//overloading various operators
		bool operator ==(Box b);
		bool operator >(Box b);
		bool operator <(Box b);
		bool operator >=(Box b);
		bool operator <=(Box b);
};

#endif /* box_H */
