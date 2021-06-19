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

#include <stdio.h>
#include <windows.h>

void Window_Adjustment()
{
	SMALL_RECT rect;
	COORD coord;
	coord.X = 80; // Defining our X and
	coord.Y = 25;  // Y size for buffer.

	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1; // height for window
	rect.Right = coord.X - 1;  // width for window

	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
	SetConsoleScreenBufferSize(hwnd, coord);       // set buffer size
	SetConsoleWindowInfo(hwnd, TRUE, &rect);       // set window size

}

int main()
{
	Window_Adjustment();
	Title();
	while (1)
	{
		PlaySound(L"Music\\MainScreen_JazzSong.WAV", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
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
