#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <conio.h>
#include <time.h>
#include "Card.h"
#include "Player.h"

using namespace std;

/*Function索引*/
//移動 輸入處
#include <windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

void gotoxyGame(double x, double y)
{	// the type is double, so objects can move less than 1 unit 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; // start from 0
	dwPos.Y = y; // start from 0
	SetConsoleCursorPosition(hCon, dwPos);
}
void MultiplayerGame();//遊戲函式 
bool PlayerNumber();//問幾個玩家 
void inputPlayerNullData(int playerNumber,int botNumber);//創造空值玩家資料 V
void ShufflePlayer();//洗玩家
void ShufflePoker();//洗牌 V
void GameInterface();//印遊戲介面
void inputPublicCard();//發公牌 V
void lostCard();//蓋牌 V
void inputPlayerCard();//發手牌 V
void ShowPublicCard();//印出公牌
void ShowPlayerOperating(int playerNumber);//印出所有玩家上一次的操作記錄
void ShowPlayerCard(int playerNumber);//印出手牌
void HidePlayerCard();//手牌隱藏
int ShowWinner();//最贏

void Public_Player_combination(int playerNumber);//自公牌與手牌取5張組合 (4次)
void CheckCard(vector<Card> Cards,int player);//判斷牌型
void RecordingMaxWinNumber(int *compareNum, int cardNumber);//記錄勝算編號
void PlayerOperating(int playerNumber);
/*Function索引*/

/*公用參數*/
int x = 0, y = 0;
vector<Card> publicCard; //可擴充的公牌
vector<Player> player;//可擴充的player
const int NUMBER_OF_CARDS = 52; //poker牌有52張
Card poker[NUMBER_OF_CARDS]; //52張Class poker牌
int player_number = 0; //玩家數
static int cardNumber = 0; //當前已用卡號至
int AllBet = 0; //彩池
int LastBet = 0; //上一注金額
int Around = 0; //回合數
bool First_lap = false;
bool AllBetExplosion = false;
static bool ferst = true;
/*公用參數*/

//////////////////////////// Functions ////////////////////////////////////

