// Nicholas LaRosa
// CSE 20212, Lab 6
//
// Puzzle class implementation
// Construct board, puzzle solver
// Puzzle printer

#include <iostream>
#include <fstream>
#include "Puzzle.h"

#define SIZE 9					// size of our sudoku board

using namespace std;

Puzzle::Puzzle( string ourFile )		// non-default constructor sets puzzle filename
{
	string word;				// ifstream will read word by word
	int currentNum;
	int count = 0;
	vector<int> temp;

	ifstream dataFile( ourFile.c_str() );	// convert to char pointer	

	while( !dataFile.eof() )
	{
		dataFile >> word;			// redirect each word to temp string

		currentNum = word[0] - 48;		// we know the string is one character, convert to integer
	
		temp.push_back( currentNum );		// add a number to the temporary vector
		count++;

		if( count == SIZE )			// once we have added 9 integers to the vector
		{
			board.push_back( temp );			// adds a vector (ie. a row) to the class 2D vector
			temp.erase(temp.begin(), temp.end());		// erase the temporary vector
			count = 0;
		}
	}
}

void Puzzle::solve()
{
	fillInitial();					// gets the initial possibilities established

	isolateHoriz();
	isolateVert();
	isolateSquare();

	cout << endl << "Original board: " << endl << endl;
	
	printBoard();

	while( solveInit() || solveHoriz() || solveVert() || solveSquare() )		// while the solving functions can still add solutions
	{
		fillInitial();

		isolateHoriz();
		isolateVert();
		isolateSquare();
	}

	cout << "Final board: " << endl << endl;
	
	printBoard();
}

void Puzzle::fillInitial()				// fills the 3D vector with possibilities 1-9 
{
	vector<int> temp1D;				// holds each set of nine
	vector< vector<int> > temp2D;			// holds nine sets of nine

	poss.clear();					// clear the possibilities

	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			if( board[row][col] == 0 )	// only need to list possibilities for zero spaces
			{
				for( int i = 1; i <= SIZE; i++ )	// values of 1 through 9
				{
					temp1D.push_back(i);
				}
			}

			temp2D.push_back( temp1D );	// populating 2D vector with 1D vectors
			temp1D.clear();			// clear this vector
		}

		poss.push_back( temp2D );		// populating the possibilities 3D vector with 2D vectors
		temp2D.clear();				// clear this vector
	}	
}

void Puzzle::isolateHoriz()				// at every position, isolate possibilities based on horizontal members
{
	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			for( int i = 0; i < SIZE; i++ )		// checking every column (horizontal)
			{
				if( col == i )	continue;			// skip checking against itself
				else if( board[row][i] == 0 )	continue;	// zero spaces cannot help us
				else
				{
					for( int j = 0; j < poss[row][col].size(); j++ )	// for every possibility remaining
					{
						if( board[row][i] == poss[row][col][j] )
						{
							poss[row][col].erase( poss[row][col].begin() + j );	// remove that possibility if found in row
						}
					}
				}
			}
		}
	}
}

void Puzzle::isolateVert()				// at every position, isolate possibilities based on vertical members
{
	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			for( int i = 0; i < SIZE; i++ )		// checking every row (vertical)
			{
				if( row == i )	continue;			// skip checking against itself
				else if( board[i][col] == 0 )	continue;	// zero spaces cannot help us
				else
				{
					for( int j = 0; j < poss[row][col].size(); j++ )	// for every possibility remaining
					{
						if( board[i][col] == poss[row][col][j] )
						{
							poss[row][col].erase( poss[row][col].begin() + j );	// remove that possibility if found in row
						}
					}
				}
			}
		}
	}
}

void Puzzle::isolateSquare()				// at every position, isolate possibilities based on containing square
{
	int sqSize = SIZE / 3;
	int colStart;					// find the beginning column index (left)
	int rowStart;					// find the beginning row index (top)

	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			if( row < sqSize )		rowStart = 0;			// determine the row and col to begin the search
			else if( row < 2*sqSize )	rowStart = sqSize;
			else				rowStart = 2*sqSize;

			if( col < sqSize )		colStart = 0;
			else if( col < 2*sqSize )	colStart = sqSize;
			else				colStart = 2*sqSize;
			
			for( int r = rowStart; r < (rowStart + 3); r++ )		// row within square
			{
				for( int c = colStart; c < (colStart + 3); c++ )	// column within square
				{
					if( row == r && col == c )	continue;	// skip checking against itself
					else if( board[r][c] == 0 )	continue;	// zero spaces cannot help us
					else
					{
						for( int j = 0; j < poss[row][col].size(); j++ )	// for every possibility remaining
						{
							if( board[r][c] == poss[row][col][j] )
							{
								poss[row][col].erase( poss[row][col].begin() + j );	// remove that possibility if found in row
							}
						}
					} 
				}
			}
		}
	}
}

