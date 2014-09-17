// Nicholas LaRosa
// CSE 20212, Lab 7
//
// Interface for Trip class

#ifndef TRIP_H
#define TRIP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trip 
{
	public:
		Trip( string );			// input a file name to initialize the locations vector
		void printLocations();		// prints a numeric label for all locations in file
		int roadTrip();			// returns the distance between a series of locations given by user
	private:
		int getUserInt();			// gets user input for custom road trip
		vector<string> locations;		// holds the list of locations
		vector< vector<int> > distances;	// holds the distances between the adjacent locations (by index)
};

#endif

