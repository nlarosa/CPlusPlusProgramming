// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Implementation for CardDeck class
// Initializes a deque and overloads ostream

#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>
#include "CardDeck.h"

using namespace std;

CardDeck::CardDeck( int sizeN )			// non-default constructor, initially fills deck
{	
	for( int i = 0; i < sizeN; i++ )
	{
		ourDeck.push_back(i);
	}

	srand( time( NULL ) );			// and provides seeding for random_shuffle
}

int CardDeck::getSize()	const			// returns the current number of cards in the deck
{
	return ourDeck.size();
}

void CardDeck::shuffle()			// runs the random_shuffle on the card deck
{
	random_shuffle(ourDeck.begin(),ourDeck.end());				// random_shuffle algorithm
}

ostream &operator<<( ostream &output, const CardDeck &argDeck )			// overload the ostream operator in order to print easily
{
	int count = 1;
	deque<int>::const_iterator iStart = argDeck.ourDeck.begin();		// begin iterator

	output << endl << "\t";

	for( iStart; iStart != argDeck.ourDeck.end(); ++iStart )		// iterate through the deque
	{	
		if( count % 10 != 0 )	output << *iStart << ", ";		
		else	
		{
			if( argDeck.getSize() % 10 == 0 && count == argDeck.getSize() )		output << *iStart;			// no new line necessary
			else									output << *iStart << endl << "\t";	// new line after every ten deck elements
		}

		count++;
	}

	output << endl;

	return output;
}

