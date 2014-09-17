// Nicholas LaRosa
//
// Estimates pi with a user-defined number of terms
//
// Lab 0, January 22nd, 2013

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int userTerms;			// placeholder for user number of terms

	int currentTermNum;		// keep track of the term number we are dealing with
	int currentDenominator = 3;
	double currentSeries = 4; 	// keep track of the series value as terms are subtracted and added
	double currentTerm;
	double currentSign = -1;	// begin by subtracting the second term in the series
	
	cout << "\nWelcome to the Pi Estimator!\nYou will be asked for the number of terms of this series,\na number which must be greater than or equal to two.\n";
	cout << endl;

	do							// user will be asked for input at least once
	{
		cout << "Please enter the number of terms: ";
		if( !( cin >> userTerms ) )			// check to make sure we have an integer input from user
		{
			cin.clear();				// clear buffer and ignore incorrect input
			cin.ignore(4096, '\n');
		}
	}
	while( userTerms < 2 );					// we want user to specify two or more terms

	cout << endl;

	for( currentTermNum = 1; currentTermNum <= userTerms; currentTermNum++ )		// we only need to go through the for loop (terms-1) times
	{											// because the first term is always four
		cout << "Estimate after " << currentTermNum << " term(s): " << setprecision(4) << currentSeries << endl;
	
		currentSeries = currentSeries + (( 4 * currentSign ) / currentDenominator );
		
		currentDenominator += 2;			// denominator grows by two after every term
		currentSign *= -1;				// and the terms alternate being subtracted and added
	}

	cout << endl;

	return 0;
}

