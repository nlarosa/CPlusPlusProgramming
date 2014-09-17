// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Implementation for BlackJack class
// User vs. computer dealer, ability to 
// play multiple matches and keep record

#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "CardDeck.h"
#include "BlackJack.h"

#define BET 5				// during each round, dealer and user bet $5
#define TIME 1000000			// usleep time

using namespace std;

BlackJack::BlackJack()			// default constructor
{
	gameDeck = new CardDeck( 52 );	// dynamically allocate for new deck

	dealerTotal = 0;		// initialize member values to zero
	userTotal = 0;

	dealerWins = 0;
	dealerBets = 0;
	userWins = 0;
	userBets = 0;
}

int BlackJack::blackJackValue( int cardValue )		// converts card number 0-51 to blackjack value 2-11
{
	int tempValue = cardValue % 13;			// there are 13 cards per suit

	switch( tempValue )
	{
		case 0:		
			return 10;		// need four cards of value 10...
			break;
		case 1:		
			return 10;	
			break;
		case 12:	
			return 10;
			break;
		default:	
			return tempValue;	// otherwise, return the actual tempValue
			break;
	}
}

void BlackJack::dealUser()				// takes top card and adds to the user's total
{
	int dealtCard;

	if( gameDeck->getSize() < 15 )			// less than 15 cards remaining
	{
		delete gameDeck;			// construct a new card deck
		gameDeck = new CardDeck( 52 );
		gameDeck->shuffle();
	}

	dealtCard = blackJackValue( gameDeck->getFront() );

	userTotal += dealtCard; 			// deal the user the current top card

	usleep(TIME);
	cout << "The user has been dealt a card with value " << dealtCard << "..." << endl;
		
	//return userTotal;
}

void BlackJack::dealDealer()				// takes top card and adds to the dealer's total
{
	int dealtCard;

	if( gameDeck->getSize() < 15 )			// less than 15 cards remaining
	{
		delete gameDeck;			// construct a new card deck
		gameDeck = new CardDeck( 52 );
		gameDeck->shuffle();
	}

	dealtCard = blackJackValue( gameDeck->getFront() ); 

	dealerTotal += dealtCard;			// deal the user the current top card

	usleep(TIME);
	cout << endl << "The dealer has dealt himself a card with value " << dealtCard << "..." << endl;
	
	//return dealerTotal;
}

bool BlackJack::printUser()				// prints the card count of the user, returns exit code
{
	if( userTotal > 21 )				// user busts, exit the game
	{
		usleep(TIME);
		cout << endl << "The user has busted with a card count of " << userTotal << "." << endl;
		dealerWins++;	
					
		dealerBets += BET;
		userBets -= BET;
	
		return true;				// give win to dealer, give code to exit	
	}
	else
	{
		usleep(TIME);
		cout << "The user's card count is currently " << userTotal << "." << endl;
		return false;
	}
}

bool BlackJack::printDealer()				// prints the card count of the dealer, returns exit code
{
	if( dealerTotal > 21 )				// dealer busts, exit the game
	{
		usleep(TIME);
		cout << endl << "The dealer has busted with a card count of " << dealerTotal << "." << endl;
		userWins++;

		userBets += BET;
		dealerBets -= BET;
		
		return true;				// give win to user, give code to exit
	}
	else if( dealerTotal >= 17 )			// dealer stops playing, check outcome
	{
		if( dealerTotal == userTotal )		// tie goes to the dealer!
		{
			usleep(TIME);
			cout << endl << "Both the user and dealer have a card count of " << dealerTotal << ". Tie goes to the dealer!" << endl;
			dealerWins++;

			dealerBets += BET;
			userBets -= BET;

			return true;			// give win to dealer, give code to exit
		}
		else if( dealerTotal > userTotal )	// dealer has higher score than user, wins
		{
			usleep(TIME);
			cout << endl << "The dealer has won with a card count of " << dealerTotal << " versus the user's " << userTotal << "." << endl;
			dealerWins++;

			dealerBets += BET;
			userBets -= BET;

			return true;			// give win to dealer, give code to exit
		}
		else 
		{
			usleep(TIME);
			cout << endl << "The user has won with a card count of " << userTotal << " versus the dealer's " << dealerTotal << "." << endl;
			userWins++;

			userBets += BET;
			dealerBets -= BET;

			return true;			// give win to user, give code to exit
		}
	}
	else		
	{
		usleep(TIME);
		cout << "The dealer's card count is currently " << dealerTotal << "." << endl;
		return false;				// give code to continue, dealer needs more cards
	}
}

