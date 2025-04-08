/* Date class header */

/* 	----------------------------
			Date
	----------------------------
	- month: int
	- day: int
	- year: int
	----------------------------
	+ Date()
	+ Date(int, int, int)
	+ setMonth(int): void
	+ setDay(int): void
	+ setYear(int): void
	+ getMonth(): int
	+ getDay(): int
	+ getYear(): int
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
		Date()
		{	month = 1; day = 1; year = 1;	}
		Date(int m, int d, int y);
		void setMonth(int month);
		void setDay(int day);
		void setYear(int year);
		int getMonth()
		{	return month;	}
		int getDay()
		{	return day;		}
		int getYear()
		{	return year;	}
		void print()
		{ 	cout << "> Birthday: "<< month << '/' << day << '/' << year << endl;	}

};

#endif
