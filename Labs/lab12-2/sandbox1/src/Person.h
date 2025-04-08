/* Person class header */

/* 	----------------------------
			Person
	----------------------------
	- ssn: int
	- birthday: Date
	----------------------------
	+ Person(int, Date)
	+ setSSN(int): void
	+ getSSN(): int
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef PERSON_H
#define PERSON_H
#include "Date.h"

class Person
{
	private:
		int ssn;
		Date birthday;
	public:
		Person(int ssn, Date bd): birthday(bd)
		{	this -> ssn = ssn;	}
		void setSSN(int ssn)
		{	this -> ssn = ssn;	}
		int getSSN()
		{	return ssn;	}
		void print()
		{	cout << "> SSN: " << ssn << endl; birthday.print();	}
};

#endif
