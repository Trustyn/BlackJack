#include "Dealer.h"

/**************************************************************
*	  Purpose: Default Constructor
*     Entry:  none.
*     Exit:  none.
****************************************************************/
Dealer::Dealer() : mHand()
{}

/**************************************************************
*	  Purpose: Draws a card to dealers hand
*     Entry:  Card card
*     Exit:  none.
****************************************************************/
void Dealer::DrawCard(Card card)
{
	mHand.AddCard(card);
}

/**************************************************************
*	  Purpose: Displays dealers cards
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Dealer::DisplayCards() const
{
	cout << "The dealers cards are : \n" << endl;
	mHand.DisplayCards();
}

/**************************************************************
*	  Purpose: Displays dealers hand score
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Dealer::DisplayScore() const
{
	cout << "\nThe dealers score is : " << mHand.GetScore() << "\n\n" << endl;
}

/**************************************************************
*	  Purpose: Gets the dealers hand
*     Entry:  none.
*     Exit:  mHand
****************************************************************/
Hand Dealer::GetHand()
{
	return mHand;
}

/**************************************************************
*	  Purpose: Clears the dealers hand
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Dealer::ClearHand()
{
	mHand.~Hand();
}