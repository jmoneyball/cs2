//Car.h
/*
-----------------------
          Car
-----------------------
- make: string
- year : int
- transponder: int
-----------------------
+ Car()
+ Car(string, int)
+ getMake() : string
+ setMake(string) : void
+ getYear() : int
+ setYear(int) : void
+ getTransponder() : int
+ setTransponder(int) : void
----------------------
*/
#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;

class Car
{
    private:
    	string make;
    	int year;
    	int transponder;

	public:
    	//constructors
    	Car()
	        { make = ""; year = transponder = 0; }
    	Car(string mk, int y, int t)
    	    { make = mk; year = y; transponder = t; }

    	//setters and getters
    	string getMake()           { return make; }
    	void setMake(string m)     { make = m; }
    	int getYear()              { return year; }
        void setYear (int y)       { year = y; }
        int getTransponder()       { return transponder; }
    	void setTransponder(int t) { transponder = t; }
};
#endif
