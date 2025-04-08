//*****************
//Program Name: Assignment 4
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: Develops and manipulates data about polling places
//*****************

#include <iostream>
#include <fstream>
using namespace std;

//constants
const int SIZE = 3;

//defining the struct
struct PollingPlace
{
	string address;
	string location;
	int numMachines;
	int numVoters;
};

//f(x) prototypes
PollingPlace PopulatePollingPlace();
void OutputPollingPlace(const PollingPlace &);

//main f(x)
int main()
{
	//declarations
	PollingPlace myPollingPlace = PopulatePollingPlace();
	ifstream fin("data.txt");
	string inAddress, inLocation;
	int inNumMachines, inNumVoters, index = 0;
	PollingPlace importedData[SIZE];

	//outputs data input by user
	cout << "\n--- Polling Place Data ---\n" << "\t>> Your Data:\n";
	OutputPollingPlace(myPollingPlace);

	//outputs data from file
	cout << "\n\t>> Imported Data:\n";
	while (getline(fin, inAddress)) //reads data from data.txt
	{
		getline(fin, inLocation);
		fin  >> inNumMachines;
		fin.ignore();
		fin  >> inNumVoters;
		fin.ignore();

		PollingPlace temp;
		temp.address = inAddress;
		temp.location = inLocation;
		temp.numMachines = inNumMachines;
		temp.numVoters = inNumVoters;

		importedData[index++] = temp;
	}
	for (int i = 0; i < SIZE; i++) //outputs data from data.txt
	{
		cout << "\t\t   " << i+1 << endl;
		OutputPollingPlace(importedData[i]);
	}

	//plagiarism pledge
	cout << "\n\nI attest that this code is my original programming work, and that I received"
		 <<	"\nno help creating it. I attest that I did not copy this code or any portion of this"
		 <<	"\ncode from any source.";

	fin.close();
	return(0);
};

//*****************
//Function name: PopulatePollingPlace
//Purpose: gets user input and assigns it to the temporary structure
//Parameters: none
//Returns: returns a temp struct to for a struct in the main function to be defined by
//Return type: PollingPlace
//*****************
PollingPlace PopulatePollingPlace()
{
	PollingPlace temp;

	//gets information from user
	cout << "\t>> Enter a the street address: ";
	getline(cin, temp.address);
	cout << "\t>> Enter the location of the polling place: ";
	getline(cin, temp.location);
	cout << "\t>> Enter the number of voting machines: ";
	cin  >> temp.numMachines;
			while (temp.numMachines < 0) //input validation for numMachines
			{
				cout << "\t>> ERROR... please enter a positive number: ";
				cin  >> temp.numMachines;
			}
	cout << "\t>> Enter the expected number of voters: ";
	cin  >> temp.numVoters;
			while (temp.numVoters < 0) //input validation for numVoters
			{
				cout << "\tERROR... please enter a positive number: ";
				cin  >> temp.numVoters;
			}
	return(temp);
};

//*****************
//Function name: OutputPollingPlace
//Purpose: outputs the structure sent to the function
//Parameters: PollingPlace
//Returns: n/a
//Return type: void
void OutputPollingPlace(const PollingPlace &p)
{
	cout << "\t\t>> Address: " << p.address << endl
		 << "\t\t>> Location: " << p.location << endl
		 << "\t\t>> Number of Voting Machines: " << p.numMachines << endl
		 << "\t\t>> Expected number of voters: " << p.numVoters << endl;
};
