/*
Program Name: lab 10-3
Author: Jordan Johnson
IDE Used: Eclipse
Program description: creating a class to show operator overloading
*/

/* preprocessor directives */
#include <iostream>
#include <cstdlib>
using namespace std;

/* class definition */
class CupCount
{
	private:
		int oz;
		int cups;
		void Simplify()
			{
				if (oz >= 8)
				{
					cups += (oz / 8);
					oz = oz % 8;
				}
				else if (oz < 0)
				{
					cups -= ((abs(oz) / 8) + 1);
					oz = 8 - (abs(oz) % 8);
				}
			}
	public:
		CupCount(int o = 8)
			{
				cups = 0;
				oz = o;
				Simplify();
			}
		void setOz(int o)
			{
				cups = 0;
				oz = o;
				Simplify();
			}
		void setCups(int c)
			{	cups = 0;
				oz += (8*c);
				Simplify();
			}
		int getOz()
			{ 	return oz; }
		int getCups()
			{ 	return cups; }
		CupCount operator +(CupCount c)
			{
				oz += c.getOz();
				cups += c.getCups();
				Simplify();
				return *this;
			}
		CupCount operator -(CupCount c)
			{
				oz -= c.getOz();
				cups -= c.getCups();
				Simplify();
				return *this;
			}
		CupCount operator ++()
			{
				++oz;
				Simplify();
				return *this;
			}
		CupCount operator ++(int)
			{
				CupCount temp(oz);
				oz++;
				Simplify();
				return temp;
			}
		CupCount operator --()
			{
				--oz;
				Simplify();
				return *this;
			}
		CupCount operator --(int)
			{
				CupCount temp(oz);
				oz--;
				Simplify();
				return temp;
			}
};

/* function prototypes */
void plagiarismPledge();

/* constants */
const int SIZE1 = 64, SIZE2 = 28, SIZE4 = 4;

/* main function */
int main ()
{
	//creates bottle1
	CupCount bottle1(SIZE1);
	cout << "Created " << SIZE1 << "-ounce bottle1.\n";

	//demonstrates prefix ++ increment operator
	cout << "Demonstrating prefix ++ operator:\n"
		 << "\t> " << bottle1.getCups() << " cups " << bottle1.getOz() << " oz\n"; //outputs size of original bottle
	for (int i = 0; i < 8; i++) //increments oz of original bottle by 1 until there is enough for a new cup
	{
		++bottle1;
		cout << "\t> " << bottle1.getCups() << " cups " << bottle1.getOz() << " oz\n";
	}

	//demonstreates prefix -- decrement operator
	cout << "\nDemonstrating prefix -- operator:\n"
		 << "\t> " << bottle1.getCups() << " cups " << bottle1.getOz() << " oz\n"; //outputs current size of bottle1
	for (int j = 0; j < 4; j++) //decrements oz of bottle1 until there is 4 oz
	{
		--bottle1;
		cout << "\t> " << bottle1.getCups() << " cups " << bottle1.getOz() << "oz\n";
	}

	//creates bottle2
	CupCount bottle2(SIZE2);
	cout << "\nCreated " << SIZE2 << "-ounce bottle2.\n";

	//demonstrates postfix ++ increment operator
	cout << "Demonstrating postfix ++ operator:\n"
		 << "\t> " << bottle2.getCups() << " cups " << bottle2.getOz() << " oz\n";
	for (int i = 0; i < 4; i++)
	{
		bottle2++;
		cout << "\t> " << bottle2.getCups() << " cups " << bottle2.getOz() << " oz\n";
	}

	//demonstrates postfix -- decrement operator
	cout << "\nDemonstrating postfix -- operator:\n"
		 << "\t> " << bottle2.getCups() << " cups " << bottle2.getOz() << " oz\n";
	for (int i = 0; i < 8; i++)
	{
		bottle2--;
		cout << "\t> " << bottle2.getCups() << " cups " << bottle2.getOz() << " oz\n";
	}

	//demonstrates + operator
	cout << "\nDemonstrating + operator:\n"
		 << "\t> bottle1: " << bottle1.getCups() << " cups " << bottle1.getOz() << " oz\n"
		 << "\t> bottle2: " << bottle2.getCups() << " cups " << bottle2.getOz() << " oz\n";
	//creates bottle3
	CupCount bottle3 = bottle1 + bottle2;
	cout << "\t> Added: " << bottle3.getCups() << " cups " << bottle3.getOz() << " oz\n";

	//creates bottle4
	CupCount bottle4(SIZE4);
	cout << "\nCreated " << SIZE4 << "-ounce bottle4";
	//demonstrates - operator
	cout << "\nDemonstrating - operator:\n"
		 << "\t> bottle3: " << bottle3.getCups() << " cups " << bottle3.getOz() << " oz\n"
		 << "\t> bottle4: " << bottle4.getCups() << " cups " << bottle4.getOz() << " oz\n";
	//creates bottle5
	CupCount bottle5 = bottle3 - bottle4;
	cout << "\t> Subtracted: " << bottle5.getCups() << " cups " << bottle5.getOz() << " oz\n";

	/* ends program */
	plagiarismPledge();
	return(0);
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
