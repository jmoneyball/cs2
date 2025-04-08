/* preprocessor directives */
#include "Movie.h"
using namespace std;

Movie :: Movie()
{
	screenWriter = "";
	yearReleased = 0;
	title = "";
}

Movie :: Movie(string s, int y, string t)
{
	screenWriter = s;
	yearReleased = y;
	title = t;
}
