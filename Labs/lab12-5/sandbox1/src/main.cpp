/*
 * Program Name: lab 12-5
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: creates a container of honor roll students
 * 						from input file using STL stack
 */

//preprocessor directives
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	double GPA;
	string name;
	stack <string> honorRoll;
	ifstream fin ("input.txt");

	//reads through input file
	while (fin >> GPA >> name)
		//adds students with high GPA to stack
		if (GPA >= 3.85)
			honorRoll.push(name);

	//prints honorRoll stack
	cout << "List of students on the honor roll of 3.85 or greater:\n";
	while(!honorRoll.empty()) {
		cout << "\t> " << honorRoll.top() << endl;
		honorRoll.pop();
	}

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
