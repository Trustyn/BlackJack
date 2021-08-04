#include "Deck.h"
/**************************************************************
*	  Purpose:  Initialized array of cards to all 13 ranks for
*			    each of the 4 suits.
*     Entry:  None.
*     Exit:  Array of cards set equal to all 13 ranks for all
*			 4 suits.
****************************************************************/
Deck::Deck() : m_currentCard(0)
{
	int count(0);
	m_deck = new Card[NUM_CARDS];
	for(int suit(0); suit < 4; ++suit)
	{
		for(int rank(1); rank < 14; ++rank)
		{
			m_deck[count].SetSuit(static_cast<Suit>(suit));
			m_deck[count].SetRank(static_cast<Rank>(rank));
			count++;
		}
	}
}

Deck::~Deck()
{
	delete [] m_deck;
}

/**************************************************************
*	  Purpose:  Shuffles the array of cards.
*     Entry:  None.
*     Exit:  Array of cards in a random order.
****************************************************************/
void Deck::Shuffle()
{
	Card * temp = new Card;
	Random tempRand;
	int index(0);
	for(int i(0); i < 7; ++i)
	{
		for(int j(0); j < NUM_CARDS; ++j)
		{
			*temp = m_deck[j];
			index = tempRand.GetRandom(NUM_CARDS);
			m_deck[j] = m_deck[index]; 
			m_deck[index] = *temp;
		}
	}
	delete temp;
	temp = nullptr;
	m_currentCard = 0;
}

/**************************************************************
*	  Purpose:  Returns next card from deck               
*     Entry:  None.
*     Exit:  Current card incremented
****************************************************************/
Card Deck::Deal()
{
	return m_deck[m_currentCard++];
}