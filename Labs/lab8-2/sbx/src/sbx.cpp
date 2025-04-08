/*
Program Name: lab 8-2
Author: Jordan Johnson
IDE Used: Eclipse
Program description: uses a class to create and calculate the volume of a box and keep track of the total boxes created
*/

/* preprocessor directives */
#include <iostream>
using namespace std;

/* static member varible */
static int numBoxes;

/* class definition */
class Box
{
	private:
		int length;
		int width;
		int height;
	public:
		Box(int l, int w, int h)
		{	length = l;
			width = w;
			height = h;
			numBoxes++;	}
		void setLength(int l)
		{	length = l;	}
		void setWidth(int w)
		{	width = w; 	}
		void setHeight(int h)
		{	height = h;	}
		int getLength()
		{	return length;	}
		int getWidth()
		{	return width;	}
		int getHeight()
		{	return height;	}
		int findVolume()
		{	return (length * width * height);	}
};

/* function prototypes */
void plagiarismPledge();

/* main function */
int main ()
{
	/*declarations */
	Box firstBox(2, 4, 6);
	Box secondBox(3, 6, 9);

	/* outputs data */
	cout << "Volume of firstBox >> " << firstBox.findVolume() << endl
		 << "Volume of secondBox >> " << secondBox.findVolume() << endl
		 << "Total number of boxes >> "<< numBoxes;

	/* ends program */
	plagiarismPledge();
	return(0);
}

/*
Function name: plagiarismPledge
Purpose: function to simply output the plagiarism pledge at the end of the program
Parameters: none
Returns: none
Return type: void
*/
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
