/*
 * Program Name: lab 15-2
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: simulates a deck of cards
 */

//preprocessor directives
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//constants
const int SIZE = 52;

//Card struct definition
struct Card {
	int value;
	string suit;
	string face;
};

//function prototypes
int welcome();
bool deckSort(Card const, Card const);
void printCard(Card c);
void plagiarismPledge();

//main function
int main() {
	//declarations
	vector <Card> deck(SIZE);
	string faces[SIZE / 4] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
						"9", "10", "Jack", "Queen", "King"};
	int count = SIZE;
	//populates a standard deck of 52 cards
	for(int i = 0; i < 52; i++) {
    	//sets values of cards in the deck
    	deck[i].value = i;
    	//sets faces of cards in the deck according to value
    	deck[i].face = faces[i % 13];
    	//sets suit of cards in the deck
    	if(i < 13) deck[i].suit = "Clubs";
        else if (i < 26) deck[i].suit = "Diamonds";
        else if (i < 39) deck[i].suit = "Hearts";
        else if (i < SIZE) deck[i].suit = "Spades";
    }

	cout << "Welcome to your virtual deck of cards!";
	//gets user choice
	int choice;
	//main menu
	do {
		choice = welcome();
		//executes choice from menu
		switch(choice) {
			case 1: //view deck
				cout << "\nPrinting " << count << " cards currently in deck:\n"
					 << "NOTE: the deck ";
				if(is_sorted(deck.begin(), deck.end(), &deckSort)) cout << "IS sorted.\n";
				else cout << "IS NOT sorted.\n";
				for (int i = 0; i < SIZE; i++) {
					cout << "\t> ";
					printCard(deck[i]);
					cout << endl;
				}
				break;
			case 2: //shuffle deck
				random_shuffle(deck.begin(), deck.end());
				cout << "\nDeck has been shuffled!\n";
				break;
			case 3: //reverse deck
				reverse(deck.begin(), deck.end());
				cout << "\nDeck has been reversed!\n";
				break;
			case 4:	//sort deck
				sort(deck.begin(), deck.end(), &deckSort);
				cout << "\nDeck has been sorted!\n";
				break;
			case 5: //quit
				break;
		}
	} while (choice != 5);

	//ends program
	plagiarismPledge();
	return(0);
}

//welcome(): displays main menu
//Arguments: none | Returns: int
int welcome() {
	int c;
	cout << "\nPlease choose an option to continue:\n"
	 	 << "\t(1) View deck\n"
		 << "\t(2) Shuffle deck\n"
		 << "\t(3) Reverse deck\n"
		 << "\t(4) Sort deck\n"
		 << "\t(5) Quit\n"
		 << "\t>>> ";
	cin  >> c;
	while(c < 1 || c > 5) {
		cerr << "\tERROR... enter 1 - 5 only\n\t>>> ";
		cin  >> c;
	}
	return c;
}

//deckSort(): function to tell STL sort to sort deck by card value
//Arguments: Card, Card | Returns: bool
bool deckSort(Card const card1, Card const card2) {
    if (card1.value != card2.value)
        return (card1.value < card2.value);
}

//printCard(): prints the card sent to the program
//Arguments: Card | Returns: void
void printCard(Card c) {
	cout << c.face << " of " << c.suit;
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge() {
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
}
