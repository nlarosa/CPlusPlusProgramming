// Nicholas LaRosa
// CSE 20212, Lab 1
//
// Implementation for Connect 4 board class

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C4Col.h"
#include "C4Board.h"

#define MAX_COLUMNS 7

C4Board::C4Board()		// default constructor where we set the number of columns in use
{
	canContinue = 1;
	numColumns = MAX_COLUMNS;
	Board = new C4Col[numColumns];	// dynamically allocate enough columns for a board
}
	
C4Board::~C4Board()		// deconstructor to erase heap space when done
{
	delete [] Board;
}

void C4Board::display()		// displays the current board to the screen
{
	int rowNum;
	int colNum;
	int count = 0;		// keep count of column labels
	int previous = 0;

	cout << endl << "\t";

	for( colNum = 0; colNum < numColumns; colNum++ )				// print column labels	
	{
		if( count == 0 )		
		{
			cout << "  " << colNum;
			count++;
		}		

		else if( previous < 10 )	cout << "   " << colNum;
		else				cout << "  " << colNum;		
		
		previous = colNum;
	}

	cout << endl;

	for( rowNum = (Board[0].getMaxDiscs()-1); rowNum >= 0; rowNum-- )		// finds how many discs are in a column and increments down (height of board)
	{
		cout << "\t";		

		for( colNum = 0; colNum < numColumns; colNum++ )
		{
			cout << "| " << Board[colNum].getDisc(rowNum) << " ";
		}
		
		cout << "|";
		cout << endl;
	}

	cout << "\t ";

	for( colNum = 0; colNum < numColumns; colNum++ )
	{
		cout << "____";
	}
	
	cout << endl << endl;
}

char C4Board::getPlayer( int player )								// converts from player number to player disc type (character)
{
	if( player == 1 )	return 'X';
	else			return 'O';
}

int C4Board::boardIsFull()								// check to see if the board is full or not
{
	int column;

	for( column = 0; column < numColumns; column++ )
	{
		if( !Board[column].isFull() )	return 0;;				// return 0 if any column is not full
	}

	return 1;									// return 1 if all columns are full
}

int C4Board::getMove( int player )							// get the player's move and make sure it is valid	
{
	int column;
	int col;			// we need to check all top pieces to make sure new Connect 4's are accounted for

	cout << "Player " << player << ", please select a column for your next disc: ";
	if( !( cin >> column ) )			// check to make sure we have an integer input from user
	{
		cin.clear();				// clear buffer and ignore incorrect input
		cin.ignore(4096, '\n');	
		return getMove( player );		// let the player go again
	}
	else if( column == -1 )				// command to end game
	{
		cout << "Thanks for playing!" << endl;
		canContinue = 0;			// do not replay the game
		return 1;
	}
	else if( column >= numColumns || column < 0 )	// specified column is out of bounds
	{
		cout << "Invalid move. Please choose a column between 0 and " << numColumns-1 << "." << endl;
		return getMove( player );		// let the player go again
	}
	else if( Board[column].isFull() )		// check for full column
	{
		cout << "That column is full. Please select another column." << endl;
		return getMove( player );
	}
	else
	{
		if( player == 1 )	Board[column].addDisc('X');	// player 1
		else			Board[column].addDisc('O');	// player 2
		
		for( col = 0; col < numColumns; col++ )			// checking the top piece at each column
		{
			if( checkMove( col, player ) ) 		return 1;
		}
		
		return 0;						// no Connect 4's were found
	}
}

