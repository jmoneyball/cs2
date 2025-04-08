//Professor class implementation
#include "Professor.h"

Professor :: Professor(string name, int age, float salary, int employeeID, bool status, int roomNum)
		   : Employee(name, age, salary, employeeID)
{
	this -> status = status;

	//roomNum data valdiation
	if (roomNum < 0)
	{
		cout << "CRITICAL ERROR... roomNum must be greater than 0.";
		exit(EXIT_FAILURE);
	}
	else this -> roomNum = roomNum;
}

//setRoomNum(): sets the private variable roomNum
//Arguments: roomNum(int) | Returns: void
void Professor :: setRoomNum(int roomNum)
{
	//roomNum data valdiation
		if (roomNum < 0)
		{
			cout << "CRITICAL ERROR... roomNum must be greater than 0.";
			exit(EXIT_FAILURE);
		}
		else this -> roomNum = roomNum;
}

//print(): outputs the private variables
//Arguments: none | Returns: void
void Professor :: print()
{
	Employee :: print();
	cout << "    > Room #: " << roomNum << endl
		 << "    > Status: ";
	if (status == true) cout << "Full-time\n";
	else cout << "Part-time\n";
}
