// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Interface for BlackJack class
// Which has a CardDeck (composition)

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include "CardDeck.h"

using namespace std;

class BlackJack
{
	public:
		BlackJack();			// default constructor
		int blackJackValue( int );	// converts from card value to equivalent blackjack value

		void dealUser();		// deals one card to the user
		void dealDealer();		// deals one card to the dealer

		bool printUser();		// prints the user's state, true if game over
		bool printDealer();		// prints the dealer's state, true if game over		

		bool promptUser();		// true if user wants hit
		bool playAgain();		// true if user wants to play again

		void playRound();		// begins a new game of blackjack (resets totals)
		void printResults();		// prints the winning records of user and dealer
	private:
		CardDeck gameDeck;		// deck of cards used for blackjack
		int currentCard;		// index of the car deck

		int dealerTotal;		// keep track of card counts
		int userTotal;

		int dealerWins;			// keep track of win totals
		int userWins;
};

#endif

