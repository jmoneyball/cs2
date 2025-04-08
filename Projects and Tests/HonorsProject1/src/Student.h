/* ======================
 * Student: Person
 * ======================
 * - GPA: float
 * - major: string
 * ======================
 * + Student(): Person()
 * + Student(string, int, float, major)
 * + setGPA(float): void
 * + setMajor(string): void
 * + getGPA(): float
 * + getMajor(): string
 * + print(): void
 * ======================
 */

//preprocessor directives
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <iomanip>

class Student: public Person
{
	private:
		float GPA;
		string major;
	public:
		//constructors
		Student() : Person()
			{ GPA = 0; major = ""; }
		Student(string name, int age, float GPA, string major);
		//mutators
		void setGPA(float GPA);
		void setMajor(string major)
			{ this -> major = major; }
		//accessors
		float getGPA()
			{ return GPA; }
		string getMajor()
			{ return major; }
		//other methods
		void print();
};

#endif
