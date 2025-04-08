/*
Program Name: lab 11-1
Author: Jordan Johnson
IDE Used: Eclipse
Program description: demonstration of simple inheritance
*/

/* preprocessor directives */
#include "Chair.h"

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	Chair barstool("Sears", 1992, 4, "blue");
	barstool.printChair();

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
