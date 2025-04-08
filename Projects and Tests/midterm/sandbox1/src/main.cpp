/*
Program Name: midterm
Author: Jordan Johnson
IDE Used: Eclipse
Program description: uses a class to create and manipulate car objects
 	 	 	 	 	 that are a part of a vector collection of cars
*/

/* preprocessor directives */
#include "Car.h"
#include <vector>

/* function prototypes */
int menu();
void printCollection(vector <Car>);
void addCar(vector <Car> &);
void removeCar(vector <Car> &);
void accelerateCar(vector <Car> &);
void brakeCar(vector <Car> &);
void addMaintenance(vector <Car> &);
void outputMaintenance(vector <Car>);
void plagiarismPledge();

/* main function */
int main ()
{
	/* declarations */
	vector <Car> carCollection;
	int userChoice;
	bool repeatProgram = true;

	do
	{
		userChoice = menu();
		switch(userChoice)
		{
		case 1:
			printCollection(carCollection);
			break;
		case 2:
			addCar(carCollection);
			break;
		case 3:
			removeCar(carCollection);
			break;
		case 4:
			accelerateCar(carCollection);
			break;
		case 5:
			brakeCar(carCollection);
			break;
		case 6:
			addMaintenance(carCollection);
			break;
		case 7:
			outputMaintenance(carCollection);
			break;
		case 8:
			repeatProgram = false;
			break;
		}
	} while (repeatProgram != false);

	/* ends program */
	plagiarismPledge();
	return(0);
}

//menu(): outputs menu option and returns selected option to main
//Arguments: none | Returns: int uC
int menu()
{
	int uC;
	//outputs menu options
	cout << "MAIN MENU -- Please choose from the following options:\n"
		 << "\t> 1 | Print complete car collection\n"
		 << "\t> 2 | Add a car to the collection\n"
		 << "\t> 3 | Remove a car from the collection\n"
		 << "\t> 4 | Accelerate a car\n"
		 << "\t> 5 | Brake a car\n"
		 << "\t> 6 | Enter maintenance mileage\n"
		 << "\t> 7 | Output maintenance record\n"
		 << "\t> 8 | Quit\n"
		 << "\t> Choice: ";

	//gets user input to return to main
	cin  >> uC;
	//input validation
	while (uC < 1 || uC > 8)
	{
		cout << "\t> **ERROR: Please enter a number 1 through 8 only.\n\t> ";
		cin >> uC;
	}

	//returns user input to main
	return uC;
}

//printCollection(): prints the entire collection of cars
//Arguments: vector <Car> | Returns: void
void printCollection(vector <Car> cC)
{
	bool printMR;

	//outputs if there is at least 1 car in the collection
	if (cC.size() != 0)
	{
		//outputs carCollection vector
		cout << "\nCar inventory:\n";
		for (long long i = 0; i < cC.size(); i++)
		{
			//all cars output with maintenance record if they have one
			printMR = true;
			//outputs cars without maintenance record if record does not exist
			if (cC[i].getNum_Recs() == 0)
				printMR = false;
			cout << "\t> ";
			cC[i].print(printMR);
		}

		cout << endl;
	}
	//outputs if there are no cars in the collection
	else cout << "\n**ERROR: Your collection is empty. Please add a car to continue.\n\n";
}

//addCar(): adds a car to the collection
//Arguments: vector <Car> & | Returns: void
void addCar(vector <Car> &cC)
{
	string m;
	int y;

	//gets user input for make and model of car to be added
	cout << "\nAdding a car to the collection...\n"
		 << "\t> Enter make: ";
	cin.ignore();
	getline(cin, m);
	cout << "\t> Enter year: ";
	cin  >> y;
	//input validation
	while (y <= 0)
	{
		cout << "\t> **ERROR: Please enter a positive number only.\n\t> ";
		cin >> y;
	}

	//adds car to carCollection vector
	cC.push_back(Car(m, y));
	cout << "Done. Car added.\n\n";
}

