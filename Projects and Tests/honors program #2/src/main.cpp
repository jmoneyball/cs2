/*
 * Program Name: Honors Project #2
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: simulates a game of 21/blackjack
 */

//preprocessor directives
#include <ctime>
#include "Deck.h"
#include <iomanip>
#include <stdlib.h>

//constants
const int WIN = 21, NEWHAND = 2;

//function prototypes
void welcome();
int menu();
void customRounds(Deck);
void endlessRounds(Deck);
void displayRound(int&);
void hit(vector <Card> &, Deck, int);
void stand(vector <Card>, vector <Card>, int&, int&);
int handValue(vector <Card>);
void printHand(vector <Card>);
void plagiarismPledge();

//main function
int main() {
	//declarations
	bool repeat = true;
	srand(time(0));
	//creates a standard deck of 52 cards
	Deck playingCards;
	playingCards.sortDeck();

	//main menu
	welcome();
	do {
	int choice = menu();
	switch(choice) {
	case 1: //custom round #
		customRounds(playingCards);
		break;
	case 2: //unlimited rounds
		endlessRounds(playingCards);
		break;
	case 3: //view deck
		cout << setw(50) << setfill('=') << "" << endl;
		playingCards.printDeck();
		break;
	case 4: //end game
		repeat = false;
		cout << setw(50) << setfill('=') << "" << endl;
		break;
	}
	} while (repeat == true);

	//ends program
	plagiarismPledge();
	return(0);
}

//welcome(): outputs rules
//Arguments: none | Returns: void
void welcome() {
	//blackjack rules
	cout << setw(50) << setfill('=') << "" << endl
		 << setw(12) << setfill('=') << "" << " Welcome to C++ Blackjack "
		 << setw(12) << setfill('=') << "" << endl
		 << setw(50) << setfill('=') << "" << endl
		 << "The  goal is to draw  cards whose values come as\n"
		 << "close to 21 as possible without  going over. You\n"
		 << "and the computer  will be given 2  cards at  the\n"
		 <<	"beginning of each round.  You will be shown  one\n"
		 << "of your  opponent's cards to help you  decide on\n"
		 << "your next move.  You can choose 'hit' to  draw a\n"
		 << "card,  or 'stand' to end the  round.  The  round\n"
		 << "ends when your  drawn cards  pass 21 or when you\n"
		 << "choose to 'stand'. If you  choose stand, a point\n"
		 << "will be given to  whoever  has  cards  that  are\n"
		 << "closer  to,   but   not  over,  21.  Good  luck!\n"
		 << setw(50) << setfill('=') << "" << endl
		 << "- Numbered cards are worth their face value\n"
		 << "- Face cards are worth 10 (Jack, Queen, King)\n"
		 << "- You can choose if an Ace card is worth 1 or 11\n";
}

//menu(): returns user choice for the main menu
//Arguments: none | Returns: int c
int menu() {
	int c;
	cout << setw(50) << setfill('=') << "" << endl
		 << "How would you like to play?\n"
		 << "\t(1) Choose number of rounds\n"
		 << "\t(2) Unlimited rounds\n"
		 << "\t(3) View deck\n"
		 << "\t(4) Quit\n"
		 << "\t>>> "; cin  >> c;
	//choice input validation
	while(c < 1 || c > 4) {
		cerr << "\tERROR... enter 1 - 4 only\n\t>>> ";
		cin  >> c;
	}
	//return choice
	return c;
}

