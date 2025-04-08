//Staff class implementation
#include "Staff.h"

Staff :: Staff(string name, int age, float salary, int employeeID, bool status, string position)
	   : Employee(name, age, salary, employeeID)
{
	this -> status = status;
	this -> position = position;
}

//print(): outputs the private variables
//Arguments: none | Returns: void
void Staff :: print()
{
	Employee :: print();
	cout << "    > Status: ";
	if (status == true) cout << "Manager\n";
	else cout << "Non-manager\n";
	cout << "    > Position: " << position << endl;
}
