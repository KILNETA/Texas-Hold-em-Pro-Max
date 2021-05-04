#include "Player.h"
#include "Card.h"

void Player::setCard(int num,Card poker)
{
	HandCard[num] = poker;
}

int Player::getCardNumber(int num)
{
	return HandCard[num].getNumber();
}

int Player::getCardSpecies(int num)
{
	return HandCard[num].getSpecies();
}