//Deck class implementation
#include "Deck.h"

void Deck :: sortDeck() {
	for(int i = 0; i < SUITNUM; i++)
		for(int j = 0; j < SUITSIZE; j++)
			deck.push_back(Card(j, j, i));
}

void Deck :: printDeck() {
	for (int i = 0; i < deck.size(); i++) {
		cout << "\t- " << deck[i].getFace() << " of " << deck[i].getSuit()
			 << " > Value: " << deck[i].getValue() << endl;
	}
}
