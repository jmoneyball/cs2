/*
 * Program Name: lab 14-2
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: uses objects with an STL deque to
 * 						simulate a line of cars at a toll booth
 *						(includes output filters lane probabilities)
 */

//preprocessor directives
#include <array>
#include "Car.h"
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
using namespace std;

//constants
const int YEARMIN = 1990, YEARMAX = 2021,
		  TRANSMIN = 1000, TRANSMAX = 9999,
		  ARRAYSIZE = 42, MIN = 1, MAX = 100,
		  DEQUESIZE = 3;

//function prototypes
Car generateCar(array<string, ARRAYSIZE>);
void outputLane(deque<Car>, int choice);
void plagiarismPledge();

//main function
int main() {
	//declarations
	array <string, ARRAYSIZE> makes = {""};
	deque<Car> carLane1;
	ifstream fin ("makes.txt");
	int counter = 0, rounds = 1, choice;
	srand(time(0));
	string input;

	//populates makes array using input file
	while(getline(fin, input)) {
		makes[counter] = input;
		counter++;
	}

	//populates deque with 3 random cars
	for(int i = 0; i < DEQUESIZE; i++)
		carLane1.push_back(generateCar(makes));

	//gets user input for output filters
	cout << "Enter:\n"
		 << "[1] Depict lanes by make/year\n"
		 << "[2] Depict lanes by transponder\n"
		 << "Choice --> ";
	cin  >> choice;
	while(choice != 1 && choice!= 2) {
		cerr << "ERROR...please enter 1 or 2 only --> ";
		cin  >> choice;
	}

	cout << "Initial lane setup:";
	//while the lane is not empty...
	while (!carLane1.empty()) {
		//outputs the lane at the start of each round
		cout << "\n\nLane 1: ";
		outputLane(carLane1, choice);
		//flips a coin to decide if a car will leave/join the deque
		int coinFlip = rand() % (MAX - MIN + 1) + MIN;
		//based on coinFlip...
		if (coinFlip <= 55) { //car pays toll and leaves
			cout << "\n\nOperations this round(#" << rounds << "):\n";
			if (choice == 1) {
				cout << "\t> Lane 1: " << (carLane1.front()).getMake()
					 << '/' << (carLane1.front()).getYear() << " going through toll gate.";
			}
			else if(choice == 2)
				cout << "\t> Lane 1: " << (carLane1.front()).getTransponder() << " going through toll gate.";
			carLane1.pop_front();
		}
		else if (coinFlip > 55) { //car joins line
			carLane1.push_back(generateCar(makes));
			cout << "\n\nOperations this round(#" << rounds << "):\n";
			if(choice == 1) {
				cout << "\t> Lane 1: " << (carLane1.back()).getMake()
					 << '/' << (carLane1.back()).getYear() << " added to the queue.";
			}
			else if(choice == 2)
				cout << "\t> Lane 1: " << (carLane1.back()).getTransponder() << " added to the queue.";
		}
		//increments round counter
		rounds++;
	}
	//outputs after while loop completes to signify that there are no more objects in the deque
	cout << "\n\nLane 1: <*empty*>";

	//ends program
	fin.close();
	plagiarismPledge();
	return(0);
}

//generateCar(): populates a Car object with random data and returns it to main to be used in the deque
//Arguments: array<String, ARRAYSIZE> | Returns: Car object
Car generateCar(array<string, ARRAYSIZE> makes) {
	//declarations
	Car myCar;
	string randMake = makes[(rand() % (ARRAYSIZE - MIN + 1) + MIN) - 1];
	int randYear = rand() % (YEARMAX - YEARMIN + 1) + YEARMIN;
	int randTrans = rand() % (TRANSMAX - TRANSMIN + 1) + TRANSMIN;
	//setting private member variables
	myCar.setMake(randMake);
	myCar.setYear(randYear);
	myCar.setTransponder(randTrans);
	//returns car object
	return(myCar);
}

//outputLane(): simply outputs the lane of cars that is passed to the function
//Arguments: deque<Car> | Returns: void
void outputLane(deque<Car> lane, int c) {
	if(c == 1)
		for(int i = 0; i < lane.size(); i++)
			cout << lane[i].getMake() << "/" << lane[i].getYear() << " ";
	else if(c == 2)
		for(int i = 0; i < lane.size(); i++)
			cout << lane[i].getTransponder() << " ";
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge() {
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
