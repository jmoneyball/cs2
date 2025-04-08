/* Alpha class header */

/* 	----------------------------
			Alpha
	----------------------------
	- num: int
	- sentence: string
	----------------------------
	+ Alpha()
	+ Alpha(int, string)
	+ setNum(int): void
	+ getNum(): int
	+ setSentence(string): void
	+ getSentence(): string
	+ print(): void
	----------------------------
 */

/* preprocessor directives */
#ifndef ALPHA_H
#define ALPHA_H
#include <iostream>
using namespace std;

class Alpha
{
	private:
		int num;
		string sentence;
	public:
		Alpha()
		{	num = 0;
			sentence = "";	}
		Alpha(int n, string sent)
		{	num = n;
			sentence = sent;	}
		void setNum(int n)
		{	num = n;	}
		int getNum()
		{	return num;	}
		void setSentence(string sent)
		{	sentence = sent;	}
		string getSentence()
		{	return sentence;	}
		void print()
		{	cout << "> Number: " << num << endl;
			cout << "> Sentence: " << sentence << endl;	}
};

#endif
