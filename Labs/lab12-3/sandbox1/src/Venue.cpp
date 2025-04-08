//Venue class implementation
#include "Venue.h"

Venue :: Venue(string type, int yearOpened, int capacity, float basePrice) {
	this -> type = type;
	//yearOpened data validation
	if(yearOpened <= 1800) {
		cout << "CRITICAL ERROR... yearOpened should be greater than 1800.";
		exit(EXIT_FAILURE);
	} else this -> yearOpened = yearOpened;
	//capacity data validation
	if(capacity < 1) {
		cout << "CRITICAL ERROR... capacity should be a positive whole number.";
		exit(EXIT_FAILURE);
	} else this -> capacity = capacity;
	//basePrice data valdiation
	if(basePrice <= 0) {
		cout << "CRITICAL ERROR... basePrice should greater than 0.";
		exit(EXIT_FAILURE);
	} else this -> basePrice = basePrice;
}

void Venue :: setYearOpened(int yearOpened) {
	if(yearOpened <= 1800) {
		cout << "CRITICAL ERROR... yearOpened should be greater than 1800.";
		exit(EXIT_FAILURE);
	} else this -> yearOpened = yearOpened;
}

void Venue :: setCapacity(int capacity) {
	if(capacity < 1) {
		cout << "CRITICAL ERROR... capacity should be a positive whole number.";
		exit(EXIT_FAILURE);
	} else this -> capacity = capacity;
}

void Venue :: setBasePrice(float basePrice) {
	if(basePrice <= 0) {
		cout << "CRITICAL ERROR... basePrice should greater than 0.";
		exit(EXIT_FAILURE);
	} else this -> basePrice = basePrice;
}

void Venue :: print() {
	cout << "\t> Type: " << type << endl
		 << "\t> Year opened: " << yearOpened << endl
		 << "\t> Capacity: " << capacity << " people" << endl
		 << "\t> Avg ticket price: $" << basePrice << endl;
}
