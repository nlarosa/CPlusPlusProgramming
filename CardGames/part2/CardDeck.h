// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Interface for CardDeck class
// Which uses a deque (template) to 
// sotre a "deck of cards"

#include <iostream>
#include <deque>

using namespace std;

class CardDeck
{
	friend ostream &operator<<( ostream &, const CardDeck & );	// we are overloading the ostream as a global function, so we point to it

	public:
		CardDeck( int = 52 );	// non-default constructor - will populate deque
		int getSize() const;	// gets the current size of the card deck
		void shuffle();		// shuffles the card deck instance
	private:
		deque<int> ourDeck;	// this deque will hold the card values
};
	
