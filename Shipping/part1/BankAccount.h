// Nicholas LaRosa
// Eric Krakowiak
//
// Interface for the Bank Account base class
// Contains variables that are standard for the bank

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class BankAccount		// interface for BankAccount object
{
	public:
		BankAccount();			// default constructor
		BankAccount( int, string );	// non-default constructor allows us to set ID number and owner name
		void transferOwner( string );	// changes the owner of the bank account
		string getOwner();		// get function for owner
		int getIDnumber();		// get function for ID number
		int getPaymentsPerYear();	// get function for payments/year
		double getPrincipal();		// get function for principal
		double getRate();		// get function for interest rate
		double getPayment();		// get function for payment
	private:
		double principal;	// traits of any loans or savings
		double rate;		// yearly interest rate
		double payment;		// amount of the payment
		int paymentsPerYear;	// how many of these payments are made per year	
		int IDnumber;		// ID number for the bank account
		string ownerName;	// full name of the bank account owner
};

#endif
