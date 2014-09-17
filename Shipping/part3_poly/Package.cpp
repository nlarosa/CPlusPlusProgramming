// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Implementation for Package class
// Including error-check constructor
// and function to calculate costs

#include <iostream>
#include <string>
#include "Package.h"

#define COST .25			// standard cost per ounce for shipping

using namespace std;

Package::Package( const string &sName, const string &sAddress, const string &sCity, const string &sState, const string &sZip, const string &rName, const string &rAddress, const string &rCity, const string &rState, const string &rZip, double weight )
	: senderName( sName ), senderAddress( sAddress ), senderCity( sCity ), senderState( sState ), senderZip( sZip ), recipientName( rName ), recipientAddress( rAddress ), recipientCity( rCity ), recipientState( rState ), recipientZip( rZip )		// member initialization syntax for strings
{
	setWeight( weight );		// set the double weight
	costPerOunce = COST;		// set the standard cost per ounce
}
	
void Package::setWeight( double packageWeight )	// checks for valid input of weight
{
	if( packageWeight <= 0 )
	{
		cout << "An invalid weight of zero or negative ounces was given. The weight of your package has been set to 16 ounces." << endl;
		weightOunces = 16;
	}
	else	weightOunces = packageWeight;
}

double Package::getWeight()			// returns the weight of the package
{
	return weightOunces;
}

void Package::setCostPerOunce( double newCost )	// allows the user to update the cost per ounce, checks for validity
{
	if( newCost < 0 )		// we will let the cost be zero (free shipping)
	{
		cout << "An invalid cost of negative dollars per ounce was given. The cost per ounce has been reset to $" << COST << " per ounce." << endl;	
		costPerOunce = COST;
	}
	else	costPerOunce = newCost;
}

double Package::calculateCost()			// calculates the weight charged to send a package
{
	return weightOunces * costPerOunce;	// we know the cost per ounce and weight are positive, so cost should be positive
}

void Package::printLabel()			// prints sender and recipient information to screen
{
	cout << endl;
	cout << "Sender information:\t" << senderName << endl;
	cout << "\t\t\t" << senderAddress << endl;
	cout << "\t\t\t" << senderCity << ", " << senderState << senderZip << endl;
	cout << endl;
	cout << "Recipient information:\t" << recipientName << endl;
	cout << "\t\t\t" << recipientAddress << endl;
	cout << "\t\t\t" << recipientCity << ", " << recipientState << " " << recipientZip << endl;
	cout << endl;
	cout << "Package weight:\t\t" << getWeight() << " ounces" << endl;
	cout << "Standard shipping cost:\t$" << Package::calculateCost() << endl;
	cout << endl;
}

