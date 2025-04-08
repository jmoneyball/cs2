//*****************
//Program Name: Assignment 3
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: Array searching/sorting with random numbers
//*****************

#include <iostream>
#include <ctime>
#include <array>
#include <algorithm>
using namespace std;

//declared constants
const int MIN = 100, MAX = 1000, SIZE = 50;

int binarySearch(int array[], int value);

int main()
{
	//declarations
	int choice;
	srand(time(0));
	array <int, SIZE> randomNumber = {};

	//populates array with random numbers
	for (int i = 0; i < SIZE; i++)
		randomNumber[i] = rand() % (MAX - MIN + 1) + MIN;

	//sorts array in ascending order
	sort(randomNumber.begin(), randomNumber.end());

	//outputs max and min numbers that were generated
	cout << "Max: " << randomNumber[SIZE - 1] << endl
		 << "Min: " << randomNumber[SIZE - SIZE] << endl;

	for (int i = 0; i < SIZE; i++)
		cout << randomNumber[i] << endl;

	//repeats search function until the user enters sentinel value
	do
	{
		//allows user to search the array for a specific number
		cout << "Enter search term or -99 to quit: ";
		cin  >> choice;
		//resets flag to check if search term exists
		bool found = 0;
		//uses for loop to search through randomNumber array for user choice
		for (int j = 0; j < SIZE; j++)
		{
			if (randomNumber[j] == choice)
			{
				cout << "Search term found at index " << j << endl;
				found = 1; //turns flag to true to indicate that search term has been found
			}
		}
		//if for loop returns flag as false, then outputs to user that their search term does not exist
		if (found == 0 and choice != -99)
			cout << "Search term not found." << endl;
	}  while (choice != -99);

	//plagiarism pledge
	cout << "\n\nI attest that this code is my original programming work, and that I received\n"
		 << "no help creating it. I attest that I did not copy this code or any portion of this\n"
		 << "code from any source.";

	return(0);
}
