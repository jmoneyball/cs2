/* ======================
 * Undergraduate: Student
 * ======================
 * - year: int
 * - studentID: int
 * ======================
 * + Undergraduate(): Student()
 * + Undergraduate(string, int, float, string, int, int)
 * + setYear(int): void
 * + setStudentID(int): void
 * + getYear(): int
 * + getStudentID(): int
 * + print(): void
 * ======================
 */

//preprocessor directives
#ifndef UNDERGRADUATE_H
#define UNDERGRADUATE_H
#include "Student.h"

class Undergraduate: public Student
{
	private:
		int year;
		int studentID;
	public:
		//consturctors
		Undergraduate(): Student()
			{ year = 0; studentID = 0; }
		Undergraduate(string name, int age, float GPA, string major, int year, int studentID);
		//mutators
		void setYear(int year);
		void setStudentID(int studentID);
		//accessors
		int getYear()
			{ return year; }
		int getStudentID()
			{ return studentID; }
		//other methods
		void print();
};

#endif
