/* class implementation file */

/* preprocessor directives */
#include "Superstring.h"
#include <iostream>
using namespace std;

/* constructor(s) */
Superstring :: Superstring(int nS)
{
	size = nS;
	stringStorage = new string[size];
	cout << "** Superstring array has been created with " << size << " slots. **\n\n";
}

//Method name: SuperString :: getFirst()
//Purpose: finds the string that alphabetically comes first
string Superstring :: getFirst()
{
	string firstString = stringStorage[0];

	for (int i = 0; i < size; i++)
		if(stringStorage[i] < firstString)
			firstString = stringStorage[i];
	return firstString;
}

//Method name: SuperString :: getLast()
//Purpose: finds the string that alphabetically comes last
string Superstring :: getLast()
{
	string lastString = stringStorage[size - 1];

	for (int i = 0; i < size; i++)
		if(stringStorage[i] > lastString)
			lastString = stringStorage[i];
	return lastString;
}

//Method name: SuperString :: ~Superstring()
//Purpose: releases dynamic memory held by the array
Superstring :: ~Superstring()
{
	delete [] stringStorage;
	stringStorage = nullptr;
	cout << endl << "\n** Superstring array has been destroyed. **";
}
