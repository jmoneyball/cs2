/* Perfect class implementation */

/* preprocessor directives */
#include "Perfect.h"

Perfect :: Perfect(const Perfect &obj, int size)
{
	students = new string[size];
	for (int i = 0; i < size; i++)
		students[i] = obj.students[i];
}

void Perfect :: print(int size)
{
	for (int i = 0; i < size; i++)
		cout << students[i] << endl;
}