//removeCar(): removes a car from the collection
//Arguments: vector <Car> & | Returns: void
void removeCar(vector <Car> &cC)
{
	int choice;
	bool printMR = false;

	//outputs if there is at least 1 car in the collection
	if (cC.size() != 0)
	{
		//outputs current collection
		cout << "\nRemoving a car from the collection...\n"
			 << "\t> Enter the number of the car to remove:\n";
		for (long long i = 0; i < cC.size(); i++)
		{
			cout << "\t> " << i + 1 << " | ";
			cC[i].print(printMR);
		}

		//gets user choice
		cout << "\t> Choice: ";
		cin  >> choice;
		//input validation
		while (choice <= 0 || choice > cC.size())
		{
			if (cC.size() == 1)
			{
				cout << "\t> **ERROR: There is only 1 car to choose from. Please enter 1.";
				cin  >> choice;
			}
			else
			{
				cout << "\t> **ERROR: Please enter a number 1 through " << cC.size() << " only.\n\t> ";
				cin >> choice;
			}
		}
		choice--;

		//removes index of user choice from carCollection vector
		cC.erase(cC.begin() + choice);
		cout << "\t> Done. car removed.\n\n";
	}
	//outputs if there are no cars in the collection
	else cout << "\n**ERROR: Your collection is empty. Please add a car to continue.\n\n";
}

//accelerateCar(): accelerates a car in the collection
//Arguments: vector <Car> & | Returns: void
void accelerateCar(vector <Car> &cC)
{
	int choice;
	bool printMR = false;

	//outputs if there is at least 1 car in the collection
	if (cC.size() != 0)
	{
		//outputs current collection
		cout << "\nAccelerating a car...\n"
			 << "\t> Enter the number of the car to accelerate:\n";
		for (long long i = 0; i < cC.size(); i++)
		{
			cout << "\t> " << i + 1 << " | ";
			cC[i].print(printMR);
		}

		//gets user choice
		cout << "\t> Choice: ";
		cin  >> choice;
		//input validation
		while (choice <= 0 || choice > cC.size())
		{
			if (cC.size() == 1)
			{
				cout << "\t> **ERROR: There is only 1 car to choose from. Please enter 1.";
				cin  >> choice;
			}
			else
			{
				cout << "\t> **ERROR: Please enter a number 1 through " << cC.size() << " only.\n\t> ";
				cin >> choice;
			}
		}
		choice--;

		//accelerates index of user choice from carCollection vector
		cC[choice].accelerate();
		cout << "\t> Done. car accelerated. New speed " << cC[choice].getSpeed() << " mph\n\n";
	}
	//outputs if there are no cars in the collection
	else cout << "\n**ERROR: Your collection is empty. Please add a car to continue.\n\n";
}

//brakeCar(): brakes a car to the collection
//Arguments: vector <Car> & | Returns: void
void brakeCar(vector <Car> &cC)
{
	int choice;
	bool printMR = false;

	//outputs if there is at least 1 car in the collection
	if (cC.size() != 0)
	{
		//outputs current collection
		cout << "\nBraking a car...\n"
			 << "\t> Enter the number of the car to brake:\n";
		for (long long i = 0; i < cC.size(); i++)
		{
			cout << "\t> " << i + 1 << " | ";
			cC[i].print(printMR);
		}

		//gets user choice
		cout << "\t> Choice: ";
		cin  >> choice;
		//input validation
		while (choice <= 0 || choice > cC.size())
		{
			if (cC.size() == 1)
			{
				cout << "\t> **ERROR: There is only 1 car to choose from. Please enter 1.";
				cin  >> choice;
			}
			else
			{
				cout << "\t> **ERROR: Please enter a number 1 through " << cC.size() << " only.\n\t> ";
				cin >> choice;
			}
		}
		choice--;

		//if car is moving...
		if (cC[choice].getSpeed() != 0)
		{
			//brakes index of user choice from carCollection vector
			cC[choice].brake();
			cout << "\t> Done. car braked. New speed " << cC[choice].getSpeed() << " mph\n\n";
		}
		//if car is not moving...
		else cout <<  "\n**ERROR: You can't brake a car that's not moving.\n\n";
	}
	//outputs if there are no cars in the collection
	else
		cout << "\n**ERROR: Your collection is empty. Please add a car to continue.\n\n";
}

