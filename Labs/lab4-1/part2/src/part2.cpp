//*****************
//Program Name: lab 4-2
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: manipulates and displays an array using various functions
//*****************

#include <iostream>
using namespace std;

//constants
const int SIZE = 10;

//prototypes
void enterArrayData(int *);
void outputArrayData(int *);
void sumArray(int *);

//main function
int main()
{
	//declarations
	int myArray[SIZE] = {0};
	int *arrayPtr = myArray;

	enterArrayData(arrayPtr);
	outputArrayData(arrayPtr);
	sumArray(arrayPtr);

	//plagiarism pledge
	cout << "\n\nI attest that this code is my original programming work, and that I received"
		 <<	"\nno help creating it. I attest that I did not copy this code or any portion of this"
		 <<	"\ncode from any source.";

	return(0);
};

//*****************
//Function name: enterArrayData
//Purpose: allows user to input data into an array
//Parameters: pointer to myArray
//Returns: n/a
//Return type: void
//*****************
void enterArrayData(int *array)
{
	int userInput;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter an integer to assign to array index " << i + 1 << ": ";
		cin  >> userInput;
		*array = userInput;
		*array++;
	}
};

//*****************
//Function name: outputArrayData
//Purpose: outputs the data of the array pointer sent to the function
//Parameters: pointer to myArray
//Returns: n/a
//Return type: void
//*****************
void outputArrayData(int *array)
{
	cout << "The elements in the array are ";
	for (int k = 0; k < SIZE - 1 ; k++)
	{
		cout << *array << ", ";
		*array++;
	};
	cout << "and " << *array << endl;
}

//*****************
//Function name: sumArray
//Purpose: adds the values in the array and outputs them to console
//Parameters: pointer to myArray
//Returns: n/a
//Return type: void
//*****************
void sumArray(int *array)
{
	int counter = 0; //counter variable
	for (int j = 0; j < SIZE; j++)
	{
		counter += *array;
		*array++;
	};
	cout << "The sum of all of these elements is " << counter;
}
