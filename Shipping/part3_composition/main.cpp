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

using namespace std;

int main()
{
	TwoDayPackage twoDay("Nick LaRosa", "133 Duncan Hall", "Notre Dame", "IN", "46556", "LaRosa Family", "3118 Kristen Trail", "Crystal Lake", "IL", "60012", 24);
	// creates a TwoDayPackage instance, 24 ounce package
	
	OvernightPackage overNight("LaRosa Family", "3118 Kristen Trail", "Crystal Lake", "IL", "60012", "Nick LaRosa", "133 Duncan Hall", "Notre Dame", "IN", "46556", 36);	// creates an OvernightPackage instance, 36 ounce package

	twoDay.print();		// derived class print functions
	cout << "______________________________________________" << endl;
	overNight.print();
}

