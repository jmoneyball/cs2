/*
 * Program Name: lab 15-1
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: uses c++ exceptions to handle errors when getting input from a user
 */

//preprocessor directives
#include "Date.h"

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	bool again = true;
	int month, day, year;
	Date myDate;

	cout << "Please enter the following:\n"
		 << "\t> Month: ";
	cin  >> month;
	cout << "\t> Day: ";
	cin  >> day;
	cout << "\t> Year: ";
	cin  >> year;

	//while loop that repeats to handle arrors as necessary
	while(again) {
		try {
			myDate.setMonth(month);
			myDate.setDay(day);
			myDate.setYear(year);
			again = false;
		}
		catch (Date :: IncorrectMonth&) {
			cout << "Error,	number outside of 1-12 entered for month.\n";
			cout << "Reenter: ";
			cin >> month;
		}
		catch (Date :: IncorrectDay&) {
			cout << "Error,	number outside of 1-" << myDate.getDaysInMonth() << " entered for day.\n";
			cout << "Reenter: ";
			cin >> day;
		}
	}

	//outputting myDate
	cout << "The date you entered can be written as:\n";
	cout << "\t> ";
	myDate.showDate1();
	cout << "\t> ";
	myDate.showDate2();
	cout << "\t> ";
	myDate.showDate3();

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
