// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Driver program for CardDeck class
// Perform three monkey shuffles each
// on decks of 7, 8, 9 cards

#include <iostream>
#include "CardDeck.h"

using namespace std;

int main()
{
	CardDeck myDeck1( 7 );			// initializes card decks of 7,8,9 elements
	CardDeck myDeck2( 8 );
	CardDeck myDeck3( 9 );	

	int i;					// for-loop counter
	int shuffleCount;			// shuffle counter

	cout << endl << "Monkey Sorting Time!" << endl << endl;
		
	// begin monkey sorting for myDeck1
	
	for( i = 1; i <= 3; i++ )
	{
		shuffleCount = 1;			// keep track of shuffles performed
		myDeck1.shuffle();			// begin with a shuffle

		while( !myDeck1.inOrder() )		// while the deck is not in order
		{
			myDeck1.shuffle();
			shuffleCount++;
		}
		
		cout << "Sorting #" << i << " completed on deck of size " << myDeck1.getSize() << ". Total shuffles: " << shuffleCount << "." << endl;
	}

	cout << endl;

	// begin monkey sorting for myDeck2
	
	for( i = 1; i <= 3; i++ )
	{
		shuffleCount = 1;			// keep track of shuffles performed
		myDeck2.shuffle();			// begin with a shuffle

		while( !myDeck2.inOrder() )		// while the deck is not in order
		{
			myDeck2.shuffle();
			shuffleCount++;
		}
		
		cout << "Sorting #" << i << " completed on deck of size " << myDeck2.getSize() << ". Total shuffles: " << shuffleCount << "." << endl;
	}

	cout << endl;

	// begin monkey sorting for myDeck3
	
	for( i = 1; i <= 3; i++ )
	{
		shuffleCount = 1;			// keep track of shuffles performed
		myDeck3.shuffle();			// begin with a shuffle

		while( !myDeck3.inOrder() )		// while the deck is not in order
		{
			myDeck3.shuffle();
			shuffleCount++;
		}
		
		cout << "Sorting #" << i << " completed on deck of size " << myDeck3.getSize() << ". Total shuffles: " << shuffleCount << "." << endl;
	}

	cout << endl;
}

