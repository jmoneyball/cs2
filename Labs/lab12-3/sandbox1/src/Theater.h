/*
 * ====================
 * Theater: Venue
 * ====================
 * - name: string
 * - address: string
 * - cityStateZip: string
 * - avgSales: float
 * ====================
 * + Theater(): Venue()
 * + Theater(string, int, int, float, string, string, string, float)
 *   : Venue(string, int, int, float)
 * + setName(string): void
 * + setAddress(string): void
 * + setCityStateZip(string): void
 * + setAvgSales(float): void
 * + getName(): string
 * + getAddress(): string
 * + getCityStateZip(): string
 * + getAvgSales(): float
 * + potRev(): float
 * + print(): void
 */

/* preprocessor directives */
#ifndef THEATER_H
#define THEATER_H
#include "Venue.h"

class Theater: public Venue {
	private:
		string name, address, cityStateZip;
		float avgSales;
	public:
		Theater(): Venue()
		{ name = address = cityStateZip = ""; avgSales = 0; }
		Theater(string type, int yearOpened, int capacity,
				float basePrice, string name, string address,
				string cityStateZip, float avgSales);
		void setName(string name)
		{ this -> name = name; }
		void setAddress(string address)
		{ this -> address = address; }
		void setCityStateZip(string cityStateZip)
		{ this -> cityStateZip = cityStateZip; }
		void setAvgSales(int avgSales);
		string getName()
		{ return name; }
		string getAddress()
		{ return address; }
		string getCityStateZip()
		{ return cityStateZip; }
		float getAvgSales()
		{ return avgSales; }
		float potRev()
		{ return (avgSales + (Venue :: potRev())); }
		void print();
};
#endif
