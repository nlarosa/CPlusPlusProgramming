// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Implementation for derived class OvernightPackage
// Inherits from Package class
// Adds a fee per ounce for overnight delivery

#include <iostream>
#include <string>
#include "Package.h"
#include "OvernightPackage.h"

#define ADDCOST .10		// additional cost per ounce

using namespace std;

OvernightPackage::OvernightPackage( const string &sName, const string &sAddress, const string &sCity, const string &sState, const string &sZip, const string &rName, const string &rAddress, const string &rCity, const string &rState, const string &rZip, double weight )
	: Package( sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, weight )		// member initialization syntax to construct base
{
	addedFee = ADDCOST;	// set added fee initially using macro
}

void OvernightPackage::setFee( double newFee )	// allows the user to set a new flat fee, given that it is valid
{
	if( newFee < 0 )	// we will allow the user to make two day shipping free (ie. zero fee)
	{
		cout << "An invalid overnight added cost of negative dollars was given. The added cost has been reset to $" << ADDCOST << " dollars per ounce." << endl;
		addedFee = ADDCOST;
	}
	else	addedFee = newFee;
}

double OvernightPackage::calculateCost()	// returns the shipping cost based on the weight and cost per ounce, plus fee
{
	return Package::calculateCost() + ( addedFee * Package::getWeight() );	// adds the new fee per ounce to the standard package cost
}

void OvernightPackage::printLabel()		// prints the sender and recipient information, in addition to total cost
{
	cout << endl;
	cout << "Overnight Shipping by UPS" << endl;

	Package::printLabel();	// print the standard information

	cout << "Total shipping cost:\t$" << calculateCost() << endl;
	cout << endl;
}

