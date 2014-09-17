// Nicholas LaRosa
// CSE 20212, Lab 7
//
// Implementation for Trip class
//
// Allows user to choose a set of locations to visit and calculates distance in miles

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include "Trip.h"

using namespace std;

Trip::Trip( string fileName )		// gets filename and subsequently fills data members
{
	string wholeLine;
	string field;
	vector<int> temp;		// this vector will be used to hold distances

	ifstream dataFile( fileName.c_str() );
	
	while( !dataFile.eof() )
	{
		getline( dataFile, wholeLine );		// each line stored as a string

		stringstream lineStream( wholeLine );	// creating a stream out of our string
	
		while( !lineStream.eof() )		// while we haven't reached the end of this string
		{
			getline( lineStream, field, '\t' );			// separate the string by tabs
			
			if( !field.empty() )	locations.push_back( field );	// add to locations if not empty

			if( isdigit( field[0] ) )		// however, if the field is an integer
			{
				locations.pop_back();				// remove the integer from the locations
				temp.push_back( atoi( field.c_str() ) );	// add the integer to the temporary vector
			}
			else if( temp.size() > 0 )		// we know there is has been a row of integers (followed by another string)
			{
				locations.pop_back();				// remove the location occurrence in each row (repeated)
				distances.push_back( temp );			// add the vector to our 2D structure
				temp.erase( temp.begin(), temp.end() );		// clear the temporary vector
			}
		}
	}
}

void Trip::printLocations()
{
	cout << endl;

	for( int i = 0; i < locations.size(); i++ )
	{
		cout << i+1 << ". " << locations[i] << endl;
	}

	cout << endl;
}

int Trip::roadTrip()			// allows the user to choose routes, and returns the distance traveled
{
	int userInput = 0;		// stores the user's next destination choice	
	int distance = 0;
	vector<int> destinations;	// vector to keep destination indeces

	cout << endl << "Destination options: " << endl;
	printLocations();

	cout << "Choose your road trip starting point (-1 to quit): " << endl;

	while( (userInput = getUserInt()) != -1 )		// gets a user choice until user enters -1
	{
		if( userInput <= 0 || userInput > locations.size() )	
		{
			cout << "Please choose a destination number between 1 and " << locations.size() << "." << endl;
			continue;
		}

		cout << "You have chosen: " << locations[ userInput-1 ] << "." << endl;
		
		destinations.push_back( userInput );
	
		cout << endl << "Please choose your next destination number (-1 to complete): " << endl;
	}

	cout << endl;

	if( destinations.size() > 0 )
	{
		for( int i = 0; i < destinations.size()-1; i++ )	// get adjacent pairs of desintations and sum distances
		{
			cout << "From " << locations[ destinations[i]-1 ] << " to " << locations[ destinations[i+1]-1 ] << " is " << distances[ destinations[i]-1 ][ destinations[i+1]-1 ] << " miles." << endl;

			distance += distances[ destinations[i]-1 ][ destinations[i+1]-1 ];
		}
	}

	cout << endl;

	cout << "This road trip is a total of: " << distance << " miles. Have fun!" << endl << endl;
}

int Trip::getUserInt()
{
	int userChoice;

	if( !( cin >> userChoice ) )			// check to make sure we have an integer input from user
	{
		cin.clear();				// clear buffer and ignore incorrect input
		cin.ignore(4096, '\n');
		return getUserInt();			// let the player try again
	}

	return userChoice;
}
