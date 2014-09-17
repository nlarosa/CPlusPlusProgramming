// Nicholas LaRosa
// CSE 20212, Lab 0 
//
// Implementation for our Mortgage class

#include <iostream>
#include <iomanip>
#include "mortgage.h" 		// includes Mortgage interface

#define STD_PRINCIPAL 100000
#define STD_RATE 5
#define STD_PAYMENT 5000

using namespace std;

Mortgage::Mortgage()								// default constructor that sets a standard principal, rate, and payment
{
	principal = STD_PRINCIPAL;	// make a default mortgage have a principal of $1000, 5% monthly interest, and a monthly payment of $100
	rate = STD_RATE;
	payment = STD_PAYMENT;
}

Mortgage::Mortgage( double myPrincipal, double myRate, double myPayment )	// non-default constructor where pricipal, rate, and payment are set
{										// where we must perform error-checking to make sure values are appropriate
	principal = myPrincipal;
	rate = myRate;
	payment = myPayment;

	if( myPrincipal < 0 )
	{
		principal = STD_PRINCIPAL;		
		cout << "A negative principal was specified. The principal has been set to its standard " << principal << " dollars." << endl;
	}
	if( myRate < 0 || myRate > 100 )
	{
		rate = STD_RATE;
		cout << "A rate between 0 and 100 percent was not specified. The rate has been set to its standard " << rate << " percent." << endl;
	}
	if( myPayment < 0 )
	{
		payment = STD_PAYMENT;
		cout << "A negative payment was specified. The payment has been set to its standard " << payment << " dollars." << endl;
	}
}

void Mortgage::credit( double value )						// subtracts the specified dollar amount from the current principal
{
	if( value < 0 )			// negative credit
	{
		cout << "A negative credit was specified. No credit was subtracted from the principal." << endl;
	}
	else if( principal <= value )  	// credit is greater than the principal
	{
		cout << "The credit exceeds the current balance. The mortgage has been paid off!" << endl;
		principal = 0;		// mortgage is paid off
	}
	else
	{
		principal -= value;
	}
}

double Mortgage::getPrincipal()							// print the current principal to the screen
{
	return principal;
}

int Mortgage::checkPayment( double intCharge )					// makes sure that the mortgage payment can eventually pay off the mortgage
{										// returns 1 if the mortgage payment is high enough, 0 otherwise
	if( intCharge >= payment )
	{
		return 0;				// interest charged is greater than the payment, so loan will last forever
	}
	else
	{
		return 1;				// interest is payable, loan will someday be paid off
	}
}

int Mortgage::checkDigits( double number )					// finds out how many digits a certain number has in order to optimize table format
{
	if( number > 1000000000 )	return 10;
	if( number > 100000000 )	return 9;
	if( number > 10000000 )		return 8;
	if( number > 1000000 )		return 7;
	if( number > 100000 )		return 6;
	if( number > 10000 )		return 5;
	if( number > 1000 )		return 4;
	if( number > 100 )		return 3;
	if( number > 10 )		return 2;
	if( number > 1 )		return 1;
	else				return 0;
}

void Mortgage::amortize()							// creates an amortization table where month, payment, interest, and balance displayed
{
	double interest = ( rate/100 );						// convert interest to decimal form
	double intCharge = ( principal*interest ) / 12;				// interest that is charged (first montH)

	int monthNum = 1;							// begin at first month
	double totalPaid = 0;
	double cutoffBalance;

	int principalDigits = checkDigits( principal );		// number of digits will help with the table construction
	int interestDigits = checkDigits( intCharge );
	int paymentDigits = checkDigits( payment );

	if( checkPayment( intCharge ) )						// we may proceed with the amortization table
	{
		cout << "\nMonth\tPayment\t\tInterest\tBalance" << endl;

		cutoffBalance = ( 12*payment ) / ( 12+interest ); 	// find balance where principal+interest is less than one full payment
		
		while( principal > cutoffBalance )			// we know to continue until our final principal is less than our calculated cutoff
		{
			intCharge = ( principal*interest ) / 12;		// calculate new interest amount after every month
			
			principal += intCharge;					// first, add monthly interest
			principal -= payment;					// then, subtract monthly payment

			cout << monthNum << "\t$" << setprecision( paymentDigits+2 ) << payment 
				<< "\t\t$" << setprecision( interestDigits+2 ) << intCharge 
				<< "\t\t$" << setprecision( principalDigits+2 ) << principal << endl;

			totalPaid += payment;
			totalPaid += intCharge;
			monthNum++;
		}

		intCharge = ( principal*interest ) / 12;
		payment = principal + intCharge;			// we know this is the last payment
		principal = 0;

		cout << monthNum << "\t$" << setprecision( paymentDigits+2 ) << payment
               		<< "\t\t$" << setprecision( interestDigits+2 ) << left << intCharge
               		<< "\t\t$" << setprecision( principalDigits+2 ) << left << principal << endl << endl;

		totalPaid += payment;
		
		cout << "You paid a total of $" << totalPaid << " over " << monthNum/12 << " year(s) and " << monthNum%12 << " month(s)." << endl << endl;
	}
	else
	{
		cout << "This mortgage can never be paid off without a higher monthly payment." << endl;
	}
}
			
