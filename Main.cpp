/*********************************************************************************
*Author:									Branden Alder
*Date Created:								2/25/2015
*Last Modification Date:					3/6/2015
*Lab Number:								CST 136 BLACKJACK
*Filename:									main.cpp
*
*Overview: 
*	This is the game of Blackjack with all funtionallity of the basic game 
*	to include the ability to double down.
*
*Input:
*	Input will be based on users bet amount, and menu options chosen.	
*
*Output:
*	Output will be the game options and play.
*
**********************************************************************************/
#include <iostream>
#include <crtdbg.h>
#include "Blackjack.h"
#include "Hand.h"

#define _CRTDBG_MAP_ALLOC

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	Blackjack start;
	start.MainSwitch();

	system("pause");
	return 0;
}

//FIX memory leaks
//Fix MainMenu type letter then number get invalid option