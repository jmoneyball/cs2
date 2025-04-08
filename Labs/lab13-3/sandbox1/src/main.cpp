/*
 * Program Name: lab 13-3
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: STL map demo code
 */

//preprocessor directives
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <vector>
#include <map>
using namespace std;

//function prototypes
void plagiarismPledge();

//constants
const int W = 20, MIN = 0, MAX = 49, SIZE = 5;

//main function
int main() {
	//declarations
	int score = 0, randState;
	string state, capital, answer;
	vector <string> states;
	map <string, string> flashCards;
	ifstream fin ("input.txt");
	srand(time(0));

	//reading input file into map
	while (getline(fin, capital)) {
		getline(fin, state);
		states.push_back(state);
		flashCards.emplace(state, capital);
	}

	//output states w/ capitols
	cout << "I am going to ask you for the capitals of 5 states...\n\n"
		 << left << setw(W) << "State" << "Capital\n\n";
	for(auto it: flashCards) cout << setw(W) << it.first << setw(W) << it.second << endl;

	//quiz
	cout << "\n\n/* QUIZ TIME */\n\n";

	for(int i = 0; i < SIZE; i++) {
		randState = rand() % (MAX - MIN + 1) + MIN;

		cout << "What is the capital of " << states[randState] << "? ";
		getline(cin, answer);

		map<string, string>::iterator it = flashCards.find(states[randState]);

		if(answer == it -> second) {
			cout << "Correct!\n\n";
			score++;
		}
		else cout << "Sorry, that's incorrect; the correct answer is " << it -> second << ".\n\n;
	}

	//output final score
	cout << "/* QUIZ STATISTICS */\n"
		 << "Correct answers: " << score << endl
		 << "Incorrect answers: " << SIZE - score;

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
