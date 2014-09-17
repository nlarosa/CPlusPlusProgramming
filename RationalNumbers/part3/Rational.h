// Nicholas LaRosa
// CSE 20212, Lab 2
//
// Interface for new Rational class
// Includes helper function to find greatest common denominator
//

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational			// this class allows for arithmetic with rational numbers (ie. integer numerator and denominator)
{	
	friend ostream & operator<<( ostream &, const Rational & ); 	// lets us overload the ostream
									// to print the rational number in friendly format
	public:
		Rational();		// default constructor
		Rational( int, int );	// non-default constructor, user provided initial values

		int getNumerator() const;	// this function returns the numerator, will not modify anything
		int getDenominator() const;	// this function returns the denominator, will not modify anything

		Rational operator+( const Rational & );		// overloading arithmetic functions for our class
		Rational operator-( const Rational & );		// which return pointers to new objects
		Rational operator*( const Rational & );
		Rational operator/( const Rational & );
		Rational operator%( const Rational & );
		int operator==( const Rational & );
	
	private:
		void findGCD();		// returns the greatest common divisor between two integers
		int numerator;		// rational number hase integer numerator, denominator	
		int denominator;
};

#endif
