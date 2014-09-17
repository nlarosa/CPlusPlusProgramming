// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Implementation for derived class TwoDayPackage
// Inherits from Package class
// Adds a fixed fee for two-day delivery

#include <iostream>
#include <string>
#include "Package.h"
#include "TwoDayPackage.h"

#define FEE 5			// flat fee dollar amount

using namespace std;

TwoDayPackage::TwoDayPackage( const string &sName, const string &sAddress, const string &sCity, const string &sState, const string &sZip, const string &rName, const string &rAddress, const string &rCity, const string &rState, const string &rZip, double weight )
	: Package( sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, weight )		// member initialization syntax to construct base
{
	flatFee = FEE;		// set flat fee initially using macro
}

void TwoDayPackage::setFee( double newFee )	// allows the user to set a new flat fee, given that it is valid
{
	if( newFee < 0 )	// we will allow the user to make two day shipping free (ie. zero fee)
	{
		cout << "An invalid two-day fee of negative dollars was given. The flat fee has been reset to $" << FEE << " dollars." << endl;
		flatFee = FEE;
	}
	else	flatFee = newFee;
}

double TwoDayPackage::calculateCost()		// returns the shipping cost based on the weight and cost per ounce, plus fee
{
	return Package::calculateCost() + flatFee;	// this value is guarenteed to be non-negative
}

void TwoDayPackage::printLabel()		// prints the sender and recipient information, in addition to total cost
{
	cout << endl;
	cout << "Two-Day Shipping by UPS" << endl;

	Package::printLabel();	// print the standard information

	cout << "Total shipping cost:\t$" << calculateCost() << endl;
	cout << endl;
}

