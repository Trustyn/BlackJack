/************************************************************************
* Class: Card
*
* Constructors:	
*	Card ()
*		Rank is initialized to Ace starting at 1 and suit 
*		is initalized to spades.
*
* Mutators:
*	void SetRank ( Rank rank )
*		Sets rank to the rank passed in.
*	void SetSuit ( Suit suit )
*		Sets suit to the suit passed in.
*	Card & operator=(const Card &rhs)
*		Overriding the = so it can be used for objects.
*
* Methods:
*	void Display ()
*		Displays a cards rank and suit the the screen.
*	Rank GetRank ()
*		Returns the rank of the card.
*	Suit GetSuit ()
*		Returns the suit of the card.
*************************************************************************/
#ifndef CARD_H
#define CARD_H
#include "Random.h"
#include <iostream>
using std::cout;
using std::endl;
#include <Windows.h> //Colored text 12 = red, 7 = white, 6 = yellow

enum Rank { Ace = 1, Deuce, Trey, Four, Five, Six, Seven,
	        Eight, Nine, Ten, Jack, Queen, King };

enum Suit { Spades, Hearts, Clubs, Diamonds };

class Card
{	
	public:
		Card(Rank rank = Ace, Suit suit = Spades);
		Card & operator=(const Card &rhs);
		void Display() const;
		void SetRank( Rank rank );
		void SetSuit( Suit suit );
		Rank GetRank() const;
		Suit GetSuit() const;

	private:
		Rank m_rank;
		Suit m_suit;
};
#endif