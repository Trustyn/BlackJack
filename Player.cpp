#include "Player.h"

/**************************************************************
*	  Purpose: Default Constructor
*     Entry:  none.
*     Exit:  none.
****************************************************************/
Player::Player() : mHand(), mBank()
{}

/**************************************************************
*	  Purpose: Draws new card to player hand
*     Entry:  Card card
*     Exit:  none.
****************************************************************/
void Player::DrawCard(Card card)
{
	mHand.AddCard(card);
}

/**************************************************************
*	  Purpose: Adjusts the players bet
*     Entry:  int betModifier
*     Exit:  none.
****************************************************************/
void Player::AdjustBet(int betModifier)
{
	mBank.AdjustMoney(betModifier);
}

/**************************************************************
*	  Purpose: Sets the players initial bet
*     Entry:  int bet
*     Exit:  none.
****************************************************************/
void Player::SetBank(int bet)
{
	mBank.SetBet(bet);
}

/**************************************************************
*	  Purpose: Gets the players bet amount
*     Entry:  none.
*     Exit:  mBank.GetBet()
****************************************************************/
int Player::GetBet() const
{
	return mBank.GetBet();
}

/**************************************************************
*	  Purpose: Gets the players bank amount
*     Entry:  none.
*     Exit:  mBank
****************************************************************/
Bank Player::GetBank() const
{
	return mBank;
}

/**************************************************************
*	  Purpose: Displays players cards
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Player::DisplayCards() const
{
	cout << "Your cards are : \n" << endl;
	mHand.DisplayCards();
}

/**************************************************************
*	  Purpose: Displays players hand score
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Player::DisplayScore() const
{
	cout << "\nYour card score is : " << mHand.GetScore() << "\n\n" << endl;
}

/**************************************************************
*	  Purpose: Gets players hand
*     Entry:  none.
*     Exit:  mHand
****************************************************************/
Hand Player::GetHand()
{
	return mHand;
}

/**************************************************************
*	  Purpose: Clears the players hand
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Player::ClearHand()
{
	mHand.~Hand();
}