/*
Program Name: lab 7-3
Author: Jordan Johnson
IDE Used: Eclipse
Program description: simulates a magic 8 ball
*/

/* preprocessor directives */
#include <iostream>
#include <iomanip>
#include <ctime>
#include "magic8ball.h"
using namespace std;

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	/* declarations */
	Magic8Ball my8Ball;
	float userResults[SIZE] = {0};
	srand(time(0));

	/* initializes answersIndex with a random value */
	Magic8Ball();

	/* shakes my8Ball 10000 times */
	for (int i = 0; i < SHAKES; i++)
	{
		my8Ball.shake();
		userResults[my8Ball.getAnswersIndex() - 1]++;

	}

	/* outputs results and statistics from the 10000 shakes */
	cout << "*** RESULTS ***\n\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Answer " << i + 1 << ": " << fixed << setprecision(0) << userResults[i] << "/" << SHAKES << " (" << fixed
			 << setprecision(2) << (userResults[i]) / 100 << "%) " << '"' << my8Ball.getAnswer(i) << '"' << endl;
	}

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
