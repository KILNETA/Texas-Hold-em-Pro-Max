#include <windows.h>
#include <vector>
#include <conio.h>

extern void Title(); //���Y (Title.cpp)

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "Card.h"
#include "Player.h"

using namespace std;

void ShufflePoker();
int PlayerNumber();

//�ܼ�
const int NUMBER_OF_CARDS = 52; //�d��
Card poker[52]; //class Card ���J�P����
const int player_number = PlayerNumber();
vector<Player> player;

//Shuffle
void ShufflePoker()
{
	int deck[NUMBER_OF_CARDS] = {0};//�d��

	for (int i = 0; i < NUMBER_OF_CARDS; i++)
	{
		deck[i] = i;//�a�J�d��
	}

	srand(time(0)); //���ɶ�
	for (int i = 0; i < NUMBER_OF_CARDS; i++) //�~�P
	{
		int index = rand() % NUMBER_OF_CARDS;
		int temp = deck[i];
		deck[i] = deck[index];
		deck[index] = temp;
	}

	for (int i = 0; i < 52; i++)
	{
		poker[i].setSpecies(deck[i] / 13); //��J���
		poker[i].setNumber(deck[i] % 13); //��J�Ʀr
	}
}
int PlayerNumber()
{
	int player = 0;
	cout << "���X�ӤH: " << endl;
	cin >> player;
	return player;
}
void ShowPlayerCard(vector<Player> Player,int playerNumber)
{
	string suits[] = { "Spades","Hearts","Diamonds","Clubs" };
	string ranks[] = { "Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King" };

	cout << "--------------------------Player" << playerNumber+1<< endl;
	for (int i = 0; i < 2; i++)
	{
		cout << suits[Player[playerNumber].getCardSpecies(i)] << " " << ranks[Player[playerNumber].getCardNumber(i)] << endl;
	}
}
void inputPlayerCard()
{
	static int cardNumber = 0;
	for (int j=0;j< player_number;j++)
	{
		for (int i = 0; i < 2; i++)
		{
			player[j].setCard(i, poker[cardNumber]);
			cardNumber++;
		}
	}
}

int main()
{
	//Title(); //���Y

	ShufflePoker(); //�~�Pfunction

	Player playertest;
	for (int i=0;i< player_number;i++)
	{
		player.push_back(playertest);
	}

	inputPlayerCard();

	for (int j = 0; j < player_number;j++)
	{
		ShowPlayerCard(player, j);
	}
}