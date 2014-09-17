// Nicholas LaRosa
// CSE 20212, Lab 1
//
// Implementation for Connect 4 Column class
// Define all functions to allow for adding discs,
// checking discs, checking for full column, and
// getting the max number of discs in a column

#include <iostream>
#include "C4Col.h"

#define INIT_DISCS 0			// each column begins with 0 discs and can hold 6 discs
#define MAX_DISCS 6

C4Col::C4Col()				// our default constructor
{
	numDiscs = INIT_DISCS;
	maxDiscs = MAX_DISCS;

	Discs = new char[maxDiscs];	// dynamically allocate for column size

	int i;

	for( i = numDiscs; i < maxDiscs; i++ )
	{
		Discs[i] = '.';
	}		
}

int C4Col::isFull()			// returns true if the column contains the maximum number of discs
{
	if( numDiscs == maxDiscs )	return 1;	// column is full
	else				return 0;	// column is not full
}

void C4Col::addDisc( char newDisc )	// adds the specified character (X or O) to the next available column position
{
	if( isFull() )		cout << "This column is full. Disc cannot be added." << endl;	// check for already-full column
	else			Discs[numDiscs++] = newDisc;					// adds to array and simultaneously increments numDiscs
}

void C4Col::removeDisc()		// removes the top disc of the specified column
{
	numDiscs--;			// make sure the disc number is updated	
	Discs[numDiscs] = '.';		// reset the position to empty
}

char C4Col::getDisc( int discIndex )		// returns the character (X or O) at the specified column index
{
	if( discIndex >= maxDiscs )					// check for no disc
	{
		cout << "There is no disc at this location." << endl;
		return '.';						// no disc at this location, return arbitrary character
	}
	else	return Discs[discIndex];
}

int C4Col::getMaxDiscs()			// returns the maximum number of discs in a column, determined by constructor (get function)
{
	return maxDiscs;
}

int C4Col::getNumDiscs()			// returns the current number of discs in a column
{
	return numDiscs;
}

