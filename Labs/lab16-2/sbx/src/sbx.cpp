/*
 * Program Name: lab 16-2
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: using lambda expressions to manipulate various data structures
 */

//functors / function objects
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <list>
using namespace std;

//IsEven Definition
class IsEven
{
public:
    bool operator() (int x)
    { return x % 2 == 0; }
};

int main()
{
    //test vector using algorithm::count_if and our lambda expression
    vector<int> vec = {1,2,3,4,5,6,7,8,11,14,17,20,24,28,32,37,42};
    //lambda expression definition, bound to variable isEven
    auto isEven = [](int x) { return x % 2 == 0; };
    int evenNums = count_if(vec.begin(), vec.end(), isEven);
    cout << "Vector has " << evenNums << " even numbers:\n";
    for (auto val : vec)
        if (isEven(val))
            cout << val << " ";
    cout << endl;

    //***********my code************//
    //***********block 1************//
		//declarations
    	auto Ascii = [](int x) { cout << (char)x << " "; };
    	vector<int> myNums = { 67, 68, 69, 70, 72, 73, 74, 75, 76, 77 };
    	cout << "\nOriginal Vector:\n";
    	for (auto val : myNums) cout << val << " ";
    	//converts each number to a corresponding ascii value
    	cout << "\nConverting Vector to ASCII Characters:\n";
    	for_each(myNums.begin(), myNums.end(), Ascii);
    //***********block 2************//
    	//declarations
    	auto addTax = [](float x) { return x+=(x*.07); };
    	list<float> bills = { 7.50, 10, 12.50, 15.75, 21.40 };
    	cout << "\n\nRestraunt bills before tax:\n";
    	for (auto val : bills) cout << '$' << fixed << setprecision(2) << val << " ";
    	//adds a 7% tax to each bill and calculates the new total
    	transform(bills.begin(), bills.end(), bills.begin(), addTax);
    	cout << "\nAdding 7% tax to each bill:\n";
    	for (auto val : bills) cout << '$'<< fixed << setprecision(2) << val << " ";
    //***********block 3************//
    	//declarations
    	auto combineStrings = [](string x) { static string sentence; return (sentence += (x + ' ')); };
    	vector<string> words = { "My", "name", "is", "Jordan", ":)" };
    	cout << "\n\nIndividual words before being combined into one string:\n";
    	for (auto val : words) cout << "\t- " << val << endl;
    	transform(words.begin(), words.end(), words.begin(), combineStrings);
    	cout << "\nAfter being combined:\n";
    	string combinedSentence = words[words.size() - 1];
    	cout << combinedSentence;
    //******************************//
    return 0;
}


//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge() {
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
