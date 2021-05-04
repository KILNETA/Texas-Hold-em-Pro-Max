#pragma once
class Card
{
private:
	int Species=0;
	int Number=0;
public:
	Card() {}

	void setNumber(int);
	void setSpecies(int);

	int getNumber();
	int getSpecies();
};