//addMaintenance(): adds mileage of maintenance to the array corresponding with the given car
//Arguments: vector <Car> & | Returns: void
void addMaintenance(vector <Car> &cC)
{
	int choice;
	int mileage;
	bool printMR = false;

	//outputs if there is at least 1 car in the collection
	if (cC.size() != 0)
	{
		//outputs current collection
		cout << "\nEntering maintenance mileage...\n"
			 << "\t> Enter the number of the car to log maintenance:\n";
		for (long long i = 0; i < cC.size(); i++)
		{
			cout << "\t> " << i + 1 << " | ";
			cC[i].print(printMR);
		}

		//gets user choice
		cout << "\t> Choice: ";
		cin  >> choice;
		//input validation
		while (choice <= 0 || choice > cC.size())
		{
			if (cC.size() == 1)
			{
				cout << "\t> **ERROR: There is only 1 car to choose from. Please enter 1.";
				cin  >> choice;
			}
			else
			{
				cout << "\t> **ERROR: Please enter a number 1 through " << cC.size() << " only.\n\t> ";
				cin >> choice;
			}
		}
		choice--;

		//gets mileage
		cout << "\t> Enter mileage when maintenance was performed: ";
		cin  >> mileage;
		//input validation
		while (mileage <= 0)
		{
			cout << "\t> **ERROR: Please enter a positive number only.\n\t> ";
			cin >> mileage;
		}

		//increments num_recs
		cC[choice].setNum_Recs(cC[choice].getNum_Recs() + 1);
		//adds mileage to maintenance array
		cC[choice].setMaintenance(mileage, cC[choice].getNum_Recs() - 1);
		cout << "\t> Maintenance entered for " << mileage << endl << endl;
	}
	//outputs if there are no cars in the collection
	else
		cout << "\n**ERROR: Your collection is empty. Please add a car to continue.\n\n";
}

//outputMaintenance(): outputs the maintenance array for a given car
//Arguments: vector <Car> | Returns: void
void outputMaintenance(vector <Car> cC)
{
	int choice;
	bool printMR = false;

	//outputs if there is at least 1 car in the collection
	if (cC.size() != 0)
	{
		//outputs current collection
		cout << "\nOutputting maintenance records...\n"
			 << "\t> Enter the number of the car to display the maintenance log:\n";
		for (long long i = 0; i < cC.size(); i++)
		{
			cout << "\t> " << i + 1 << " | ";
			cC[i].print(printMR);
		}

		//gets user choice
		cout << "\t> Choice: ";
		cin  >> choice;
		while (choice <= 0 || choice > cC.size())
		{
			if (cC.size() == 1)
			{
				cout << "\t> **ERROR: There is only 1 car to choose from. Please enter 1.";
				cin  >> choice;
			}
			else
			{
				cout << "\t> **ERROR: Please enter a number 1 through " << cC.size() << " only.\n\t> ";
				cin >> choice;
			}
		}
		choice--;

		//outputs maintenance record
		if (cC[choice].getNum_Recs() != 0)
		{
			cout << "\t> Maintenance performed at: ";
			for (int j = 0; j < cC[choice].getNum_Recs(); j++)
				cout << cC[choice].getMaintenance(j) << " ";
			cout << endl << endl;
		}
		else
			cout << "\n**ERROR: The car you selected does not have a maintenance record.\n\n";
	}
	//outputs if there are no cars in the collection
	else
		cout << "\n**ERROR: Your collection is empty. Please add a car to continue.\n\n";
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
