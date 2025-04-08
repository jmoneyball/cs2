/*
 * Program Name: assignment 13
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: counts the number of times each word appears in the input file
 */

//preprocessor directives
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	string word;
	int count = 1;
	ifstream fin ("story.txt");
	map <string, int> wordIndex;
	map <string, int> :: iterator it;

	//reading from input file
	while(fin >> word) {
		//string word
		string validWord = ""; //resets validWord variable
		for (int i = 0, length = word.length(); i < length; i++) {
			if(ispunct(word[i])) { //if word contains punctuation...
				word.erase(i--, 1);//it gets deleted
				length = word.length();
			}
			else { //turns current character in word to lowercase
				word[i] = tolower(word[i]);
				validWord += word[i];
			}
		}
		//int count
		if(wordIndex.count(validWord) == 1) {
			it = wordIndex.find(validWord);
			it -> second++;
		}
		wordIndex.emplace(validWord, count); //adds to map
	}

	//final output
	cout << "*****WORD INDEX:*****\n";
	for(auto it: wordIndex)
		cout << it.first << ": " << it.second << endl;

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
