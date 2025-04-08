/* Perfect class header */

/*
 _______________________
           Perfect
 _______________________
 - students: *string
 _______________________
 + Perfect(size: int)
 + Perfect(&obj: const Perfect, size: int)
 + ~Perfect()
 + getStudent(index: int): string
 + setStudent(index: int, name: string): void
 + printStudents(int size): void;
*/

/* preprocessor directives */
#ifndef PERFECT_H
#define PERFECT_H
#include <iostream>
using namespace std;

class Perfect
{
	private:
		string *students = nullptr;
	public:
		Perfect(int size)
		{ students = new string[size]; }
		Perfect(const Perfect &obj, int size);
		~Perfect()
		{ delete [] students; }
		string getStudent(int index)
		{ return students[index]; }
		void setStudent(int index, string name)
		{ students[index] = name; }
		void print(int size);
};

#endif /* PERFECT_H */
