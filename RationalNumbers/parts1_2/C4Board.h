// Nicholas LaRosa
// CSE 20212, Lab 1
//
// Interface for Connect 4 board class

#ifndef C4BOARD_H
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"

using namespace std;

class C4Board			// board of the Connect 4 game
{
	friend ostream &operator<<( ostream &, const C4Board & );	// we are overloading the ostream as a global function, so we point to it
									// and the board it is given must be constant
	public:
		C4Board();		// default constructor
		void display();		// displays the current board to the screen
		void play();		// allows users to begin playing a Connect 4 game
		int weCanContinue();	// get function for canContinue boolean
	private:
		int canContinue;	// boolean to keep track of when to start new games or not
		int numColumns;		// keeps track of how many columns are actually in use
		C4Col Board[100];	// create column objects to be used in board
		
		void promptUser();			// ask the user if they'd like to play again
		char getPlayer( int );			// converts from player number to disc character
		int boardIsFull();			// returns true if the board is full

		int computerMove();			// AI, acting as player 2
		int getMove( int );			// gets user input and passes along exit code ( returns 1 if game is over )
		int checkMove( int, int );		// checks disc position and calls directional functions
		int checkUp( int, int, int );		// directional functions that recursively pass along the exit code
		int checkUpRight( int, int, int );
		int checkRight( int, int, int );
		int checkDnRight( int, int, int );
		int checkDn( int, int, int );
		int checkDnLeft( int, int, int );
		int checkLeft( int, int, int );
		int checkUpLeft( int, int, int );
};

#endif
