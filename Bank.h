/************************************************************************
* Class: Bank
*
* Constructors:	
*	Bank()
*		Default Constructor
* Mutators:
*	void AdjustMoney(int betModifier)
*		Modifies money based on win loss modifier
*	void SetBet(int bet)
*		Sets the bet data member to passed in value
* Methods:
*	int GetMoney() const
*		Returns money amount
*	int GetBet() const
*		Returns bet amount
*************************************************************************/
#ifndef BANK_H
#define BANK_H
#include <Windows.h> //Colored text 12 = red, 7 = white, 6 = yellow
#include <iostream>
using std::cout;
using std::endl;

class Bank
{
	public:
		Bank();
		int GetMoney() const;
		int GetBet() const;
		void SetBet(int bet);
		void AdjustMoney(int betModifier);
	private:
		unsigned int mMoney;
		int mBet;
};

#endif