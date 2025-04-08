/*
Program Name: lab 10-1
Author: Jordan Johnson
IDE Used: Eclipse
Program description: demos the new copy constructor
*/

/* preprocessor directives */
#include "Perfect.h"
#include <fstream>

//constants
const int PERFECT = 100;

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	//declarations
	int grade, counter = 0;
	string name;
	Perfect topStudents(20);
	ifstream fin ("input.txt");

	//reads input file
	while (fin >> grade)
	{
		fin >> name;
		//if student with perfect grade is read, add them to array
		if (grade == PERFECT)
		{
			counter++;
			topStudents.setStudent(counter, name);
		}
	}

	//prints the array of perfect students
	cout << "Compiling list of students with perfect grades:";
	topStudents.print(counter);

	//creates and outputs a duplicate list
	cout << "\nCreating a duplicate list with the copy constructor";
	Perfect copyStudents(topStudents, 20);
	copyStudents.print(counter);

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
