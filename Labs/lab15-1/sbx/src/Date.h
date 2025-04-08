//Date class header

//preprocessor directives
#include <iostream>
using namespace std;

//constant
const int NUM_MONTHS = 12;

//class definition
class Date {
	private:
	   int month;
	   int day;
	   int year;
	   string names[NUM_MONTHS];
	   int daysInMonth[NUM_MONTHS];
	   void setNames();
	public:
	   //constructors
	   Date()  { setNames(); }
	   Date(int, int, int);
	   //setters & getters
	   void setMonth(int m);
	   void setDay(int d);
	   void setYear(int y)  { year = y; }
	   int getDaysInMonth() { return daysInMonth[month - 1]; }
	   //functions to print the date
	   void showDate1()
		   { cout << month << "/" << day << "/" << year << endl; }
	   void showDate2()
		   { cout << names[month-1] << " " << day << ", " << year << endl; }
	   void showDate3()
		   { cout << day << " " << names[month-1] << " " << year << endl; }
	   //exception classes
	   class IncorrectMonth {};
	   class IncorrectDay   {};
};
