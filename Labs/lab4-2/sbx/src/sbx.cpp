//*****************
//Program Name: lab 4-2
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: reverses the numbers of an int array
//*****************

#include <iostream>
using namespace std;

//prototypes
int * reverseArray(int *);
void displayArray(int *);

const int SIZE = 10;

int main()
{
	//declarations
	int myArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//outputs original array
	cout << "Original Array: ";
	displayArray(myArray);
	//reverses original array
	int *arrayPtr = reverseArray(myArray);
	//outputs reversed array
	cout << "\nReversed Array: ";
	displayArray(arrayPtr);

	//plagiarism pledge
	cout << "\n\nI attest that this code is my original programming work, and that I received"
		 <<	"\nno help creating it. I attest that I did not copy this code or any portion of this"
		 <<	"\ncode from any source.";

	delete [] arrayPtr;
	return(0);
};

//*****************
//Function name: reverseArray
//Purpose: reverses the array sent to the function
//Parameters: int*
//Returns: array pointer
//Return type: int*
//*****************
int * reverseArray(int *array)
{
	//swaps the element from the first 5 numbers of the array with the corresponding element
	//from the last 5 numbers of the array
	for (int i = 0; i < SIZE / 2; i++)
	{
		int temp = array[(SIZE - i) - 1];
		array [(SIZE - i) - 1] = array[i];
		array[i] = temp;
	}
	return(array);
};

//*****************
//Function name: displayArray
//Purpose: displays the array sent to the function
//Parameters: int*
//Returns: n/a
//Return type: void
//*****************
void displayArray(int *ptr)
{
	for (int k = 0; k < SIZE; k++)
		cout << ptr[k] << " ";
};
