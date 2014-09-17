// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Interface of derived class OvernightPackage
// Inherits from base class Package
// Adds a fee per ounce for overnight delivery

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include <iostream>
#include <string>
#include "Package.h"

using namespace std;

class OvernightPackage: public Package		// interface for class OvernightPackage that inherits Package members
{
	public:
		OvernightPackage( const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, double = 16.0 );	// non-default constructor
		void setFee( double );		// sets the added fee per ounce to a desired dollar amount
		virtual double calculateCost();	// calculates cost, which is ( normal fee + added fee ) * weight
		virtual void printLabel();	// prints the sender and recipient information
	private:		
		double addedFee;		// added fee per ounce for overnight shipping
};

#endif
