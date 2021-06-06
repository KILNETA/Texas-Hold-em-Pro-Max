#include "Player.h"
#include "Card.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

/*private class function*/
//計算勝算編號
bool Player::CalculationMaxWinNumber(int compareNum[])
{
	for (int i = 0; i < 5; i++)
	{
		if (MaxWin[i] < compareNum[i]) { return true; }
	}
	return false;
}
//最佳排組整理
void Player::ArrangeCards()
{
	Card tmp;
	for (int i = 0; i < 4; i++)
	{ 
		for (int j = 4; j > 0; j--)
		{
			if (MaxWinCards[j].getNumber() > MaxWinCards[j - 1].getNumber())
			{
				tmp = MaxWinCards[j];
				MaxWinCards[j] = MaxWinCards[j - 1];
				MaxWinCards[j - 1] = tmp;
			}
		}
	}
}

/*public class function*/

void Player::setCard(int num,Card poker)
{
	HandCard[num] = poker;
}

void Player::setMaxWin(int maxWinMode , int maxWin[], Card maxWinCards[])
{
	if (MaxWinMod == maxWinMode && CalculationMaxWinNumber(maxWin))
	{
		for (int i = 0; i < 5; i++)
		{
			MaxWin[i] = maxWin[i];
			MaxWinCards[i] = maxWinCards[i];
		}
		ArrangeCards();
	}
	if (MaxWinMod < maxWinMode)
	{
		MaxWinMod = maxWinMode;
		for (int i = 0; i < 5; i++)
		{
			MaxWin[i] = maxWin[i];
			MaxWinCards[i] = maxWinCards[i];
		}
		ArrangeCards();
	}
}
void Player::setLastOperation(int operation)
{
	LastOperation = operation;
}
void Player::setEnd(bool end)
{
	End = end;
}


int Player::getCardNumber(int num)
{
	return HandCard[num].getNumber();
}

int Player::getCardSpecies(int num)
{
	return HandCard[num].getSpecies();
}
int Player::getMaxWinCardsNumber(int num)
{
	return MaxWinCards[num].getNumber();
}
int Player::getMaxWinCardsSpecies(int num)
{
	return MaxWinCards[num].getSpecies();
}
Card Player::getCard(int num)
{
	return HandCard[num];
}
int Player::getMaxWinMode()
{
	return MaxWinMod;
}
int Player::getMaxWinNumber(int num)
{
	return MaxWin[num];
}
int Player::getLastOperation()
{
	return LastOperation;
}
bool Player::getEnd()
{
	return End;
}