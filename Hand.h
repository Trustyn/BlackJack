/************************************************************************
* Class: Hand
*
* Constructors:	
*	Hand()
*		Default Constructor
*	~Hand()
*		Destructor
* Mutators:
*	void AddCard(Card card)
*		Adds a new card to the hand array
*	Hand(cosnt Hand & rhs)
*		Copy Constructor
* Methods:
*	int GetScore() const
*		Returns the card score
*	void CalcScore()
*		Calculates the score of whats in hand
*	void DisplayCards() const
*		Displays the cards to screen
*************************************************************************/
#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <Windows.h> //Colored text 12 = red, 7 = white, 6 = yellow
#include <iostream>
using std::cout;
using std::endl;

class Hand
{
	public:
		Hand();
		~Hand();
		void AddCard(Card card);
		int GetScore() const;
		void CalcScore();
		void DisplayCards() const;
		Hand(const Hand & rhs);
	private:
		Card * mCardArray;
		int mCardScore;
		int mCardCount;
};

#endif