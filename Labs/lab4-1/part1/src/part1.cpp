//*****************
//Program Name: lab 4-1
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: Uses pointers instead of reference variables when sending variables to a function
//*****************

#include <iostream>
using namespace std;

//prototype
int changeValues(int *, int *);

int main()
{
	//declarations
	int a = 5, b = 10;
	int *aptr = &a, *bptr = &b;

	//output
	cout << "a + b = "<< a + b << ";\tOriginal Values: \ta = "<< a << "\tb = " << b << endl //outputs original values of a and b
		 << "a + b = "<< changeValues(aptr, bptr) << ";\tNew Values: \t\ta = "<< a << "\tb = " << b << endl; //calculates and outputs new values of a and b

	//plagiarism pledge
	cout << "\n\nI attest that this code is my original programming work, and that I received"
		 <<	"\nno help creating it. I attest that I did not copy this code or any portion of this"
		 <<	"\ncode from any source.";

	return(0);
};

//*****************
//Function name: changeValues
//Purpose: swaps two values and does various mathematical calculations with them
//Parameters: two integer values x and y
//Returns: returns new values of x and y added together
//Return type: integer
//*****************
int changeValues(int *x, int *y)
{
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}