bool BlackJack::promptUser()				// prompts user to hit or stand
{
	char userInput;

	if( userTotal < 18 )	userInput = 'h';	// user chooses to hit until count is 18 or higher
	else			userInput = 's';	// at which point they stand

	switch( userInput )
	{
		case 'h':
			usleep(TIME);
			cout << "The user has chosen to hit..." << endl;
			return true;			// user chooses to hit
			break;
		case 's':
			usleep(TIME);
			cout << "The user has chosen to stand..." << endl;
			return false;			// user chooses to stand
			break;
		default:
			return promptUser();		// invalid input, try again
			break;
	}
}

bool BlackJack::playAgain()				// prompts user to play another hard or exit
{
	char userInput;

	usleep(TIME);	
	cout << endl << "Good game! Would you like to play again? (y)es or (n)o: ";
	
	if( !( cin >> userInput ) )			// check to make sure we have an integer input from user
        {
		cin.clear();				// clear buffer and ignore incorrect input
		cin.ignore(4096, '\n');
		return playAgain();			// ask the player again
        }

	cout << endl;
	userInput = tolower( userInput );		// convert to lowercase

	switch( userInput )
	{
		case 'y':
			return true;			// user chooses to play again
			break;
		case 'n':
			return false;			// user chooses to exit
			break;
		default:
			return playAgain();		// invalid input, try again
			break;
	}
}

void BlackJack::printResults()				// prints the number of wins for user and dealer
{
	double percentUser = (double)userWins / (userWins + dealerWins);
	double percentDealer = (double)dealerWins / (userWins + dealerWins);

	usleep(TIME);
	cout << endl << "Current user wins: " << userWins << " (" << setprecision(4) << percentUser*100 << "%)" << endl;
	cout << "\tNet user earnings: $" << userBets << endl;
	cout << "Current dealer wins: " << dealerWins << " (" << setprecision(4) << percentDealer*100 << "%)" << endl;
	cout << "\tNet dealer (bank) earnings: $" << dealerBets << endl;
}

void BlackJack::playRound()				// begins a new hand of blackjack
{
	gameDeck->shuffle();				// shuffle deck, reset variables
	dealerTotal = 0;
	userTotal = 0;

	bool endGame = false;				// early game ending code

	usleep(TIME);
	cout << endl << "Welcome to Blackjack! The game begins with one card to the dealer and two to the user..." << endl;
	cout << "The current bet count is $5 by the user..." << endl << endl;
	
	dealDealer(); 					// initial dealings
	dealUser(); 
	dealUser();

	cout << endl;

	printDealer();					// initial printings
	printUser();					

	cout << endl;
	while( promptUser() )				// while the user wants to hit
	{
		dealUser();				// deal the user a card	
		if( printUser() == true )	
		{
			endGame = true;			// if we have an exit code (game is over)
			break;
		}
		cout << endl;
	}

	cout << endl;

	while( endGame == false && printDealer() == false )	
	{
		dealDealer(); 				// deal the dealer a card only if the game is still going on...
	}

	printResults();					// give win numbers

	if( playAgain() == true )			// if the user wants to play again
	{
		return playRound();			// play another round!
	}

	delete gameDeck;
	return;
}

