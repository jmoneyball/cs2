/* ======================
 * Person
 * ======================
 * - name: string
 * - age: int
 * ======================
 * + Person()
 * + Person(string, int)
 * + setName(string): void
 * + setAge(int): void
 * + getName(): string
 * + getAge(): int
 * + print(): void
 * ======================
 */

//preprocessor directives
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person
{
	private:
		string name;
		int age;
	public:
		//constructors
		Person()
			{ name = ""; age = 0; }
		Person(string name, int age);
		//mutators
		void setName(string name)
			{ this -> name = name; }
		void setAge(int age);
		//accessors
		string getName()
			{ return name; }
		int getAge()
			{ return age; }
		//other methods
		void print();
};
#endif
