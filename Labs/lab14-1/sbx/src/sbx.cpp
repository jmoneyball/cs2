/*
 * Program Name: lab 14-1
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: keeps track of the line numbers that each word appears in a story
 */

//preprocessor directives
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	string input, word;
	int lineCount = 1;
	ifstream fin ("story.txt");
	map <string, set<int>> wordIndex;
	map <string, set<int>> :: iterator it;

	//reading from input file
	while(getline(fin, input)) {
		istringstream line(input); //turns line into string stream
		while (line >> word) { //parses each word in the line
			string validWord = ""; //resets validWord variable
			for (int i = 0, length = word.length(); i < length; i++) {
				if(ispunct(word[i]) and word[i] != 39) { //if word contains punctuation (except "'")...
					word.erase(i--, 1);//it gets deleted
					length = word.length();
				}
				else { //turns current character in word to lowercase
					word[i] = tolower(word[i]);
					validWord += word[i];
				}
			}
			if(!wordIndex.count(validWord)) { //if the word doesn't exist in the map...
				wordIndex.emplace(validWord, set<int> {lineCount}); //add it along with the current line
			}
			else { //finds word if it exists in map...
				it = wordIndex.find(validWord);
				it -> second.insert(lineCount); //adds line number
			}
		}
		lineCount++; //iterates line counter
	}

	//final output
	cout << "*****WORD INDEX:*****\n";
	for(auto it: wordIndex) { //outputs map's word
		cout << it.first << ": ";
		for(auto it2: it.second) { //outputs set of integers within map
			cout << it2 << " ";
		}
		cout << endl;
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
