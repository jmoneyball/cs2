//*****************
//Program Name: Car Collection
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: Keeps track of the user's collection of cars as well as their current speed.
//*****************

#include <iostream>
#include <vector>
using namespace std;

//constants
const int SPEED = 5;

//structs
struct Car
{
	string make, model;
	int year, mileage, speed = 0;
};

//f(x) prototypes
void addCar(vector <Car> &);
void outputCars(vector <Car>);
void accCar(vector <Car> &);
void decCar(vector <Car> &);
void removeCar(vector <Car> &);

int main ()
{
	//declarations
	int userChoice;
	vector <Car> carCollection;

	//repeats program until user quits
	do
	{
		//main menu
		cout << "Select:"
			 << "\t[1] Accelerate a car\n"
			 << "\t[2] Decelerate a car\n"
			 << "\t[3] Add a car to the collection\n"
			 << "\t[4] Remove a car from the collection\n"
			 << "\t[5] Output car collection status\n"
			 << "\t[6] Quit\n\t> ";

		//gets user input w/ validation
		cin  >> userChoice;
			while (userChoice < 1 or userChoice > 6)
			{
				cout <<"\t> ERROR... please enter 1 - 6 only\n\t> ";
				cin  >> userChoice;
			}

		//menu selection
		switch(userChoice)
		{
			//accelerate a car
			case 1: if (carCollection.size() == 0) //prevents user from using if collection is empty
					{
						cout << "\t> You cannot accelerate a car when your collection is empty.\n"
							 << "\t> Please add a car to your collection to continue.\n\n";
						break;
					}
					else
					{
						accCar(carCollection);
						break;
					}

			//decelerate a car
			case 2:  if (carCollection.size() == 0) //prevents user from using if collection is empty
					 {
						cout << "\t> You cannot decelerate a car when your collection is empty.\n"
							 << "\t> Please add a car to your collection to continue.\n\n";
						break;
					 }
					 else
					 {
						decCar(carCollection);
						break;
					 }

			//add a car to the collection
			case 3: addCar(carCollection);
					break;

			//remove a car from the collection
			case 4:  if (carCollection.size() == 0) //prevents user from using if collection is empty
					{
						cout << "\t> You cannot remove a car when your collection is empty.\n"
							 << "\t> Please add a car to your collection to continue.\n\n";
						break;
					}
					else
					{
						removeCar(carCollection);
						break;
					}

			//output the current collection of cars
			case 5:  if (carCollection.size() == 0) //prevents user from using if collection is empty
				   	 {
						cout << "\t> You cannot view your collection when your collection is empty.\n"
							 << "\t> Please add a car to your collection to continue.\n\n";
						break;
					 }
					 else
			         {
						outputCars(carCollection);
						break;
			         }

			//end program
			case 6: break;
		}
	}
	while (userChoice != 6);

	return(0);
}

//*****************
//Function name: removeCar
//Purpose: Removes a car from the collection.
//*****************
void removeCar(vector <Car> &c)
{
	//declarations
	int remInput;

	cout << "\n\t> Removing a car from the collection. Select:" << endl;

	//outputs cars
	for (int l = 0; l < c.size(); l++)
	{
		cout << "\t> [" << l + 1 << "] " << c[l].year
			 << " " << c[l].make << " " << c[l].model << endl;
	}

	//gets user input
	cout << "\t> ";
	cin  >> remInput;

	//removes user selection from vector
	remInput--;
	c.erase(c.begin() + remInput);

	cout << "\t> Car removed." << endl << endl;
}


//*****************
//Function name: decCar
//Purpose: Decelerates the selected car.
//*****************
void decCar(vector <Car> &c)
{
	//declarations
	int decInput;

	cout << "\n\t> Decelerating a car. Select:" << endl;

	//outputs cars
	for (int k = 0; k < c.size(); k++)
	{
		cout << "\t> [" << k + 1 << "] " << c[k].year
			 << " " << c[k].make << " " << c[k].model << endl;
	}

	//gets user input
	cout << "\t> ";
	cin  >> decInput;

	if (c[decInput - 1].speed == 0)
		cout << "\t> The car you selected has a speed of zero and cannot decelerate further.\n\n";
	else if (c[decInput - 1].speed != 0)
	{
		//updates car speed
		c[decInput - 1].speed -= SPEED;
		//outputs cars new speed
		cout << "\t> New speed: " << c[decInput - 1].speed << endl << endl;
	}
}

////*****************
//Function name: accCar
//Purpose: Accelerates the selected car.
//*****************
void accCar(vector <Car> &c)
{
	//declarations
	int accInput;

	cout << "\n\t> Accelerating a car. Select:" << endl;

	//outputs cars
	for (int j = 0; j < c.size(); j++)
	{
		cout << "\t> [" << j + 1 << "] " << c[j].year
			 << " " << c[j].make << " " << c[j].model << endl;
	}

	//gets user input
	cout << "\t> ";
	cin  >> accInput;

	//updates car speed
	c[accInput - 1].speed += SPEED;

	//outputs cars new speed
	cout << "\t> New speed: " << c[accInput - 1].speed << endl << endl;

}

//*****************
//Function name: outputCars
//Purpose: Outputs the current collection of cars.
//*****************
void outputCars(vector <Car> c)
{
	cout << "\n\t> Car collection status:\n";

	//outputs cars
	for (int i= 0; i < c.size(); i++)
	{
		cout << "\t> " << c[i].year << " " << c[i].make << " " << c[i].model << endl
			 << "\t\t> Mileage: " << c[i].mileage << endl
			 << "\t\t> Speed: " << c[i].speed << endl;
	}

	cout << endl;
}

//*****************
//Function name: addCar
//Purpose: Adds a car to the collection.
//*****************
void addCar(vector <Car> &c)
{
	//declarations
	Car temp;

	//gets user input
	cin.ignore();
	cout << "\n\t> Adding a car to the collection. Please enter the following:\n";
	cout << "\t> Make: ";
	getline (cin, temp.make);
	cout << "\t> Model: ";
	getline (cin, temp.model);
	cout << "\t> Year: ";
	cin  >> temp.year;
	cout << "\t> Mileage: ";
	cin  >> temp.mileage;
	cout << "\t> The car is now a part of your collection!\n\n";
	cin.ignore();

	//pushes car into carCollection vector
	c.push_back(temp);
}
