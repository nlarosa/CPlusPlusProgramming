// Nicholas LaRosa
// CSE 20212, Lab 4
//
// Implementation for BlackJack class
// User vs. computer dealer, ability to 
// play multiple matches and keep record

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "CardDeck.h"
#include "BlackJack.h"

#define TIME 1000000			// usleep time (for pauses)

using namespace std;

BlackJack::BlackJack()			// default constructor
	: gameDeck( 52 )		// member initialization to construct 52 card deck
{
	dealerTotal = 0;		// initialize member values to zero
	userTotal = 0;

	dealerWins = 0;
	userWins = 0;

	currentCard = 0;		// current index of the card deck
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

	if( 51 - (++currentCard) < 15 )			// less than 15 cards remaining
	{
		gameDeck.shuffle();			// grab a "new" deck, ie. shuffle deck
		currentCard = 0;
	}

	dealtCard = blackJackValue( gameDeck.getCard( currentCard ) );

	userTotal += dealtCard; 			// deal the user the current top card

	usleep(TIME);
	cout << "The user has been dealt a card with value " << dealtCard << "..." << endl;
		
	//return userTotal;
}

void BlackJack::dealDealer()				// takes top card and adds to the dealer's total
{
	int dealtCard;

	if( 51 - (++currentCard) < 15 )			// less than 15 cards remaining
	{
		gameDeck.shuffle();			// grab a "new" deck, ie. shuffle deck
		currentCard = 0;
	}

	dealtCard = blackJackValue( gameDeck.getCard( currentCard ) ); 

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
		return true;				// give win to user, give code to exit
	}
	else if( dealerTotal >= 17 )			// dealer stops playing, check outcome
	{
		if( dealerTotal == userTotal )		// tie goes to the dealer!
		{
			usleep(TIME);
			cout << endl << "Both the user and dealer have a card count of " << dealerTotal << ". Tie goes to the dealer!" << endl;
			dealerWins++;
			return true;			// give win to dealer, give code to exit
		}
		else if( dealerTotal > userTotal )	// dealer has higher score than user, wins
		{
			usleep(TIME);
			cout << endl << "The dealer has won with a card count of " << dealerTotal << " versus the user's " << userTotal << "." << endl;
			dealerWins++;
			return true;			// give win to dealer, give code to exit
		}
		else 
		{
			usleep(TIME);
			cout << endl << "The user has won with a card count of " << userTotal << " versus the dealer's " << dealerTotal << "." << endl;
			userWins++;
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
	
	usleep(TIME);
	cout << endl << "User, please choose your next move: (h)it or (s)tand: ";

	if( !( cin >> userInput ) )			// check to make sure we have an integer input from user
        {
		cin.clear();				// clear buffer and ignore incorrect input
		cin.ignore(4096, '\n');
		return promptUser();			// ask the player again
        }

	cout << endl;
	userInput = tolower( userInput );		// convert to lowercase

	switch( userInput )
	{
		case 'h':
			return true;			// user chooses to hit
			break;
		case 's':
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
	cout << "Current dealer wins: " << dealerWins << " (" << setprecision(4) << percentDealer*100 << "%)" << endl;
}

void BlackJack::playRound()				// begins a new hand of blackjack
{
	gameDeck.shuffle();				// shuffle deck, reset variables
	currentCard = 0;
	dealerTotal = 0;
	userTotal = 0;

	bool endGame = false;				// early game ending code

	usleep(TIME);
	cout << endl << "Welcome to Blackjack! The game begins with one card to the dealer and two to the user..." << endl << endl;
	
	dealDealer(); 					// initial dealings
	dealUser(); 
	dealUser();

	cout << endl;

	printDealer();					// initial printings
	printUser();					

	while( promptUser() )				// while the user wants to hit
	{
		dealUser();				// deal the user a card	
		if( printUser() == true )	
		{
			endGame = true;			// if we have an exit code (game is over)
			break;
		}
	}

	cout << endl;

	while( endGame == false && printDealer() == false )	
	{
		dealDealer(); 				// deal the dealer a card only if the game is still going on...
	}

	printResults();					// give win numbers

	if( playAgain() == true )			// if the user wants to play again
	{
		playRound();				// play another round!
	}

	cout << "Have a good day!!" << endl << endl;
}
