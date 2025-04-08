/*
Program Name: program11
Author: Jordan Johnson
IDE Used: Eclipse
Program description: uses multiple inheritance to create objects with data that comes from multiple classes
*/

/* preprocessor directives */
#include "ReaderApp.h"

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	//declaring ReaderApp objects
	ReaderApp kindle("J.K. Rowling", 1997, "Kindle Fire", "FireOS", 32, "Kindle Reader", 2.99);
	ReaderApp audible("Michelle Obama", 2018, "iPad", "iOS 14", 64, "Audible", 0);
	ReaderApp iBooks("Suzane Collins", 2008, "iPhone 6", "iOS 7", 32, "iBooks", 0.99);
	ReaderApp adobe("Tony Gaddis", 2015, "Galaxy Tablet S6", "Android", 128, "Adobe Acrobat", 3.99);

	//printing objects
	cout << "Reading 'Harry Potter and the Sorcerer's Stone' on a Kindle Fire:" << endl;
	kindle.print();
	cout << endl;
	cout << "Reading 'Becoming' on an iPad:" << endl;
	audible.print();
	cout << endl;
	cout << "Reading 'The Hunger Games' on an old iPhone:" << endl;
	iBooks.print();
	cout << endl;
	cout << "Reading 'Starting Out with C++' on a Galaxy Tablet:" << endl;
	adobe.print();

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
