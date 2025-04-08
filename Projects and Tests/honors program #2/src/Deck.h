/*============================
 *           Deck
 *============================
 *- size: int
 *- deck: vector<Card>
 *============================
 *+ Deck()
 *+ getSize(): int
 *+ getDeck(): vector<Card>
 *+ setSize(int): void
 *+ setDeck(vector<Card>): void
 *+ sortDeck(): void
 *+ shuffleDeck(): void
 *+ drawCard(): Card
 *+ printDecK(): void
 *============================
 */

//preprocessor directives
#ifndef DECK_H
#define DECK_H
#include <algorithm>
#include "Card.h"
#include <vector>

//class definition
class Deck: public Card {
private:
	int size;
	vector<Card> deck;
public:
//constuctor
	Deck()
		{ size = 52; deck.reserve(size); }
//accessors
	//getSize(): returns size
	//Arguments: none | Returns: int size
	int getSize()
		{ return size; }
	//getDeck(): returns a deck of cards
	//Arguments: none | Returns: vector<Card> deck
	vector<Card> getDeck()
		{ return deck; }
//mutators
	//setSize(): sets size
	//Arguments: int size | Returns: void
	void setSize(int size)
		{ this -> size = size; }
	//setDeck(): sets deck
	//Arguments: vector<Card> deck | Returns: void
	void setDeck(vector<Card> deck)
		{ this -> deck = deck; }
//other methods
	//sortDeck(): populates the deck with cards, sorted by suit
	//Arguments: none | Returns: void
	void sortDeck();
	//shuffleDeck(): shuffles the deck of cards randomly
	//Arguments: none | Returns: void
	void shuffleDeck()
		{ random_shuffle(deck.begin(), deck.end()); }
	//drawCard(): returns a random card from the deck
	//Arguments: none | Returns: Card
	Card drawCard()
		{ return (deck[rand() % size]); }
	//printDeck(): prints the deck
	//Arguments: none | Returns: void
	void printDeck();
};

#endif
