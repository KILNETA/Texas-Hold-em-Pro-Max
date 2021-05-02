#ifndef Title_CPP
#define Title_CPP

#include<iostream>
#include<iomanip>
#include <windows.h>

#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

//移動 輸入處
void gotoxy(double x, double y)
{	// the type is double, so objects can move less than 1 unit 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; // start from 0
	dwPos.Y = y; // start from 0
	SetConsoleCursorPosition(hCon, dwPos);
}

//片頭 //漸逝
void Title_lost(int x, int y)
{
	gotoxy(x - 39, y + 17); cout << "                                                                                                        ";
	Sleep(150); gotoxy(x - 39, y + 10); cout << "                                                                                                       ";
	Sleep(150); gotoxy(x - 39, y + 15); cout << "                                                                                                       ";
	Sleep(150); gotoxy(x - 39, y + 13); cout << "                                                                                                       ";
	Sleep(150); gotoxy(x - 39, y + 9); cout << "                                                                                                       ";
	Sleep(150); gotoxy(x - 39, y + 16); cout << "                                                                                                       ";
	Sleep(150); gotoxy(x - 39, y + 12); cout << "                                                                                                        ";
	Sleep(150); gotoxy(x - 39, y + 18); cout << "                                                                                                       ";
	Sleep(150); system("cls");
}

