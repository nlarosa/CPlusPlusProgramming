// Nicholas LaRosa
// Eric Krakowiak
//
// Interface for IslandLoan

#ifndef ISLANDLOAN_H
#define ISLANDLOAN_H

#include <iostream>
#include <string>

class IslandLoan: public BankAccount {

  public:
    IslandLoan();				// default constructor
    IslandLoan( int &, string , double );	//non default constructor

  private:
    int coordinates[2];	// gps coordinates of the island
    string name;	// name of the island
    double size;	// square mileage of the islan
};    

#endif
