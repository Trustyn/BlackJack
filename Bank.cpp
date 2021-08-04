#include "Bank.h"

/**************************************************************
*	  Purpose: Default Constructor
*     Entry:  sets mMoney(200) and mBet(0)
*     Exit:  none.
****************************************************************/
Bank::Bank() : mMoney(200), mBet(0)
{}

/**************************************************************
*	  Purpose: Gets bank money amount
*     Entry:  none.
*     Exit:  mMoney
****************************************************************/
int Bank::GetMoney() const
{
	return mMoney;
}

/**************************************************************
*	  Purpose: Sets the initial bet
*     Entry:  int bet
*     Exit:  none.
****************************************************************/
void Bank::SetBet(int bet)
{
	mBet = bet;
}

/**************************************************************
*	  Purpose: Gets the bet
*     Entry:  none.
*     Exit:  int mBet
****************************************************************/
int Bank::GetBet() const
{
	return mBet;
}

/**************************************************************
*	  Purpose: Adjusts the bank money
*     Entry:  int betModifier
*     Exit:  none.
****************************************************************/
void Bank::AdjustMoney(int betModifier)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

	mMoney += (mBet * betModifier); 
	cout << "You have " << mMoney << " left in the bank. " << endl;
 	system("pause");
}

