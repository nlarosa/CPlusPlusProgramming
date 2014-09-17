// Nicholas LaRosa
// Eric Krakowiak
// CSE 20212, Lab 3

#ifndef BOATLOAN_H
#define BOATLOAN_H

#include <iostream>
#include <string>
using namespace std;

class BoatLoan: public BankAccount {

  public:
    BoatLoan();			// default constructor 
    BoatLoan( string , int );	// non default constructor

  private:
    string boatType;		// type of boat: sail, row, speed, etc
    int maxBootyStorage;	// amount of booty the boat can hold
};
    
#endif