bool Puzzle::solveInit()				// enter solutions if there are single possibilities
{
	bool willReturn = false;

	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			if( poss[row][col].size() == 1 )	// singleton that can be chosen right away
			{
				board[row][col] = poss[row][col][0];
				willReturn = true;
			}
		}
	}

	return willReturn;
}

bool Puzzle::solveHoriz()				// fill in the board based on singletons in each column
{
	bool unique = false;				// if unique possibility (singeton) found
	bool willReturn = false;			// boolean to return (true if solution added)

	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			for( int currPoss = 0; currPoss < poss[row][col].size(); currPoss++ )		// for every possibility in the current index
			{
				for( int i = 0; i < SIZE; i++ )				// checking every column (horizontal)
				{
					if( col == i )	continue;				// skip checking against itselfi
					else if( poss[row][i].size() == 0 )	continue;	// skip empty
					else
					{
						for( int checkPoss = 0; checkPoss < poss[row][i].size(); checkPoss++ )	// for every possibility being checked
						{
							if( poss[row][col][currPoss] == poss[row][i][checkPoss] )	
							{
								unique = false;
								break;
							}
							else	unique = true;
						}
	
						if( !unique ) 	break;	
					}
				}
				
				if( unique )		// we have a unique possibility in the row
				{
					board[row][col] = poss[row][col][currPoss];
					willReturn = true;
					unique = false;
				}
			}
		}
	}

	return willReturn;
}

bool Puzzle::solveVert()				// fill in the board based on singletons in each row
{
	bool unique = false;				// if unique possibility (singleton) found
	bool willReturn = false;			// boolean to return (true if solution added)

	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			for( int currPoss = 0; currPoss < poss[row][col].size(); currPoss++ )		// for every possibility in the current index
			{
				for( int i = 0; i < SIZE; i++ )		// checking every row (vertical)
				{
					if( row == i )				continue;		// skip checking against itself
					else if( poss[i][col].size() == 0 )	continue;		// skip empty
					else
					{
						for( int checkPoss = 0; checkPoss < poss[i][col].size(); checkPoss++ )	// for every possibility being checked
						{
							if( poss[row][col][currPoss] == poss[i][col][checkPoss] )	
							{
								unique = false;
								break;
							}
							else	unique = true;	
						}	

						if( !unique ) 	break;
					}
				}
				
				if( unique )		// we have a unique possibility in the row
				{
					board[row][col] = poss[row][col][currPoss];	
					willReturn = true;
					unique = false;
				}
			}
		}
	}

	return willReturn;
}

bool Puzzle::solveSquare()				// at every position, isolate possibilities based on containing square
{
	int sqSize = SIZE / 3;
	int colStart;					// find the beginning column index (left)
	int rowStart;					// find the beginning row index (top)

	bool unique = false;				// if unique possibility (singleton) found
	bool willReturn = false;			// boolean to return (true if solution added)

	for( int row = 0; row < board.size(); row++ )
	{
		for( int col = 0; col < board[row].size(); col++ )
		{
			if( row < sqSize )		rowStart = 0;			// determine the row and col to begin the search
			else if( row < 2*sqSize )	rowStart = sqSize;
			else				rowStart = 2*sqSize;

			if( col < sqSize )		colStart = 0;
			else if( col < 2*sqSize )	colStart = sqSize;
			else				colStart = 2*sqSize;
		
			for( int currPoss = 0; currPoss < poss[row][col].size(); currPoss++ )	// for every possibility in the current position
			{
				for( int r = rowStart; r < (rowStart + 3); r++ )		// row within square
				{	
					for( int c = colStart; c < (colStart + 3); c++ )	// column within square
					{
						if( row == r && col == c )		continue;	// skip checking against itself
						else if( poss[r][c].size() == 0 )	continue;	// skip empty
						else
						{
							for( int checkPoss = 0; checkPoss < poss[r][c].size(); checkPoss++ )	// for every possibility being checked
							{
								if( poss[row][col][currPoss] == poss[r][c][checkPoss] )	
								{
									unique = false;
									break;
								}
								else	unique = true;
							}

							if( !unique ) 	break;
						} 
					}

					if( !unique )	break;
				}
	
				if( unique )
				{
					board[row][col] = poss[row][col][currPoss];
					willReturn = true;
					unique = false;
				}
			}
		}
	}

	return willReturn;
}

void Puzzle::printBoard()				// prints the 2D board to the screen
{
	int countRow = 0;				// keeping track of columns and rows to print nicely
	int countCol = 0;

	cout << " -------------------------" << endl;
	cout << " |";	

	for( int row = 0; row < board.size(); row++ )
	{
		if( countRow == SIZE/3 )
		{
			cout << " -------------------------" << endl;
			countRow = 0;		
		}

		for( int col = 0; col < board[row].size(); col++ )
		{
			if( countCol == SIZE/3 )	
			{
				cout << " |";			
				countCol = 0;
			}			

			cout << " " << board[row][col];
			
			countCol++;
		}

		cout << " |";	
		countRow++;
		cout << endl;
	}

	cout << " -------------------------" << endl << endl;	
}

