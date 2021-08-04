#include "Hand.h"

/**************************************************************
*	  Purpose: Defalut Constructor
*     Entry:  mCardArray(nullptr), mCardCount(0), mCardScore(0)
*     Exit:  none.
****************************************************************/
Hand::Hand() : mCardArray(nullptr), mCardCount(0), mCardScore(0)
{}

/**************************************************************
*	  Purpose: Destructor
*     Entry:  none.
*     Exit:  deletes mCardArray, reinitializes data members
****************************************************************/
Hand::~Hand()
{
	delete [] mCardArray;
	mCardArray = nullptr;
	mCardCount = 0;
	mCardScore = 0;
}

/**************************************************************
*	  Purpose: Copy Constructor
*     Entry:  const Hand & rhs
*     Exit:  none.
****************************************************************/
Hand::Hand(const Hand & rhs) : mCardCount(rhs.mCardCount), mCardScore(rhs.mCardScore)
{
	mCardArray = new Card[mCardCount + 1];
	for(int i(0); i < mCardCount; ++i)
	{
		mCardArray[i] = rhs.mCardArray[i];
	}

}

/**************************************************************
*	  Purpose: Adds new card to array
*     Entry:  Card card
*     Exit:  none.
****************************************************************/
void Hand::AddCard(Card card)
{ 
	Card * temp = new Card[mCardCount + 1];
	for(int i(0); i < mCardCount; ++i)
	{
		temp[i] = mCardArray[i];
	}
	temp[mCardCount] = card;
	delete [] mCardArray;
	mCardArray = temp;
	mCardCount++;
	CalcScore();
}

/**************************************************************
*	  Purpose: Returns score
*     Entry:  none.
*     Exit:  mCardScore
****************************************************************/
int Hand::GetScore() const
{
	return mCardScore;
}

/**************************************************************
*	  Purpose: Calculates scores in hand
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Hand::CalcScore()
{
	int tempScore(0);
	bool foundAce = false;

	for(int i(0); i < mCardCount; ++i)
	{
		if(mCardArray[i].GetRank() == Ace)
		{
			foundAce = true;
		}
		if(mCardArray[i].GetRank() > 10)
		{
			tempScore += 10;
		}
		else
		{
			tempScore += mCardArray[i].GetRank();
		}
	}
	if(foundAce && tempScore <= 11)
	{
		tempScore += 10;
	}
	mCardScore = tempScore;
}

/**************************************************************
*	  Purpose: Displays card array to screen
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Hand::DisplayCards() const
{
	for(int i(0); i < mCardCount; ++i)
	{
		mCardArray[i].Display();
	}
}