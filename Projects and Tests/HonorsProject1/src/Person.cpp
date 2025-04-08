//Person class implementation
#include "Person.h"

Person :: Person(string name, int age)
{
	this -> name = name;
	//age data valdiation
	if (age < 0)
	{
		cout << "CRITICAL ERROR... age must be greater than or equal to 0.";
		exit(EXIT_FAILURE);
	}
	else this -> age = age;
}

//setAge(): sets the age private variable
//Arguments: age(int) | Returns: void
void Person :: setAge(int age)
{
	//age data valdiation
	if (age < 0)
	{
		cout << "CRITICAL ERROR... age must be greater than or equal to 0.";
		exit(EXIT_FAILURE);
	}
	else this -> age = age;
}

//print(): prints the private variables
//Arguments: none | Returns: void
void Person :: print()
{
	cout << "    > Name: " << name << endl
		 << "    > Age: " << age << endl;
}
