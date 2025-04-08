/* Charlie class header */

/* 	----------------------------
		Charlie: Bravo
	----------------------------
	- situation: string
	- balance: float
	----------------------------
	+ Charlie() : Bravo()
	+ Charlie(int, string, bool, float, string, float) : Bravo(int, string, bool, float)
	+ setSituation(string): void
	+ getSituation(): string
	+ setBalance(float): void
	+ getBalancel(): float
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef CHARLIE_H
#define CHARLIE_H
#include "Bravo.h"

class Charlie: public Bravo
{
	private:
		string situation;
		float balance;
	public:
		Charlie() : Bravo()
		{	situation = "";
			balance = 0;	}
		Charlie(int n, string sent, bool stat, float t, string sit, float b) : Bravo(n, sent, stat, t)
		{	situation = sit;
			balance = b;	}
		void setSituation(string sit)
		{	situation = sit;	}
		string getSituation()
		{	return situation;	}
		void setBalance(float b)
		{	balance = b;	}
		float getBalance()
		{	return balance;	}
		void print()
		{	Bravo :: print();
			cout << "> Situation: " << situation << endl;
			cout << "> Balance: " << balance << endl;	}
};

#endif