int C4Board::checkMove( int column, int player )					// checks the specified player's move to see if four discs were connected
{
	int currDiscNum = Board[column].getNumDiscs();		// access private data member numDiscs

	if( Board[column].getDisc(0) == '.' )	return 0;			// do not check move if there the column is empty
	else if( Board[column].getDisc(currDiscNum-1) == 'X') 	player = 1;	// reset the player numbers in case they are wrong
	else 							player = 2;
	
	if( column == 0 )				// disc has been placed in left-most column
	{
	//	cout << "Farthest left column." << endl;
		
		if( currDiscNum == 1 )			// there is only one disc in this column, cannot check down
		{
			if( checkRight( column, player, 1 ) || checkUp( column, player, 1 ) || checkUpRight( column, player, 1 ) ) 	return 1;
			else		return 0;		//if any return successful exit code, return 1
		}
		else if( Board[column].isFull() )		// column is now full, cannot check up
		{	
			if( checkRight( column, player, 1 ) || checkDn( column, player, 1 ) ||  checkDnRight( column, player, 1 ) )	return 1;
			else		return 0;
		}
		else					// disc is in the middle of the row, check anywhere not to the left
		{
			if( checkRight( column, player, 1 ) ||  checkUp( column, player, 1 ) || checkUpRight( column, player, 1 ) || checkDn( column, player, 1 ) || checkDnRight( column, player, 1 ) )	return 1;
			else		return 0;
		}
	}
	else if( column == numColumns-1 )		// disk has been placed in right-most column
	{
	//	cout << "Farthest right column." << endl;

		if( currDiscNum == 1 )			// there is only one disc in this column, cannot check down
		{
			if( checkLeft( column, player, 1 ) || checkUp( column, player, 1 ) || checkUpLeft( column, player, 1 ) )	return 1;
			else 		return 0;
		}
		else if( Board[column].isFull() )		// column is now full, cannot check up
		{	
			if( checkLeft( column, player, 1 ) || checkDn( column, player, 1 ) || checkDnLeft( column, player, 1 ) )	return 1;
			else		return 0;
		}
		else					// disc is in the middle of the row, check anywhere not to the right
		{
			if( checkLeft( column, player, 1 ) || checkUp( column, player, 1 ) || checkUpLeft( column, player, 1 ) || checkDn( column, player, 1 ) || checkDnLeft( column, player, 1 ) ) 		return 1;
			else		return 0;
		}
	}
	else if( currDiscNum == 1 )			// disk has been placed at bottom of the board ( corners are caught in earlier conditionals )
	{
	//	cout << "Bottom row." << endl;

		if( checkUp( column, player, 1 ) || checkUpRight( column, player, 1 ) || checkUpLeft( column, player, 1 ) || checkRight( column, player, 1 ) || checkLeft( column, player, 1 ) )		return 1;
		else			return 0;
	}
	else if( Board[column].isFull() )		// disk has been placed at top of the board ( corners are caught in earlier conditionals )
	{
	//	cout << "Top row." << endl;

		if( checkDn( column, player, 1 ) ||  checkDnRight( column, player, 1 ) || checkDnLeft( column, player, 1 ) || checkRight( column, player, 1 ) || checkLeft( column, player, 1 ) )		return 1;
		else			return 0;
	}
	else						// disk has been placed in the middle of the board, check all directions
	{
	//	cout << "Middle of board." << endl;
	
		if( checkUp( column, player, 1 ) || checkUpRight( column, player, 1 ) || checkRight( column, player, 1 ) || checkDnRight( column, player, 1 ) || checkDn( column, player, 1 ) || checkDnLeft( column, player, 1 ) || checkLeft( column, player, 1 ) || checkUpLeft( column, player, 1 ) )	return 1;
		else			return 0;
	}
}

int C4Board::checkUp( int origColumn, int player, int currConnect )			// checks upward for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );			// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();	// access private data member numDiscs

	int column = origColumn;
	int row = currDiscNum + currConnect - 1;

	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space
	
	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )			// go up in the same column
	{	
		currConnect++;
		//cout << currConnect << endl;
	
		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl;
			return 1;
		}
		else		checkUp( origColumn, player, currConnect );
	}
	else	return 0;
}

int C4Board::checkUpRight( int origColumn, int player, int currConnect )		// checks up to right for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );		// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();		// access private data member numDiscs
	
	int column = origColumn + currConnect;
	int row = currDiscNum + currConnect - 1;
		
	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space
		
	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )	// go up in column to the right
	{
		currConnect++;
		//cout << currConnect << endl;
	
		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl;
			return 1;
		}
		else		checkUpRight( origColumn, player, currConnect );
	}
	else	return 0;
}

int C4Board::checkRight( int origColumn, int player, int currConnect )			// checks to right for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );		// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();		// access private data member numDiscs

	int column = origColumn + currConnect;
	int row = currDiscNum - 1;

	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space	

	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )			// go across in column to the right
	{
		currConnect++;
		//cout << currConnect << endl;	

		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl;
			return 1; 
		}
		else		checkRight( origColumn, player, currConnect );
	}
	else	return 0;
}

int C4Board::checkDnRight( int origColumn, int player, int currConnect )		// checks down to right for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );		// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();		// access private data member numDiscs

	int column = origColumn + currConnect;
	int row = currDiscNum - currConnect - 1;

	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space

	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )	// go down in column to the right
	{
		currConnect++;
		//cout << currConnect << endl;
			
		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl;
			return 1;
		}
		else		checkDnRight( origColumn, player, currConnect );
	}
	else	return 0;
}

int C4Board::checkDn( int origColumn, int player, int currConnect )			// checks downward for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );		// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();		// access private data member numDiscs

	int column = origColumn;
	int row = currDiscNum - currConnect - 1;

	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds	
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space
	
	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )			// go down in the same column
	{	
		currConnect++;
		//cout << currConnect << endl;

		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl;
			return 1;
		}
		else		checkDn( origColumn, player, currConnect );
	}
	else	return 0;
}

