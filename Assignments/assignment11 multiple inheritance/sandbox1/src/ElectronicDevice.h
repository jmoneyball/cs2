/* ElectronicDevice class header */

/* 	----------------------------
	ElectronicDevice
	----------------------------
	- type: string
	- OS: string
	- GB: int
	----------------------------
	+ ElectronicDevice()
	+ ElectronicDevice(string, string, int)
	+ setType(string): void
	+ getType(): string
	+ setOS(string): void
	+ getOS(): string
	+ setGB(int): void
	+ getGB(): int
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H
#include <iostream>
using namespace std;

class ElectronicDevice
{
	private:
		string type;
		string OS;
		int GB;
	public:
		ElectronicDevice();
		ElectronicDevice(string type, string OS, int GB);
		void setType(string t)
			{ type = t; }
		string getType()
			{ return type; }
		void setOS(string os)
			{ OS = os; }
		string getOS()
			{ return OS; }
		void setGB(int gb)
			{ GB = gb; }
		int getGB()
			{ return GB; }
		void print();
};

#endif
