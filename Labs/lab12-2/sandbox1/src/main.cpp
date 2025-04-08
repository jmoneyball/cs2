/*
Program Name: lab 12-2
Author: Jordan Johnson
IDE Used: Eclipse
Program description: uses class aggregation to create a date object using the person class
*/

/* preprocessor directives */
#include "Person.h"

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	//creates different date and person objects
	Date jordanBD(2, 26, 2001);
	Person jordan(123456789, jordanBD);
	Date mikeBD(12, 21, 1970);
	Person mike(987654321, mikeBD);
	Date heatherBD(7, 18, 1972);
	Person heather(192837465, heatherBD);
	Date laurenBD(10, 16, 2002);
	Person lauren(564738291, laurenBD);

	//outputs the person objects
	cout << "Info for Jordan: " << endl;
	jordan.print();
	cout << "\nInfo for Mike: " << endl;
	mike.print();
	cout << "\nInfo for Heather: " << endl;
	heather.print();
	cout << "\nInfo for Lauren: " << endl;
	lauren.print();

	/* ends program */
	plagiarismPledge();
	return(0);
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
