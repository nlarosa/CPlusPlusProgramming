// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Interface of derived class TwoDayPackage
// Inherits from base class Package
// Adds a fixed fee for two-day delivery

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include <iostream>
#include <string>
#include "Package.h"

using namespace std;

class TwoDayPackage: public Package		// interface for class TwoDayPackage that inherits Package object
{
	public:
		TwoDayPackage( const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, double = 16.0 );		// non-default constructor
		void setFee( double );		// sets the flat fee to a desired dollar amount
		virtual double calculateCost();	// calculates cost, which is normal fee + added fee
		virtual void printLabel();	// prints the sender and recipient information
	private:		
		double flatFee;			// flat fee added for two-day shipping
};

#endif
