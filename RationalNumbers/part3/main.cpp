// Nicholas LaRosa
// CSE 20212, Lab 2
//
// This is the main program that will run an "interactive"
// mode for our rational number class. The user will be asked
// for the numerator and denominator of two rational numbers,
// and then four mathematical functions will be performed.

#include <iostream>
#include "Rational.h"

int main()
{
	int numbers[4];		// create an array for easier input handling, first two index is first rational number, second two index is second number

	cout << endl;

	for( int i = 0; i < 4; i++ )			// we need four inputs ( two for rational numbers )
	{
		if( i == 0 )		cout << "Please enter an integer value for the numerator of rational number 1: ";	// get rational #1
		else if( i == 1 )	cout << "Please enter an integer value for the denominator of rational number 1: ";
		else if( i == 2 )	cout << "Please enter an integer value for the numerator of rational number 2: "; 	// get rational #2
		else 			cout << "Please enter an integer value for the denominator of rational number 2: ";

		if( !( cin >> numbers[i] ) )		// check to make sure we have an integer input from user
        	{
       			cin.clear();			// clear buffer and ignore incorrect input
        		cin.ignore(4096, '\n');
			i--;
                	continue;               	// ask the user again for the same number
        	}
	}

	Rational first( numbers[0], numbers[1] );	// first and second rational numbers
	Rational second( numbers[2], numbers[3] );
	Rational temp1;					// these numbers will store the mathematical return value
	Rational temp2;	

	cout << endl << "Mathematical functions, where x = " << first << " and y = " << second << ": " << endl << endl;

	cout << "\tx + y = " << first+second << endl;
	cout << "\tx - y = " << first-second << endl;
	cout << "\tx * y = " << first*second << endl;
	cout << "\tx / y = " << first/second << endl;
	cout << "\tx % y = " << first%second << endl << endl;

	temp1 = first + second;
	temp1 = temp1 * temp1;
	cout << "\t( x + y )*( x + y ) = " << temp1 << endl;

	temp1 = first - second;
	temp1 = temp1 * temp1;
	cout << "\t( x - y )*( x - y ) = " << temp1 << endl;
	
	temp1 = first + second;
	temp2 = first - second;
	cout << "\t( x + y )/( x - y ) = " << temp1/temp2 << endl;

	cout << "\t( x + y )%( x - y ) = " << temp1%temp2 << endl;

	cout << endl;

	if( first == second )	cout << "Using the logical equality operator, we found that x and y are equal!" << endl;
	else			cout << "Using the logical equality operator, we found that x and y are NOT equal!" << endl;

	cout << endl;
}
	
