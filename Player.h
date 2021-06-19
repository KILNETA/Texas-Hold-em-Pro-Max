#pragma once

#include "Card.h"
#include <vector>

class Player
{
private:
	Card HandCard[2];
	int MaxWin[5] = {};
	int MaxWinMod=0;
	Card MaxWinCards[5] = {};
	int LastOperation = -1;
	bool End = false;
	bool Fold = false;
	bool bot = false;

	bool CalculationMaxWinNumber(int[]);
	void ArrangeCards();
	int PlayerNumber = 0;

public:
	Player() {}
	Player(bool bot) 
	{
		this->bot = bot;
		End = false;
	}

	void setCard(int,Card);
	void setMaxWin(int, int[], Card[]);
	void setLastOperation(int);
	void setEnd(bool);
	void Folding();
	void setBot();
	void setPlayerNumber(int);

	int getCardNumber(int);
	int getCardSpecies(int);
	int getMaxWinCardsNumber(int);
	int getMaxWinCardsSpecies(int);
	Card getCard(int);
	int getMaxWinMode();
	int getMaxWinNumber(int);
	int getLastOperation();
	bool getEnd();
	bool getFold();
	bool  getBot();
	int getPlayerNumber();

};

