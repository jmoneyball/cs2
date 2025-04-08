/*
 Program Name: Lab 5
 Author: Jordan Johnson
 IDE Used: Eclipse
 Program description: reads restaurant data from an input file and outputs
 	 	 	 	 	  it to a console using various pointers to dynamically allocated arrays
*/

#include <iostream>
#include <fstream>
using namespace std;

/* constant integers */
const int RESTAURANTS = 3, REVIEWS = 3;

/* structure declaration */
struct Restaurant
{
	string name;
	int zip;
	float *reviews;
	string *comments;
	~ Restaurant()
	{
		if (reviews) delete [] reviews;
		reviews = nullptr;
		if (comments) delete [] comments;
		comments = nullptr;
	};
};

/* function prototypes */
void getRestaurantData(Restaurant *, ifstream &);
void outputRestaurantData(Restaurant*);

/* main function */
int main ()
{
	/* declarations */
	Restaurant *restaurantData = new Restaurant[RESTAURANTS];
	ifstream inFile ("input.txt"); /* opens input file */

	/* gathers data from input file */
	for (int i = 0; i < RESTAURANTS; i++)
		getRestaurantData((restaurantData + i), inFile); /* sends input file to function */

	/* outputs data to console */
	cout << "Reading restaurant data...done.\n\n";
	for (int j = 0; j < RESTAURANTS; j++)
		outputRestaurantData(restaurantData + j);

	/* plagiarism pledge */
	cout << "\n\nI attest that this code is my original programming work, and that I received\n"
		 << "no help creating it. I attest that I did not copy this code or any portion of this\n"
		 << "code from any source.";

	inFile.close(); /* closes input file */
	delete [] restaurantData;
	return(0);
}

/*
Function name: getRestaurantData
Purpose: gathers data from the input file to enter into the dynamic array being pointed to by restaurantData
Parameters: pointer to dynamic array of type Restaurant (struct)
Returns: n/a
Return type: void
*/
void getRestaurantData(Restaurant *rptr, ifstream &fin)
{
	/* creates dynamic arrays for struct pointers*/
	rptr -> reviews = new float[REVIEWS];
	rptr -> comments = new string[REVIEWS];

	/* sequentially gathers information from input file*/
	getline(fin, rptr -> name);
	fin >> rptr -> zip;
	for (int j = 0; j < REVIEWS; j++)
	{
		fin >> rptr -> reviews[j];
		fin.ignore();
		getline(fin, rptr -> comments[j]);
	};
};

/*
Function name: outputRestaurantData
Purpose: outputs the data from the dynamic array being pointed to by restaurantData
Parameters: pointer to dynamic array of type Restaurant (struct)
Returns: n/a
Return type: void
*/
void outputRestaurantData(Restaurant *rptr)
{
	cout << "Restaurant summary:\n"
		 << "\t> Name: " << rptr -> name << endl
		 << "\t> Zip: " << rptr -> zip << endl;

	/* outputs reviews with their corresponding comments */
	for (int k = 0; k < REVIEWS; k++)
		cout << "\t> Review #" << k + 1 << ": "<< rptr -> reviews[k] << " -- " << rptr -> comments[k] << endl;
};