int C4Board::checkDnLeft( int origColumn, int player, int currConnect )			// checks down to left for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );		// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();		// access private data member numDiscs

	int column = origColumn - currConnect;
	int row = currDiscNum - currConnect - 1;

	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space

	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )	// go down in column to the left
	{	
		currConnect++;
		//cout << currConnect << endl;
		
		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl;
			return 1;
		}
		else		checkDnLeft( origColumn, player, currConnect );
	}
	else	return 0;
}

int C4Board::checkLeft( int origColumn, int player, int currConnect )			// checks to left for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );		// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();		// access private data member numDiscs

	int column = origColumn - currConnect;
	int row = currDiscNum - 1;
	
	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space

	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )			// go left in same column
	{		
		currConnect++;
		//cout << currConnect << endl;	
		
		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl;
			return 1;
		}
		else		checkLeft( origColumn, player, currConnect );
	}
	else	return 0;
}
		
int C4Board::checkUpLeft( int origColumn, int player, int currConnect )			// checks up to left for similar discs, using the original added disc column
{
	char playerChar = getPlayer( player );		// convert to disc character
	int currDiscNum = Board[origColumn].getNumDiscs();		// access private data member numDiscs

	int column = origColumn + currConnect;
	int row = currDiscNum + currConnect - 1;

	if( column >= numColumns || column < 0 || row >= Board[0].getMaxDiscs() || row < 0 )	return 0;	// do not check out of bounds
	else if( Board[column].getDisc(row) == '.' )						return 0;	// do not check empty space

	//cout << "Checking coordinates (col, row): (" << column << "," << row << ")" << endl;

	if( Board[column].getDisc(row) == playerChar )	// go up in column to the left
	{
		currConnect++;
		//cout << currConnect << endl;
	
		if( currConnect == 4 )	// we have a connect 4
		{
			cout << "Player " << player << " wins! Good game!" << endl << endl;
			return 1;
		}
		else		checkUpLeft( origColumn, player, currConnect );
	}
	else	return 0;
}

int C4Board::computerMove()								// the computer acts as player 2 and if not Connect 4, makes random move
{
	int connectExists = 0;				// boolean if Connect 4 exists
	int currentColumn;				// where computer is checking placement
	int column;					// iterator to check each possible column
	int col;					// iterator to check side effects of discs
	
	for( column = 0; column < numColumns; column++ )
	{
		if( !Board[column].isFull() )
		{
			Board[column].addDisc('O');		// computer is player 2
		
			for( col = 0; col < numColumns; col++ )			// checking the top piece at each column
			{
				if( checkMove( col, 2 ) ) 
				{
					connectExists = 1;
					cout << "Player 2 places disc in column " << column << "." << endl;
					return 1;				// if a Connect 4 was found, computer makes move and we exit
				}
			}
		
			Board[column].removeDisc();		// reset top disc if no Connect 4's were found
		}
	}		
	
	srand( time( NULL ) );				// seed random number generator	
	column = rand() % ( numColumns - 1 );		// generate a random column
	Board[column].addDisc('O');			// we know no Connect 4 exists, so we do not have to check again for connections
	cout << "Player 2 places disc in column " << column << "." << endl;

	return 0;
} 	

void C4Board::promptUser()								// ask user if they would like to play again (changes canContinue boolean)
{
	char answer;

	cout << "Would you like to play again? (y)es or (n)o: ";
	
	if( !( cin >> answer ) )			// check to make sure we have a char input from user
	{
		cin.clear();				// clear buffer and ignore incorrect input
		cin.ignore(4096, '\n');
	}

	if( answer == 'y' )		canContinue = 1;
	else if( answer == 'n' )	canContinue = 0;
	else				promptUser();
}

int C4Board::weCanContinue()								// get function for canContinue boolean
{
	return canContinue;
}

void C4Board::play()
{
	int turnNumber = -1;
	int player = ( turnNumber % 2 ) + 1;			// retrieve player number from turn number
	int stopGame = 0;

	while( !stopGame )				// a return value of 1 corresponds to the game being over 
	{
		if( boardIsFull() )			// check if the board is full every turn, end if so
		{
			cout << "The game is a draw! The board has been entirely filled with discs." << endl;
			return;
		}
		
		turnNumber++;
		player = ( turnNumber % 2 ) + 1;			// retrieve player number from turn number
	
		usleep(1000000);	
		printf("\033[2J\033[H");
		cout << "\n\tWelcome to Connect 4!\n\nThis is a two-player game in which each player attempts to connect\nfour of their \"discs\" in whatever direction possible. Good luck!\n";
		display();

		if( player == 1 )	stopGame = getMove( player );		// user chooses as player 1
		else if( player == 2 )	stopGame = computerMove();		// computer is player 2
	}

	cout << endl << "Final board:" << endl;
	display();
	
	if( canContinue )	promptUser();		// if the user hasn't already ended the game, ask them if they want to
	cout << endl;
}

