// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Driver program for Package, TwoDayPackage, and OvernightPackage classes
// Displays contents of derived TwoDayPackage and OvernightPackage

#include <iostream>
#include <string>

#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

#define SIZE 6		// size of our Package array

using namespace std;

int main()
{
	double currentCost = 0;			// keep a running sum of the delivery costs

	// first create the class instances: three TwoDayPackage and three OvernightPackage

	TwoDayPackage twoDay1("Nick LaRosa","133 Duncan Hall","Notre Dame","IN","46556","LaRosa Family","3118 Kristen Trail","Crystal Lake","IL","60012",24);
	TwoDayPackage twoDay2("Nick LaRosa","133 Duncan Hall","Notre Dame","IN","46556","Barack Obama","1600 Pennsylvania Ave.","Washington","DC","20500",16);
	TwoDayPackage twoDay3("Nick LaRosa","133 Duncan Hall","Notre Dame","IN","46556","Dept. of the Navy","2 Navy Annex","Washington","DC","20380",56);
	
	OvernightPackage overNight1("LaRosa Family","3118 Kristen Trail","Crystal Lake","IL","60012","Nick LaRosa","133 Duncan Hall","Notre Dame","IN","46556",42);
	OvernightPackage overNight2("Barack Obama","1600 Pennsylvania Ave.","Washington","DC","20500","Nick LaRosa","133 Duncan Hall","Notre Dame","IN","46556",14);
	OvernightPackage overNight3("Dept. of the Navy", "2 Navy Annex", "Washington", "DC","20380","Nick LaRosa","133 Duncan Hall","Notre Dame","IN","46556",64);

	Package *myPackages[6];			// array of six Package pointers

	myPackages[0] = &twoDay1;		// begin assignment of Package pointers to addresses of derived class instances
	myPackages[1] = &overNight1;
	myPackages[2] = &twoDay2;
	myPackages[3] = &overNight2;
	myPackages[4] = &twoDay3;
	myPackages[5] = &overNight3;

	cout << "______________________________________________" << endl;

	for( int i = 0; i < SIZE; i++ )
	{
		myPackages[i] -> printLabel();						// print the derived class (virtual)
		cout << "______________________________________________" << endl;
		currentCost += myPackages[i] -> calculateCost();			// adds cost to running sum (virtual)
	}
}

