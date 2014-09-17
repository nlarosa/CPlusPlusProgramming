#include "C4Board.h" // class definition for C4Board used below

int main() 
{
	int userWantsToPlay = 1;

	while( userWantsToPlay )
	{
		C4Board ourGame;
		ourGame.play();
		userWantsToPlay = ourGame.weCanContinue();
	}
}

