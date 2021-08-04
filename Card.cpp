#include "Card.h"

char * RankText[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
	"Eight", "Nine", "Ten", "Jack", "Queen", "King" };

char * SuitText[] = { "Spades", "Hearts", "Clubs", "Diamonds" };

/**************************************************************
*	  Purpose:  Initializes card Rank to rank, and card suit to
*				suit.
*     Entry:  none.
*     Exit:  none.
****************************************************************/
Card::Card (Rank rank, Suit suit) : m_rank( rank ), m_suit( suit )
{}

/**************************************************************
*	  Purpose:  overides the = operator to be used with objects
*     Entry:  const Card &rhs
*     Exit:  *this
****************************************************************/
Card & Card::operator=(const Card &rhs)
{
	if(this != &rhs){
		this->m_rank = rhs.m_rank;
		this->m_suit = rhs.m_suit;
	}
	return *this;
}

/**************************************************************
*	  Purpose:  Display card rank and suit to the screen                 
*     Entry:  None.
*     Exit:  None.
****************************************************************/
void Card::Display() const
{
	if(m_suit == Diamonds || m_suit == Hearts)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	cout << RankText[m_rank - 1] << " of " << SuitText[m_suit] << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
}

/**************************************************************
*	  Purpose:  Changes card rank to what is passed in.                 
*     Entry:  Rank storing a card rank in it.
*     Exit:  Card rank now equal to the rank passed in.
****************************************************************/
void Card::SetRank ( Rank rank )
{
	m_rank = rank;
}

/**************************************************************
*	  Purpose:  Changes card suit to what is passed in.        
*     Entry:  Suit storing a card suit in it.
*     Exit:  Card suit now equal to the suit passed in.
****************************************************************/
void Card::SetSuit ( Suit suit )
{
	m_suit = suit;
}

/**************************************************************
*	  Purpose:  Returns the card rank.                 
*     Entry:  None.
*     Exit:  None.
****************************************************************/
Rank Card::GetRank() const
{
	return m_rank;
}

/**************************************************************
*	  Purpose:  Returns the card suit.
*     Entry:  None.
*     Exit:  None.
****************************************************************/
Suit Card::GetSuit() const
{
	return m_suit;
}