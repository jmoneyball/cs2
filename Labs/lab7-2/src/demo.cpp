/*
Program Name: lab 7-2
Author: Jordan Johnson
IDE Used: Eclipse
Program description: creates and outputs a superstring array
*/

/* preprocessor directives */
#include <iostream>
#include "Superstring.h"
using namespace std;


/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	/* declarations */
	int numStrings;
	string stringInput;

	/* sends user specified number to be declared as the number of strings */
	cout << "How many strings do you want to store? ";
	cin  >> numStrings;
	cin.ignore();
	Superstring userStrings(numStrings);

	/* sends user input strings to be added to the stringStorage array */
	cout << "Enter the " << numStrings << " strings below: " << endl;
	for (int i = 0; i < numStrings; i++)
	{
		cout << "\tString " << i + 1 << ": ";
		getline(cin, stringInput);
		userStrings.setString(stringInput, i);
	}

	/* outputs the strings and data about the strings to the user */
	cout << "\n---------------------------------\n\n"
		 << "Here are the strings you entered:\n";
	for (int j = 0; j < numStrings; j++)
		cout << "String " << j + 1<< ": " << userStrings.getString(j) << endl;
	cout << "Alphabetically this string comes first: " << userStrings.getFirst() << endl
		 << "Alphabetically this string comes last: " << userStrings.getLast() << endl;

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
