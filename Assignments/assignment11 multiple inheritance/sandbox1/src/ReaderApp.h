/* ReaderApp class header */

/* 	----------------------------
	ReaderApp: PublishedWork, ElectronicDevice
	----------------------------
	- appName: string
	- appCost: float
	----------------------------
	+ ReaderApp()
	+ ReaderApp(string, float)
	+ setAppName(string): void
	+ getAppName(): string
	+ setAppCost(float): void
	+ GetAppCost(): float
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef READERAPP_H
#define READERAPP_H
#include "PublishedWork.h"
#include "ElectronicDevice.h"

class ReaderApp: public PublishedWork, public ElectronicDevice
{
	private:
		string appName;
		float appCost;
	public:
		ReaderApp();
		ReaderApp(string author, int yearPublished, string type, string OS, int GB, string appName, float appCost);
		void setAppName(string an)
			{ appName = an; }
		string getAppName()
			{ return appName; }
		void setAppCost(float ac)
			{ appCost = ac; }
		float getAppCost()
			{ return appCost; }
		void print();
};

#endif
