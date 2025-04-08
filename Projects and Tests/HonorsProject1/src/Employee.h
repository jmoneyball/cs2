/* ======================
 * Employee: Person
 * ======================
 * - salary: float
 * - employeeID: int
 * ======================
 * + Employee(): Person()
 * + Employee(string, int, float int)
 * + setSalary(float): void
 * + setEmployeeID(int): void
 * + getSalary(): float
 * + getEmployeeID(): int
 * + print(): void
 * ======================
 */


//preprocessor directives
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include <iomanip>

class Employee: public Person
{
	private:
		float salary;
		int employeeID;
	public:
		//constructors
		Employee() : Person()
			{ salary = 0; employeeID = 0; }
		Employee(string name, int age, float salary, int employeeID);
		//mutators
		void setSalary(float salary);
		void setEmployeeID(int employeeID);
		//accessors
		float getSalary()
			{ return salary; }
		int getEmployeeID()
			{ return employeeID; }
		//other methods
		void print();
};

#endif
