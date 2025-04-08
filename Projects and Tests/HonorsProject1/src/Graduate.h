/* ======================
 * Graduate: Student
 * ======================
 * - goal: string
 * - gradYear: int
 * ======================
 * + Graduate(): Student()
 * + Graduate(string, int, float, string, string, int)
 * + setGoal(string): void
 * + setGradYear(int): void
 * + getGoal(): string
 * + getGradYear(): int
 * + print(): void
 * ======================
 */

//preprocessor directives
#ifndef GRADUATE_H
#define GRADUATE_H
#include "Student.h"

class Graduate: public Student
{
	private:
		string goal;
		int gradYear;
	public:
		//consturctors
		Graduate(): Student()
			{ goal = ""; gradYear = 0; }
		Graduate(string name, int age, float GPA, string major, string goal, int gradYear);
		//mutators
		void setGoal(string goal)
			{ this -> goal = goal; }
		void setGradYear(int gradYear);
		//accessors
		string getGoal()
			{ return goal; }
		int getGradYear()
			{ return gradYear; }
		//other methods
		void print();
};

#endif
