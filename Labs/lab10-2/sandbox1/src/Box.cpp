/* Box class implementation */

/* preprocessor directives */
#include "box.h"

bool Box :: operator ==(Box b)
	{ if ((length * width * height) == b.volume()) return true;
	  return false; }
bool Box :: operator >(Box b)
	{ if ((length * width * height) > b.volume()) return true;
	  return false; }
bool Box :: operator <(Box b)
	{ if ((length * width * height) < b.volume()) return true;
	  return false; }
bool Box :: operator >=(Box b)
	{ if (length > b.getLength() && width > b.getWidth() && height > b.getHeight()) return true;
	  return false; }
bool Box :: operator <=(Box b)
	{ if (length < b.getLength() && width < b.getWidth() && height < b.getHeight()) return true;
	  return false; }
