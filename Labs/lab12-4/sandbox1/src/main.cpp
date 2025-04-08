/*
 * Program Name: lab 12-4
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: similuates a starbucks line using STL queue
 */

//preprocessor directives
#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

//constants
const int SIZE = 5, ITERATIONS = 15, MIN = 1, MAX = 2;

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	queue <string> line, temp;
	string names[] = {"Joe", "Jen", "Job", "Jya", "Jed", "Jim", "Jet",
					  "Jai", "Jay", "Jan", "Jin", "Jae", "Jax", "Jad", "Jao",
					  "Joo", "Jiu", "Jef"};
	int nextCustomer = 0, coinToss;
	srand(time(0));

	//creates initial queue of size 5
	cout << "Initial line:\n";
	for (int i = 0; i < SIZE; i++) {
			line.push(names[i]);
			cout << names[i] << " ";
			nextCustomer++;
		}

	//performs 15 operations
	for (int i = 0; i < ITERATIONS; i++) {
		//50/50 chance to pop/push a customer in the queue
		if (!line.empty())
			coinToss = rand() % (MAX - MIN + 1) + MIN;
		else coinToss = 2;

		//if coinToss == 1, pop from line
		if (coinToss == 1) {
			cout << "\n\nNow serving " << line.front() << " at the front of the line.\n";
			line.pop();
			temp = line;
			//print line
			for (int j = 0; j < line.size(); j++) {
				cout << temp.front() << " ";
				temp.pop();
			}
		}
		//if coinToss == 2, push into line
		else {
			cout << "\n\nNow adding " << names[nextCustomer] << " to the back of the line.\n";
			line.push(names[nextCustomer]);
			nextCustomer++;
			temp = line;
			//print line
			for (int j = 0; j < line.size(); j++) {
				cout << temp.front() << " ";
				temp.pop();
			}
		}
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
