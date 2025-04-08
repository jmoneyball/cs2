/*
 * Program Name: lab 6-3
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: outputs dates in military format using a class
 */

/* preprocessor directives */
#include <iostream>
#include <fstream>
#include "MilitaryDate.h"
using namespace std;

/* constants */
const int SIZE = 6;

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	/* declarations */
	MilitaryDate dates[SIZE] = { MilitaryDate(26, "FEB", 2001), /* uses constructors to initialize */
								MilitaryDate(21, "DEC", 1970),  /* the first 3 military dates in array */
								MilitaryDate(8, "AUG", 1972)    };
	ifstream fin ("input.txt");
	int dateDay, dateYear;
	string dateMonth;

	/* welcome message */
	cout << "Welcome!\n"
		 << "This program will output a few different dates in military format.\n"
		 << "Reading input file... Done!\n\n";

	/* initializes last 3 dates to zero */
	for (int i = SIZE/2; i < SIZE; i++)
		dates[i] = MilitaryDate();

	/* using accessors to set last 3 dates*/
	for (int j = SIZE/2; j < SIZE; j++) /* reads input from file */
	{
		fin >> dateDay;
		fin >> dateMonth;
		fin >> dateYear;
		dates[j].setDay(dateDay);
		dates[j].setMonth(dateMonth);
		dates[j].setYear(dateYear);
	}

	/* prints all dates */
	for (int k = 0; k < SIZE; k++)
		dates[k].print();

	/* ends program */
	fin.close();
	plagiarismPledge();
	return(0);
}

/*
 * Function name: plagiarismPledge
 * Purpose: function to simply output the plagiarism pledge at the end of the program
 * Parameters: none
 * Returns: none
 * Return type: void
 */
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
