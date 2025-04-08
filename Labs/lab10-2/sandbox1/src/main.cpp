/*
Program Name: lab 10-2
Author: Jordan Johnson
IDE Used: Eclipse
Program description: demos the new operator overloading
*/

/* preprocessor directives */
#include "box.h"

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	//declarations
	Box box1;
	Box box2(3.5, 2.5, 4.0);
	Box box3(2, 2, 2);
	Box box4(3, 6, 9);

	//outputs volumes of boxes
	cout << "Volume of box #1: " << box1.volume() << endl
		 << "Volume of box #2: " << box2.volume() << endl
		 << "Volume of box #3: " << box3.volume() << endl
		 << "Volume of box #4: " << box4.volume() << endl;

	//tests if volumes are equal
	cout << "\nTesting equality:\n" // box1 and 2
		 << "Testing if box1 = box2: ";
			if(box1 == box2)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box3 = box4: ";  // box3 and 4
			if(box3 == box4)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box1 = box3: ";  // box1 and 3
			if(box1 == box3)
				cout << "True\n";
			else cout << "False\n";

	//tests if volume of first box is greater than volume of second
	cout << "\nTesting (volume) greater than:\n" // box1 and 2
		 << "Testing if box1 > box2: ";
			if(box1 > box2)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box2 > box3: ";  // box2 and 3
			if(box2 > box3)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box4 > box3: ";  // box4 and 3
			if(box4 > box3)
				cout << "True\n";
			else cout << "False\n";

	//tests if volume of first box is less than volume of second
	cout << "\nTesting (volume) less than:\n" // box1 and 2
		 << "Testing if box1 < box2: ";
			if(box1 < box2)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box2 < box3: ";  // box2 and 3
			if(box2 < box3)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box3 < box4: ";  // box3 and 4
			if(box3 < box4)
				cout << "True\n";
			else cout << "False\n";

	//tests if all dimensions of first box are greater than all dimensions of second
	cout << "\nTesting (all dimensions) greater than:\n" // box1 and 2
		 << "Testing if box1 >= box2: ";
			if(box1 >= box2)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box2 >= box3: ";  // box2 and 3
			if(box2 >= box3)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box3 >= box4: ";  // box3 and 4
			if(box3 >= box4)
				cout << "True\n";
			else cout << "False\n";

	//tests if all dimensions of first box are less than all dimensions of second
	cout << "\nTesting (all dimensions) less than:\n" // box1 and 2
		 << "Testing if box2 <= box1: ";
			if(box2 <= box1)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box2 <= box3: ";  // box2 and 3
			if(box2 <= box3)
				cout << "True\n";
			else cout << "False\n";
	cout << "Testing if box3 <= box4: ";  // box3 and 4
			if(box3 <= box4)
				cout << "True\n";
			else cout << "False\n";

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
