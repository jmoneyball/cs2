/* class header file */

/*
----------------------------
		 Superstring
----------------------------
- stringStorage : string[]
- size : int
----------------------------
+ Superstring(nS: int)
+ ~Superstring()
+ setString(s: string, index: int): void
+ setSize(nS: int) : void
+ getString(index: int): string
+ getSize() : int
+ getFirst(): string
+ getLast(): string
----------------------------
*/

/* preprocessor directives */
#ifndef SUPERSTRING_H
#define SUPERSTRING_H
#include <iostream>
using namespace std;

/* class definition */
class Superstring
{
	private:
		string *stringStorage;
		int size;
	public:
		/* constructor(s) */
		Superstring(int);
		/* destructor */
		~Superstring();
		/* setter(s) */
		void setString(string s, int index)
		{ stringStorage[index] = s; }
		void setSize(int nS)
		{ size = nS; }
		/* getter(s) */
		string getString(int index)
		{ return stringStorage[index]; }
		int getSize()
		{ return size; }
		/* other method(s) */
		string getFirst();
		string getLast();
};

#endif /* SUPERSTRING_H */
