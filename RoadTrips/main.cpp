// Nicholas LaRosa
// CSE 20212, Lab 7
//
// Main driver program
//
// Prints locations in input file
// Gives distance for user-defined path

#include <iostream>
#include <string>
#include "Trip.h"

using namespace std;

int main( int argc, char *argv[] )
{
	if( argc != 2 )
	{
		cout << "Usage: ./main <data file>" << endl;
		return 1;
	}
	
	Trip userTrip( argv[1] );
	
	userTrip.roadTrip();
}

