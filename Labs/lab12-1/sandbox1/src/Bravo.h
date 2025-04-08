/* Bravo class header */

/* 	----------------------------
			Bravo: Alpha
	----------------------------
	- status: bool
	- total: float
	----------------------------
	+ Bravo() : Alpha()
	+ Bravo(int, string, bool, float): Alpha(int, string)
	+ setStatus(bool): void
	+ getStatus(): bool
	+ setTotal(float): void
	+ getTotal(): float
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef BRAVO_H
#define BRAVO_H
#include "Alpha.h"

class Bravo: public Alpha
{
	private:
		bool status;
		float total;
	public:
		Bravo() : Alpha()
		{	status = false;
			total = 0;	}
		Bravo(int n, string sent, bool stat, float t) : Alpha(n, sent)
		{	status = stat;
			total = t;	}
		void setStatus(bool stat)
		{	status = stat;	}
		bool getStatus()
		{	return status;	}
		void setTotal(float t)
		{	total = t;	}
		float getTotal()
		{	return total;	}
		void print()
		{	Alpha :: print();
			cout << "> Status: ";
				if (status == true) cout << "true" << endl;
				else cout << "false" << endl;
			cout << "> Total: " << total << endl;	}
};

#endif