//customRounds(): repeats game for a set amount of iterations
//Arguments: Deck deck | Returns: void
void customRounds(Deck deck) {
	//declarations
	int pScore = 0, cScore = 0; //score counters
	int round = 0; //round counter
	int roundsNum; //rounds to be played
	int choice; //user choice for menu

	//get roundsNum
	cout << "How many rounds would you like to play?\n" << "\t>>> "; cin  >> roundsNum;
		//choice input validation
		while(roundsNum < 1) {
			cerr << "\tERROR... enter a positive whole number only\n\t>>> ";
			cin  >> roundsNum;
		}

	//randomly shuffles the deck
	deck.shuffleDeck();

	//repeats game for set amount of rounds
	for(int i = 0; i < roundsNum; i++)
	{
	//starts a new round
	displayRound(round);
	bool roundRepeat = true;
	//deals hand
	vector <Card> pHand, cHand;
	int pValue = 0, cValue = 0; //card value counters
	for(int i = 0; i < NEWHAND; i++) {
		hit(pHand, deck, pValue);
		cHand.push_back(deck.drawCard());
	}
		//repeat turn until it ends
		do {
		//redeclare card values according to hand dealt
		pValue = handValue(pHand), cValue = handValue(cHand);

		//player gets a blackjack
		if(pValue == 21) {
			pScore++;
			cout << setw(50) << setfill('=') << "" << endl;
			cout << "21!\n"
				 << "You win the round.\n"
				 << "\t- Player wins: " << pScore << endl << "\t- Computer wins: " << cScore << endl;
			break;
		}
		//player breaks 21
		if(pValue > WIN) {
			cScore++;
			cout << setw(50) << setfill('=') << "" << endl;
			cout << "You drew cards worth more than 21.\n"
				 << "Computer wins the round.\n"
				 << "\t- Player wins: " << pScore << endl << "\t- Computer wins: " << cScore << endl;
			break;
		}

		//display cards in hand
		cout << setw(50) << setfill('=') << "" << endl;
		cout << "Opponent's visible card: "; cHand[0].printCard(); cout << endl;
		cout << "Your hand:\n";
		printHand(pHand); cout << "\tValue: " << pValue << " / " << WIN << endl;

		//options to play
		cout << setw(50) << setfill('=') << "" << endl
			 << "Choose a move to play:\n"
			 << setw(24) << setfill(' ') << left << "\t(1) Hit"
			 << right << "(draw another card)\n"
			 << "\t(2) Stand" << setw(34) << right << "(end round w/ current hand)\n"
			 << "\t(3) Quit\n"
			 << "\t>>> "; cin  >> choice;
		//choice input validation
		while(choice < 1 || choice > 3) {
			cerr << "\tERROR... enter 1 - 3 only\n\t>>> ";
			cin  >> choice;
		}

		//game menu
		switch(choice) {
		case 1: //hit
			hit(pHand, deck, pValue);
			break;
		case 2: //stand
			//computer draw extra card if hand is < 16
			if(handValue(cHand) < 16) cHand.push_back(deck.drawCard());
			//if computer hand passes 21
			if(handValue(cHand) > WIN)
			{
				pScore++;
				roundRepeat = false;
				cout << setw(50) << setfill('=') << "" << endl;
				cout << "Computer drew cards worth more than 21.\n"
					 << "You win the round.\n"
					 << "\t- Player wins: " << pScore << endl << "\t- Computer wins: " << cScore << endl;
				pValue = 0;
				break;
			}
			//if it doesn't, compare scores and determine winner
			else {
				stand(pHand, cHand, pScore, cScore);
				pValue = 0;
				roundRepeat = false;
				break;
			}
		case 3: //quit
			roundRepeat = false;
			break;
		}
		} while (roundRepeat == true);
	}

	//display states
	cout << setw(50) << setfill('=') << "" << endl;
	if (pScore > cScore) { //if player wins
		cout << "You beat the computer " << pScore << "-" << cScore
			 << " in " << roundsNum << " rounds of blackjack.\n";
	}
	else if (cScore > pScore) { //if computer wins
		cout << "The computer beat you " << cScore << "-" << pScore
			 << " in " << roundsNum << " rounds of blackjack.\n";
	}
	else if (cScore == pScore) { //if there is a tie
		cout << "You tied with the computer " << cScore << "-" << pScore
			 << " in " << roundsNum << " rounds of blackjack.\n";
	}

	//ask user to play again
	int playAgain;
	cout << "Play again?\n"
		 << "\t(1) Yes\n" << "\t(2) No\n" << "\t>>> "; cin >> playAgain;
	//choice input validation
	while(choice < 1 || choice > 2) {
		cerr << "\tERROR... enter 1 - 2 only\n\t>>> ";
		cin  >> choice;
	}
	//end game if choice == 2
	if(playAgain == 2) {
		cout << setw(50) << setfill('=') << "" << endl;
		plagiarismPledge();
		exit(1);
	}
}

//endlessRounds(): repeats game until user quits
//Arguments: Deck deck | Returns: void
void endlessRounds(Deck deck) {
	//declarations
	int pScore = 0, cScore = 0; //score counters
	int round = 0; //round counter
	int choice; //user choice for menu
	bool returnToMain = true; //repeat until (return to main menu)

	//randomly shuffles the deck
	deck.shuffleDeck();

	//repeats game endlessly until user quits
	do {
	//starts a new round
	displayRound(round);
	bool roundRepeat = true;
	//deals hand
	vector <Card> pHand, cHand;
	int pValue = 0, cValue = 0; //card value counters
	for(int i = 0; i < NEWHAND; i++) {
		hit(pHand, deck, pValue);
		cHand.push_back(deck.drawCard());
	}
		//repeat turn until it ends
		do {
		//redeclare card values according to hand dealt
		pValue = handValue(pHand), cValue = handValue(cHand);

		//player gets a blackjack
		if(pValue == 21) {
			pScore++;
			cout << setw(50) << setfill('=') << "" << endl;
			cout << "21!\n"
				 << "You win the round.\n"
				 << "\t- Player wins: " << pScore << endl << "\t- Computer wins: " << cScore << endl;
			break;
		}
		//player breaks 21
		if(pValue > WIN) {
			cScore++;
			cout << setw(50) << setfill('=') << "" << endl;
			cout << "You drew cards worth more than 21.\n"
				 << "Computer wins the round.\n"
				 << "\t- Player wins: " << pScore << endl << "\t- Computer wins: " << cScore << endl;
			break;
		}

		//display cards in hand
		cout << setw(50) << setfill('=') << "" << endl;
		cout << "Opponent's visible card: "; cHand[0].printCard(); cout << endl;
		cout << "Your hand:\n";
		printHand(pHand); cout << "\tValue: " << pValue << " / " << WIN << endl;

		//options to play
		cout << setw(50) << setfill('=') << "" << endl
			 << "Choose a move to play:\n"
			 << setw(24) << setfill(' ') << left << "\t(1) Hit"
			 << right << "(draw another card)\n"
			 << "\t(2) Stand" << setw(34) << right << "(end round w/ current hand)\n"
			 << "\t(3) Quit\n"
			 << "\t>>> "; cin  >> choice;
		//choice input validation1
		while(choice < 1 || choice > 3) {
			cerr << "\tERROR... enter 1 - 3 only\n\t>>> ";
			cin  >> choice;
		}

		//game menu
		switch(choice) {
		case 1: //hit
			hit(pHand, deck, pValue);
			break;
		case 2: //stand
			//computer draw extra card if hand is < 16
			if(handValue(cHand) < 16) cHand.push_back(deck.drawCard());
			//if computer hand passes 21
			if(handValue(cHand) > WIN)
			{
				pScore++;
				roundRepeat = false;
				cout << setw(50) << setfill('=') << "" << endl;
				cout << "Computer drew cards worth more than 21.\n"
					 << "You win the round.\n"
					 << "\t- Player wins: " << pScore << endl << "\t- Computer wins: " << cScore << endl;
				pValue = 0;
				break;
			}
			//if it doesn't, compare scores and determine winner
			else {
				stand(pHand, cHand, pScore, cScore);
				pValue = 0;
				roundRepeat = false;
				break;
			}
		case 3: //quit
			roundRepeat = false;
			returnToMain = false;
			break;
		}
		} while (roundRepeat == true);
	} while (returnToMain == true);
}

