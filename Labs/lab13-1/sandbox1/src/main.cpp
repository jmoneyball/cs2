/*
 * Program Name: lab 13-1
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: reading words from an input file into a set
 */

//preprocessor directives
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

//function prototypes
void plagiarismPledge();

//main function
int main() {
	//declarations
	set<string> words;
	set<string>::iterator it;
	ifstream fin("words.txt");
	string read;

	//reading into set
	while(fin >> read) words.insert(read);

	//using RBFL
	cout << "Unique words in the list (using RBFL):\n";
	for(auto it: words) cout << it << endl;

	//using iterator
	cout << "\nUnique words in the list (using iterator):\n";
	for(it = words.begin(); it != words.end(); it++) cout << *it << endl;

	//checking for words
	cout << "\nChecking for specific values:";

	bool flag = false;
	cout << "\n\tcertain: ";
	for(auto it: words) if(it == "certain") flag = true;
	if (flag == true) cout << "found"; else cout << "not found";

	flag = false;
	cout << "\n\twait: ";
	for(auto it: words) if(it == "wait") flag = true;
	if (flag == true) cout << "found"; else cout << "not found";

	flag = false;
	cout << "\n\tyardstick: ";
	for(auto it: words) if(it == "yardstick") flag = true;
	if (flag == true) cout << "found"; else cout << "not found";

	flag = false;
	cout << "\n\tcapitol: ";
	for(auto it: words) if(it == "capitol") flag = true;
	if (flag == true) cout << "found"; else cout << "not found";

	flag = false;
	cout << "\n\tcry: ";
	for(auto it: words) if(it == "cry") flag = true;
	if (flag == true) cout << "found"; else cout << "not found";


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