//片頭
void Title()
{
	PlaySound(L"Music\\GameTitel_PornHub&GTA.WAV", NULL, SND_FILENAME | SND_ASYNC);
	int x = 39, y = 0;
	//●ＲＥＣ
	{
		gotoxy(x - 4, y + 12); cout << "●ＲＥＣ"; Sleep(120);
		gotoxy(x - 4, y + 12); cout << "○"; Sleep(120);
		gotoxy(x - 4, y + 12); cout << "●"; Sleep(120); system("cls"); }
	//筆電
	{
		gotoxy(x - 11, y + 9); cout << " ____________________ ";
		gotoxy(x - 11, y + 10); cout << "|                    |";
		gotoxy(x - 11, y + 11); cout << "|                    |";
		gotoxy(x - 11, y + 12); cout << "|                    |";
		gotoxy(x - 11, y + 13); cout << "|                    |";
		gotoxy(x - 11, y + 14); cout << "|                    |";
		gotoxy(x - 11, y + 15); cout << " ____________________ ";
		gotoxy(x - 13, y + 16); cout << " /______________________\\";
	}
	//跑球
	{
		gotoxy(x - 4, y + 14); cout << "   ▁";
		Sleep(120);
		gotoxy(x - 4, y + 13); cout << "   ▁";
		gotoxy(x - 4, y + 14); cout << " /    \\";
		Sleep(100);
		gotoxy(x - 4, y + 12); cout << "   ▁";
		gotoxy(x - 4, y + 13); cout << " /    \\";
		gotoxy(x - 4, y + 14); cout << "|  ▲  |";
		Sleep(100);
		gotoxy(x - 4, y + 11); cout << "   ▁";
		gotoxy(x - 4, y + 12); cout << " /    \\";
		gotoxy(x - 4, y + 13); cout << "|  ▲  |";
		gotoxy(x - 4, y + 14); cout << " \\ ▁ / ";
		Sleep(100);
		gotoxy(x - 4, y + 10); cout << "   ▁";
		gotoxy(x - 4, y + 11); cout << " /    \\";
		gotoxy(x - 4, y + 12); cout << "|  ▲  |";
		gotoxy(x - 4, y + 13); cout << " \\ ▁ / ";
		gotoxy(x - 4, y + 14); cout << "       ";
		Sleep(100);
		system("cls");
		gotoxy(x - 4, y + 10); cout << "   ▁";
		gotoxy(x - 4, y + 11); cout << " /    \\";
		gotoxy(x - 4, y + 12); cout << "|  ▲  |";
		gotoxy(x - 4, y + 13); cout << " \\ ▁ / ";
		Sleep(100);
		system("cls");
		gotoxy(x - 4, y + 10); cout << "   ▁";
		gotoxy(x - 4, y + 11); cout << " /    \\";
		gotoxy(x - 4, y + 12); cout << "|  |>  |";
		gotoxy(x - 4, y + 13); cout << " \\ ▁ / ";
		gotoxy(x - 4, y + 14); cout << "       ";
		Sleep(65);
		gotoxy(x + 8, y + 19); cout << "▲";
		Sleep(65);
		gotoxy(x + 8, y + 19); cout << " ";
		gotoxy(x + 7, y + 18); cout << "▲";
		Sleep(65);
		gotoxy(x + 7, y + 18); cout << " ";
		gotoxy(x + 7, y + 17); cout << "▲";
		Sleep(65);
		gotoxy(x + 7, y + 17); cout << " ";
		gotoxy(x + 6, y + 16); cout << "▲";
		Sleep(65);
		gotoxy(x + 6, y + 16); cout << " ";
		gotoxy(x + 6, y + 15); cout << "▲";
		Sleep(65);
		gotoxy(x + 6, y + 15); cout << " ";
		gotoxy(x + 5, y + 14); cout << "▲";
		Sleep(65);
		gotoxy(x + 6, y + 14); cout << " ";
		gotoxy(x + 4, y + 13); cout << "▲";
		Sleep(100); system("cls");
	}
	//pornhub LOGO
	{gotoxy(x - 9, y + 12); cout << "Ｐ";
	Sleep(50); gotoxy(x - 7, y + 12); cout << "ｏ";
	Sleep(50); gotoxy(x - 5, y + 12); cout << "ｒ";
	Sleep(50); gotoxy(x - 3, y + 12); cout << "ｎ";
	Sleep(50); gotoxy(x - 1, y + 12); cout << "｜";
	Sleep(50); gotoxy(x + 1, y + 12); cout << "ｈ";
	gotoxy(x + 1, y + 11); cout << "－";
	gotoxy(x + 1, y + 13); cout << "－";
	Sleep(50); gotoxy(x + 3, y + 12); cout << "ｕ";
	gotoxy(x + 3, y + 11); cout << "－";
	gotoxy(x + 3, y + 13); cout << "－";
	Sleep(50); gotoxy(x + 5, y + 12); cout << "ｂ";
	gotoxy(x + 5, y + 11); cout << "－";
	gotoxy(x + 5, y + 13); cout << "－";
	Sleep(50); gotoxy(x + 7, y + 12); cout << "｜"; }
	// LOGO
	{Sleep(50); system("cls");
	gotoxy(x - 11, y + 8); cout << "  __________   ▁";
	gotoxy(x - 11, y + 9); cout << "||          |/    \\";
	gotoxy(x - 11, y + 10); cout << "|| Texas    |  20 $|\\";
	gotoxy(x - 11, y + 11); cout << "||    hold  |\\ ▁ / $|";
	gotoxy(x - 11, y + 12); cout << "||      'em |　 |▁ /";
	gotoxy(x - 11, y + 13); cout << "||          |   |";
	gotoxy(x - 11, y + 14); cout << "|| Game     ▍  |";
	gotoxy(x - 11, y + 15); cout << "||__________▉  |";
	gotoxy(x - 11, y + 16); cout << "     |   ▉▉   |";
	gotoxy(x - 11, y + 17); cout << "     |    ▉  Ａ|";
	gotoxy(x - 11, y + 18); cout << "     |_________ |";
	Sleep(3400); Title_lost(x, y); }
	//1次
	{Sleep(300);
	gotoxy(x - 17, y + 8); cout << " __________ ";
	gotoxy(x - 17, y + 9); cout << "|Ａ        |";
	gotoxy(x - 17, y + 10); cout << "|   ▲▲   |";
	gotoxy(x - 17, y + 11); cout << "|  ▉▉▉  |";
	gotoxy(x - 17, y + 12); cout << "|  ▉▉▉  |";
	gotoxy(x - 17, y + 13); cout << "|   ▉▉   |";
	gotoxy(x - 17, y + 14); cout << "|    ▉  Ａ|";
	gotoxy(x - 17, y + 15); cout << "|__________|";
	Sleep(300);
	gotoxy(x - 27, y + 5); cout << "  ▁▁";
	gotoxy(x - 27, y + 6); cout << " //    \\";
	gotoxy(x - 27, y + 7); cout << "|| 20 $ |";
	gotoxy(x - 27, y + 8); cout << " \\\\ ▁ /";
	Sleep(300);
	gotoxy(x - 13, y + 16); cout << "  ▁▁";
	gotoxy(x - 13, y + 17); cout << " /    \\";
	gotoxy(x - 13, y + 18); cout << "| 20 $ |";
	gotoxy(x - 13, y + 19); cout << " \\ ▁ /";
	Sleep(300);
	gotoxy(x - 29, y + 13); cout << " __________";
	gotoxy(x - 29, y + 14); cout << "|◆  ◆  ◆";
	gotoxy(x - 29, y + 15); cout << "|  ◆  ◆  ";
	gotoxy(x - 29, y + 16); cout << "|◆  ◆  ◆  ◆|";
	gotoxy(x - 29, y + 17); cout << "|  ◆  ◆  ◆  |";
	gotoxy(x - 29, y + 18); cout << "|◆__◆__◆__◆|";
	Sleep(300);
	gotoxy(x, y + 8); cout << "Ｐｒｏｄｕｃｅｒ＿＿＿";
	gotoxy(x + 4, y + 11); cout << "＠TREASURE1112";
	gotoxy(x + 4, y + 13); cout << "＠KILNETA";
	gotoxy(x + 4, y + 15); cout << "＠a9210183";
	Sleep(2200); Title_lost(x, y); }
	//2次
	{Sleep(300);
	gotoxy(x - 23, y + 10); cout << "     ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁";
	gotoxy(x - 23, y + 11); cout << "   |"; gotoxy(x + 21, y + 11); cout << "|";
	gotoxy(x - 23, y + 12); cout << "  |"; gotoxy(x + 21, y + 12); cout << " |";
	gotoxy(x - 23, y + 13); cout << " |"; gotoxy(x + 21, y + 13); cout << "  |";
	gotoxy(x - 23, y + 14); cout << "|"; gotoxy(x + 21, y + 14); cout << "   |";
	gotoxy(x - 23, y + 15); cout << "|"; gotoxy(x + 21, y + 15); cout << "   |";
	gotoxy(x - 23, y + 16); cout << "|"; gotoxy(x + 21, y + 16); cout << "   |";
	gotoxy(x - 23, y + 17); cout << " |"; gotoxy(x + 21, y + 17); cout << "  |";
	gotoxy(x - 23, y + 18); cout << "  |"; gotoxy(x + 21, y + 18); cout << " |";
	gotoxy(x - 23, y + 19); cout << "   | ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁ |";
	Sleep(300);
	gotoxy(x + 15, y + 12); cout << "◆";
	gotoxy(x + 15, y + 13); cout << " ◆ ◆";
	gotoxy(x + 15, y + 14); cout << " ◆  ◆";
	gotoxy(x + 15, y + 15); cout << "   ◆";
	Sleep(300);
	gotoxy(x - 15, y + 11); cout << "  ▉ ▉";
	gotoxy(x - 15, y + 12); cout << "▉ ▉";
	gotoxy(x - 10, y + 14); cout << "口 口 口 口 口";
	gotoxy(x - 19, y + 17); cout << " ▉";
	gotoxy(x - 19, y + 18); cout << "▉ ▉";
	Sleep(300);
	gotoxy(x - 7, y + 17); cout << "◆◆             ▉";
	gotoxy(x - 7, y + 18); cout << " ◆             ▉";
	Sleep(300);
	gotoxy(x + 3, y + 8); cout << "Ｐｒｏｄｕｃｅｒ＿＿＿";
	gotoxy(x - 19, y + 22); cout << "＠KILNETA";
	Sleep(2200); Title_lost(x, y); }
	//3次
	{Sleep(300);
	gotoxy(x + 5, y + 21); cout << "Ｌａｓ Ｖｅｇａｓ";
	Sleep(300);
	gotoxy(x + 1, y + 8); cout << "▁|▁▁▁▁|▁";
	gotoxy(x + 1, y + 9); cout << "|▉▉▉▉▉▉|";
	gotoxy(x + 1, y + 10); cout << "|▉▉▉▉▉▉|";
	gotoxy(x + 1, y + 11); cout << "|▉▉▉▉▉▉|";
	gotoxy(x + 1, y + 12); cout << "|▉▉▉▉▉▉|";
	gotoxy(x + 1, y + 13); cout << "|▉▉▉▉▉－";
	gotoxy(x + 1, y + 14); cout << "|▉▉▉▉－";
	gotoxy(x + 1, y + 15); cout << "|▉▉－－";
	gotoxy(x + 1, y + 16); cout << "|－－   |";
	gotoxy(x + 1, y + 17); cout << "| ◆ ◆ |";
	gotoxy(x + 1, y + 18); cout << "| ◆ ◆ |";
	gotoxy(x + 1, y + 19); cout << "| ◆ ◆ |";
	gotoxy(x + 1, y + 20); cout << "|";
	gotoxy(x + 1, y + 21); cout << "|";
	gotoxy(x + 1, y + 22); cout << "|▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁|";
	Sleep(300);
	gotoxy(x + 15, y + 11); cout << "      ▁▁";
	gotoxy(x + 15, y + 12); cout << "▁▁▁|  |▁▁▁";
	gotoxy(x + 14, y + 13); cout << "                |";
	gotoxy(x + 14, y + 14); cout << "口 口 口 口 口  |";
	gotoxy(x + 14, y + 15); cout << "                |";
	gotoxy(x + 1, y + 16); cout << "|－－   | 口 口 口 口 口 口  |";
	gotoxy(x + 1, y + 17); cout << "| ◆ ◆ |                    |";
	gotoxy(x + 1, y + 18); cout << "| ◆ ◆ | 口 口 口 口 口 口   |";
	gotoxy(x + 1, y + 19); cout << "| ◆ ◆ |                      |";
	gotoxy(x + 33, y + 20); cout << "|";
	gotoxy(x + 34, y + 21); cout << "|";
	Sleep(300);
	gotoxy(x + 31, y + 14); cout << "▁▁▁";
	gotoxy(x + 31, y + 15); cout << " ◆◆|";
	gotoxy(x + 31, y + 16); cout << " ◆◆|";
	gotoxy(x + 31, y + 17); cout << " ◆◆|";
	gotoxy(x + 32, y + 18); cout << "◆◆|";
	gotoxy(x + 33, y + 19); cout << " ◆|";
	gotoxy(x + 34, y + 20); cout << "◆|";
	gotoxy(x + 35, y + 21); cout << " |";
	Sleep(300);
	gotoxy(x - 23, y + 11); cout << "Ｐｒｏｄｕｃｅｒ＿＿＿";
	gotoxy(x - 21, y + 15); cout << "＠TREASURE1112";
	gotoxy(x - 21, y + 17); cout << "＠KILNETA";
	gotoxy(x - 21, y + 19); cout << "＠a9210183";
	Sleep(2200); Title_lost(x, y); }
	//4次
	{
		Sleep(300);
		gotoxy(x - 25, y + 7); cout << " __________ ";
		gotoxy(x - 25, y + 8); cout << "|Ａ        |";
		gotoxy(x - 25, y + 9); cout << "|   ▲▲   |";
		gotoxy(x - 25, y + 10); cout << "|  ▉▉▉  |";
		gotoxy(x - 25, y + 11); cout << "|  ▉▉▉  |";
		gotoxy(x - 25, y + 12); cout << "|   ▉▉   |";
		gotoxy(x - 25, y + 13); cout << "|    ▉  Ａ|";
		gotoxy(x - 25, y + 14); cout << "|__________|";
		Sleep(300);
		gotoxy(x - 13, y + 8); cout << "__ ";
		gotoxy(x - 13, y + 9); cout << "  |__ ";
		gotoxy(x - 13, y + 10); cout << "  |  |";
		gotoxy(x - 13, y + 11); cout << "  |  |";
		gotoxy(x - 13, y + 12); cout << "  |  |";
		gotoxy(x - 13, y + 13); cout << "  |  |";
		gotoxy(x - 13, y + 14); cout << "Ｋ|  |";
		gotoxy(x - 22, y + 15); cout << "|__________|Ｑ|";
		gotoxy(x - 19, y + 16); cout << "|__________|";
		Sleep(300);
		gotoxy(x - 7, y + 10); cout << "__ ";
		gotoxy(x - 7, y + 11); cout << "  |__ ";
		gotoxy(x - 7, y + 12); cout << "  |  |";
		gotoxy(x - 7, y + 13); cout << "  |  |";
		gotoxy(x - 7, y + 14); cout << "  |  |";
		gotoxy(x - 7, y + 15); cout << "  |  |";
		gotoxy(x - 7, y + 16); cout << "Ｊ|  |";
		gotoxy(x - 16, y + 17); cout << "|__________|10|";
		gotoxy(x - 13, y + 18); cout << "|__________|";
		Sleep(300);
		gotoxy(x - 27, y + 20); cout << "   ▁";
		gotoxy(x - 27, y + 21); cout << " /    \\";
		gotoxy(x - 27, y + 22); cout << "| 20 $ |";
		gotoxy(x - 27, y + 23); cout << " \\ ▁ /";
		Sleep(300);
		gotoxy(x + 7, y + 8); cout << "Ｐｒｏｄｕｃｅｒ＿＿＿";
		gotoxy(x + 10, y + 12); cout << "＠KILNETA";
		Sleep(2200); Title_lost(x, y); }
	//5次
	{Sleep(300);
	gotoxy(x - 22, y + 4); cout << " __________ ";
	gotoxy(x - 22, y + 5); cout << "|９        |";
	gotoxy(x - 22, y + 6); cout << "|   ▲▲   |";
	gotoxy(x - 22, y + 7); cout << "|  ▉▉▉  |";
	gotoxy(x - 22, y + 8); cout << "|  ▉▉▉  |";
	gotoxy(x - 22, y + 9); cout << "|   ▉▉   |";
	gotoxy(x - 22, y + 10); cout << "|    ▉  ９|";
	gotoxy(x - 22, y + 11); cout << "|__________|";
	Sleep(300);
	gotoxy(x + 2, y + 6); cout << " __________ ";
	gotoxy(x + 2, y + 7); cout << "|２        |";
	gotoxy(x + 2, y + 8); cout << "|    ▉    |";
	gotoxy(x + 2, y + 9); cout << "|   ▉▉   |";
	gotoxy(x + 2, y + 10); cout << "|  ▉▉▉  |";
	gotoxy(x + 2, y + 11); cout << "|   ▉▉   |";
	gotoxy(x + 2, y + 12); cout << "|    ▉  ２|";
	gotoxy(x + 2, y + 13); cout << "|__________|";
	Sleep(300);
	gotoxy(x - 10, y + 5); cout << " __________ ";
	gotoxy(x - 10, y + 6); cout << "|Ａ        |";
	gotoxy(x - 10, y + 7); cout << "|   ▲▲   |";
	gotoxy(x - 10, y + 8); cout << "|  ▉▉▉  |";
	gotoxy(x - 10, y + 9); cout << "|  ▉▉▉  |";
	gotoxy(x - 10, y + 10); cout << "|   ▉▉   |";
	gotoxy(x - 10, y + 11); cout << "|    ▉  Ａ|";
	gotoxy(x - 10, y + 12); cout << "|__________|";
	Sleep(300);
	gotoxy(x + 14, y + 7); cout << " __________";
	gotoxy(x + 14, y + 8); cout << "|10        | __________";
	gotoxy(x + 14, y + 9); cout << "|    ◆    ||Ｋ        |";
	gotoxy(x + 14, y + 10); cout << "|   ◆◆   ||    ▲    |";
	gotoxy(x + 14, y + 11); cout << "| ◆◆◆◆ ||   ▉▉   |";
	gotoxy(x + 14, y + 12); cout << "|  ◆||◆  ||  ▉▉▉  |";
	gotoxy(x + 14, y + 13); cout << "|    ▅  10|| ▉ || ▉ |";
	gotoxy(x + 14, y + 14); cout << "|__________||    ▅  Ｋ|";
	gotoxy(x + 26, y + 15); cout << "|__________|";
	Sleep(300);
	gotoxy(x - 32, y + 17); cout << "＿＿＿Ｓｏｕｎｄｔｒａｃｋ";
	gotoxy(x - 26, y + 21); cout << "＠KILNETA";
	Sleep(2200); Title_lost(x, y); }
	//6次
	{Sleep(300);
	gotoxy(x - 26, y + 6); cout << "   __________";
	gotoxy(x - 26, y + 7); cout << " _|◆  ◆  ◆|";
	gotoxy(x - 26, y + 8); cout << "|◆  ◆  ◆  |";
	gotoxy(x - 26, y + 9); cout << "| |◆  ◆  ◆|";
	gotoxy(x - 26, y + 10); cout << "|◆  ◆  ◆  |";
	gotoxy(x - 26, y + 11); cout << "| |◆  ◆  ◆|";
	gotoxy(x - 26, y + 12); cout << "|◆  ◆  ◆  |";
	gotoxy(x - 26, y + 13); cout << "| |◆__◆__◆|";
	gotoxy(x - 26, y + 14); cout << "|◆__◆__◆|";
	Sleep(300);
	gotoxy(x + 11, y + 15); cout << " __________";
	gotoxy(x + 11, y + 16); cout << "|◆  ◆  ◆|";
	gotoxy(x + 11, y + 17); cout << "|  ◆  ◆  |";
	gotoxy(x + 11, y + 18); cout << "|◆  ◆  ◆|";
	gotoxy(x + 11, y + 19); cout << "|  ◆  ◆  |";
	gotoxy(x + 11, y + 20); cout << "|◆  ◆  ◆|";
	gotoxy(x + 11, y + 21); cout << "|  ◆  ◆  |";
	gotoxy(x + 11, y + 22); cout << "|◆__◆__◆|";
	Sleep(300);
	gotoxy(x - 27, y + 20); cout << "   ▁";
	gotoxy(x - 27, y + 21); cout << " /    \\";
	gotoxy(x - 27, y + 22); cout << "| 20 $ |";
	gotoxy(x - 27, y + 23); cout << " \\ ▁ /";
	Sleep(300);
	gotoxy(x + 13, y + 14); cout << " __________";
	gotoxy(x + 13, y + 15); cout << "|◆__◆__◆|";
	gotoxy(x + 22, y + 16); cout << "| |";
	gotoxy(x + 22, y + 17); cout << "◆|";
	gotoxy(x + 22, y + 18); cout << "| |";
	gotoxy(x + 22, y + 19); cout << "◆|";
	gotoxy(x + 22, y + 20); cout << "| |";
	gotoxy(x + 22, y + 21); cout << "◆|";
	Sleep(300);
	gotoxy(x + 6, y + 5); cout << "Ｄｉｒｅｃｔｏｒ＿＿＿";
	gotoxy(x + 10, y + 8); cout << "＠TREASURE1112";
	Sleep(2200); Title_lost(x, y); }
	//7次
	{Sleep(300);
	gotoxy(x - 25, y + 14); cout << "    ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁";
	gotoxy(x - 25, y + 15); cout << " /                                          \\";
	gotoxy(x - 25, y + 16); cout << "|";
	gotoxy(x + 20, y + 16); cout << "|";
	gotoxy(x - 25, y + 17); cout << " \\▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁/";
	Sleep(300);
	gotoxy(x - 20, y + 13); cout << "(﹁.﹁)                      ( LoL )";
	gotoxy(x - 31, y + 16); cout << "( :3)";
	Sleep(300);
	gotoxy(x - 20, y + 16); cout << "Ｔｅｘａｓ　ｈｏｌｄ'ｅｍ　ｇａｍｅ";
	Sleep(300);
	gotoxy(x + 15, y + 19); cout << " (B_B)";
	gotoxy(x - 16, y + 21); cout << "*(o.O)";
	Sleep(300);
	gotoxy(x - 4, y + 5); cout << "＿＿＿Ｉｃｅ ｃｒｅａｍ ｓｐｏｎｓｏｒ";
	gotoxy(x + 3, y + 8); cout << "＠a9210183";
	Sleep(2200); Title_lost(x, y); }
	//8次
	{Sleep(300);
	gotoxy(x - 1, y + 10); cout << " Λ 〃Λ    Λ 〃Λ";
	gotoxy(x - 1, y + 11); cout << "( ‧ω‧)  (‧ω‧ )";
	gotoxy(x - 1, y + 12); cout << " (    Ｕ)   ( ◎」)";
	gotoxy(x - 1, y + 13); cout << "   U   U     U   U";
	Sleep(300);
	gotoxy(x + 13, y + 20); cout << "   Λ  Λ";
	gotoxy(x + 13, y + 21); cout << " (      )";
	gotoxy(x + 13, y + 22); cout << "╭(  x )╮";
	gotoxy(x + 13, y + 23); cout << "   U  U";
	Sleep(300);
	gotoxy(x - 3, y + 17); cout << " Λ  Λ";
	gotoxy(x - 3, y + 18); cout << "(≧°ω°)";
	gotoxy(x - 3, y + 19); cout << " (  ﹋)";
	gotoxy(x - 3, y + 20); cout << "  U  U";
	Sleep(300);
	gotoxy(x + 25, y + 16); cout << " Λ  Λ";
	gotoxy(x + 25, y + 17); cout << "(‧‵  )";
	gotoxy(x + 25, y + 18); cout << " (    )";
	gotoxy(x + 25, y + 19); cout << "   U U";
	Sleep(300);
	gotoxy(x - 31, y + 7); cout << "Ｌｕｎｃｈ ｓｐｏｎｓｏｒ＿＿＿";
	gotoxy(x - 24, y + 11); cout << "＠TREASURE1112";
	Sleep(2200); Title_lost(x, y); }
	//9次
	{Sleep(300);
	gotoxy(x - 16, y + 15); cout << "┴┴︵╰（‵□′）╯︵┴┴";
	Sleep(300);
	gotoxy(x + 11, y + 19); cout << "          __________";
	gotoxy(x + 11, y + 20); cout << "        ∠  ㄟ  嘿  )";
	gotoxy(x + 11, y + 21); cout << "(☉∀☉)";
	Sleep(300);
	gotoxy(x - 30, y + 9); cout << "! (O_o)";
	gotoxy(x - 30, y + 17); cout << "   \\  /";
	gotoxy(x - 30, y + 18); cout << "(♯▼皿▼)";
	Sleep(300);
	gotoxy(x + 18, y + 8); cout << "             _____";
	gotoxy(x + 18, y + 9); cout << "            (What?)";
	gotoxy(x + 18, y + 10); cout << "        o O";
	gotoxy(x + 18, y + 11); cout << "Σ(°口°)";
	Sleep(300);
	gotoxy(x - 11, y + 9); cout << "  _____________________";
	gotoxy(x - 11, y + 10); cout << " /                     \\";
	gotoxy(x - 11, y + 11); cout << "| 德  \"粥\"  撲  克  牌  |";
	gotoxy(x - 11, y + 12); cout << " \\_________ ___________/";
	gotoxy(x - 11, y + 13); cout << "          V";
	Sleep(2200); Title_lost(x, y); }
	//10次
	{Sleep(300);
	gotoxy(x - 39, y + 10); cout << "               ____－－                                  －－____";
	gotoxy(x - 39, y + 11); cout << "       ____－－        |                                |        －－____";
	gotoxy(x - 39, y + 12); cout << "___－－                 |                              |                 －－___";
	gotoxy(x - 39, y + 13); cout << "                         |                            |";
	gotoxy(x - 39, y + 14); cout << "             _____        |                          |         _____";
	gotoxy(x - 39, y + 15); cout << "            (      \\       |                        |        /      )";
	gotoxy(x - 39, y + 16); cout << "             |       \\      |                      |       /       |";
	gotoxy(x - 39, y + 17); cout << "              |              |                    |               |";
	gotoxy(x - 39, y + 18); cout << "               |______________)                  (______________|";
	gotoxy(x - 39, y + 19); cout << "___                         )                      (                         ___";
	gotoxy(x - 39, y + 20); cout << "    \\ _____________________/                        \\ _____________________/";
	Sleep(300); system("cls");
	gotoxy(x - 39, y + 10); cout << "                       ____－－                －－____";
	gotoxy(x - 39, y + 11); cout << "               ____－－        |              |        －－____";
	gotoxy(x - 39, y + 12); cout << "        ___－－                 |            |                 －－___";
	gotoxy(x - 39, y + 13); cout << "____－－                         |          |                         －－______";
	gotoxy(x - 39, y + 14); cout << "                     _____        |        |         _____";
	gotoxy(x - 39, y + 15); cout << "                    (      \\       |      |        /      )";
	gotoxy(x - 39, y + 16); cout << "                     |       \\      |    |       /       |";
	gotoxy(x - 39, y + 17); cout << "                      |              |  |               |";
	gotoxy(x - 39, y + 18); cout << "                       |______________)(______________|";
	gotoxy(x - 39, y + 19); cout << "___________                         )    (                         _____________";
	gotoxy(x - 39, y + 20); cout << "            \\_____________________/        \\_____________________/";
	Sleep(300);
	gotoxy(x - 4, y + 9); cout << "   ▁";
	gotoxy(x - 4, y + 10); cout << " /    \\";
	gotoxy(x - 4, y + 11); cout << "| 20 $ |";
	gotoxy(x - 4, y + 12); cout << " \\ ▁ /";
	Sleep(300);
	gotoxy(x - 9, y + 5); cout << "Ｂｅｔ Ｐａｓｓｅｄ！";
	gotoxy(x - 7, y + 7); cout << "ｒｅｓｐｅｃｔ ＋";
	Sleep(300); Sleep(2200); Title_lost(x, y); }
	//11次
	{Sleep(300);
	gotoxy(x + 13, y + 3); cout << "   __________";
	gotoxy(x + 13, y + 4); cout << " _|◆  ◆  ◆|";
	gotoxy(x + 13, y + 5); cout << "|◆  ◆  ◆  |";
	gotoxy(x + 13, y + 6); cout << "| |◆  ◆  ◆|";
	gotoxy(x + 13, y + 7); cout << "|◆  ◆  ◆  |";
	gotoxy(x + 13, y + 8); cout << "| |◆  ◆  ◆|";
	gotoxy(x + 13, y + 9); cout << "|◆  ◆  ◆  |";
	gotoxy(x + 13, y + 10); cout << "| |◆__◆__◆|";
	gotoxy(x + 13, y + 11); cout << "|◆__◆__◆|";
	Sleep(300);
	gotoxy(x - 37, y + 8); cout << " __________";
	gotoxy(x - 37, y + 9); cout << "|９        |";
	gotoxy(x - 37, y + 10); cout << "|   ▲▲   |";
	gotoxy(x - 37, y + 11); cout << "|  ▉▉▉  |";
	gotoxy(x - 37, y + 12); cout << "|  ▉▉▉  |";
	gotoxy(x - 37, y + 13); cout << "|   ▉▉   |";
	gotoxy(x - 37, y + 14); cout << "|    ▉  ９|";
	gotoxy(x - 37, y + 15); cout << "|__________|";
	Sleep(300);
	gotoxy(x - 13, y + 10); cout << " __________";
	gotoxy(x - 13, y + 11); cout << "|８        |";
	gotoxy(x - 13, y + 12); cout << "|    ◆    |";
	gotoxy(x - 13, y + 13); cout << "|   ◆◆   |";
	gotoxy(x - 13, y + 14); cout << "| ◆◆◆◆ |";
	gotoxy(x - 13, y + 15); cout << "|  ◆||◆  |";
	gotoxy(x - 13, y + 16); cout << "|    ▅  ８|";
	gotoxy(x - 13, y + 17); cout << "|__________|";
	Sleep(300);
	gotoxy(x - 25, y + 9); cout << " __________";
	gotoxy(x - 25, y + 10); cout << "|Ａ        |";
	gotoxy(x - 25, y + 11); cout << "|    ▉    |";
	gotoxy(x - 25, y + 12); cout << "|   ▉▉   |";
	gotoxy(x - 25, y + 13); cout << "|  ▉▉▉  |";
	gotoxy(x - 25, y + 14); cout << "|   ▉▉   |";
	gotoxy(x - 25, y + 15); cout << "|    ▉  Ａ|";
	gotoxy(x - 25, y + 16); cout << "|__________|";
	Sleep(300);
	gotoxy(x + 7, y + 18); cout << "Ｆｉｎｅ　Ａｒｔ＿＿＿";
	gotoxy(x + 14, y + 21); cout << "＠KILNETA";
	Sleep(2200); Title_lost(x, y); }
	//12次
	{Sleep(300);
	gotoxy(x + 18, y + 4); cout << " __________";
	gotoxy(x + 18, y + 5); cout << "|Ａ        |";
	gotoxy(x + 18, y + 6); cout << "|    ▉    |";
	gotoxy(x + 18, y + 7); cout << "|   ▉▉   |";
	gotoxy(x + 18, y + 8); cout << "|  ▉▉▉  |";
	gotoxy(x + 18, y + 9); cout << " ﹋﹋﹋﹋﹋";
	Sleep(300);
	gotoxy(x - 1, y + 8); cout << " __________";
	gotoxy(x - 1, y + 9); cout << "|◆  ◆  ◇|";
	gotoxy(x - 1, y + 10); cout << "|  ◇  ◇  |";
	gotoxy(x - 1, y + 11); cout << "|◇  ◆  ◆|";
	gotoxy(x - 1, y + 12); cout << "|  ◆  ◆  |";
	gotoxy(x - 1, y + 13); cout << "|◆  ◇  ◆|";
	gotoxy(x - 1, y + 14); cout << "|  ◆  ◆  |";
	gotoxy(x - 1, y + 15); cout << "|◆__◇__◇|";
	Sleep(300);
	gotoxy(x + 19, y + 20); cout << "  ▁▁";
	gotoxy(x + 19, y + 21); cout << " /    \\";
	gotoxy(x + 19, y + 22); cout << "| #^%@ |";
	gotoxy(x + 19, y + 23); cout << " \\ ▁ /";
	Sleep(300);
	gotoxy(x + 18, y + 11); cout << "|﹋﹋▉﹋10|";
	gotoxy(x + 18, y + 12); cout << "|__________|";
	Sleep(300);
	gotoxy(x - 31, y + 6); cout << "Ｔｅｓｔｅｒ＿＿＿";
	gotoxy(x - 28, y + 10); cout << "＠TREASURE1112";
	gotoxy(x - 28, y + 12); cout << "＠KILNETA";
	gotoxy(x - 28, y + 14); cout << "＠a9210183";
	Sleep(2200); Title_lost(x, y); }
	//13次
	{Sleep(300);
	gotoxy(x - 39, y + 10); cout << "╔══╦╗                                  ╔╗        ╔═╦╗          ╔╗  ";
	gotoxy(x - 39, y + 11); cout << "╚╗╔╣╚╦═╗╔═╦═╗╔══╦═╗╔╦╦╬╬╗╔╗  ║═╣╚╦═╗╔╦╣╚╗";
	gotoxy(x - 39, y + 12); cout << "  ║║║║║╩╣║╬║╬╚╣║║║╩╣║║║║║╚╣╚╗╠═║╔╣╬╚╣╔╣╔╣";
	gotoxy(x - 39, y + 13); cout << "  ╚╝╚╩╩═╝╠╗╠══╩╩╩╩═╝╚══╩╩═╩═╝╚═╩═╩══╩╝╚═╝";
	gotoxy(x - 39, y + 14); cout << "                ╚═╝";
	Sleep(300);
	gotoxy(x - 25, y + 18); cout << "＠TREASURE1112        ＠KILNETA          ＠a9210183";
	Sleep(3100); Title_lost(x, y); }
	//14次
	{Sleep(300);
	gotoxy(x - 33, y + 8); cout << "ＷＩＮＮＥＲ";
	Sleep(300);
	gotoxy(x - 19, y + 8); cout << "ＷＩＮＮＥＲ,";
	Sleep(300);
	gotoxy(x - 3, y + 8); cout << "ＣＨＩＣＫＥＮ ＤＩＮＮＥ！";
	Sleep(300);
	gotoxy(x + 21, y + 14); cout << "－21－";
	Sleep(2500); Title_lost(x, y); }
	//15次
	{Sleep(300);
	gotoxy(x - 30, y + 10); cout << "╔═══╗              ╔╗╔╗                ╔╗    ╔╗";
	gotoxy(x - 30, y + 11); cout << "║╔═╗║              ║║║║                ║║    ║║";
	gotoxy(x - 30, y + 12); cout << "║║  ╚╬══╦══╦═╝║║║    ╔╗╔╦══╣║╔╗║║";
	gotoxy(x - 30, y + 13); cout << "║║╔═╣╔╗║╔╗║╔╗║║║  ╔╣║║║╔═╣╚╝╝╚╝";
	gotoxy(x - 30, y + 14); cout << "║╚╩═║╚╝║╚╝║╚╝║║╚═╝║╚╝║╚═╣╔╗╗╔╗";
	gotoxy(x - 30, y + 15); cout << "╚═══╩══╩══╩══╝╚═══╩══╩══╩╝╚╝╚╝";
	Sleep(3100); Title_lost(x, y); }
}

#endif