/*
 * ====================
 * Venue
 * ====================
 * - type: string
 * - yearOpened: int
 * - capacity: int
 * - basePrice: float
 * ====================
 * + Venue()
 * + Venue(string, int, int, float)
 * + setType(string): void
 * + setYearOpened(int): void
 * + setCapacity(int): void
 * + setBasePrice(float): void
 * + getType(): string
 * + getYearOpened(): int
 * + getCapacity(): int
 * + getBasePrice(): float
 * + potRev(): float
 * + print(): void
 */

/* preprocessor directives */
#ifndef VENUE_H
#define VENUE_H
#include <iostream>
using namespace std;

class Venue {
	private:
		string type;
		int yearOpened, capacity;
		float basePrice;
	public:
		Venue()
		{ type = ""; yearOpened = capacity = basePrice = 0; }
		Venue(string type, int yearOpened, int capacity, float basePrice);
		void setType(string type)
		{ this -> type = type; }
		void setYearOpened(int yearOpened);
		void setCapacity(int capcity);
		void setBasePrice(float basePrice);
		string getType()
		{ return type; }
		int getYearOpened()
		{ return yearOpened; }
		int getCapacity()
		{ return capacity; }
		float getBasePrice()
		{ return basePrice; }
		float potRev()
		{ return(capacity * basePrice); }
		void print();
};
#endif
