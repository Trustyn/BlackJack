/************************************************************************
* Class: Player
*
* Constructors:	
*	Player()
*		Default Constructor
* Mutators:
*	void DrawCard(Card card)
*		Draws a new card to the players hand
*	void SetBank(int bet)
*		Sets the passed in value to the banks bet
*	void ClearHand()
*		Clears the players hand of cards
*	void AdjustBet(int betModifier)
*		Uses pased in modifier to adjust the players bank
* Methods:
*	Bank GetBank()
*		Returns the bank total
*	void DisplayCards() const
*		Displays the players cards
*	void DisplayScore() const
*		Displays the cards score
*	Hand GetHand()
*		Returns the players hand	
*	int GetBet() const
*		returns the players bet
*************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"
#include "Bank.h"
#include "Card.h"

class Player
{
	public:
		Player();
		void DrawCard(Card card);
		void SetBank(int bet);
		Bank GetBank() const;
		void DisplayCards() const;
		void DisplayScore() const;
		Hand GetHand();
		void ClearHand();
		void AdjustBet(int betModifier);
		int GetBet() const;
	private:
		Hand mHand;
		Bank mBank;
};

#endif