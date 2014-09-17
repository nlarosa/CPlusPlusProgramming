// Nicholas LaRosa
// CSE 20212, Lab 2
//
// Implementation for Rational class
// Allows for non-default constructor
// Overloads arithmetic operators
//

#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational()						// default constructor initializes rational to 1/1
{
	numerator = 1;
	denominator = 1;
}

Rational::Rational( int userNumerator, int userDenominator )	// non-default constructor allows the user to specify the numerator and denominator
{
	if( userNumerator == 0 )
	{
		numerator = 0;
		denominator = 1;		// simplify the denominator if number is zero
	}	
	else if( userDenominator == 0 )
	{	
		numerator = userNumerator;
		cout << "A denominator of 0 is not allowed; it has instead been set to 1." << endl;
		denominator = 1;
	}
	else
	{
		numerator = userNumerator;
		denominator = userDenominator;			
		findGCD();			// if neither is zero, we can proceed to reduce if necessary
	
		if( denominator < 0 )		// if negative, we want the numerator to have the sign
		{
			numerator *= -1;
			denominator *= -1;
		}
	}
}

ostream & operator<<( ostream &output, const Rational &ourNumber )	// overload the output stream to print a rational object
{
	output << "( " << ourNumber.getNumerator() << "/" << ourNumber.getDenominator() << " )";
	
	return output;
}

int Rational::getNumerator() const				// get function for instance numerator
{
	return numerator;
}

int Rational::getDenominator() const				// get function for instance denominator
{
	return denominator;
}

void Rational::findGCD()					// member function that reduces the numerator and denominator
{								// ie. divides both numerator and denominator by GCD, storing in class variables
	int larger = 1;		
	int smaller = 1;		// for Euclidean algorithm, we need to store which number is larger, smaller
	int modulus = 1;

	if( numerator == denominator )		// if the numerator and denominator are the same, we know the total number is 1
	{
		numerator = 1;
		denominator = 1;
		return;				// end if this is the case
	}		
	else if( numerator > denominator )	// numerator is bigger
	{
		larger = numerator;
		smaller = denominator;
	}
	else					// denominator is bigger
	{
		larger = denominator;
		smaller = numerator;
	}

	while( modulus != 0 )			// this is the Euclidean algorithm for the GCD
	{
		modulus = larger % smaller;	// first find the modulus of the two numbers of interest
		larger = smaller;		// the former divisor is then divided by the modulus on the next pass
		smaller = modulus;		// until the modulus remainder is zero, then we know the GCD
	}

	numerator /= larger;			// the larger variable is the GCD (because the smaller is 0)
	denominator /= larger;			// so divide both the numerator and denominator by it to simplify

	return;
}

Rational Rational::operator+( const Rational &ourRational )	// allows for the addition of two rational numbers
{
	int numerator1 = numerator;
	int denominator1 = denominator;

	int numerator2 = ourRational.getNumerator();
	int denominator2 = ourRational.getDenominator();

	denominator1 *= ourRational.getDenominator();
	denominator2 *= denominator;
							// multiplying numerator and denominator of each rational number by same number
	numerator1 *= ourRational.getDenominator();	// to get a common denominator
	numerator2 *= denominator;

	Rational temp( numerator1+numerator2, denominator1 );

	return temp;
}

Rational Rational::operator-( const Rational &ourRational )	// allows for the subtraction of two rational numbers
{
	int numerator1 = numerator;
	int denominator1 = denominator;

	int numerator2 = ourRational.getNumerator();
	int denominator2 = ourRational.getDenominator();

	denominator1 *= ourRational.getDenominator();
	denominator2 *= denominator;
							// multiplying numerator and denominator of each rational number by same number
	numerator1 *= ourRational.getDenominator();	// to get a common denominator
	numerator2 *= denominator;

	Rational temp( numerator1-numerator2, denominator1 );

	return temp;
}

Rational Rational::operator*( const Rational &ourRational )	// allows for the multiplication of two rational numbers
{
	int numerator1 = numerator;
	int denominator1 = denominator;

	int numerator2 = ourRational.getNumerator();
	int denominator2 = ourRational.getDenominator();

	numerator1 *= numerator2;
	denominator1 *= denominator2;				// multiply both the numerator and denominator by eachother

	Rational temp( numerator1, denominator1 );

	return temp;
}

Rational Rational::operator/( const Rational &ourRational )	// allows for the division of two rational numbers
{
	int numerator1 = numerator;
	int denominator1 = denominator;

	int numerator2 = ourRational.getNumerator();
	int denominator2 = ourRational.getDenominator();

	numerator1 *= denominator2;				// multiply the first rational by the reciprocal of the second
	denominator1 *= numerator2;

	Rational temp( numerator1, denominator1 );		// and return the first (order matters)

	return temp;
}

Rational Rational::operator%( const Rational &ourRational )	// returns the modulus of two rational numbers
{
	int numerator1 = numerator;
	int denominator1 = denominator;

	int numerator2 = ourRational.getNumerator();
	int denominator2 = ourRational.getDenominator();

	denominator1 *= ourRational.getDenominator();
	denominator2 *= denominator;
							// multiplying numerator and denominator of each rational number by same number
	numerator1 *= ourRational.getDenominator();	// to get common denominator
	numerator2 *= denominator;			// then we will return the numerator as the modulus

	if( numerator2 == 0 )	
	{
		cout << "The modulus operator cannot be performed with a value of zero. The zero value has been changed to 1 for this operation." << endl;
		numerator2 = 1;
	}

	Rational temp( numerator1%numerator2, denominator1 );

	return temp;
}

int Rational::operator==( const Rational &ourRational )		// returns true if the rationals are the same, false otherwise
{
	if( numerator == ourRational.getNumerator() )
	{
		if( denominator == ourRational.getDenominator() )
		{
			return 1;				// if both the numerator and denominator are the same, we know the rationals are the same
		}
	}

	return 0;
}
