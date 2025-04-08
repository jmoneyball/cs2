/*
 * Program Name: lab 12-3
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: redefining a base class function
 */

//preprocessor directives
#include "Theater.h"

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	Venue myVenue("Public Venue", 1999, 250, 20.50);
	Theater myTheater("Private Venue", 2007, 500, 32.50, "The Vine",
					  "123 First Street", "Livermore, CA 94550", 1250.50);

	cout << "Venue:\n";
	myVenue.print();
	cout << "\n\t> Potential revenue: $" << myVenue.potRev();

	cout << "\n\nTheater:\n";
	myTheater.print();
	cout << "\n\t> Potential revenue: $" << myTheater.potRev();

	//ends program
	plagiarismPledge();
	return(0);
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge() {
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
