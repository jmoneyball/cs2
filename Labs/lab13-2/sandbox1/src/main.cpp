/*
 * Program Name: lab 13-2
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: STL deque demo code
 */

//preprocessor directives
#include <iostream>
#include <ctime>
#include <deque>
using namespace std;

//constants
const int MIN = 0, MAX1 = 1, MAX2 = 2, SIZE = 5, ITERATIONS = 15;

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	int nextCustomer = 0, coinToss;
	string names[] = {"Joe", "Jen", "Job", "Jya", "Jed", "Jim", "Jet",
					  "Jai", "Jay", "Jan", "Jin", "Jae", "Jax", "Jad", "Jao",
					  "Joo", "Jiu", "Jef" };
	deque <string> line, temp;
	srand(time(0));

	//creates initial queue of size 5
	cout << "Initial line:\n";
	for (int i = 0; i < SIZE; i++) {
			line.push_back(names[i]);
			cout << names[i] << " ";
			nextCustomer++;
		}

	//performs 15 operations
	for (int i = 0; i < ITERATIONS; i++) {
		//50/50 chance to pop/push a customer in the queue
		if (!line.empty())
			coinToss = rand() % (MAX2 - MAX1 + 1) + MAX1;
		else coinToss = 1;

		//if coinToss == 1, add a customer
		if (coinToss == 1) {
			coinToss = rand() % (MAX2 - MIN + 1) + MIN;

			//if coinToss == 0, 1, add customer to back
			if(coinToss == 0 || coinToss == 1) {
				cout << "\n\nNow adding " << names[nextCustomer] << " to the back of the line.\n";
				line.push_back(names[nextCustomer]);
				nextCustomer++;
				temp = line;
				//print line
				for (int j = 0; j < line.size(); j++) {
					cout << temp.front() << " ";
					temp.pop_front();
				}
			}
			else { //if coinToss == 2, add a customer to the front
				cout << "\n\nNow adding Special Customer " << names[nextCustomer] << " to the front of the line.\n";
				line.push_front(names[nextCustomer]);
				nextCustomer++;
				temp = line;
				//print line
				for (int j = 0; j < line.size(); j++) {
					cout << temp.front() << " ";
					temp.pop_front();
				}
			}
		}
		//if coinToss == 2, serve a customer
		else if (coinToss == 2) {
			coinToss = rand() % (MAX2 - MIN + 1) + MIN;

			//if coinToss == 0, 1, serve customer at the front
			if(coinToss == 0 || coinToss == 1) {
				cout << "\n\nNow serving " << line.front() << " at the front of the line.\n";
				line.pop_front();
				temp = line;
				//print line
				for (int j = 0; j < line.size(); j++) {
					cout << temp.front() << " ";
					temp.pop_front();
				}
			}
			else { //if coinToss == 2, serve a customer at the back
				cout << "\n\nNow serving VIP customer " << line.back() << " at the back of the line.\n";
				line.pop_back();
				temp = line;
				//print line
				for (int j = 0; j < line.size(); j++) {
					cout << temp.front() << " ";
					temp.pop_front();
				}
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
