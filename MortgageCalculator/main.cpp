#include <iostream>
#include <iomanip>
#include "mortgage.h"

using namespace std;

int main()
{
	Mortgage first;				// using default constructor
	Mortgage second( 10000, 5, 500 );	// using non-default constructor
	
	cout << "\nError-check on invalid principal: ";
	Mortgage error1( -10000, 5, 500 );	// testing for error from invalid principal amount (negative)
	
	cout << "Error-check on invalid interest (below 0): ";
	Mortgage error2_1( 10000, -5, 500 );	// testing for error from invalid interest rate (below 0)
	
	cout << "Error-check on invalid interest (above 100): ";
	Mortgage error2_2( 10000, 105, 500 );	// testing for error from invalid interest rate (above 100)
	
	cout << "Error-check on invalid payment: ";
	Mortgage error3( 10000, 5, -500 );	// testing for error from invalid payment amount (negative)

	cout << "Error-check on multiple constructing invalidities: ";
	Mortgage error4( -100, -5, -50 );	// testing for multiple invalid inputs

	cout << "\nInitial principal of first mortgage: " << first.getPrincipal() << endl;
	first.credit( 10000 );			// credit the first mortgage with a $10000 payment
	cout << "Initial principal of a formerly invalid mortgage: " << error1.getPrincipal() << endl;
	error1.credit( 1000 );	

	cout << "\nPrincipal of the first mortgage after a $10000 credit: " << first.getPrincipal() << endl;
	cout << "Principal of the formerly invalid mortgage after a $1000 credit: " << error1.getPrincipal() << endl;
	
	cout << "Error-check on invalid credit: ";
	first.credit( -1000 );			// testing for error from invalid credit amount (negative)
	
	Mortgage error5( 0, 5, 5 );
	cout << "Error-check on paid-off mortgage: ";
	error5.credit( 100 );			// testing for error when attempting to credit a mortgage that has been paid off

	cout << "\nAmortization table of the second mortgage:" << endl;
	second.amortize();
}

