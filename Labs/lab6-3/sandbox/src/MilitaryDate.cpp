/*
 * MilitaryDate.cpp
 * sandbox
 *
 * Jordan Johnson
 */

/* preprocessor directives */
#include "MilitaryDate.h"
using namespace std;

MilitaryDate :: MilitaryDate()
{
	day = 0;
	month = "";
	year = 0;
};

MilitaryDate :: MilitaryDate(int d, string m, int y)
{
	day = d;
	month = m;
	year = y;
};

