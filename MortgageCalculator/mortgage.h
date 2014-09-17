// Nicholas LaRosa
// CSE 20212, Lab 0
//
// Interface for our Mortgage class

#include <iostream>

class Mortgage				// building mortgage class
{
	private:			// data members
		double principal;
		double rate;
		double payment;
		int checkPayment( double );		// function used by amortize
		int checkDigits( double );		// function used by amortize

	public:				// data member functions
		Mortgage();						// default constructor
		Mortgage( double, double, double );			// non-default constructor
		void credit( double );					// subtracts the payment from the principal remaining
		double getPrincipal();					// returns the current principal remaining
		void amortize();					// displays the amortization table		
};

