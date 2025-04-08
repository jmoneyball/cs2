//Employee class implementation
#include "Employee.h"

Employee :: Employee(string name, int age, float salary, int employeeID)
		  : Person(name, age)
{
	//salary data valdiation
	if (salary < 0)
	{
		cout << "CRITICAL ERROR... salary must be greater than or equal to 0.";
		exit(EXIT_FAILURE);
	}
	else this -> salary = salary;
	//employeeID data valdiation
	if (employeeID < 0)
	{
		cout << "CRITICAL ERROR... employeeID must be greater than or equal to 0.";
		exit(EXIT_FAILURE);
	}
	else this -> employeeID = employeeID;
}


//setSalary(): sets the private variable salary
//Arguments: salary(float) | Returns: void
void Employee :: setSalary(float salary)
{
	//salary data valdiation
	if (salary < 0)
	{
		cout << "CRITICAL ERROR... salary must be greater than or equal to 0.";
		exit(EXIT_FAILURE);
	}
	else this -> salary = salary;
}

//setEmployeeID(): sets the private variable employeeID
//Arguments: employeeID(int) | Returns: void
void Employee :: setEmployeeID(int employeeID)
{
	//salary data valdiation
	if (employeeID < 0)
	{
		cout << "CRITICAL ERROR... employeeID must be greater than or equal to 0.";
		exit(EXIT_FAILURE);
	}
	else this -> employeeID = employeeID;
}

//print(): outputs the private variables
//Arguments: none | Returns: void
void Employee :: print()
{
	Person :: print();
	cout << "    > Salary: $" << showpoint << fixed << setprecision(2) << salary << endl
		 << "    > Employee ID #: " << employeeID << endl;
}