//
void GameReturn()
{
publicCard.clear(); //可擴充的公牌
player.clear();//可擴充的player
player_number = 0; //玩家數
cardNumber = 0; //當前已用卡號至
AllBet = 0; //彩池
LastBet = 0; //上一注金額
Around = 0; //回合數
First_lap = false;
AllBetExplosion = false;
ferst = true;
PlayerOperating(-1);
ShowPlayerOperating(-1);
}
//彩池溢出
void AllBetExplosionVerification()
{
	if (AllBet > 99999999)
	{
		AllBetExplosion = true;
	}
}
//彩池溢出彩蛋
void AllBetExplosionEasterEggs()
{
	system("cls");
	cout << endl << endl;
	cout << "                                                                  ▁" << endl;
	cout << "                                                                /    \\" << endl;
	cout << "              ▁                                               | 20 $ |-" << endl;
	cout << "            /    \\                                              \\ ▁ /  \\" << endl;
	cout << "           | 20 $ |                                               | 20 $ |" << endl;
	cout << "            \\ ▁ /               彩池發生溢出！                    \\ ▁ /" << endl;
	cout << endl << endl;
	cout << "                           遊戲將把彩池平分給各玩家！" << endl;
	cout << endl << endl;
	cout << "                                恭喜達成隱藏成就" << endl;
	cout << endl;
	cout << "                        ＿＿＿【超越八位數的賭局】＿＿＿" << endl;
	cout << endl;
	cout << "                                                          ▁" << endl;
	cout << "              ▁                                        /    \\" << endl;
	cout << "            /    \\             ～ 本局遊戲結束 ～      | 20 $ |" << endl;
	cout << "           | 20 $ |                                     \\ ▁ /" << endl;
	cout << "            \\ ▁ /" << endl;
	cout << endl;
	cout << "                                Ｏ 任意鍵離開 Ｏ" << endl;

	gotoxyGame(x + 79, y + 24);
	_getch();
}
//多人遊戲提示
void MultiplayerGamePrompt()
{
	system("cls");
	gotoxyGame(x + 28, y + 2);  cout << "Ｏ 多 人 遊 戲  提 示 Ｏ";
	gotoxyGame(x + 29, y + 5);  cout << "多人遊戲性質為 \"友誼賽\"";
	gotoxyGame(x + 23, y + 7);  cout << "因此無下注總額限制  無\"ALL IN\"玩法";
	gotoxyGame(x + 18, y + 9);  cout << "盲注最大 100$  且單次加注上限為 跟注金額 x10倍";
	gotoxyGame(x + 29, y + 11);  cout << "彩池上限  99,999,999 $";
	gotoxyGame(x + 25, y + 13);  cout << "(超過上限則平分彩池且遊戲結束)";
	gotoxyGame(x + 22, y + 15);  cout << "切換玩家時皆有 按鍵驗證 防止手牌外曝";
	gotoxyGame(x + 17, y + 17);  cout << "玩家編號皆由 1號 開始 真人玩家可先自行決定順序";
	gotoxyGame(x + 27, y + 19);  cout << "開局所有玩家排序將隨機編排";
	gotoxyGame(x + 32, y + 22);  cout << "Ｏ 任意鍵離開 Ｏ";
	gotoxyGame(x + 79, y + 24);
	_getch();
	system("cls");

	gotoxyGame(x + 45, y + 5); cout << "  __________   ▁";
	gotoxyGame(x + 45, y + 6); cout << "||          |/    \\";
	gotoxyGame(x + 45, y + 7); cout << "|| Texas    |  20 $|\\";
	gotoxyGame(x + 45, y + 8); cout << "||    hold  |\\ ▁ / $|";
	gotoxyGame(x + 45, y + 9); cout << "||      'em |　 |▁ /";
	gotoxyGame(x + 45, y + 10); cout << "||          |   |";
	gotoxyGame(x + 45, y + 11); cout << "|| Game     ▍  |";
	gotoxyGame(x + 45, y + 12); cout << "||__________▉  |";
	gotoxyGame(x + 45, y + 13); cout << "     |   ▉▉   |";
	gotoxyGame(x + 45, y + 14); cout << "     |    ▉  Ａ|";
	gotoxyGame(x + 45, y + 15); cout << "     |_________ |";
	gotoxyGame(x + 40, y + 19); cout << "Ｔｅｘａｓ ｈｏｌｄ'ｅｍ Ｇａｍｅ";
	gotoxyGame(x + 11, y + 3); cout << "多 人 遊 戲";
	gotoxyGame(x + 9, y + 5); cout << "(遊玩人數2~22人)";
	gotoxyGame(x + 5, y + 8); cout << ">";
	gotoxyGame(x + 8, y + 8); cout << "玩家人數";
	gotoxyGame(x + 8, y + 11); cout << "機器人數";

	gotoxyGame(x + 10, y + 15); cout << " T    遊戲教學";
	gotoxyGame(x + 10, y + 17); cout << " P    遊戲提示";
	gotoxyGame(x + 8, y + 19); cout << "Enter   進入遊戲";
	gotoxyGame(x + 10, y + 21); cout << "Esc   返回";

}
//多人遊戲遊戲設置
bool PlayerNumber()
{
	int select = 0;
	static int playerNumber = 0 , botNumber = 0;

	gotoxyGame(x + 45, y + 5); cout << "  __________   ▁";
	gotoxyGame(x + 45, y + 6); cout << "||          |/    \\";
	gotoxyGame(x + 45, y + 7); cout << "|| Texas    |  20 $|\\";
	gotoxyGame(x + 45, y + 8); cout << "||    hold  |\\ ▁ / $|";
	gotoxyGame(x + 45, y + 9); cout << "||      'em |　 |▁ /";
	gotoxyGame(x + 45, y + 10); cout << "||          |   |";
	gotoxyGame(x + 45, y + 11); cout << "|| Game     ▍  |";
	gotoxyGame(x + 45, y + 12); cout << "||__________▉  |";
	gotoxyGame(x + 45, y + 13); cout << "     |   ▉▉   |";
	gotoxyGame(x + 45, y + 14); cout << "     |    ▉  Ａ|";
	gotoxyGame(x + 45, y + 15); cout << "     |_________ |";
	gotoxyGame(x + 40, y + 19); cout << "Ｔｅｘａｓ ｈｏｌｄ'ｅｍ Ｇａｍｅ";
	gotoxyGame(x + 11, y + 3); cout << "多 人 遊 戲";
	gotoxyGame(x + 9, y + 5); cout << "(遊玩人數2~22人)";
	gotoxyGame(x + 5, y + 8); cout << ">";
	gotoxyGame(x + 8, y + 8); cout << "玩家人數";
	gotoxyGame(x + 8, y + 11); cout << "機器人數";

	gotoxyGame(x + 10, y + 15); cout << " T    遊戲教學";
	gotoxyGame(x + 10, y + 17); cout << " P    遊戲提示";
	gotoxyGame(x + 8, y + 19); cout << "Enter   進入遊戲";
	gotoxyGame(x + 10, y + 21); cout << "Esc   返回";

	while(1)
	{
		gotoxyGame(x + 21, y + 8); cout << "  ";
		gotoxyGame(x + 21, y + 11); cout << "  ";
		gotoxyGame(x + 21, y + 8); cout <<setw(2)<< right << playerNumber;
		gotoxyGame(x + 21, y + 11); cout << setw(2) <<right<< botNumber;
		if (playerNumber + botNumber < 22)
		{
			gotoxyGame(x + 24, y + 8); cout << ">";
			gotoxyGame(x + 24, y + 11); cout << ">";
		}
		else
		{
			gotoxyGame(x + 24, y + 8); cout << " ";
			gotoxyGame(x + 24, y + 11); cout << " ";
		}
		if (playerNumber + botNumber > 2)
		{
			gotoxyGame(x + 19, y + 8); cout << "<";
			gotoxyGame(x + 19, y + 11); cout << "<";
		}
		else
		{
			gotoxyGame(x + 19, y + 8); cout << " ";
			gotoxyGame(x + 19, y + 11); cout << " ";
		}
		gotoxyGame(x + 79, y +24);
		switch (_getch())
		{
		case 72:
			if (select == 1) { select--; }//up
			gotoxyGame(x + 5, y + 11); cout << " ";
			gotoxyGame(x + 5, y + 8); cout << ">";
			break;
		case 80:
			if (select == 0) { select++; }//down
			gotoxyGame(x + 5, y + 8); cout << " ";
			gotoxyGame(x + 5, y + 11); cout << ">";
			break;
		case 77: //right
			if (select == 0)
			{
				if (playerNumber+ botNumber<22 && playerNumber<22)
				{
					playerNumber++;
				}
			}
			else
			{
				if (playerNumber + botNumber < 22 && botNumber < 22)
				{
					botNumber++;
				}
			}
			break;
		case  75: //left
			if (select == 0)
			{
				if (playerNumber + botNumber > 2 && playerNumber>0)
				{
					playerNumber--;
				}
			}
			else
			{
				if (playerNumber + botNumber > 2 && botNumber > 0)
				{
					botNumber--;
				}
			}
			break;
		case 116: //T
			system("START www.youtube.com/watch?v=I4UIn-0N7Fs");
			break;
		case 112: //P
			MultiplayerGamePrompt();
			break;
		case 13: //Enter
			if (playerNumber + botNumber >= 2 && playerNumber > 0)
			{
				system("cls");
				player_number = playerNumber + botNumber;
				inputPlayerNullData(playerNumber, botNumber);
				ShufflePlayer();
				return true;
			}
			break;
		case 27: //Ecs
			system("cls");
			return false;
			break;
		}
	}
}
//創造空值玩家資料
void inputPlayerNullData(int playerNumber, int botNumber)
{
	Player playerNull_1(false);
	for (int i = 0; i < playerNumber; i++) { player.push_back(playerNull_1); }
	Player playerNull_2(true);
	for (int i = 0; i < botNumber; i++) { player.push_back(playerNull_2); }
}
//洗玩家
void ShufflePlayer()
{
	for (int i = 0; i < player.size(); i++)
	{
		player[i].setPlayerNumber(i+1);//帶入卡號
	}

	srand(time(0)); //取時間
	for (int i = 0; i < player.size(); i++) //洗牌
	{
		int index = rand() % player.size();
		Player ShufflePlayer = player[i];
		player[i] = player[index];
		player[index] = ShufflePlayer;
	}
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
//印遊戲介面
void GameInterface()
{
	gotoxyGame(x, y + 1);
	cout << "        __________  __________  __________  __________  __________ " << endl;
	cout << " 公牌  |          ||          ||          ||          ||          |" << endl;
	cout << "       |          ||          ||          ||          ||          |" << endl;
	cout << "       |          ||          ||          ||          ||          |" << endl;
	cout << "       |          ||          ||          ||          ||          |" << endl;
	cout << "       |          ||          ||          ||          ||          |" << endl;
	cout << "       |          ||          ||          ||          ||          |" << endl;
	cout << "       |__________||__________||__________||__________||__________|" << endl << endl;
	for (int y1 = 0; y1 < 25; y1++)
	{
		gotoxyGame(x + 68, y + y1); cout << "|";
	}
	gotoxyGame(x + 37, y + 12); cout << " ______________________________";
	for (int y1 = 13; y1 < 25; y1++)
	{
		gotoxyGame(x + 37, y + y1); cout << "|";
	}
	gotoxyGame(x, y + 12);
	cout << "        __________  __________" << endl;
	cout << " 手牌  |          ||          |" << endl;
	cout << "       |          ||          |" << endl;
	cout << "       |          ||          |" << endl;
	cout << "       |          ||          |" << endl;
	cout << "       |          ||          |" << endl;
	cout << "       |          ||          |" << endl;
	cout << "       |__________||__________|" << endl << endl;
}
//印出公牌
void ShowPublicCard()
{
	string species[] = { "紅心","方塊","梅花","黑桃" };
	string ranks[] = { "Ａ"," ２","３","４","５","６","７","８","９","10","Ｊ","Ｑ","Ｋ" };
	for (int i = 0; i < publicCard.size(); i++)
	{
		switch (publicCard[i].getSpecies())
		{
		case 0:
			gotoxyGame(x + 8 + (12 * i), y + 3); cout << "   ▲▲   ";
			gotoxyGame(x + 8 + (12 * i), y + 4); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 5); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 6); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 7); cout << "    ▉    ";
			break;
		case 1:
			gotoxyGame(x + 8 + (12 * i), y + 3); cout << "    ▉    ";
			gotoxyGame(x + 8 + (12 * i), y + 4); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 5); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 6); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 7); cout << "    ▉    ";
			break;
		case 2:
			gotoxyGame(x + 8 + (12 * i), y + 3); cout << "    ◆    ";
			gotoxyGame(x + 8 + (12 * i), y + 4); cout << "   ◆◆   ";
			gotoxyGame(x + 8 + (12 * i), y + 5); cout << " ◆◆◆◆ ";
			gotoxyGame(x + 8 + (12 * i), y + 6); cout << "  ◆||◆  ";
			gotoxyGame(x + 8 + (12 * i), y + 7); cout << "    ▅    ";
			break;
		case 3:
			gotoxyGame(x + 8 + (12 * i), y + 3); cout << "    ▲    ";
			gotoxyGame(x + 8 + (12 * i), y + 4); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 5); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 6); cout << " ▉ || ▉ ";
			gotoxyGame(x + 8 + (12 * i), y + 7); cout << "    ▅    ";
			break;
		}
		gotoxyGame(x + 8 + (12 * i), y + 2); cout << ranks[publicCard[i].getNumber()];
		gotoxyGame(x + 16 + (12 * i), y + 7); cout << ranks[publicCard[i].getNumber()];
		gotoxyGame(x + 10 + (12 * i), y + 10); cout << species[publicCard[i].getSpecies()] << ranks[publicCard[i].getNumber()];
	}
}
//印出玩家的操作記錄列表
void ShowPlayerOperatinglist()
{
	for (int i = 0; i < player_number; i++)
	{
		if (!player[i].getFold()) 
		{
			gotoxyGame(x + 69, y + 2 + i); cout << "P" << right << setw(2) << player[i].getPlayerNumber() << "     ";
		}
	}
}

