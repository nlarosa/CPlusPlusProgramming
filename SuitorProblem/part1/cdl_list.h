// Nicholas LaRosa
// CSE 20212, Lab 5
//
// Circular Doubly-Linked List
// Last element points to first element

#ifndef CDL_LIST_H
#define CDL_LIST_H

#include <iostream>
#include <deque>

using namespace std;

template <typename T>
class cdl_list
{
	public:
		cdl_list();
		~cdl_list();
		void insertFromFront( T );	// insert element in front
		void insertFromBack( T );	// insert element in back
		void deleteFront();		// removes front element
		void deleteBack();		// removes back element
		bool isEmpty();			// return true if empty
		void print();			// displays current data
	private:
		deque<T> container;
		int current;			// index to the current element
};

template <typename T>
cdl_list<T>::cdl_list()				// default constructor
	: current( 0 )
{}

template <typename T>
cdl_list<T>::~cdl_list()			// deconstructor
{}

template <typename T>
void cdl_list<T>::insertFromFront( T obj )	// adds front element
{
	container.push_front( obj );		// adds object of type T to front
}

template <typename T>
void cdl_list<T>::insertFromBack( T obj )	// adds back element
{
	container.push_back( obj );		// adds object of type T to back
}

template <typename T>
void cdl_list<T>::deleteFront()			// removes front element
{
	container.pop_front();			// removes object of type T from front
}

template <typename T>
void cdl_list<T>::deleteBack()			// removes back element
{
	container.pop_back();			// removes object of type T from front
}

template <typename T>
bool cdl_list<T>::isEmpty()			// returns true if the cdl_list is empty
{
	return container.empty();		// checks for size of 0
}

template <typename T>
void cdl_list<T>::print()			// prints the deque in a nice format
{
	int count = 1;
	deque<int>::const_iterator iStart = container.begin();			// begin iterator

        cout << endl << "\t";

	for( iStart; iStart != container.end(); ++iStart )			// iterate through the deque
	{
		if( count % 10 != 0 )	cout << *iStart << ", ";
		else
		{
			if( container.getSize() % 10 == 0 && count == container.getSize() )	cout << *iStart;			// no new line necessary
                        else									cout << *iStart << endl << "\t";	// new line after every ten deck elements
		}
		
		count++;
	}

	cout << endl;
}

#endif

