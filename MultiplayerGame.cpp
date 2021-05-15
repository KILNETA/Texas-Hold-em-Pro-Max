#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <conio.h>

#include "Card.h"
#include "Player.h"

using namespace std;

/*Function索引*/
void MultiplayerGame();//遊戲函式
int PlayerNumber();//問幾個玩家
void ShufflePoker();//洗牌
void inputPublicCard();//發公牌
void lostCard();//蓋牌
void inputPlayerCard();//發手牌
void ShowPublicCard(vector<Card> publicCard);//印出公牌
void ShowPlayerCard(int playerNumber);//印出手牌
void MaxWinCards(int playerNumber);//印最佳牌型
void ShowMaxWinCards(int playerNumber);//最佳牌型 展示
void ShowWinner();//最贏

void Public_Player_combination(int playerNumber);//自公牌與手牌取5張組合 (4次)
void CheckCard(vector<Card> Cards,int player);//判斷牌型
void RecordingMaxWinNumber(int *compareNum, int cardNumber);//記錄勝算編號
/*Function索引*/

/*公用參數*/
vector<Card> publicCard;
vector<Player> player;
const int NUMBER_OF_CARDS = 52;
Card poker[52];
const int player_number = PlayerNumber();
static int cardNumber = 0;
int AllBet = 0;
int Around = 0;
/*公用參數*/

//////////////////////////// Functions ////////////////////////////////////

