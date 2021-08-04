/************************************************************************
* Class: Dealer
*
* Constructors:	
*	Dealer()
*		Defalut Constructor
* Mutators:
*	void DrawCard(Card card)
*		Draws a new card to hand
* Methods:
*	void DisplayCards() const
*		Displays hand to screen
*	void DisplayScore() const
*		Displays score to screen
*	Hand GetHand()
*		Returns dealers hand
*	void ClearHand()
*		Clears the dealers hand of cards
*************************************************************************/
#ifndef DEALER_H
#define DEALER_H
#include "Card.h"
#include "Hand.h"

class Dealer
{
	public:
		Dealer();
		void DrawCard(Card card);
		void DisplayCards() const;
		void DisplayScore() const;
		Hand GetHand();
		void ClearHand();
	private:
		Hand mHand;
		

};

#endif