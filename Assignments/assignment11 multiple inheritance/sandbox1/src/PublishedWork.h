/* PublishedWork class header */

/* 	----------------------------
	PublishedWork
	----------------------------
	- author: string
	- yearPublished: int
	----------------------------
	+ PublishedWork()
	+ PublishedWork(string, int)
	+ setAuthor(string): void
	+ getAuthor(): string
	+ setYearPublished(int): void
	+ getYearPublished(): int
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef PUBLISHEDWORK_H
#define PUBLISHEDWORK_H
#include <iostream>
using namespace std;

class PublishedWork
{
	private:
		string author;
		int yearPublished;
	public:
		PublishedWork();
		PublishedWork(string author, int yearPublished);
		void setAuthor(string a)
			{ author = a; }
		string getAuthor()
			{ return author; }
		void setYearPublished(int yp)
			{ yearPublished = yp; }
		int getYearPublished()
			{ return yearPublished; }
		void print();
};

#endif
