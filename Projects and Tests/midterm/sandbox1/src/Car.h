/* Car class header */

/*
 _______________________
           Car
 _______________________
 - make: string
 - year : int
 - speed: int
 - num_recs : int
 - maintenance : int[]
 _______________________
 + Car(string, int)
 + setMake(m: string): void
 + setYear(y: int): void
 + setSpeed(s: int): void
 + setNum_Recs(nR: int): void
 + setMaintenance(m: int, i: int): void
 + getMake(): string
 + getYear(): int
 + getSpeed(): int
 + getNum_Recs(): int
 + getMaintenance(i: int): int
 + accelerate(): void
 + brake(): void
 + print(bool): void
*/

/* preprocessor directives */
#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;

//constants
const int SIZE = 50;
const int SPEED = 5;

class Car
{
	private:
		string make;
		int year;
		int speed;
		int num_recs;
		int maintenance[SIZE];
	public:
		Car(string m, int y);
		void setMake(string m)
		{ make = m; }
		void setYear(int y)
		{ year = y; }
		void setSpeed(int s)
		{ speed = s; }
		void setNum_Recs(int nR)
		{ num_recs = nR; }
		void setMaintenance(int m, int i)
		{ maintenance[i] = m; }
		string getMake()
		{ return make; }
		int getYear()
		{ return year; }
		int getSpeed()
		{ return speed; }
		int getNum_Recs()
		{ return num_recs; }
		int getMaintenance(int i)
		{ return maintenance[i]; }
		void accelerate()
		{ speed += SPEED; }
		void brake()
		{ speed -= SPEED; }
		void print(bool);
};

#endif /* CAR_H */
