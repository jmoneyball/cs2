/*
 * Program Name: lab 16-1
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: using functors to manipulate a vector
 */

//functors / function objects
#include <iostream>
#include <algorithm>
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

//***********my functors***************
//Double Definition
class Double
{
public:
	int operator() (int x)
	{ return 2*x; }
};

//Decrement Definition
class Decrement
{
public:
	int operator() (int x)
	{ return x-1; }
};

//AddAll Definition
class AddAll
{
public:
	int operator() (int x)
	{
	  static int sum;
	  return sum += x; }
};
//*************************************

int main()
{
    //test vector using algorithm::count_if and our lambda expression
    vector<int> vec = {1,2,3,4,5,6,7,8,11,14,17,20,24,28,32,37,42};
    cout << "Vector: ";
    for (auto val : vec) cout << val << " ";
    cout << endl;

    //lambda expression definition, bound to variable isEven
    IsEven isNumberEven;
    list<int> evens;
    int evenNums = count_if(vec.begin(), vec.end(), isNumberEven);
    int evenNums2 = count_if(vec.begin(), vec.end(), IsEven()); // anonymous functor
    cout << "Vector has " << evenNums << " even numbers: ";
    for (auto val : vec)
        if (val % 2 == 0)
            evens.push_back(val);
    for (auto val : evens) cout << val << " ";
    cout << endl;
    cout << "evenNums2 is: " << evenNums2 << endl << endl;

    //demo double functor
    Double doubleNum;
    cout << "Doubling each number in the vector:\n";
    transform(vec.begin(), vec.end(), vec.begin(), doubleNum); //doubles each number of the vector
    for (auto val : vec) cout << val << " "; //outputs each number

    //demo decrement functor
    Decrement decrementNum;
    cout << "\n\nDecrementing each number in the vector:\n";
    transform(vec.begin(), vec.end(), vec.begin(), decrementNum); //Subtracts 1 from each number of the vector
    for (auto val : vec) cout << val << " "; //outputs each number

    //demo addAll functor
    AddAll addAllNums;
    cout << "\n\nAdding all numbers in the vector:\n";
    transform(vec.begin(), vec.end(), vec.begin(), addAllNums); //adds all numbers in the vector
    cout << vec[vec.size() - 1]; //prints the last number in the vector (total sum of all previous numbers)

    return 0;
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge() {
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
