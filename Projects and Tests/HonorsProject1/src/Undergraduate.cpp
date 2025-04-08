//Undergraduate class implementation
#include "Undergraduate.h"

Undergraduate :: Undergraduate(string name, int age, float GPA, string major, int year, int studentID)
			   : Student(name, age, GPA, major)
{
	//year data valdiation
	if (year < 0 || year > 4)
	{
		cout << "CRITICAL ERROR... year must be between 0 and 4.";
		exit(EXIT_FAILURE);
	}
	else this -> year = year;
	//studentID data valdiation
	if (studentID < 0)
	{
		cout << "CRITICAL ERROR... studentID must be greater than 0.";
		exit(EXIT_FAILURE);
	}
	else this -> studentID = studentID;
}

//setYear(): sets the year private variable
//Arguments: year(int) | Returns: void
void Undergraduate :: setYear(int year)
{
	//year data valdiation
	if (year < 0 || year > 4)
	{
		cout << "CRITICAL ERROR... year must be between 0 and 4.";
		exit(EXIT_FAILURE);
	}
	else this -> year = year;
}

//setStudentID(): sets the studentID private variable
//Arguments: studentID(int) | Returns: void
void Undergraduate :: setStudentID(int studentID)
{
	//studentID data valdiation
	if (studentID < 0)
	{
		cout << "CRITICAL ERROR... studentID must be greater than 0.";
		exit(EXIT_FAILURE);
	}
	else this -> studentID = studentID;
}

//print(): outputs the private variables
//Arguments: none | Returns: void
void Undergraduate :: print()
{
	Student :: print();
	cout << "    > Year: " << year << endl
		 << "    > Student ID #: " << studentID << endl;
}
