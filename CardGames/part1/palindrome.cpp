// Nicholas LaRosa
// CSE 20212, Lab 3
//
// Checks to see if a vector is a palindrome
// Using STL library and reverse algorithm

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> testPalindrome;		// construct two vectors for future use

	int currentUserVal;		 	// stores the current value entered by the user
	int count = 0;

	cout << endl << "Welcome to the Palindrome Tester." << endl;
	cout << "Please enter your collection, one integer at a time." << endl;
	cout << "Enter a '.' when your vector is complete." << endl << endl;
	cout << "Please enter the first integer in the collection: ";

	while( cin >> currentUserVal )
	{
		testPalindrome.push_back(currentUserVal);
		cout << "Please enter the next integer in the collection: ";
	}
	
	cout << endl << "The collection is complete. Testing for palindrome..." << endl;

	vector<int>::const_iterator iStart = testPalindrome.begin();
	vector<int>::const_reverse_iterator rStart = testPalindrome.rbegin();

	int midPoint = (testPalindrome.size()/2)+1;

	for( iStart; count <= midPoint; ++iStart )		// we could check until the end iterator, but this saves a few loops
	{
		if( *iStart != *rStart )	
		{
			cout << endl << "Your collection is not a palindrome. Have a good day!" << endl << endl;
			return 0;
		}
		else		++rStart;
	
		count++;
	}

	cout << endl << "Congratulations, your collection is a palindrome!" << endl << endl;
	return 0;
}