//問幾個玩家
int PlayerNumber()
{
	int player = 0;
	cout << "有幾個人: " << endl;
	cin >> player;
	return player;
}
//洗牌
void ShufflePoker()
{
	int deck[NUMBER_OF_CARDS] = { 0 };//卡片

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
//印出公牌
void ShowPublicCard(vector<Card> publicCard)
{
	string suits[] = { "愛心","方塊","梅花","黑桃" };
	string ranks[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

	cout << "--------------------------PublicCard"<< endl;
	for (int i = 0; i < publicCard.size(); i++)
	{
		cout << suits[publicCard[i].getSpecies()] << " " <<left << setw(3) << ranks[publicCard[i].getNumber()] << endl;
	}
}
//印出手牌
void ShowPlayerCard(int playerNumber)
{
	string suits[] = { "愛心","方塊","梅花","黑桃" };
	string ranks[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

	cout << "--------------------------Player" << playerNumber + 1 << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << suits[player[playerNumber].getCardSpecies(i)] << " " << left << setw(3) << ranks[player[playerNumber].getCardNumber(i)] << endl;
	}
	cout << endl;
	if (Around == 3) 
	{
		MaxWinCards(playerNumber);
	}
}
//印最佳牌型
void MaxWinCards(int playerNumber)
{
	switch (player[playerNumber].getMaxWinMode())
	{
	case 10:cout << "　　　\"皇家同花順\"" ; break;
	case 9:cout << "　　　\"同花順\"" ; break;
	case 8:cout << "　　　\"四條\"" ; break;
	case 7:cout << "　　　\"葫蘆\"" ; break;
	case 6:cout << "　　　\"同花\"" ; break;
	case 5:cout << "　　　\"順子\"" ; break;
	case 4:cout << "　　　\"三條\"" ; break;
	case 3:cout << "　　　\"兩對\"" ; break;
	case 2:cout << "　　　\"一對\"" ; break;
	case 1:cout << "　　　\"散牌\"" ; break;
	}
	cout << "　　";
	ShowMaxWinCards(playerNumber);
}
//最佳牌型 展示
void ShowMaxWinCards(int playerNumber)
{
	string suits[] = { "愛心","方塊","梅花","黑桃" };
	string ranks[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	for (int i = 0; i < 5; i++)
	{
		cout << suits[player[playerNumber].getMaxWinCardsSpecies(i)] << " " << left <<setw(3)<< ranks[player[playerNumber].getMaxWinCardsNumber(i)] << "　";
	}
	cout << endl;
}
//最贏
void ShowWinner()
{
	static int nowWinnerPlayerNumber = 0;
	static int nowWinnerPlayerMaxWinNumber[5] = { 0 };
	static int nowWinnerPlayerMaxWinMode = 0;
	for(int j=0;j< player_number;j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (nowWinnerPlayerMaxWinMode < player[j].getMaxWinMode())
			{
				nowWinnerPlayerNumber = j + 1;
				nowWinnerPlayerMaxWinMode = player[j].getMaxWinMode();
				for(int i=0;i<5;i++)
				{
					nowWinnerPlayerMaxWinNumber[i] = player[j].getMaxWinNumber(i);
				}
			}
			else
			{ 
				if (nowWinnerPlayerMaxWinMode == player[j].getMaxWinMode())
				{
					for (int i = 0; i < 5; i++)
					{
						if (nowWinnerPlayerMaxWinNumber[i] < player[j].getMaxWinNumber(i))
						{
							nowWinnerPlayerNumber = j + 1;
							for (int f = 0; f < 5; f++)
							{
								nowWinnerPlayerMaxWinNumber[f] = player[j].getMaxWinNumber(f);
							}
							break;
						}
					}
				}
			}
		}
	}
	cout << "--------------------------------Winner is Player" << nowWinnerPlayerNumber << endl;
}

//發公牌
void inputPublicCard()
{
	publicCard.push_back(poker[cardNumber]);
	cardNumber++;
}
//蓋牌
void lostCard()
{
	cardNumber++;
}
//發手牌
void inputPlayerCard()
{
	for (int j = 0; j < player_number; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			player[j].setCard(i, poker[cardNumber]);
			cardNumber++;
		}
	}
}

//自公牌與手牌取5張組合 (4次)
void Public_Player_combination(int playerNumber)
{
	for (int i = 1; i <= 4; i++)
	{
		switch (i)
		{
		case 1: 
			
			for (int j = 0; j < 5; j++)
			{
				vector<Card> Cards = {};
				Cards.push_back(player[playerNumber].getCard(0));
				for (int q = 0; q < 5; q++)
				{
					if (q != j) { Cards.push_back(publicCard[q]); }
				}
				CheckCard(Cards, playerNumber);
			}
			break;
		case 2: 
			for (int j = 0; j < 5; j++)
			{
				vector<Card> Cards = {};
				Cards.push_back(player[playerNumber].getCard(1));
				for (int q = 0; q < 5; q++)
				{
					if (q != j) { Cards.push_back(publicCard[q]); }
				}
				CheckCard(Cards, playerNumber);
			}
			break;
		case 3: 
			for (int j = 0; j < 5; j++)
			{
				for (int q = 0; q < 5; q++)
				{
					vector<Card> Cards = {};
					Cards.push_back(player[playerNumber].getCard(0));
					Cards.push_back(player[playerNumber].getCard(1));
					for (int f = 0; f < 5; f++)
					{
						if (q != j && f != j && f != q && q > j) { Cards.push_back(publicCard[f]); }

					}
					if (Cards.size() == 5) { CheckCard(Cards, playerNumber); }  /////////////~!!!!
				}
			}
			break;
		case 4: 
			vector<Card> Cards = {};
			for (int i = 0; i < 5; i++)
			{
				Cards.push_back(publicCard[i]);
			}
			CheckCard(Cards, playerNumber);
			break;
		}
	}
}

//判斷牌型
void CheckCard(vector<Card> Cards,int playerNumber)
{
	int flush = 0, straight = 0, four_of_a_kind = 0, three_of_a_king = 0, i;
	int pair = 0, count = 0, a_straight = 0, start, end=0;
	int kind[4] = { 0 }, scard[13] = { 0 }; // 4種花色 13個卡號
	int compareNum[5] = {};
	Card Cards_2[5]{};

	for (i = 0; i < 5; i++)
	{
		kind[Cards[i].getSpecies()]++; //各花色 有幾張 
		scard[Cards[i].getNumber()]++; //各卡號 有幾張 

		Cards_2[i]= Cards[i];
	}
	for (i = 0; i < 4; i++)
	{
		if (kind[i] == 5) { flush = 1; }//如果 相同花色有5張 //是否有同花
	}
	for (i = 12; i > -1; i--)
	{
		if (scard[i] != 0)//如果有這個牌號 
		{
			if (end < i) { end = i; }//end 最大一張牌號 
			if (scard[i] == 4) {four_of_a_kind = 1; RecordingMaxWinNumber(compareNum,i);}            //是四條 
			else if (scard[i] == 3) { three_of_a_king = 1; RecordingMaxWinNumber(compareNum, i);}             //是三條 
		}
	}
	for (i = 12; i > -1; i--)
	{
		if (scard[i] != 0)//如果有這個牌號 
		{
			if (scard[i] == 2) { pair++; RecordingMaxWinNumber(compareNum, i);}                        //有X對 
			else if (scard[i] == 1) { count++; RecordingMaxWinNumber(compareNum, i);}                    //無關牌數 
		}
	}

	/* check straight */
	if (count == 5) // 五張都無關牌 
	{
		if (scard[0] && scard[9] && scard[10] && scard[11] && scard[12]) { a_straight = 1; }//大同花 
		else
		{
			start = end - count + 1;//最大牌號-無關牌數+1 
			for (i = start; i <= end; i++) { if (scard[i]) { count--; } } //無關牌數 遞減  (最大牌號-無關牌數+1  ->  最大牌號) 次 
			if (count == 0) { straight = 1; RecordingMaxWinNumber(compareNum, i);}// 無關牌數 = 0// 是順子
		}
	}

	if (a_straight && flush) { player[playerNumber].setMaxWin(10, 0, Cards_2); }  //同花大順 
	else 	if (straight && flush) { player[playerNumber].setMaxWin(9, compareNum, Cards_2); }  //同花順 
	else 	if (four_of_a_kind) { player[playerNumber].setMaxWin(8, compareNum, Cards_2); }  //四條 
	else 	if (three_of_a_king && pair) { player[playerNumber].setMaxWin(7, compareNum, Cards_2); }  //葫蘆 
	else 	if (flush) { player[playerNumber].setMaxWin(6, compareNum, Cards_2); }  //同花 
	else 	if (straight || a_straight) { player[playerNumber].setMaxWin(5, compareNum, Cards_2); }  //順子 
	else 	if (three_of_a_king) { player[playerNumber].setMaxWin(4, compareNum, Cards_2); }  //三條 
	else 	if (pair == 2) { player[playerNumber].setMaxWin(3, compareNum, Cards_2); }  //兩對
	else 	if (pair == 1) { player[playerNumber].setMaxWin(2, compareNum, Cards_2); }  //一對
	else 	if (pair == 0) { player[playerNumber].setMaxWin(1, compareNum, Cards_2); }  //雜牌
}
//記錄勝算編號
void RecordingMaxWinNumber(int* compareNum,int cardNumber)
{
	for (int i=0;i<5;i++)
	{
		if (*(compareNum + i) == 0)
		{
			*(compareNum + i) = cardNumber;
			return;
		}
	}
}


//遊戲函式
void MultiplayerGame()
{
	int Place_a_bet = 0;
	int winPlayer = 0;
	int Maxwin = 0;
	ShufflePoker(); //洗牌function

	Player playertest;
	for (int i = 0; i < player_number; i++)
	{
		player.push_back(playertest);
	}

		cout << "目前彩池" << AllBet << "    Player " << 1 << endl;
		cout << "小盲注下多少: ";
		cin >> Place_a_bet;
		AllBet += Place_a_bet;
		cout << endl << endl << "按任意鍵下一位" << endl;
		_getch();

		system("cls");
		cout << "目前彩池" << AllBet << "    Player " << 2 << endl;
		cout << "強制下大盲注:  "<< Place_a_bet*2;
		AllBet += (Place_a_bet*2);
		cout << endl << endl << "按任意鍵下一位" << endl;
		_getch();

		inputPlayerCard();
	//印自己+下注
	for (int j = 2; j < player_number; j++)
	{
		system("cls");
		cout << "目前彩池" << AllBet <<"    Player "<< j+1 << endl;
		ShowPlayerCard(j);
		cout << "下注多少: ";
		cin >> Place_a_bet;
		AllBet += Place_a_bet;
		cout << endl << endl << "按任意鍵下一位" << endl;
		_getch();
	}
	for (int j = 0; j < 2; j++)
	{
		system("cls");
		cout << "目前彩池" << AllBet << "    Player " << j+1 << endl;
		ShowPlayerCard(j);
		cout << "下注多少: ";
		cin >> Place_a_bet;
		AllBet += Place_a_bet;
		cout << endl << endl << "按任意鍵下一位"<<endl;
		_getch();
	}
	lostCard(); inputPublicCard(); inputPublicCard(); inputPublicCard();//棄一牌 發公牌*3
	for (int j = 0; j < player_number; j++)
	{
		system("cls");
		cout << "目前彩池" << AllBet << "    Player " << j + 1 << endl;
		ShowPublicCard(publicCard);
		ShowPlayerCard(j);
		cout << "下注多少: ";
		cin >> Place_a_bet;
		AllBet += Place_a_bet;
		cout << endl << endl << "按任意鍵下一位" << endl;
		_getch();
	}
	Around++;
	lostCard(); inputPublicCard(); ;//棄一牌 發公牌+1
	for (int j = 0; j < player_number; j++)
	{
		system("cls");
		cout << "目前彩池" << AllBet << "    Player " << j + 1 << endl;
		ShowPublicCard(publicCard);
		ShowPlayerCard(j);
		cout << "下注多少: ";
		cin >> Place_a_bet;
		AllBet += Place_a_bet;
		cout << endl << endl << "按任意鍵下一位" << endl;
		_getch();
	}
	Around++;
	lostCard(); inputPublicCard(); ;//棄一牌 發公牌+1
	for (int j = 0; j < player_number; j++)
	{
		system("cls");
		cout << "目前彩池" << AllBet << "    Player " << j + 1 << endl;
		ShowPublicCard(publicCard);
		ShowPlayerCard(j);
		cout << "下注多少: ";
		cin >> Place_a_bet;
		AllBet += Place_a_bet;
		cout << endl << endl << "按任意鍵下一位" << endl;
		_getch();
	}
	Around++;


	for (int j = 0; j < player_number; j++)
	{
		Public_Player_combination(j);
	}
	for (int j = 0; j < player_number; j++)
	{
		ShowPlayerCard(j);
	}
	ShowWinner();
}