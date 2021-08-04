/************************************************************************
* Class: Deck
*
* Constructors:	
*	Deck ()
*		The array of cards is initialized to the 13 different
*		ranks for each of the 4 suits.
*
* Mutators: 
*	void Shuffle ()
*		Randomly rearranges the cards in the array.
*
* Methods:		
*	Card Deal ()
*		Starting out at 0 each time the deck is shuffled
*		It will deal the next card then output it to the screen.
*************************************************************************/
#ifndef DECK_H
#define DECK_H
#include <iostream>
using std::cout;
using std::endl;
#include "Card.h"
#include "Random.h"

const int NUM_CARDS = 52;

class Deck
{
	public:
		Deck();
		~Deck();
		void Shuffle();
		Card Deal();
	private:
		Card * m_deck;
		int m_currentCard;
};
#endif 