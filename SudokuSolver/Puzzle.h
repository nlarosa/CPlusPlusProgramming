// Nicholas LaRosa
// CSE 20212, Lab 6
//
// Puzzle class interface
// Contains constructor, solver, print

#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Puzzle					// interface for Package class
{
	public:
		Puzzle( string );		// constructor takes a filename (contains puzzle)
		void solve();			// solves the sudoku puzzle
		void printBoard();		// prints the sudoku puzzle
	private:
		void fillInitial();		// helper function to fill in possibilities
	
		void isolateHoriz();		// helper function to remove possibilities if contained in column
		void isolateVert();		// helper function to remove possibilities if contained in row
		void isolateSquare();		// helper funciton to remove possibilities if contained in square

		bool solveInit();		// helper function to fill in singletons
		bool solveHoriz();		// helper function to fill in singletons if contained in column (all return true if solution added)
		bool solveVert();		// helper function to fill in singletons if contained in row
		bool solveSquare();		// helper function to fill in singletons if contained in square

		vector< vector<int> > board;		// board is stored as a 2D vector
		vector< vector< vector<int> > > poss;	// possible values are stored in a 3D vector
};

#endif
