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
		cdl_list();			// default constructor 
		~cdl_list();			// deconstructor
		void insertFromFront( T );	// insert element in front
		void insertFromBack( T );	// insert element in back
		void deleteFront();		// removes front element
		void deleteBack();		// removes back element
		bool isEmpty();			// return true if empty
		void print();			// displays current data

		void reset();			// make the "current" element the front (0-index)
		void next();			// make the "current" element point to next
		void previous();		// make the "current" element point to the previous
		T currentValue();		// return the data at the current index
		void removeNode();		// remove the element pointed to by current
		cdl_list<T> & operator++();	// prefix increment operator (passes by reference, object itself incremented)
		cdl_list<T> operator++( int );	// postfix increment operator (returns original object, then increment)
		cdl_list<T> & operator--();	// prefix decrement operator
		cdl_list<T> operator--( int );	// postfix decrement operator
	private:
		deque<T> container;
		int current;			// index to the current element
};

template <typename T>
cdl_list<T>::cdl_list()				// default constructor
	: current( 0 )				// initialize the initial element to the zero index
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
			if( container.size() % 10 == 0 && count == container.size() )		cout << *iStart;			// no new line necessary
                        else									cout << *iStart << endl << "\t";	// new line after every ten deck elements
		}
		
		count++;
	}

	cout << endl;
}

template <typename T>
void cdl_list<T>::reset()			// make the current element "point" to the front of the container
{
	current = 0;
}

template <typename T>
void cdl_list<T>::next()			// make the current element "point" to the next element in the container
{
	if( ++current == container.size() )	reset();		// if the next index is out of bounds, reset to zero (circular)
}									// or else allow the index to be incremented
	
template <typename T>
void cdl_list<T>::previous()			// make the current element "point" to the previous element in the container
{
	if( --current < 0 )			current = container.size() - 1;		// if the previous index is out of bound, reset to end (circular)
}

template <typename T>
T cdl_list<T>::currentValue()			// returns the data at the current index
{
	return container[current];
}

template <typename T>
void cdl_list<T>::removeNode()			// removes the current index-ed element
{
	container.erase(container.begin()+current);	// erases the current position
	previous();					// move to the previous position
}

template <typename T>
cdl_list<T> & cdl_list<T>::operator++()		// prefix increment
{
	next();					// increments current "pointer"
	return *this;				// returns a reference
} 

template <typename T>
cdl_list<T> cdl_list<T>::operator++( int )	// postfix increment
{
	cdl_list<T> temp = *this;
	next();					// increments current "pointer"
	return temp;				// return a value (object)
}

template <typename T>
cdl_list<T> & cdl_list<T>::operator--()		// prefix decrement
{
	previous();				// decrements current "pointer"
	return *this;				// returns a reference
} 

template <typename T>
cdl_list<T> cdl_list<T>::operator--( int )	// postfix decrement
{
	cdl_list<T> temp = *this;
	previous();				// decrements current "pointer"
	return temp;				// return a value (object)
}	

#endif

