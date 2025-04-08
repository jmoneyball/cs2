/* ReaderApp class implementation */

/* preprocessor directives */
#include "ReaderApp.h"

ReaderApp :: ReaderApp(): PublishedWork(), ElectronicDevice()
{
	appName = "";
	appCost = 0;
}

ReaderApp :: ReaderApp(string author, int yearPublished, string type, string OS, int GB, string appName, float appCost)
				: PublishedWork(author, yearPublished), ElectronicDevice(type, OS, GB)
{
	this->appName = appName;

	if (appCost >= 0)
		this->appCost = appCost;
	else
	{
		cout << "***ERROR invalid app cost";
		exit(EXIT_FAILURE);
	}
}

void ReaderApp :: print()
{
	PublishedWork :: print();
	ElectronicDevice :: print();

	cout << "\t> App Name: " << appName << endl;
	cout << "\t> App Cost: " << '$' << appCost << endl;
}
