// Nicholas LaRosa
// CSE 20212, Lab 6
//
// Driver Program
// Creates Sudoku Puzzles from files
// and solves them, displaying solution

#include <iostream>
#include "Puzzle.h"

using namespace std;

int main( int argc, char *argv[] )
{
	if( argc == 1 || argc > 2 )
	{
		cout << "Usage: ./main [sudoku_file]" << endl;
		return 1;
	}

	Puzzle sudoku( argv[1] );

	sudoku.solve();
	
	return 0;
}
