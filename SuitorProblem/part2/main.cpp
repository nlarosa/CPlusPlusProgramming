// Nicholas LaRosa
// CSE 20212, Lab 5
//
// Driver program for cdl_list object
// Instantiates cdl_lists of different types

#include <iostream>
#include "cdl_list.h"

using namespace std;

int main()
{
	cdl_list<int> intList;			// instantiate cdl_list with integers

	int i;

	for( i = 3; i <= 9; i++ )
	{
		intList.insertFromBack( i );	// add items to the list
	}

	cout << "Circular Doubly Linked List!" << endl << endl;
	cout << "Original list:" << endl; 
	intList.print();			// print original

	cout << endl << "The first element is: " << intList.currentValue() << endl;
	
	for( i = 0; i < 5; i++ )		// print ten items in a row
	{
		++intList;			// iterate current element (prefix)
		cout << "The next element (using prefix) is: " << intList.currentValue() << endl;
	}

	cout << endl;

	for( i = 0; i < 5; i++ )		// print the next ten items
	{
		intList++;
		cout << "The next element (using postfix) is: " << intList.currentValue() << endl;
	}

	cout << endl;

	for( i = 0; i < 5; i++ )		// print the previous ten items
	{
		--intList;			// iterate current element (prefix)
		cout << "The previous element (using prefix) is: " << intList.currentValue() << endl;
	}

	cout << endl;

	for( i = 0; i < 5; i++ )		// print the previous ten items
	{
		intList--;
		cout << "The previous element (using postfix) is: " << intList.currentValue() << endl;
	}

	cout << endl << "Deleting the current element..." << endl;
	intList.removeNode();
	cout << "New list:" << endl;
	intList.print();

	if( intList.isEmpty() )		cout << endl << "According to the isEmpty() function, this list is now empty!" << endl;
	else				cout << endl << "According to the isEmpty() function, this list is not empty!" << endl;	

	cout << endl << "Inserting 0 in the front of the list: " << endl;
	intList.insertFromFront( 0 );
	intList.print();

	cout << endl << "Removing the front and back elements of the list: " << endl;
	intList.deleteFront();
	intList.deleteBack();
	intList.print();
	cout << endl;
}

