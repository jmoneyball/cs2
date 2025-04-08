//*****************
//Program Name: Assignment 5
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: Creates and stores a vector of structs
//*****************

#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

struct Color
{
	int r; //red
	int g; //green
	int b; //blue
};

//constants
const int AMT_MIN = 5, AMT_MAX = 50, RGB_MIN = 0, RGB_MAX = 255;

int main ()
{
	//declarations
	srand(time(0));
	vector <Color> myColors;
	int numColors = rand() % (AMT_MAX - AMT_MIN + 1) + AMT_MIN; //generates amount between 5 and 50

	//outputs headers
	cout << setw(10) << "Color#" << setw(10) << "R value" << setw(10) << "G value" << setw(10) << "B value" << endl
		 << setw(10) << "------" << setw(10) << "-------" << setw(10) << "-------" << setw(10) << "-------" << endl;

	//pushes random color values into myColors vector
	for(int i = 0; i < numColors; i++)
	{
		int R = rand() % (RGB_MAX - RGB_MIN + 1) + RGB_MIN; //populates ints with random numbers
		int G = rand() % (RGB_MAX - RGB_MIN + 1) + RGB_MIN;
		int B = rand() % (RGB_MAX - RGB_MIN + 1) + RGB_MIN;

		Color tempColor = {R, G, B}; //assigns random numbers to a temp struct
		myColors.push_back(tempColor);
	};

	//outputs random numbers in columns/rows
	for(int j = 0; j < myColors.size(); j++)
	{
		cout << right << setw(8) << j + 1
			 << setw(10) << myColors[j].r
			 << setw(10) << myColors[j].g
			 << setw(10) << myColors[j].b
			 << endl;
	};

	//plagiarism pledge
	cout << "\n\nI attest that this code is my original programming work, and that I received\n"
		 << "no help creating it. I attest that I did not copy this code or any portion of this\n"
		 << "code from any source.";

	return(0);
}