//印出上一個玩家的操作記錄
void ShowPlayerOperating(int playerNumber)
{
	static int PreviousplayerNumber = -1;
	if (playerNumber == -1)
	{
		PreviousplayerNumber = -1;
		return;
	}
	if (PreviousplayerNumber == -1)
	{
		gotoxyGame(x + 78, y + 2); cout << "<";
		gotoxyGame(x + 39, y + 23); cout << "彩池：" << right << setw(8) << AllBet << " $  Player " << right << 1;
	}
	else
	{
		gotoxyGame(x + 78, y + 2 + playerNumber); cout << "<";
		gotoxyGame(x + 78, y + 2 + PreviousplayerNumber); cout << " ";
		gotoxyGame(x + 69, y + 2 + PreviousplayerNumber); cout << "P" << right << setw(2) << player[PreviousplayerNumber].getPlayerNumber()<< " ";
		if (player[PreviousplayerNumber].getFold()) 
		{
			cout << "蓋牌";
		}
		else
		{
			switch (player[PreviousplayerNumber].getLastOperation())
			{
			case 1:cout << "加注"; break;
			case 2:cout << "跟注"; break;
			case 3:cout << "過牌"; break;
			case 4:cout << "小盲"; break;
			case 5:cout << "大盲"; break;
			}
		}
		gotoxyGame(x + 64, y + 23); cout << "  ";
		gotoxyGame(x + 39, y + 23); cout << "彩池：" << right << setw(8) << AllBet << " $  Player " << right << player[playerNumber].getPlayerNumber();
	}
	PreviousplayerNumber = playerNumber;
}
//印出手牌
void ShowPlayerCard(int playerNumber)
{
	string species[] = { "紅心","方塊","梅花","黑桃" };
	string ranks[] = { "Ａ","２","３","４","５","６","７","８","９","10","Ｊ","Ｑ","Ｋ" };
	if (player[playerNumber].getBot() == true){return;}
	if (player[playerNumber].getFold()) { return; }

	for (int i = 0; i < 2; i++)
	{
		switch (player[playerNumber].getCardSpecies(i))
		{
		case 0:
			gotoxyGame(x + 8 + (12 * i), y + 14); cout << "   ▲▲   ";
			gotoxyGame(x + 8 + (12 * i), y + 15); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 16); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 17); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 18); cout << "    ▉    ";
			break;
		case 1:
			gotoxyGame(x + 8 + (12 * i), y + 14); cout << "    ▉    ";
			gotoxyGame(x + 8 + (12 * i), y + 15); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 16); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 17); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 18); cout << "    ▉    ";
			break;
		case 2:
			gotoxyGame(x + 8 + (12 * i), y + 14); cout << "    ◆    ";
			gotoxyGame(x + 8 + (12 * i), y + 15); cout << "   ◆◆   ";
			gotoxyGame(x + 8 + (12 * i), y + 16); cout << " ◆◆◆◆ ";
			gotoxyGame(x + 8 + (12 * i), y + 17); cout << "  ◆||◆  ";
			gotoxyGame(x + 8 + (12 * i), y + 18); cout << "    ▅    ";
			break;
		case 3:
			gotoxyGame(x + 8 + (12 * i), y + 14); cout << "    ▲    ";
			gotoxyGame(x + 8 + (12 * i), y + 15); cout << "   ▉▉   ";
			gotoxyGame(x + 8 + (12 * i), y + 16); cout << "  ▉▉▉  ";
			gotoxyGame(x + 8 + (12 * i), y + 17); cout << " ▉ || ▉ ";
			gotoxyGame(x + 8 + (12 * i), y + 18); cout << "    ▅    ";
			break;
		}
		gotoxyGame(x + 8 + (12 * i), y + 13); cout << ranks[player[playerNumber].getCardNumber(i)];
		gotoxyGame(x + 16 + (12 * i), y + 18); cout << ranks[player[playerNumber].getCardNumber(i)];
		gotoxyGame(x + 10 + (12 * i), y + 21); cout << species[player[playerNumber].getCardSpecies(i)] << ranks[player[playerNumber].getCardNumber(i)];
	}
}
//手牌隱藏
void HidePlayerCard()
{
	for (int i = 0; i < 2; i++)
	{

		for (int y1 = 13; y1 < 19; y1++)
		{
			gotoxyGame(x + 8 + (12 * i), y + y1); cout << "          ";
		}
		gotoxyGame(x + 10 + (12 * i), y + 21); cout << "      ";
	}
	for (int y1 = 0; y1 < 9; y1++)
	{
		gotoxyGame(x + 40, y +14 + y1); cout << "　　　　　　　　　　　　　　";
	}
	gotoxyGame(x + 79, y + 24);
}
//最贏
int ShowWinner()
{
	int nowWinnerPlayerNumber = 0;
	int nowWinnerPlayerMaxWinNumber[5] = { 0 };
	int nowWinnerPlayerMaxWinMode = 0;
	for(int j=0;j< player_number;j++)
	{
		if(!player[j].getFold())
		{
			if (nowWinnerPlayerMaxWinMode < player[j].getMaxWinMode())
			{
				nowWinnerPlayerNumber = j ;
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
							nowWinnerPlayerNumber = j;
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
	return nowWinnerPlayerNumber;
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
	int kind[4] = { 0 }, scard[13] = {}; // 4種花色 13個卡號
	int compareNum[5] = {-1,-1,-1,-1,-1};
	Card Cards_2[5]={};

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
		if (*(compareNum + i) == -1)
		{
			*(compareNum + i) = cardNumber;
			return;
		}
	}
}
//加注
bool addBet()
{
	int addBet;
	while(1)
	{
		gotoxyGame(x + 50, y + 15); cout << " +                ";
		gotoxyGame(x + 52, y + 15);
		cin >> addBet;
		if (addBet >= LastBet&& addBet%10==0&& addBet<= LastBet*10)
		{
			LastBet = LastBet+addBet;
			AllBet += LastBet;
			gotoxyGame(x + 53, y + 19); cout << "加注成功 !";
			AllBetExplosionVerification();
			if (AllBetExplosion) { return true; }
			gotoxyGame(x + 39, y + 23); cout << "彩池：" << right << setw(8) << AllBet << " $";
			gotoxyGame(x + 39, y + 15);
			Sleep(1500);
			gotoxyGame(x + 53, y + 19); cout << "          ";
			gotoxyGame(x + 50, y + 15); cout << "                  ";
			gotoxyGame(x + 39, y + 15);
			return true;
		}
		else
		{
			gotoxyGame(x + 53, y + 19); cout << "加注失敗 !";
			gotoxyGame(x + 79, y + 24);
			Sleep(1500);
			gotoxyGame(x + 53, y + 19); cout << "          ";
			gotoxyGame(x + 50, y + 15); cout << "                  ";
			gotoxyGame(x + 38, y + 15); cout << " ";
			gotoxyGame(x + 79, y + 24);
			return false;
		}
	}
}
//盲注加注
bool addBlind()
{
	int addBet;
	while (1)
	{
		gotoxyGame(x + 40, y + 16); cout << " +                ";
		gotoxyGame(x + 42, y + 16);
		cin >> addBet;
		if (addBet % 10 == 0 && addBet <= 100)
		{
			LastBet = LastBet + addBet;
			AllBet += LastBet;
			gotoxyGame(x + 53, y + 19); cout << "盲注成功 !";
			gotoxyGame(x + 39, y + 23); cout << "彩池：" << right << setw(8) << AllBet << " $";
			gotoxyGame(x + 39, y + 15);
			Sleep(1500);
			gotoxyGame(x + 53, y + 19); cout << "          ";
			gotoxyGame(x + 40, y + 16); cout << "                  ";
			gotoxyGame(x + 39, y + 15);
			return true;
		}
		else
		{
			gotoxyGame(x + 53, y + 19); cout << "盲注失敗 !";
			gotoxyGame(x + 79, y + 24);
			Sleep(1500);
			gotoxyGame(x + 53, y + 19); cout << "          ";
			gotoxyGame(x + 40, y + 16); cout << "                  ";
			gotoxyGame(x + 38, y + 15); cout << " ";
			gotoxyGame(x + 79, y + 24);
			return false;
		}
	}
}

//玩家操作
void PlayerOperating(int playerNumber)
{
	static int PreviousplayerNumber = -1;
	if (playerNumber==-1)
	{
		PreviousplayerNumber = -1;
		return;
	}
	gotoxyGame(x + 40, y + 15); cout << "Ｒ　加　注　　";
	gotoxyGame(x + 40, y + 17); cout << "Ｃ　跟　注　　";
	if(PreviousplayerNumber!=-1)
	{
		if (player[PreviousplayerNumber].getLastOperation() != 1 && First_lap ) { gotoxyGame(x + 40, y + 19); cout << "Ｓ　過　牌　　"; }
	}
	gotoxyGame(x + 40, y + 21); cout << "Ｆ　蓋　牌　　";
	gotoxyGame(x + 53, y + 17); cout << LastBet<<" $";
	gotoxyGame(x + 79, y + 24);
	while(1){
		if (player[playerNumber].getFold()){return;}//此玩家已棄牌
		if (player[playerNumber].getBot() == true)
		{
			Sleep(200);
			while(1)
			{
				int num = rand() % 10 + 1;
				if (num==1) 
				{	//加　注
					LastBet = LastBet + LastBet;
					AllBet += LastBet;
					gotoxyGame(x + 38, y + 15); cout << ">";
					for (int i = 0; i < player_number; i++)
					{
						if (player[i].getEnd() == true)
						{
							player[i].setEnd(false);
						}
					}
					player[playerNumber].setEnd(true);
					player[playerNumber].setLastOperation(1);
					if (AllBetExplosion) { return; }
					Sleep(800);
					gotoxyGame(x + 38, y + 15); cout << " ";
					PreviousplayerNumber = playerNumber;
					return;
				}
				if (num == 2 || num == 3|| num == 4 || num == 5 || num == 6) 
				{	//跟　注
					gotoxyGame(x + 38, y + 17); cout << ">";
					AllBet += LastBet;
					gotoxyGame(x + 39, y + 23); cout << "彩池：" << right << setw(8) << AllBet << " $";
					gotoxyGame(x + 39, y + 17);
					player[playerNumber].setLastOperation(2);
					AllBetExplosionVerification();
					if (AllBetExplosion) { return; }
					Sleep(800);
					gotoxyGame(x + 38, y + 17); cout << " ";
					PreviousplayerNumber = playerNumber;
					return;
				}
				if (num == 7 || num == 8 || num == 9)
				{	//過　牌
					if (PreviousplayerNumber != -1)
					{
						if (player[PreviousplayerNumber].getLastOperation() != 1 && First_lap)
						{
							gotoxyGame(x + 38, y + 19); cout << ">";
							player[playerNumber].setLastOperation(3);
							Sleep(800);
							gotoxyGame(x + 38, y + 19); cout << " ";
							PreviousplayerNumber = playerNumber;
							return;
						}
					}
					else
					{
						gotoxyGame(x + 38, y + 17); cout << ">";
						AllBet += LastBet;
						gotoxyGame(x + 39, y + 23); cout << "彩池：" << right << setw(8) << AllBet << " $";
						gotoxyGame(x + 39, y + 17);
						player[playerNumber].setLastOperation(2);
						AllBetExplosionVerification();
						if (AllBetExplosion) { return; }
						Sleep(800);
						gotoxyGame(x + 38, y + 17); cout << " ";
						PreviousplayerNumber = playerNumber;
						return;
					}
				}
				if (num == 10)
				{	//蓋　牌
					gotoxyGame(x + 38, y + 21); cout << ">";
					player[playerNumber].Folding();
					Sleep(800);
					gotoxyGame(x + 38, y + 21); cout << " ";
					PreviousplayerNumber = playerNumber;
					return;
				}
			}
		}
		switch (_getch())
		{
		case 114://加　注
			gotoxyGame(x + 38, y + 15); cout << ">";
			if (addBet())
			{
				for (int i = 0; i < player_number; i++)
				{
					if (player[i].getEnd() == true)
					{
						player[i].setEnd(false);
					}
				}
				player[playerNumber].setEnd(true);
				player[playerNumber].setLastOperation(1);
				if (AllBetExplosion) { return; }
				Sleep(2000); gotoxyGame(x + 38, y + 15); cout << " ";
				PreviousplayerNumber = playerNumber;
				return;
			}
			break;
		case 99://跟　注
			gotoxyGame(x + 38, y + 17); cout << ">";
			AllBet += LastBet;
			gotoxyGame(x + 39, y + 23); cout << "彩池：" << right << setw(8) << AllBet << " $";
			gotoxyGame(x + 39, y + 17);
			player[playerNumber].setLastOperation(2);
			AllBetExplosionVerification();
			if (AllBetExplosion) { return; }
			Sleep(2000); gotoxyGame(x + 38, y + 17); cout << " "; 
			PreviousplayerNumber = playerNumber;
			return;
			break;
		case 115://過　牌
			if (PreviousplayerNumber != -1)
			{
				if (player[PreviousplayerNumber].getLastOperation() != 1 && First_lap) 
				{
					gotoxyGame(x + 38, y + 19); cout << ">";
					player[playerNumber].setLastOperation(3);
					Sleep(2000); gotoxyGame(x + 38, y + 19); cout << " ";
					PreviousplayerNumber = playerNumber;
					return;
				}
			}
			break;
		case 102://蓋　牌
			gotoxyGame(x + 38, y + 21); cout << ">";
			player[playerNumber].Folding();
			Sleep(2000); gotoxyGame(x + 38, y + 21); cout << " "; 
			PreviousplayerNumber = playerNumber;
			return;
			break;
		}
	}
}
//大小盲注
void PlayerBlind(int playerNumber,int Blind)
{
	switch (Blind)
	{
	case 1:
		gotoxyGame(x + 40, y + 15); cout << "Ｂ　小　盲　注";
		gotoxyGame(x + 79, y + 24);
		break;
	case 2:
		gotoxyGame(x + 40, y + 15); cout << "Ｂ　大　盲　注";
		gotoxyGame(x + 58, y + 15); cout << LastBet * 2 << " $";
		gotoxyGame(x + 79, y + 24);
		break;
	}
	while (1) {
		if (player[playerNumber].getBot() == true)
		{
			if (Blind == 1)
			{
				gotoxyGame(x + 38, y + 15); cout << ">";
				LastBet = LastBet + 20;
				AllBet += LastBet;
				player[playerNumber].setLastOperation(4);
				Sleep(800);
				gotoxyGame(x + 38, y + 15); cout << " ";
				Blind++;
				return;
			}
			else//大　盲　注
			{
				gotoxyGame(x + 38, y + 15); cout << ">";
				player[playerNumber].setLastOperation(5);
				LastBet *= 2;
				AllBet += LastBet;
				Sleep(800);
				gotoxyGame(x + 38, y + 15); cout << " ";
				Blind++;
				return;
			}
		}
		if(_getch()== 98)
		{
			if (Blind == 1)
			{
				gotoxyGame(x + 38, y + 15); cout << ">";
				if (addBlind())
				{
					player[playerNumber].setLastOperation(4);
					Sleep(2000); gotoxyGame(x + 38, y + 15); cout << " ";
					Blind++;
					return;
				}
			}
			else//大　盲　注
			{
				gotoxyGame(x + 38, y + 15); cout << ">";
				player[playerNumber].setLastOperation(5);
				LastBet *= 2;
				AllBet += LastBet;
				Sleep(2000); gotoxyGame(x + 38, y + 15); cout << " ";
				Blind++;
				return;
			}
		}
	}
}
//驗證
void Verification(int playerNumber)
{
	if (player[playerNumber].getBot() == true) { return; }
	if (player[playerNumber].getFold()) { return; }
	srand(time(0)); //取時間
	int verificationNumber = (rand()%36)+1;
	if(verificationNumber>=1 && verificationNumber <= 10)
	{
		verificationNumber += 47;
	}
	else {
		if (verificationNumber >= 11 && verificationNumber <= 36)
		{
			verificationNumber += 86;
		}
	}
	gotoxyGame(x + 10, y + 16); cout << "驗證:";
	gotoxyGame(x + 24, y + 16); cout << char(verificationNumber);
	gotoxyGame(x + 79, y + 24);
	while (1)
	{
		if (_getch()== verificationNumber)
		{
			gotoxyGame(x + 10, y + 16); cout << "     ";
			gotoxyGame(x + 24, y + 16); cout << " ";
			return;
		}
	}
}
//檢查是否加注
bool CheckAddBet()
{
	for (int i = 0; i < player_number; i++)
	{
		if (player[i].getEnd() == true)
		{
			return true;
		}
	}
	return false;
}
//洗白加注者註記&上一回合的玩家所有操作
void Revert_CheckAddBet_and_PlayerOperating()
{
	for (int i = 0; i < player_number; i++)
	{
		player[i].setEnd(false);
		player[i].setLastOperation(-1);
	}
}
//
void ShowEndingPlayerResult()
{
	int winner = ShowWinner();
	string suits[] = { "愛心","方塊","梅花","黑桃" };
	string ranks[] = { "Ａ","２","３","４","５","６","７","８","９","10","Ｊ","Ｑ","Ｋ" };
	int playerNumber = 0;
	gotoxyGame(x + 24, y + 4); cout << "玩 家 最 大 牌 型";
	for (int i = 0; i < 25; i++)
	{
		gotoxyGame(x + 66, y + i); cout << "|";
	}
	gotoxyGame(x + 67, y + 16); cout << "＿＿＿＿＿＿";
	gotoxyGame(x + 70, y + 1); cout << "最佳";
	gotoxyGame(x + 70, y + 2); cout << "組合:";
	switch (player[winner].getMaxWinMode())
	{
	case 10:gotoxyGame(x + 68, y + 4);  cout << "皇家同花順"; break;
	case 9:gotoxyGame(x + 70, y + 4); cout << "同花順"; break;
	case 8:gotoxyGame(x + 71, y + 4); cout << "四條"; break;
	case 7:gotoxyGame(x + 71, y + 4); cout << "葫蘆"; break;
	case 6:gotoxyGame(x + 71, y + 4); cout << "同花"; break;
	case 5:gotoxyGame(x + 71, y + 4); cout << "順子"; break;
	case 4:gotoxyGame(x + 71, y + 4); cout << "三條"; break;
	case 3:gotoxyGame(x + 71, y + 4); cout << "兩對"; break;
	case 2:gotoxyGame(x + 71, y + 4); cout << "一對"; break;
	case 1:gotoxyGame(x + 71, y + 4); cout << "散牌"; break;
	}
	for (int i = 0; i < 5; i++)
	{
		gotoxyGame(x + 70, y + 6+i);
		cout << suits[player[winner].getMaxWinCardsSpecies(i)] << ranks[player[winner].getMaxWinCardsNumber(i)];
	}
	gotoxyGame(x + 71, y + 12); cout << "彩池:";
	gotoxyGame(x + 68, y + 14); cout <<right<<setw(8)<< AllBet <<" $";
	gotoxyGame(x + 70, y + 24); cout << "Esc 離開";

	while (1)
	{
		gotoxyGame(x + 71, y + 18); cout << "    ";
		if (player[playerNumber].getFold())
		{
			gotoxyGame(x + 71, y + 18); cout << "棄牌";
		}
		else
		{
			if (player[playerNumber].getMaxWinMode()== player[winner].getMaxWinMode())
			{
				if (player[playerNumber].getMaxWinCardsNumber(0) == player[winner].getMaxWinCardsNumber(0))
				{
					if (player[playerNumber].getMaxWinCardsNumber(1) == player[winner].getMaxWinCardsNumber(1))
					{
						if (player[playerNumber].getMaxWinCardsNumber(2) == player[winner].getMaxWinCardsNumber(2))
						{
							if (player[playerNumber].getMaxWinCardsNumber(3) == player[winner].getMaxWinCardsNumber(3))
							{
								if (player[playerNumber].getMaxWinCardsNumber(4) == player[winner].getMaxWinCardsNumber(4))
								{
									gotoxyGame(x + 71, y + 18); cout << "贏家";
								}
							}
						}
					}
				}
			}
		}

		if (playerNumber == 0) { gotoxyGame(x + 69, y + 22); cout << " "; }
		else { gotoxyGame(x + 69, y + 22); cout << "<"; }
		if (playerNumber == player_number - 1) { gotoxyGame(x + 76, y + 22); cout << " "; }
		else { gotoxyGame(x + 76, y + 22); cout << ">"; }

		gotoxyGame(x + 75, y + 20); cout << "  ";
		gotoxyGame(x + 68, y + 20); cout << "Player " << right << setw(2) << player[playerNumber].getPlayerNumber();

		gotoxyGame(x + 27, y + 8);  cout << "          ";
		switch (player[playerNumber].getMaxWinMode())
		{
		case 10:gotoxyGame(x + 27, y+7);  cout << "皇家同花順"; break;
		case 9:gotoxyGame(x + 29, y + 7); cout << "同花順"; break;
		case 8:gotoxyGame(x + 30, y + 7); cout << "四條"; break;
		case 7:gotoxyGame(x + 30, y + 7); cout << "葫蘆"; break;
		case 6:gotoxyGame(x + 30, y + 7); cout << "同花"; break;
		case 5:gotoxyGame(x + 30, y + 7); cout << "順子"; break;
		case 4:gotoxyGame(x + 30, y + 7); cout << "三條"; break;
		case 3:gotoxyGame(x + 30, y + 7); cout << "兩對"; break;
		case 2:gotoxyGame(x + 30, y + 7); cout << "一對"; break;
		case 1:gotoxyGame(x + 30, y + 7); cout << "散牌"; break;
		}
		gotoxyGame(x, y + 9);
		cout << "     __________  __________  __________  __________  __________ " << endl;
		cout << "   |          ||          ||          ||          ||          |" << endl;
		cout << "   |          ||          ||          ||          ||          |" << endl;
		cout << "   |          ||          ||          ||          ||          |" << endl;
		cout << "   |          ||          ||          ||          ||          |" << endl;
		cout << "   |          ||          ||          ||          ||          |" << endl;
		cout << "   |          ||          ||          ||          ||          |" << endl;
		cout << "   |__________||__________||__________||__________||__________|" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			switch (player[playerNumber].getMaxWinCardsSpecies(i))
			{
			case 0:
				gotoxyGame(x + 4 + (12 * i), y + 11); cout << "   ▲▲   ";
				gotoxyGame(x + 4 + (12 * i), y + 12); cout << "  ▉▉▉  ";
				gotoxyGame(x + 4 + (12 * i), y + 13); cout << "  ▉▉▉  ";
				gotoxyGame(x + 4 + (12 * i), y + 14); cout << "   ▉▉   ";
				gotoxyGame(x + 4 + (12 * i), y + 15); cout << "    ▉    ";
				break;
			case 1:
				gotoxyGame(x + 4 + (12 * i), y + 11); cout << "    ▉    ";
				gotoxyGame(x + 4 + (12 * i), y + 12); cout << "   ▉▉   ";
				gotoxyGame(x + 4 + (12 * i), y + 13); cout << "  ▉▉▉  ";
				gotoxyGame(x + 4 + (12 * i), y + 14); cout << "   ▉▉   ";
				gotoxyGame(x + 4 + (12 * i), y + 15); cout << "    ▉    ";
				break;
			case 2:
				gotoxyGame(x + 4 + (12 * i), y + 11); cout << "    ◆    ";
				gotoxyGame(x + 4 + (12 * i), y + 12); cout << "   ◆◆   ";
				gotoxyGame(x + 4 + (12 * i), y + 13); cout << " ◆◆◆◆ ";
				gotoxyGame(x + 4 + (12 * i), y + 14); cout << "  ◆||◆  ";
				gotoxyGame(x + 4 + (12 * i), y + 15); cout << "    ▅    ";
				break;
			case 3:
				gotoxyGame(x + 4 + (12 * i), y + 11); cout << "    ▲    ";
				gotoxyGame(x + 4 + (12 * i), y + 12); cout << "   ▉▉   ";
				gotoxyGame(x + 4 + (12 * i), y + 13); cout << "  ▉▉▉  ";
				gotoxyGame(x + 4 + (12 * i), y + 14); cout << " ▉ || ▉ ";
				gotoxyGame(x + 4 + (12 * i), y + 15); cout << "    ▅    ";
				break;
			}
			gotoxyGame(x + 4 + (12 * i), y + 10); cout << ranks[player[playerNumber].getMaxWinCardsNumber(i)];
			gotoxyGame(x + 12 + (12 * i), y + 15); cout << ranks[player[playerNumber].getMaxWinCardsNumber(i)];
			gotoxyGame(x+6+(12*i), y + 18);
			cout << suits[player[playerNumber].getMaxWinCardsSpecies(i)]<< ranks[player[playerNumber].getMaxWinCardsNumber(i)];
		}
		gotoxyGame(x+79, y+24);
		switch(_getch())
		{
		case 75:
			if (playerNumber > 0) { playerNumber--; }//left
			break;
		case 77:
			if (playerNumber < player_number-1) { playerNumber++; }//right
			break;
		case 27://esc
			return;
			break;
		}
	}
}
//檢查牌局棄牌
bool CheckFold()
{
	int noFolder = 0;
	for (int i = 0; i < player_number; i++)
	{
		if(player[i].getFold()==false)
		{
			noFolder++;
		}
		if (noFolder > 1)
		{
			return false;
		}
	}
	return true;
}
//
int CheckAllFoldGetPlayerNumber()
{
	for (int i = 0; i < player_number; i++)
	{
		if (player[i].getFold() == false)
		{
			return player[i].getPlayerNumber();
		}
	}
}
//棄牌結束
void AllFoldGameEnd()
{
	system("cls");
	gotoxyGame(x + 31, y + 5);  cout << "～ 本局遊戲結束 ～";
	gotoxyGame(x + 30, y + 8);  cout << "( 場上玩家全數蓋牌 )";
	gotoxyGame(x + 28, y + 11);  cout << "彩池由  Player "<<setw(2)<<right<< CheckAllFoldGetPlayerNumber() <<"   全拿";
	gotoxyGame(x + 32, y + 13);  cout << "彩池: "<< setw(8) << right << AllBet <<" $";
	gotoxyGame(x + 31, y + 16);  cout << "～ 本局遊戲結束 ～";
	gotoxyGame(x + 32, y + 20);  cout << "Ｏ 任意鍵離開 Ｏ";
	gotoxyGame(x + 79, y + 24);
	_getch();
	system("cls");
}

//遊戲函式
void MultiplayerGame()
{
	PlaySound(L"Music\\Jazz_TexasHold'Em_Game.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	GameReturn();
	if (PlayerNumber()==false) { return; }
	int Place_a_bet = 0;
	int winPlayer = 0;
	int Maxwin = 0;
	/*初始遊戲*/
	ShufflePoker(); //洗牌function
	GameInterface(); // 初始遊戲介面
	Revert_CheckAddBet_and_PlayerOperating();
	/*初始遊戲*/
	ShowPlayerOperatinglist();
	gotoxyGame(x + 79, y + 24);
	//盲注time start
	gotoxyGame(x + 71, y); cout << "盲   注";
	for (int i = 0; i < 2; i++)
	{
		ShowPlayerOperating(i);
		PlayerBlind(i,i+1);
		HidePlayerCard();
	}
	inputPlayerCard();//發手牌
	//盲注time over
	/*第一回合 start*/
	Around++; gotoxyGame(x + 71, y); cout << "第 " << Around << " 局";
	//發手牌後由第3位玩家開始下注  (只有兩位玩家會跳過此步)
	for(bool around_cards= true; around_cards== true;)
	{
		if (CheckFold()) { break; }
		if (AllBetExplosion) { break; }
		for (int i = 0; i < player_number; i++)
		{
			if (CheckFold()) { break; }
			if (AllBetExplosion) { break; }
			if (ferst && player_number>2) { ferst = false; i = 2; }
			if (player_number == 2) { break; }
			if (player[i].getEnd() == true)
			{
				player[i].setEnd(false);
				around_cards = false;
				break;
			}
			else
			{
				ShowPlayerOperating(i);
				Verification(i);
				ShowPlayerCard(i);
				PlayerOperating(i);
				HidePlayerCard();
			}
		}
		if (!CheckAddBet())
		{
			around_cards = false;
		}
	}
	First_lap = true;
	/*第一回合 end*/
	/*第二~四回合 start*/
	for(int tep=0;tep<3;)
	{
		if (CheckFold()) { break; }
		if (AllBetExplosion) { break; }
		Revert_CheckAddBet_and_PlayerOperating();
		ShowPlayerOperatinglist();
		bool around_cards=true;
		if (tep == 0)
		{
			lostCard(); inputPublicCard(); inputPublicCard(); inputPublicCard();//棄一牌 發公牌*3
			ShowPublicCard();//開公牌
		}
		else
		{
			lostCard(); inputPublicCard();//棄一牌 發公牌
			ShowPublicCard();//開公牌
		}
		Around++;	gotoxyGame(x + 71, y); cout << "第 " << Around << " 局";

		while (around_cards)
		{
			if (CheckFold()) { break; }
			if (AllBetExplosion) { break; }
			for (int i = 0; i < player_number; i++)
			{
				if (CheckFold()) { break; }
				if (AllBetExplosion) { break; }
				if (player[i].getEnd() == true)
				{
					player[i].setEnd(false);
					around_cards = false;
					break;
				}
				else
				{
						ShowPlayerOperating(i);
						Verification(i);
						ShowPlayerCard(i);
						PlayerOperating(i);
						HidePlayerCard();
				}
			}
			if (!CheckAddBet())
			{
				around_cards = false;
			}
		}
		tep++;
	}
	/*第二~四回合 end*/
	system("cls"); gotoxyGame(x, y);
	/*比輸贏*/
	Around++;
	for (int j = 0; j < player_number; j++)
	{
		if (CheckFold()) { break; }
		if (AllBetExplosion) { break; }
		Public_Player_combination(j);
	}

	if (CheckFold()) 
	{
		AllFoldGameEnd();
		system("cls"); gotoxyGame(x, y);
		return;
	}
	if (AllBetExplosion) 
	{
		AllBetExplosionEasterEggs();
	}
	else 
	{ 
		ShowEndingPlayerResult();
	}
	system("cls"); gotoxyGame(x, y);
	/*比輸贏*/
}