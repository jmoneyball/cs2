/* ElectronicDevice class implementation */

/* preprocessor directives */
#include "ElectronicDevice.h"

ElectronicDevice :: ElectronicDevice()
{
	type = "";
	OS = "";
	GB = 0;
}

ElectronicDevice :: ElectronicDevice(string type, string OS, int GB)
{
	this->type = type;
	this->OS = OS;

	if (GB >= 0)
		this->GB = GB;
	else
	{
		cout << "***ERROR invalid number of GBs";
		exit(EXIT_FAILURE);
	}
}

void ElectronicDevice :: print()
{
	cout << "\t> Device Type: " << type << endl;
	cout << "\t> OS: " << OS << endl;
	cout << "\t> Memory: " << GB << " GB" << endl;
}
