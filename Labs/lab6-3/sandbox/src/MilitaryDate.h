/*
 * MilitaryDate.h
 * sandbox
 *
 * Jordan Johnson
 */

/* preprocessor directives */
#ifndef MILITARYDATE_H
#define MILITARYDATE_H
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * _______________________
 * MilitaryDate
 * _______________________
 * - day : int
 * - month : int
 * - year : int
 * _______________________
 * + MilitaryDate()
 * + MilitaryDate(d: int, m: string, y: int)
 * + setDay(d: int): void
 * + setMonth(m: string): void
 * + setYear(y: int): void
 * + getDay(): int
 * + getMonth(): string
 * + getYear(): int
 * + print(): void
 * _______________________
 */

class MilitaryDate
{
	private:
		int day, year;
		string month;
	public:
		MilitaryDate();
		MilitaryDate(int, string, int);
		void setDay(int d)
			{ day = d; }
		void setMonth(string m)
			{ month = m; }
		void setYear(int y)
			{ year = y; }
		int getDay()
			{ return day; }
		string getMonth()
			{ return month; }
		int getYear()
			{ return year; }
		void print()
			{ cout << setw(2) << setfill ('0') << day << month << year << endl; }
};

#endif/* MILITARYDATE_H */;
