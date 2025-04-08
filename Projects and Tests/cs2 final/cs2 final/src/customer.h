/*
	-----------------------
	Customer
	-----------------------
	- custNr: int
	- lName: string // last name
	- fName: string // first name
	-----------------------
	+ Customer()
	+ Customer(int, string, string)
	+ getCustNr() : int
	+ getLName() : string
	+ getFName() : string
	+ setFName(string) : void
	+ setLName(string) : void
	+ setCustNr(int) : void
	----------------------
*/

//preprocessor directives
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;

//class definition
class Customer {
private:
	int custNr;
	string lName;
	string fName;
public:
	//constructors
	Customer()
		{
		  custNr = 0;
		  lName = "";
		  fName = "";
		}
	Customer(int custNr, string lName, string fName)
		{
		  this -> custNr = custNr;
		  this -> lName = lName;
		  this -> fName = fName;
		}
	//accessors
	int getCustNr()
		{ return custNr; }
	string getLName()
		{ return lName; }
	string getFName()
		{ return fName; }
	//mutators
	void setCustNr(int custNr)
		{ this -> custNr = custNr; }
	void setLName(string lName)
		{ this -> lName = lName; }
	void setFName(string fName)
		{ this -> fName = fName; }
};
#endif
