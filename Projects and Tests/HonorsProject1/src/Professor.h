/* ======================
 * Professor: Employee
 * ======================
 * - status: bool
 * - roomNum: int
 * ======================
 * + Professor(): Employee()
 * + Professor(string, int, float, int, bool, int)
 * + setStatus(bool): void
 * + setRoomNum(int): void
 * + getStatus(): bool
 * + getRoomNum(): int
 * + print(): void
 * ======================
*/

//preprocessor directives
#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Employee.h"

class Professor: public Employee
{
	private:
		bool status;
		int roomNum;
	public:
		//constructors
		Professor(): Employee()
			{ status = false; roomNum = 0; }
		Professor(string name, int age, float salary, int employeeID, bool status, int roomNum);
		//mutators
		void setStatus(bool status)
			{ this -> status = status; }
		void setRoomNum(int roomNum);
		//accessors
		bool getStatus()
			{ return status; }
		int getRoomNum()
			{ return roomNum; }
		//other methods
		void print();
};

#endif
