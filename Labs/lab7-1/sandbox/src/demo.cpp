/*
Program Name: lab 7-1
Author: Jordan Johnson
IDE Used: Eclipse
Program description: reads objects from a file to put into an array of objects
*/

/* preprocessor directives */
#include <iostream>
#include <fstream>
#include "Movie.h"
using namespace std;

/* constants */
const int SIZE = 4;

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	/* declarations */
	Movie *myMovies = new Movie[SIZE];
	int count = 0;
	ifstream fin ("input.txt");


	/* temporary variables to read from file */
	string tempSW, tempT;
	int tempYR;
	/* reads input from file and assigns it to array */
	while (getline(fin, tempSW))
	{
		fin >> tempYR;
		fin.ignore();
		getline(fin, tempT);
		myMovies[count].setScreenWriter(tempSW);
		myMovies[count].setYearReleased(tempYR);
		myMovies[count].setTitle(tempT);
		/* increments counter variable*/
		count++;
	}

	/* outputs array to console */
	cout << "This program will create several objects depicting movies.\n"
		 << "Reading input file...\n"
		 << "...done.";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "\nMovie: " << myMovies[i].getTitle()
			 << "\n\t> Year released: " << myMovies[i].getYearReleased()
			 << "\n\t> Screenwriter: " << myMovies[i].getScreenWriter();
	}

	/* ends program */
	delete [] myMovies;
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
