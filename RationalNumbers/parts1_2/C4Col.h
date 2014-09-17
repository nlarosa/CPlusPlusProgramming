// Nicholas LaRosa
// CSE 20212, Lab 1
//
// Interface file for Connect 4 column class
// Written by Dr. Scott Emrich

#ifndef C4COL_H
#define C4COL_H

#include <iostream>

using namespace std;

class C4Col		// column of a Connect 4 board	
{  
	public:
		C4Col();  			// default constructor
		int isFull();        		// returns 1 if column full, 0 otherwise
		void addDisc(char);  		// adds a character disc to column: 'X' or 'O' depending on player
		void removeDisc();		// removes the top disc from the specified column
		char getDisc(int) const;   	// returns this element from a column
		int getMaxDiscs() const;  	// get function for maxDiscs data member
		int getNumDiscs() const;	// get function for numDiscs data member
		C4Col operator+=(char);		// overriding the += operator	

	private:
		int numDiscs;    		// current number of discs, starts at 0
		int maxDiscs;    		// maximum number of discs, 6 for normal game
		char Discs[10];  		// array to store disc chars
};

#endif
