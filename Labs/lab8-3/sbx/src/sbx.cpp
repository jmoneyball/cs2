/*
Program Name: lab 8-3
Author: Jordan Johnson
IDE Used: Eclipse
Program description: program that morphs a rectangle into a square
*/

/* preprocessor directives */
#include <iostream>
#include "Square.h"
#include "Rectangle.h"
using namespace std;

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	/* declarations */
    Rectangle rec(3,6);
    Square sq(3);

    /* outputs before */
    cout << "Before morphing into a square:" << endl;
    rec.displayArea();
    sq.displayArea();

    /* morphs rectangle to a square */
    rec.morphToSquare(sq);

    /* outputs after */
    cout << "\nAfter morphing into a square:\n";
    rec.displayArea();
    sq.displayArea();

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
