/* Date class implementation */
#include "Date.h"

Date :: Date(int m, int d, int y)
{
	if (m <= 0 || m > 12)
	{
		cout << "ERROR... month must be a number 1-12";
		exit(EXIT_FAILURE);
	}
	else month = m;
	if (d <= 0 || d > 31)
	{
		cout << "ERROR... day must be a number 1-31";
		exit(EXIT_FAILURE);
	}
	else day = d;
	if (y <= 0)
	{
		cout << "ERROR... year must be a positive number";
		exit(EXIT_FAILURE);
	}
	else year = y;
};

void Date :: setMonth(int month)
{
	if (month <= 0 || month > 12)
	{
		cout << "ERROR... month must be a number 1-12";
		exit(EXIT_FAILURE);
	}
	else this -> month = month;
}

void Date :: setDay(int day)
{
	if (day <= 0 || day > 31)
	{
		cout << "ERROR... day must be a number 1-31";
		exit(EXIT_FAILURE);
	}
	else this -> day = day;
}

void Date :: setYear(int year)
{
	if (year <= 0)
	{
		cout << "ERROR... year must be a positive number";
		exit(EXIT_FAILURE);
	}
	else this -> year = year;
}
