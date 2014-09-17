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

CardDeck::CardDeck( int sizeN )				// default constructor, initially fills deck with 52 cards
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

int CardDeck::getCard( int index )		// returns the card value at the specified index
{
	return ourDeck[index];
}

void CardDeck::shuffle()			// runs the random_shuffle on the card deck
{
	random_shuffle(ourDeck.begin(),ourDeck.end());				// random_shuffle algorithm
}

bool CardDeck::inOrder()			// returns 1 if the card deck is increasing order
{
	deque<int>::const_iterator iStart = ourDeck.begin();			// iterator for i-th element
	deque<int>::const_iterator iNext = ourDeck.begin();			// iterator for (i+1)-th element
	
	++iNext;				// the iNext iterator now corresponds to iterator after iStart

	for( iNext; iNext != ourDeck.end(); ++iNext )				// iterate through (i+1)-th element (make sure we don't run off)
	{
		if( *iNext < *iStart )		return false;			// incorrect order		
		++iStart;
	}

	return true;
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

