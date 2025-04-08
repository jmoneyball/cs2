/*
----------------------------
		 Movie
----------------------------
- screenWriter: string
- yearReleased: int
- title: string
----------------------------
+ Movie()
+ Movie(string, int, string)
+ getScreenWriter(): string
+ getYearReleased(): int
+ getTitle(): string
+ setScreenWriter(string): void
+ setYearReleased(int): void
+ setTitle(string): void
----------------------------
*/

/* preprocessor directives */
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
using namespace std;

class Movie
{
	private:
		string screenWriter;
		int yearReleased;
		string title;
	public:
		Movie();
		Movie(string, int, string);
		string getScreenWriter()
			{ return screenWriter; }
		int getYearReleased()
			{ return yearReleased; }
		string getTitle()
			{ return title; }
		void setScreenWriter(string s)
			{ screenWriter = s; }
		void setYearReleased(int y)
			{ yearReleased = y; }
		void setTitle(string t)
			{ title = t; }
};

#endif /* MOVIE_H */
