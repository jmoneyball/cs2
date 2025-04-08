//*****************
//Program Name: Assignment 1: Shapes
//Author: Jordan Johnson
//IDE Used: Eclipse
//Program description: Calculates different values of various 2D and 3D shapes
//*****************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
	//declarations
	string tokenName, line;
	float token1, token2, token3;
	ifstream fin("shapes.txt");
	ofstream fout("output.txt");

	//repeats until all calculations are completed
	while (getline(fin, line))
	{
		//reads from input file
		stringstream ss(line);
		ss >> tokenName >> token1 >> token2 >> token3;

		//calculations and output
		if (tokenName == "SQUARE") //output and calculations for square
		{
			cout << tokenName << " side=" << setprecision(2) << fixed << token1
				 << " area=" << pow(token1, 2) << " perimeter=" << 4 * token1 << endl;
			fout << tokenName << " side=" << setprecision(2) << fixed << token1
				 << " area=" << pow(token1, 2) << " perimeter=" << 4 * token1 << endl;
		}
		else if (tokenName == "RECTANGLE") //output and calculations for rectangle
		{
			cout << tokenName << " length=" << setprecision(2) << fixed << token1 << " width= " << token2
				 << " area=" << token1 * token2 << " perimeter=" << (2 * token1) + (2 * token2) << endl;
			fout << tokenName << " length=" << setprecision(2) << fixed << token1 << " width= " << token2
				 << " area=" << token1 * token2 << " perimeter=" << (2 * token1) + (2 * token2) << endl;
		}
		else if (tokenName == "CIRCLE") //output and calculations for circle
		{
			cout << tokenName << " radius=" << setprecision(2) << fixed << token1
				 << " area=" << M_PI * (pow(token1, 2)) << " perimeter=" << (2 * M_PI) * token1 << endl;
			fout << tokenName << " radius=" << setprecision(2) << fixed << token1
				 << " area=" << pow((M_PI * token1), 2) << " perimeter=" << (2 * M_PI) * token1 << endl;
		}
		else if (tokenName == "TRIANGLE") //output and calculations for triangle
		{
			cout << tokenName << " side=" << setprecision(2) << fixed << token1
				 << " area=" << (token1 * (sqrt(3) * (token1 / 2))) / 2 << " perimeter=" << token1 * 3 << endl;
			fout << tokenName << " side=" << setprecision(2) << fixed << token1
				 << " area=" << (token1 * (sqrt(3) * (token1 / 2))) / 2 << " perimeter=" << token1 * 3 << endl;
		}
		else if (tokenName == "CUBE") //output and calculations for cube
		{
			cout << tokenName << " side=" << setprecision(2) << fixed << token1
				 << " volume=" << pow(token1, 3) << " surface=" << 6 * pow(token1, 2) << endl;
			fout << tokenName << " side=" << setprecision(2) << fixed << token1
				 << " volume=" << pow(token1, 3) << " surface=" << 6 * pow(token1, 2) << endl;
		}
		else if (tokenName == "BOX") //output and calculations for box
		{
			cout << tokenName << " length=" << token1 << " width=" << token2 << " height=" << token3
				 << " volume=" << token1 * token2 * token3 << " surface=" << (2 * (token1 * token2)) + (2 * (token1 * token3)) + (2 * (token2 * token3)) << endl;
			fout << tokenName << " length=" << token1 << " width=" << token2 << " height=" << token3
				 << " volume=" << token1 * token2 * token3 << " surface=" << (2 * (token1 * token2)) + (2 *(token1 * token3)) + (2 * (token2 * token3)) << endl;
		}
		else if (tokenName == "CYLINDER") //output and calculations for cylinder
		{
			cout << tokenName << " radius=" << token1 << " height=" << token2
				 << " volume=" << M_PI * token2 * pow(token1, 2) << " surface=" << (2 * M_PI * token1 * token2) + (2 * M_PI * pow(token1, 2)) << endl;
			fout << tokenName << " radius=" << token1 << " height=" << token2
				 << " volume=" << M_PI * token2 * pow(token1, 2) << " surface=" << (2 * M_PI * token1 * token2) + (2 * M_PI * pow(token1, 2)) << endl;
		}
		else //output for invalid shapes
		{
			cout << tokenName << " invalid object\n";
			fout << tokenName << " invalid object\n";
		};
	};

	//plagiarism pledge
	cout << "\n\nI attest that this code is my original programming work, and that I received\n"
		 << "no help creating it. I attest that I did not copy this code or any portion of this\n"
		 << "code from any source.";

	fin.close();
	fout.close();
	return(0);
}
