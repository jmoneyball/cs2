/*
	-----------------------
	Video
	-----------------------
	- title: string
	- inventoryNumber: int
	- checkedOut: bool
	- overdue: bool
	- customer: int //represents which customer is currently renting the video
	-----------------------
	+ Video()
	+ Video(string, int, bool, bool, int)
	+ getTitle() : string
	+ getInvNr() : int
	+ getCheckedOut() : bool
	+ getOverdue() : bool
	+ getCustomer() : int
	+ setCheckedOut(bool) : void
	+ setTitle(string) : void
	+ setInvNr(int) : void
	+ setCustomer(int) : void
	----------------------
 */

//preprocessor directives
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
using namespace std;

//class definition
class Video {
private:
	string title;
	int inventoryNumber;
	bool checkedOut;
	bool overdue;
	int customer;
public:
	//constructor
	Video()
		{ title = "";
		  inventoryNumber = 0;
		  checkedOut = false;
		  overdue = false;
		  customer = 0;
		}
	Video(string title, int inventoryNumber,
		  bool checkedOut, bool overdue, int customer)
		{
		  this -> title = title;
		  this -> inventoryNumber = inventoryNumber;
		  this -> checkedOut = checkedOut;
		  this -> overdue = overdue;
		  this -> customer = customer;
		};
	//accessors
	string getTitle()
		{ return title; }
	int getInvNr()
		{ return inventoryNumber; }
	bool getCheckedOut()
		{ return checkedOut; }
	bool getOverdue()
		{ return overdue; }
	int getCustomer()
		{ return customer; }
	//mutators
	void setTitle(string title)
		{ this -> title = title; }
	void setInvNr(int inventoryNumber)
		{ this -> inventoryNumber = inventoryNumber; }
	void setCheckedOut(bool checkedOut)
		{ this -> checkedOut = checkedOut; }
	void setOverdue(bool overdue)
		{ this -> overdue = overdue; }
	void setCustomer(int customer)
		{ this -> customer = customer; }
};
#endif
