/*
Program Name: lab 8-1
Author: Jordan Johnson
IDE Used: Eclipse
Program description: fills different collections with various data using a template
*/

/* preprocessor directives */
#include <iostream>
#include <ctime>
#include "Collection.h"
using namespace std;
/* constant */
const int SIZE = 5, MIN = 65, MAX = 122, DIV = 999;

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	/*declarations */
	srand(time(0));
	/* initializes a Collection for each data type */
	Collection<int> myInts(SIZE, 0);
	Collection<double> myDoubles(SIZE, 0.0);
	Collection<char> myChars(SIZE, 'a');
	Collection<string> myStrings(SIZE, "");

	/* fills int, double, and char Collections w/ random data */
	for (int i = 0; i < SIZE; i++)
	{
		myInts.push(rand() % (MAX - MIN + 1) + MIN);
		myChars.push(rand() % (MAX - MIN + 1) + MIN);
		myDoubles.push((rand() % (MAX - MIN + 1) + MIN) / (float)DIV);
	}
	/* fills string Collections with movie quotes */
	myStrings.push("May the Force be with you.");
	myStrings.push("I'm going to make him an offer he can't refuse.");
	myStrings.push("You talkin' to me?.");
	myStrings.push("Why so serious?");
	myStrings.push("I see dead people.");

	/* example use of setValue() member function */
	myInts.setValue(90210, 3);
	myStrings.push("I'll be back.");

	/* outputs Collections */
	cout << "Integers:\n";
	myInts.print();
	cout << "\nDoubles:\n";
	myDoubles.print();
	cout << "\nCharacters:\n";
	myChars.print();
	cout << "\nStrings:\n";
	myStrings.print();

	/* ends program */
	plagiarismPledge();
	return(0);
}

/*
Function name: plagiarismPledge
Purpose: function to simply output the plagiarism pledge at the end of the program
Parameters: none
Returns: none
Return type: void
*/
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
