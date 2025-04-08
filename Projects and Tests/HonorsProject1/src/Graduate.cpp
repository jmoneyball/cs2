//Graduate class implementation
#include "Graduate.h"

Graduate :: Graduate(string name, int age, float GPA, string major, string goal, int gradYear)
    	  : Student(name, age, GPA, major)
{
	this -> goal = goal;

	//gradYear data valdiation
	if (gradYear < 0)
	{
		cout << "CRITICAL ERROR... gradYear must be greater than 0.";
		exit(EXIT_FAILURE);
	}
	else this -> gradYear = gradYear;
}

//setGradYear(): sets the gradYear private variable
//Arguments: gradYear(int) | Returns: void
void Graduate :: setGradYear(int gradYear)
{
	//gradYear data valdiation
	if (gradYear < 0)
	{
		cout << "CRITICAL ERROR... gradYear must be greater than 0.";
		exit(EXIT_FAILURE);
	}
	else this -> gradYear = gradYear;
}

//print(): outputs the private variables
//Arguments: none | Returns: void
void Graduate :: print()
{
	Student :: print();
	cout << "    > Goal: " << goal << " degree"<< endl
		 << "    > Graduation Year: " << gradYear << endl;
}