//displayRound(): displays the current round of the game
//Arguments: int r | Returns: void
void displayRound(int &r) {
	r++;
	if(r < 10){
		cout << setw(50) << setfill('=') << "" << endl
			 << setw(20) << setfill('=') << "" << " Round  " << r << " "
			 << setw(20) << setfill('=') << "" << endl;
	}
	else {
		cout << setw(50) << setfill('=') << "" << endl
			 << setw(20) << setfill('=') << "" << " Round " << r << " "
			 << setw(20) << setfill('=') << "" << endl;
	}
}

//hit(): adds a card to the player's hand
//Arguments: vector <Card> &h, Deck d, int v | Returns: void
void hit(vector <Card> &h, Deck d, int v) {
	Card c = d.drawCard();
	int choice;

	if(c.getFace() == "Ace") {
		cout << setw(50) << setfill('=') << "" << endl;
		cout << "You drew an Ace. Would you like it to be worth 1 or 11?\n"
			 << "Your current hand value is " << v << "...\n"
			 << "\t(1) 1\n"
			 << "\t(2) 11\n"
			 << "\t>>> "; cin  >> choice;
		//choice input validation
		while(choice < 1 || choice > 2) {
			cerr << "\tERROR... enter 1 - 2 only\n\t>>> ";
			cin  >> choice;
		}
		if(choice == 1) c.setValue(1);
		else if(choice == 2) c.setValue(11);
	}
	h.push_back(c);
}

//stand(): ends the current round and compares scores to determine a winner
//Arguments: vector <Card> p, vector <Card> c, int &pS, int &cS | Returns: void
void stand(vector <Card> p, vector <Card> c, int &pS, int &cS) {
	//prints player's hand
	cout << setw(50) << setfill('=') << "" << endl
		 << "Players hand:\n"; printHand(p);
	cout << "\tValue: " << handValue(p) << endl;

	//prints computers hand
	cout << "Computer's hand:\n"; printHand(c);
	cout << "\tValue: " << handValue(c) << endl;

	if(handValue(p) < handValue(c)) {
		cS++;
		cout << setw(50) << setfill('=') << "" << endl << "Computer wins the round.\n"
			 << "\t- Player wins: " << pS << endl << "\t- Computer wins: " << cS << endl;
	}
	else if (handValue(p) > handValue(c)){
		pS++;
		cout << setw(50) << setfill('=') << "" << endl << "You win the round.\n"
			 << "\t- Player wins: " << pS << endl << "\t- Computer wins: " << cS << endl;
	}
	else if (handValue(p) == handValue(c)){
		cout << setw(50) << setfill('=') << "" << endl << "You tied with the computer.\n"
			 << "\t- Player wins: " << pS << endl << "\t- Computer wins: " << cS << endl;
	}
}

//handValue(): returns the value of the hand sent to the function
//Arguments: vector <Card> h | Returns: int value
int handValue(vector <Card> h) {
	int value = 0;

	for(int i = 0; i < h.size(); i++)
		value += h[i].getValue();

	return value;
}

//printHand(): prints the hand sent to the function
//Arguments: vector <Card> h | Returns: void
void printHand(vector <Card> h) {
	for(int i = 0; i < h.size(); i++) {
		cout << "\t- ";
		h[i].printCard();
		cout << endl;
	}
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge() {
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this "
		 << "code from any source.";
}
