//Student class implementation
#include "Student.h"

Student :: Student(string name, int age, float GPA, string major)
		 : Person(name, age)
{
	//GPA data valdiation
	if (GPA < 0 || GPA > 4)
	{
		cout << "CRITICAL ERROR... GPA must be between 0.0 and 4.0";
		exit(EXIT_FAILURE);
	}
	else this -> GPA = GPA;

	this -> major = major;
}

//setGPA(): sets the GPA private variable
//Arguments: GPA(float) | Returns: void
void Student :: setGPA(float GPA)
{
	//GPA data valdiation
	if (GPA < 0 || GPA > 4)
	{
		cout << "CRITICAL ERROR... GPA must be between 0.0 and 4.0";
		exit(EXIT_FAILURE);
	}
	else this -> GPA = GPA;
}

//print(): outputs the private variables
//Arguments: none | Returns: void
void Student :: print()
{
	Person :: print();
	cout << "    > GPA: " << showpoint << fixed << setprecision(2) << GPA << endl
		 << "    > Major: " << major << endl;
}
