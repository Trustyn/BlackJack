#include "Blackjack.h"

/**************************************************************
*	  Purpose: Default Constructor
*     Entry:  none.
*     Exit:  none.
****************************************************************/
Blackjack::Blackjack() : mDeck()
{
	mDeck.Shuffle();
}

/**************************************************************
*	  Purpose: Adjusts the bet based on win, loss, tie
*     Entry:  int betModifier
*     Exit:  none.
****************************************************************/
void Blackjack::CheckBet(int betModifier)
{
	mPlayer.AdjustBet(betModifier);
}

/**************************************************************
*	  Purpose: Checks if double down is possible
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::MenuCheck()
{
	if(mPlayer.GetHand().GetScore() == 10 || mPlayer.GetHand().GetScore() == 11)
	{
		DoubleMenu();		
	}
	else
	{		
		PlayMenu();
	}
}

/**************************************************************
*	  Purpose: Clears the cards from hand
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::ClearCards()
{
	mPlayer.ClearHand();
	mDealer.ClearHand();
	mDeck.Shuffle();
}

/**************************************************************
*	  Purpose: Checks to see if player has blackjack
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::BlackjackCheck()
{
	if(mPlayer.GetHand().GetScore() == 21)
	{
		system("cls");
		cout << "~~~~BLACKJACK~~~~" << endl;
		system("pause");
		ClearCards();
		CheckBet(1);
		MainSwitch();
	}
}

/**************************************************************
*	  Purpose: Checks the win, lose, tie status
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::ScoreCheck()
{
	if(mPlayer.GetHand().GetScore() > mDealer.GetHand().GetScore() &&
	   mPlayer.GetHand().GetScore() <= 21 || mDealer.GetHand().GetScore() > 21 && 
	   mPlayer.GetHand().GetScore() <= 21)
	{
		system("cls");
		cout << "~~~~YOU WIN~~~~" << endl;
		system("pause");
		ClearCards();
		CheckBet(1);
		MainSwitch();
	}
	else if(mPlayer.GetHand().GetScore() < mDealer.GetHand().GetScore() &&
		    mDealer.GetHand().GetScore() <= 21 || mPlayer.GetHand().GetScore() > 21)
	{
		system("cls");
		cout << "~~~~YOU LOSE~~~~" << endl;
		system("pause");
		ClearCards();
		CheckBet(-1);
		if(mPlayer.GetBank().GetMoney() == 0)
		{
			system("cls");
			cout << "You have lost all your money." << endl;
			cout << "Have a nice day please play again." << endl;
			system("pause");
			exit(1);
		}
		MainSwitch();
	}
	else if(mPlayer.GetHand().GetScore() == mDealer.GetHand().GetScore())
	{
		system("cls");
		cout << "~~~~YOU TIE~~~~" << endl;
		system("pause");
		ClearCards();
		CheckBet(0);
		MainSwitch();
	}
	else
		ClearCards();
}

/**************************************************************
*	  Purpose: Asks user for initial bet amount
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::IntroBet()															
{													
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	int startingBet(0);
	system("cls");
	cout << "Your current balance is $" << mPlayer.GetBank().GetMoney() << ". Please place your bet now\n"
		 << "by entering a dollar amount (example 5, 50, 100)." << endl;
	cin >> startingBet;
	if(cin.fail() || startingBet > mPlayer.GetBank().GetMoney())
	{
		cin.clear();
		cin.sync();
		
		cin.ignore(cin.rdbuf()->in_avail());
		IntroBet();
	}
	mPlayer.SetBank(startingBet);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}

/**************************************************************
*	  Purpose: initial menu for game.
*     Entry:  none.
*     Exit:  int menuChoice
****************************************************************/
int Blackjack::MainMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	int menuChoice(0);
	system("cls");
	cout << "Welcome to BlackJack." << endl;
	cout << "Please choose an option below.\n"
		 << "1. BET! to play.\n"
		 << "2. Quit." << endl;
	cin >> menuChoice;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		MainMenu();
	}
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return menuChoice;
}

