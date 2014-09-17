// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Interface for Package.h class
// Contains recipient and sender info

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using namespace std;

class Package			// interface
{
	public:
		Package( const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, const string &, double = 16.0 );		// non-default constructor		
		double calculateCost();		// calculates the cost of sending a package
		void setWeight( double );	// sets the weight of the package (in ounces)
		double getWeight();		// returns the weight (necessary for OvernightPackage)
		void setCostPerOunce( double );	// sets the cost per ounce of shipping (in dollars)
		void print();			// prints the sender and recipient information
	private:
		string senderName;		// sender information
		string senderAddress;
		string senderCity;
		string senderState;
		string senderZip;

		string recipientName;		// recipient information
		string recipientAddress;
		string recipientCity;
		string recipientState;
		string recipientZip;

		double weightOunces;		// weight of the package in ounces
		double costPerOunce;		// cost in dollars per ounce
};

#endif

