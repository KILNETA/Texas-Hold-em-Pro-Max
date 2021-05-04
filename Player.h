#pragma once

#include "Card.h"

class Player
{
private:
	Card HandCard[2];
public:
	Player() {}

	void setCard(int,Card);

	int getCardNumber(int);
	int getCardSpecies(int);

};

