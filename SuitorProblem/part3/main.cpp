// Nicholas LaRosa
// CSE 20212, Lab 5
//
// Driver program for suitor problem
// Displays the spot where Wesley should stand

#include <iostream>
#include "cdl_list.h"

using namespace std;

int getUserInput()				// returns a positive integer entered by the user
{
	int userInput;

	cout << endl << "Enter a positive integer number of suitors: ";

	if( !( cin >> userInput ) )			// check to make sure we have an integer input from user
        {
		cin.clear();				// clear buffer and ignore incorrect input
		cin.ignore(4096, '\n');
        	return getUserInput();			// try again
	}
	else	
	{
		if( userInput > 0 )		return userInput;	// user entered a positive integer
		else				return getUserInput();	// try again
	}
}

int main()
{
	cdl_list<int> ourSuitors;		// instantiate cdl_list with integers to represent suitors

	int userN;				// user input into how many suitors are in the selection pool
	int previousDeletion = 10;		// store the last element to be deleted
	int count = 1;				// keep count of suitor to delete every third

	userN = getUserInput();			// get user input via function

	for( int i = 1; i <= userN; i++ )	// populate the list of suitors in ascending order
	{
		ourSuitors.insertFromBack( i );	// add each number to the end of the list
	}

	ourSuitors.print();

	while( !ourSuitors.isEmpty() )		// continue deleting "suitors" until the list is empty
	{
		if( count == 3 )
		{
			previousDeletion = ourSuitors.currentValue();	
			ourSuitors.removeNode();
			ourSuitors.print();
			count = 0;
		}

		ourSuitors.next();		// go to the next suitor
		count++;			// increment the count to three, then reset	
	}
						// once the list is empty, we know that the last deletion was the last remaining suitor

	cout << "Wesley, you must be suitor number " << previousDeletion << " to win Buttercup's hand!" << endl << endl;
}
	
