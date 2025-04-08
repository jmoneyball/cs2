/* class header file */

/*
----------------------------
		 Magic8Ball
----------------------------
- answersIndex : int
- answers : string[]
----------------------------
+ Magic8Ball()
+ getAnswersIndex(): int
+ getAnswer(index: int): string
+ shake(): void
----------------------------
*/

/* preprocessor directives */
#ifndef MAGIC8BALL_H
#define MAGIC8BALL_H
#include <iostream>
using namespace std;

/* constants */
static const int MIN = 1, SIZE = 6, SHAKES = 10000;

/* class definition */
class Magic8Ball
{
	private:
		int answersIndex;
		string answers[SIZE] = { "By all means, yes",
								 "Oh nooooooo",
								 "The future is uncertain",
								 "I don't know; shake again",
								 "It's up to you; your choice",
								 "Absolutely, positively NO" };
	public:
		/* constructor(s) */
		Magic8Ball()
			{ answersIndex = rand() % (SIZE - MIN + 1) + MIN; }
		/* getter(s) */
		int getAnswersIndex()
			{ return answersIndex; }
		string getAnswer(int index)
			{ return answers[index]; }
		/* other method(s) */
		void shake()
			{ answersIndex = rand() % (SIZE - MIN + 1) + MIN; }
};

#endif /* MAGIC8BALL_H_H */
