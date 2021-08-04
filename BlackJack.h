/************************************************************************
* Class: Blackjack
*
* Constructors:	
*	Blackjack()
*		Default Constructor
* Mutators:
*	void PlaySwitch(int)
*		Switch for the play menu	
*	void DoubleSwitch(int)
*		Switch for the double down menu
*	void CheckBet(int);
*		Adjusts the players bet
* Methods:
*	void IntroBet()
*		Asks the user for initial bet
*	int MainMenu()
*		Displays the main menu
*	void PlayMenu()
*		Displays the hit stand menu
*	void DoubleMenu()
*		Displays the double down menu
*	void MainSwitch()
*		Switch for the main menu
*	void ScoreCheck()
*		Checks whether the player for win,loss or tie
*	void BlackjackCheck()
*		Checks if the players initial two cards are a blackjack
*	void MenuCheck()
*		Checks if the players initial two cards are 10 or 11 for double down
*	void ClearCards()
*		Calls clearcards from player and dealer to clear the hands
*************************************************************************/
#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include <Windows.h> //Colored text 12 = red, 7 = white, 6 = yellow
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Blackjack
{
	public:
		Blackjack();
		void IntroBet();
		int MainMenu();
		void PlayMenu();
		void DoubleMenu();
		void MainSwitch();
		void PlaySwitch(int);
		void DoubleSwitch(int);
		void CheckBet(int);
		void ScoreCheck();
		void BlackjackCheck();
		void MenuCheck();
		void ClearCards();
	private:
		Deck mDeck;
		Player mPlayer;
		Dealer mDealer;

};

#endif