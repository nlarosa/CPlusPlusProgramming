// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Driver program for CardDeck class
// Initialize an array of 10 elements
// and print using the ostream

#include <iostream>
#include "CardDeck.h"

using namespace std;

int main()
{
	CardDeck myDeck( 10 );			// initializes a card deck of 10 elements
	
	cout << endl << "The created deck contains " << myDeck.getSize() << " cards." << endl << endl;
	
	cout << "Cards before shuffling: " << myDeck << endl;

	myDeck.shuffle();

	cout << "Cards after shuffling: " << myDeck << endl;
}

