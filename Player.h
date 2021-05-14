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

	bool CalculationMaxWinNumber(int[]);
	void ArrangeCards();

public:
	Player() {}

	void setCard(int,Card);
	void setMaxWin(int, int[], Card[]);

	int getCardNumber(int);
	int getCardSpecies(int);
	int getMaxWinCardsNumber(int);
	int getMaxWinCardsSpecies(int);
	Card getCard(int);
	int getMaxWinMode();
	int getMaxWinNumber(int);

};

