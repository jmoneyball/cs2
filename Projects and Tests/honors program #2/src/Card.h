/*============================
 *           Card
 *============================
 *- value: int
 *- values[]: int
 *- face: string
 *- faces[]: string
 *- suit: string
 *- suits[]: string
 *============================
 *+ Card()
 *+ Card(int, int, int)
 *+ getValue(): int
 *+ getFace(): string
 *+ getSuit(): string
 *+ setValue(int): void
 *+ setFace(string): void
 *+ setSuit(string): void
 *+ printCard(): void
 *============================
 */

//preprocessor directives
#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

//constants
const int SUITSIZE = 13, SUITNUM = 4;

//class definition
class Card {
private:
	int value;
	int values[SUITSIZE] = { 2, 3, 4, 5, 6, 7, 8,
							 9, 10, 10, 10, 10, 11 };
	string face;
	string faces[SUITSIZE] = { "2", "3", "4", "5", "6",
							   "7", "8", "9", "10", "Jack",
							   "Queen", "King", "Ace" };
	string suit;
	string suits[SUITNUM] = { "Clubs", "Diamonds",
							  "Hearts", "Spades" };
public:
//constructors
	Card()
		{ value = 0; face = ""; suit = ""; }
	Card(int v, int f, int s)
		{ value = values[v]; face = faces[f]; suit = suits[s]; }
//accessors
	//getValue(): returns value
	//Arguments: none | Returns: int
	int getValue()
		{ return value; }
	//getFace(): returns face
	//Arguments: none | Returns: string
	string getFace()
		{ return face; }
	//getSuit(): returns suit
	//Arguments: none | Returns: string
	string getSuit()
		{ return suit; }
//mutators
	//setValue(): sets the value of a card
	//Arguments: int value | Returns: void
	void setValue(int value)
		{ this -> value = value; }
	//setFace(): sets the face of a card
	//Arguments: int face | Returns: void
	void setFace(string face)
		{ this -> face = face; }
	//setSuit(): sets the suit of a card
	//Arguments: suit | Returns: void
	void setSuit(string suit)
		{ this -> suit = suit; }
//other methods
	//printCard(): prints the face and suit of a card
	//Arguments: none | Returns: void
	void printCard()
		{ cout << face << " of " << suit; }
};
#endif
