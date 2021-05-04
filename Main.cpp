#include <windows.h>
#include <vector>
#include <conio.h>

extern void Title(); //片頭 (Title.cpp)

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "Card.h"
#include "Player.h"

using namespace std;

void ShufflePoker();
int PlayerNumber();

//變數
const int NUMBER_OF_CARDS = 52; //卡數
Card poker[52]; //class Card 撲克牌物件
const int player_number = PlayerNumber();
vector<Player> player;

//Shuffle
void ShufflePoker()
{
	int deck[NUMBER_OF_CARDS] = {0};//卡片

	for (int i = 0; i < NUMBER_OF_CARDS; i++)
	{
		deck[i] = i;//帶入卡號
	}

	srand(time(0)); //取時間
	for (int i = 0; i < NUMBER_OF_CARDS; i++) //洗牌
	{
		int index = rand() % NUMBER_OF_CARDS;
		int temp = deck[i];
		deck[i] = deck[index];
		deck[index] = temp;
	}

	for (int i = 0; i < 52; i++)
	{
		poker[i].setSpecies(deck[i] / 13); //輸入花色
		poker[i].setNumber(deck[i] % 13); //輸入數字
	}
}
int PlayerNumber()
{
	int player = 0;
	cout << "有幾個人: " << endl;
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
	//Title(); //片頭

	ShufflePoker(); //洗牌function

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