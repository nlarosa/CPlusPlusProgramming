// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Interface for CardDeck class
// Which uses a deque (template) to 
// sort a "deck of cards"

#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>
#include <deque>

using namespace std;

class CardDeck
{
	friend ostream &operator<<( ostream &, const CardDeck & );	// we are overloading the ostream as a global function, so we point to it

	public:
		CardDeck( int = 52 );	// non-default constructor - will populate deque
		int getSize() const;	// gets the current size of the card deck
		int getCard( int );	// gets the card located at the given deque index
		int getFront();		// gets the card located at the 0-th index
		void shuffle();		// shuffles the card deck instance
		bool inOrder();		// checks to see if the deck is increasing order
	private:
		deque<int> ourDeck;	// this deque will hold the card values
};
	
#endif

