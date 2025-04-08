//Theater class implementation
#include "Theater.h"

Theater :: Theater(string type, int yearOpened, int capacity, float basePrice,
				   string name, string address, string cityStateZip, float avgSales)
		 : Venue(type, yearOpened, capacity, basePrice) {
	this -> name = name;
	this -> address = address;
	this -> cityStateZip = cityStateZip;
	if(avgSales <= 0) {
		cout << "CRITICAL ERROR... avgSales should be a positive number.";
		exit(EXIT_FAILURE);
	} else this -> avgSales = avgSales;
}

void Theater :: setAvgSales(int avgSales) {
	if(avgSales <= 0) {
		cout << "CRITICAL ERROR... avgSales should be a positive number.";
		exit(EXIT_FAILURE);
	} else this -> avgSales = avgSales;
}

void Theater :: print() {
	cout << "\t> Name: " << name << endl
		 << "\t> Address: " << address << endl
		 << "\t> City/State/Zip: " << cityStateZip << endl
		 << "\t> Avg. Concession Sales: $" << avgSales << endl;
 	Venue :: print();
}
