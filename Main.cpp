#include <windows.h>
#include <vector>
#include <conio.h>

extern void Title(); //片頭 (Title.cpp)
extern int MainScreen();//主畫面 (Title.cpp)
extern void Enactment();//設定
extern void MultiplayerGame(); //多人遊戲 (MultiplayerGame.cpp)

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

int main()
{
	PlaySound(L"Music\\MainScreen_JazzSong.WAV", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (1)
	{
		switch (MainScreen())
		{
		case 1:break;//單 人 遊 戲
		case 2:
			MultiplayerGame();
			PlaySound(L"", NULL, NULL);
			break;//多 人 遊 戲
		case 3:break;//設       置
		case 4: return 0; break;//離 開 遊 戲
		}
	}
}
