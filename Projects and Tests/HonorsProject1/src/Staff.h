/* ======================
 * Staff: Employee
 * ======================
 * - status: bool
 * - position: string
 * ======================
 * + Staff(): Employee()
 * + Staff(string, int, float, int, bool, string)
 * + setStatus(bool): void
 * + setPosition(string): void
 * + getStatus(): bool
 * + getPosition(): string
 * + print(): void
 * ======================
 */

//preprocessor directives
#ifndef STAFF_H
#define STAFF_H
#include "Employee.h"

class Staff: public Employee
{
	private:
		bool status;
		string position;
	public:
		//consturctors
		Staff(): Employee()
			{ status = false; position = ""; }
		Staff(string name, int age, float salary, int employeeID, bool status, string position);
		//mutators
		void setStatus(bool status)
			{ this -> status = status; }
		void setPosition(string position)
			{ this -> position = position; }
		//accessors
		bool getStatus()
			{ return status; }
		string getPosition()
			{ return position; }
		//other methods
		void print();
};

#endif