/**************************************************************
*	  Purpose: Menu for the play options
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::PlayMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	int menuChoice(0);
	cout << "Please choose a play option.\n"
		 << "1. HIT! \n"
		 << "2. STAND! \n" << endl;
	cin >> menuChoice;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		system("cls");
		mPlayer.DisplayCards();
		mPlayer.DisplayScore();
		mDealer.DisplayCards();
		mDealer.DisplayScore();
		PlayMenu();
	}
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	PlaySwitch(menuChoice);
}

/**************************************************************
*	  Purpose: Menu for the double down options.
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::DoubleMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	int menuChoice(0);
	cout << "Please choose a play option.\n"
		 << "1. HIT! \n"
		 << "2. STAND! \n"
		 << "3. DOUBLE DOWN!" << endl;
	cin >> menuChoice;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		system("cls");
		mPlayer.DisplayCards();
		mPlayer.DisplayScore();
		mDealer.DisplayCards();
		mDealer.DisplayScore();
		DoubleMenu();
	}
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	PlaySwitch(menuChoice);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	DoubleSwitch(menuChoice);  

}

/**************************************************************
*	  Purpose: Switch for the main menu
*     Entry:  none.
*     Exit:  none.
****************************************************************/
void Blackjack::MainSwitch()
{
	int mainChoice = MainMenu();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	
	switch(mainChoice)
	{
		case 1:
			system("cls");
			IntroBet();
			system("cls");
			mPlayer.DrawCard(mDeck.Deal());
			mPlayer.DrawCard(mDeck.Deal());
			mPlayer.DisplayCards();
			mPlayer.DisplayScore();
			mDealer.DrawCard(mDeck.Deal());
			mDealer.DisplayCards();
			mDealer.DisplayScore();
			system("pause");
			if(mPlayer.GetHand().GetScore() == 21)
				BlackjackCheck();
			MenuCheck();
			break;
		case 2:
			exit(1);
			break;
		default:
			system("cls");
			ClearCards();
			MainSwitch();
	}
}

/**************************************************************
*	  Purpose: Switch for the play menu
*     Entry:  playChoice
*     Exit:  none.
****************************************************************/
void Blackjack::PlaySwitch(int playChoice)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	
	switch(playChoice)
	{
		case 1:
			system("cls");
			mPlayer.DrawCard(mDeck.Deal());
			if(mPlayer.GetHand().GetScore() > 21)
			{
				cout << "~~~~BUST~~~~" << endl;
				system("pause");
				ScoreCheck();
			}
			mPlayer.DisplayCards();
			mPlayer.DisplayScore();
			mDealer.DisplayCards();
			mDealer.DisplayScore();
			PlayMenu();
			break;
		case 2:
			system("cls");
			mPlayer.DisplayCards();
			mPlayer.DisplayScore();
			do{
			mDealer.DrawCard(mDeck.Deal());
			}while(mDealer.GetHand().GetScore() < 17);
			mDealer.DisplayCards();
			mDealer.DisplayScore();
			system("pause");
			system("cls"); 
			ScoreCheck();
			break;
		default:
			system("cls");
			mPlayer.DisplayCards();
			mPlayer.DisplayScore();
			mDealer.DisplayCards();
			mDealer.DisplayScore();
			PlayMenu();
	}
}

/**************************************************************
*	  Purpose: Switch for double down menu
*     Entry:  doubleChoice
*     Exit:  none.
****************************************************************/
void Blackjack::DoubleSwitch(int doubleChoice)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	
	switch(doubleChoice)
	{
		case 1:
			system("cls");
			mPlayer.DrawCard(mDeck.Deal());
			if(mPlayer.GetHand().GetScore() > 21)
			{
				cout << "~~~~BUST~~~~" << endl;
				ScoreCheck();
			}
			mPlayer.DisplayCards();
			mPlayer.DisplayScore();
			mDealer.DisplayCards();
			mDealer.DisplayScore();
			system("pause");
			if(mPlayer.GetHand().GetScore() > 21)
				ScoreCheck();
			else
				PlayMenu();
			break;
		case 2:
			system("cls");
			mPlayer.DisplayCards();
			mPlayer.DisplayScore();
			do{
				mDealer.DrawCard(mDeck.Deal());
			}while(mDealer.GetHand().GetScore() < 17);
			mDealer.DisplayCards();
			mDealer.DisplayScore();
			system("pause");
			system("cls"); 
			ScoreCheck();		
			break;
		case 3:
			if(mPlayer.GetBank().GetMoney() >= mPlayer.GetBank().GetBet() * 2)
			{
				system("cls");
				mPlayer.GetBet() * 2; 
				mPlayer.DrawCard(mDeck.Deal());
				if(mPlayer.GetHand().GetScore() > 21)
				{
					cout << "~~~~BUST~~~~" << endl;
					mPlayer.DisplayCards();
					mPlayer.DisplayScore();
					mDealer.DisplayCards();
					mDealer.DisplayScore();
					system("pause");
					ScoreCheck();
				}
				mPlayer.DisplayCards();
				mPlayer.DisplayScore();
				mDealer.DisplayCards();
				mDealer.DisplayScore();
				system("pause");
				ScoreCheck();
			}
			else
			{
				system("cls");
				mPlayer.DisplayCards();
				mPlayer.DisplayScore();
				mDealer.DisplayCards();
				mDealer.DisplayScore();
				cout << "Insufficient Bank Funds." << endl;
				system("pause");
				PlayMenu();
			}
			break;
		default:
			system("cls");
			mPlayer.DisplayCards();
			mPlayer.DisplayScore();
			mDealer.DisplayCards();
			mDealer.DisplayScore();
			DoubleMenu();
	}
}
