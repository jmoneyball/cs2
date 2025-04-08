/* class header file */

/*
----------------------------
		 COLLECTION
----------------------------
- userCollection : vector <Type>
----------------------------
+ Collection(size: int, val: Type)
+ push(val: Type): void
+ print(): void
+ setValue(val: Type, i: int): void;
----------------------------
*/

/* preprocessor directives */
#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <vector>
using namespace std;

/* class definition */
template <class Type>
class Collection
{
	private:
		vector <Type> userCollection;
	public:
		Collection(int size, Type val)
		{ vector <Type> userCollection(size, val); }
		void push(Type val)
		{ userCollection.push_back(val); }
		void print()
		{ for (int i = 0; i < userCollection.size(); i++)
			cout << "\t> " << userCollection[i] << endl; }
		void setValue(Type val, int i)
		{ userCollection[i] = val; }
};

#endif /* COLLECTION_H */
