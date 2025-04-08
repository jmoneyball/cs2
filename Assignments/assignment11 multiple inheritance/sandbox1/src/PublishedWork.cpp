/* PublishedWork class implementation */

/* preprocessor directives */
#include "PublishedWork.h"

PublishedWork :: PublishedWork()
{
	author = "";
	yearPublished = 0;
}

PublishedWork :: PublishedWork(string author, int yearPublished)
{
	this->author = author;

	if (yearPublished >= 0)
		this->yearPublished = yearPublished;
	else
	{
		cout << "***ERROR invalid year";
		exit(EXIT_FAILURE);
	}
}

void PublishedWork :: print()
{
	cout << "\t> Author: " << author << endl;
	cout << "\t> Year Published: " << yearPublished << endl;
}
