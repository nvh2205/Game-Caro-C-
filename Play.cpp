#include "Play.h"
#include <vector>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include"Game.h"
#include<string>
#include"Map.h"
using namespace std;
struct Name {
	char data[30];
};
vector <Name> ch;


void AnTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//int ReadChedo(char a[30])
//{
//	int d1, d2, chedo;
//	system("cls");
//	ifstream f;
//	f.open(a, ios::in);
//	if (!f) {
//		ConsoleManipulation::gotoXY(35, 46);
//		cout << "\n FILE KHONG TON TAI!" << endl;
//		Sleep(1000);
//		ScreenStartGame(99);
//	}
//	else
//		f >> d1 >> d2 >> chedo;
//	f.close();
//	return chedo;
//}
void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
//void ReadNameFile()
//{
//	Textcolor(Cyan);
//	ConsoleManipulation::gotoXY(60, 18);
//	cout << "LIST FILE NAME";
//	int i = 19;
//	ifstream f;
//	f.open("Name.txt", ios::in);
//	while (!f.eof())
//	{
//		char s[30];
//		f >> s;
//		ConsoleManipulation::gotoXY(30, i);
//		cout << s;
//		i++;
//	}
//	f.close();
//}

void PrintCaro() {
	ifstream fileIntro;
	fileIntro.open("Intro.txt", ios::in);
	while (!fileIntro.eof())
	{
		Textcolor(Blue);
		string str1;
		getline(fileIntro, str1);

		cout << str1 << endl;
		Sleep(100);
	}
	fileIntro.close();
}

//void LoadLoad()
//{
//	int n = 100;
//	system("cls");
//	PrintCaro();
//	ReadNameFile();
//	char data[30];
//	ConsoleManipulation::gotoXY(30, 32);
//	HienTroChuot();
//	cout << "ENTER FILE NAME: ";
//	cin.getline(data, 30);
//	int chedo = ReadChedo(data);
//	if (chedo == -30 || chedo == -31)
//	{
//		Diem a;
//		a.score1 = 0;
//		a.score2 = 0;
//		int t = PlayerVsPlayer(a, chedo, data);
//		if (t == 27)
//		{
//			system("cls");
//			ScreenStartGame(n - 1);
//		}
//	}
//	if (chedo == -4)
//	{
//		Diem a;
//		a.score1 = 0;
//		a.score2 = 0;
//		int t = PlayerVsCom2(a, -4, data);
//		if (t == 27)
//		{
//			system("cls");
//			ScreenStartGame(n - 1);
//		}
//	}
//	if (chedo == -5)
//	{
//		Diem a;
//		a.score1 = 0;
//		a.score2 = 0;
//		int t = PlayerVsCom(a, -5, data);
//		if (t == 27)
//		{
//			system("cls");
//			ScreenStartGame(n - 1);
//		}
//	}
//}
void ScreenStartGame(int n)
{

	AnTroChuot();
	int x = 30, y = 25;
	int i;
	char s[30] = " ";
	int check = 1;
	Textcolor(Red);
	ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
	Textcolor(7);
	ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
	ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
	ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
	if (n == 100)
	{

		ConsoleManipulation::gotoXY(0, 1);
		Screen();
		//PrintCaro();
	}
	else {
		ConsoleManipulation::gotoXY(0, 1);
		PrintCaro();
	}
	ConsoleManipulation::gotoXY(30, 25);
	while (check)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':

				if (y > 24)
				{
					y--;
					ConsoleManipulation::gotoXY(x, y);
				}
				if (y == 25)
				{
					Textcolor(Red);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				if (y == 26)
				{
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					Textcolor(Blue);
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				if (y == 27)
				{
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					Textcolor(10);
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				if (y == 28)
				{
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					Textcolor(14);
					Textcolor(14);
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				break;
			case 's':

				if (y < 28)
				{
					y++;
					ConsoleManipulation::gotoXY(x, y);
				}
				if (y == 25)
				{
					Textcolor(Red);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				if (y == 26)
				{
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					Textcolor(Blue);
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				if (y == 27)
				{
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					Textcolor(10);
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				if (y == 28)
				{
					Textcolor(7);
					ConsoleManipulation::gotoXY(30, 25); cout << "Player Vs Player";
					ConsoleManipulation::gotoXY(30, 26); cout << "Player Vs Bot (Very Easy)";
					ConsoleManipulation::gotoXY(30, 27); cout << "Player Vs Bot (Medium-Trung binh)";
					Textcolor(14);
					Textcolor(14);
					ConsoleManipulation::gotoXY(30, 28); cout << "Exit";
				}
				break;
			case 13:

				if (y == 25)
				{
					Diem a;
					a.score1 = 0;
					a.score2 = 0;
					int t = PlayerVsPlayer(a, 0, s);
					if (t == 27)
					{
						system("cls");
						ScreenStartGame(99);
					}
				}
				if (y == 26)
				{
					Diem a;
					a.score1 = 0;
					a.score2 = 0;
					int t = PlayerVsCom2(a, 0, s);
					if (t == 27)
					{
						system("cls");
						ScreenStartGame(99);
					}
				}
				if (y == 27)
				{
					Diem a;
					a.score1 = 0;
					a.score2 = 0;
					int t = PlayerVsCom(a, 0, s);
					if (t == 27)
					{
						system("cls");
						ScreenStartGame(99);
					}
				}
				if (y == 28)
				{
					exit(0);
				}
				break;
			}
		}
	}
}

void Tro1() {
	ifstream flieTro;
	flieTro.open("Tro.txt", ios::in);
	//ConsoleManipulation::gotoXY(SIZE * 3 + 10, 4);
	int i = 1;
	while (!flieTro.eof())
	{
		Textcolor(Blue);
		ConsoleManipulation::gotoXY(SIZE * 4+2, i++);
		string str1;
		getline(flieTro, str1);

		cout << str1 << endl;
		Sleep(20);
	}
	flieTro.close();
	int j = 12;
	while (j < 21)
	{
		Textcolor(Blue);
		ConsoleManipulation::gotoXY(SIZE * 4 + 2, j++);


		cout << "                        " << endl;

	}
}
void Tro2() {
	ifstream flieTro;
	flieTro.open("Tro.txt", ios::in);
	//ConsoleManipulation::gotoXY(SIZE * 3 + 10, 4);
	int i = 12;
	while (!flieTro.eof())
	{
		Textcolor(Blue);
		ConsoleManipulation::gotoXY(SIZE * 4 + 2, i++);
		string str1;
		getline(flieTro, str1);

		cout << str1 << endl;
		Sleep(20);
	}
	flieTro.close();
	int j = 1;

	while (j<10)
	{
		Textcolor(Blue);
		ConsoleManipulation::gotoXY(SIZE * 4 + 2, j++);


		cout << "                        " << endl;

	}


}
//Cho no dep thoi
void Beer() {
	ifstream Beer;
	Beer.open("Beer.txt", ios::in);
	//ConsoleManipulation::gotoXY(SIZE * 3 + 10, 4);
	int i = 29;
	while (!Beer.eof())
	{
		Textcolor(Yellow);
		ConsoleManipulation::gotoXY(SIZE * 4 + 2, i++);
		string str1;
		getline(Beer, str1);

		cout << str1 << endl;
		Sleep(20);
	}
	Beer.close();

}
void Beer2() {
	ifstream Beer;
	Beer.open("Beer.txt", ios::in);
	//ConsoleManipulation::gotoXY(SIZE * 3 + 10, 4);
	int i = 20;
	while (!Beer.eof())
	{
		Textcolor(Pink);
		ConsoleManipulation::gotoXY(SIZE * 4 + 2, i++);
		string str1;
		getline(Beer, str1);

		cout << str1 << endl;
		Sleep(20);
	}
	Beer.close();

}
void Beer3() {
	ifstream Beer;
	Beer.open("Beer.txt", ios::in);
	//ConsoleManipulation::gotoXY(SIZE * 3 + 10, 4);
	int i = 19;
	while (!Beer.eof())
	{
		Textcolor(DarkGreen);
		ConsoleManipulation::gotoXY(SIZE * 4 + 32+7, i++);
		string str1;
		getline(Beer, str1);

		cout << str1 << endl;
		Sleep(20);
	}
	Beer.close();

}

void PrintScoreBoard()
{
	Textcolor(Pink);
	//// cot doc
	//for (int i = 1; i < SIZE * 2; i++) {
	//	Sleep(1);
	//	ConsoleManipulation::gotoXY(SIZE * 4 + 18, i);
	//	cout << char(219);
	//}
	//Textcolor(DarkPink);
	//for (int i = 1; i < SIZE * 2; i++) {
	//	Sleep(1);
	//	ConsoleManipulation::gotoXY(SIZE * 4 + 17, i);
	//	cout << char(219);
	//}
	//
	/*Textcolor(White);
	Sleep(1);
	ConsoleManipulation::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 + 1); cout << "    C A R O";*/
	// cot ke ben ban co
	//for (int i = 0; i < (SIZE * 2 - 1) / 2 - 2; i++)
	//{
	//	Sleep(1);
	//	ConsoleManipulation::gotoXY(SIZE * 4 + 1, i + 1);
	//	cout << char(186);
	//}
	//Sleep(1);
	//ConsoleManipulation::gotoXY(SIZE * 4 + 1, 0); cout << char(187);
	//ConsoleManipulation::gotoXY(SIZE * 4 + 1, SIZE * 2); cout << char(188);
	//for (int i = (SIZE * 2 - 1) / 2 + 3; i < SIZE * 2 - 1; i++)
	//{
	//	Sleep(1);
	//	ConsoleManipulation::gotoXY(SIZE * 4 + 1, i + 1);
	//	cout << char(186);
	//}
	////
	//ConsoleManipulation::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 - 1); cout << char(200);
	//for (int i = 0; i < 15; i++)
	//{
	//	Sleep(1);
	//	cout << char(205);
	//}
	//ConsoleManipulation::gotoXY(SIZE * 4 + 1, (SIZE * 2 - 1) / 2 + 3); cout << char(201);
	//for (int i = 0; i < 15; i++)
	//{
	//	Sleep(1);
	//	cout << char(205);
	//}
	//Bang 2
	ConsoleManipulation::gotoXY(SIZE * 4 + 19+10, (SIZE * 2 - 1) / 2 + 1);
	//cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 8; i++) {
		Sleep(10);
		ConsoleManipulation::gotoXY(SIZE * 4 + 30+5, 11 + i);
		cout << char(219);
	}
	for (int i = 0; i < 8; i++) {
		Sleep(10);
		ConsoleManipulation::gotoXY(SIZE * 4 + 61+10, 11 + i);
		cout << char(219);
	}
	ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, 10);
	for (int i = 0; i < 37; i++) {
		Sleep(10);
		cout << char(220);
	}
	ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, 11 + 8);
	for (int i = 0; i < 37; i++) {
		Sleep(10);
		cout << char(223);
	}
	// Bang 3
	Sleep(15);
	ConsoleManipulation::gotoXY(SIZE * 4 + 19+10, (SIZE * 2 - 1) );
	//cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 10; i++) {
		Sleep(12);
		ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, SIZE * 2 - i+2);
		cout << char(219);
	}
	for (int i = 0; i < 10; i++) {
		Sleep(15);
		ConsoleManipulation::gotoXY(SIZE * 4 + 61+10, SIZE * 2 - i+2);
		cout << char(219);
	}
	ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, SIZE * 2+2);
	for (int i = 0; i < 37; i++) {
		Sleep(17);
		cout << char(223);
	}
	ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, SIZE * 2 - 10+3);
	for (int i = 0; i < 37; i++) {
		Sleep(13);
		cout << char(220);
	}
	// Bang 1
	Sleep(18);
	ConsoleManipulation::gotoXY(SIZE * 4 + 19+10, 4);
	//cout << char(219) << char(205) << char(205) << char(205) << char(205) << char(254);
	for (int i = 0; i < 8; i++) {
		Sleep(15);
		ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, i + 1);
		cout << char(219);
	}
	for (int i = 0; i < 8; i++) {
		Sleep(15);
		ConsoleManipulation::gotoXY(SIZE * 4 + 61+10, i + 1);
		cout << char(219);
	}
	ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, 0);
	for (int i = 0; i < 37; i++) {
		Sleep(12);
		cout << char(220);
	}
	ConsoleManipulation::gotoXY(SIZE * 4 + 25+10, 8 + 1);
	for (int i = 0; i < 37; i++) {
		Sleep(20);
		cout << char(223);
	}




	ConsoleManipulation::gotoXY(SIZE * 4 + 40+10, 2);
	cout << "PLAYER 1: X";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 4);
	cout << "Number of moves X : ";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 5);
	cout << "Number of games won : ";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 10, 7);
	cout << "Note: Turn off UniKey!";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 10, 8);
	cout << "--------------------------";


	ConsoleManipulation::gotoXY(SIZE * 4 + 40+10, 12);
	cout << "PLAYER 2: O";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 14);
	cout << "Number of moves O : ";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 15);
	cout << "Number of games won : ";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 10, 17);
	cout << "Note: Turn off UniKey!";
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 10, 18);
	cout << "---------------------------";



	ConsoleManipulation::gotoXY(SIZE * 4 + 30+7, 27+4);
	cout << "------Controls And Functions------";

	ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 28+4);
	cout << " W A S D : Move ";
	/*ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 29+4);
	cout << " L : Save Game ";*/

	ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 30+4);
	//cout << " T : Load Game ";
	ConsoleManipulation::textcolor(6);
	cout << "----ADMiN WITH LOVE----";

	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 10, 26+4);
	cout << "Design By ADMiN: H.N";
	Textcolor(Red);

	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 10, 31+4);
	cout << " U: Udo Funtion ";


	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 10, 32+4);
	cout << " H: Display the move ";

	ConsoleManipulation::gotoXY(SIZE * 4 + 30+10, 33+4);
	cout << " ESC : Exit ";
	Beer();
	Beer2();
	Beer3();

	ConsoleManipulation::gotoXY(2, 1);
} // IN BANG DIEM
void Screen()
{
	int check = 1;
	//while (check < 20)
	//{
		PrintCaro();
		//Sleep(100);
		//check++;
	//}
}

//void ChucNang_Udo(stack<ToaDo>&Udo,int &x,int &y) {
//	_Game a;
//	if (Udo.empty() == false) {
//		ToaDo t;
//		t = Udo.top();
//		Udo.pop();
//		x = t.x;
//		y = t.y;
//
//	}
//
//}

int PlayerVsCom(Diem& a, int load, char data[30])
{
	int k = 1, n = 100;
	ToaDo t;
	stack<ToaDo> List;
	HienTroChuot();
	_Game g(SIZE, 0, 0);
	g.setCountXY();
	if (load == -5)
	{
		g.LoadGame(data);
	}
	else
	{
		g.startGame();
		g.setTurn();
	}
	PrintScoreBoard();
	Textcolor(Cyan);
	ConsoleManipulation::gotoXY(SIZE * 4 + 32, 28);
	cout << " PLAYER VS ComPuter (Trung Binh-Medium) ";
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 5);
	cout << a.score1;
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 15);
	cout << a.score2;
	ConsoleManipulation::gotoXY(2, 1);
	int x2, y2,x3,y3;
	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				g.setX((SIZE * 4 / 2) - 2);
				g.setY((SIZE * 2 / 2) - 1);
				ConsoleManipulation::gotoXY((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
				g.setCommand(13);
			}
			else
			{
				g.TimKiemNuocDi();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				//t.x1 = x;
				//t .y1 = y;
				//List.push(t);
				ConsoleManipulation::gotoXY(x, y);
				Sleep(300);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27)
		{

			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':

				g.moveLeft();
				break;
			case 'D':

				g.moveRight();
				break;
			case 'W':

				g.moveUp();
				break;
			case 'S':

				g.moveDown();
				break;
			//case 'L':

			//	g.SaveGame(-5);
			//	break;

			case 'U': {

				//int a = 31;
				//while (!List.empty()) {
				//	ConsoleManipulation::gotoXY(SIZE * 4 + 30, a++);
				//	cout << " " << List.top().x1 <<"-  "<<List.top().y1 <<endl;
				//	List.pop();

				//}

				ToaDo t1;
				t1 = List.top();
				//ConsoleManipulation::gotoXY(SIZE * 4 + 10, 31);
				//cout << " " << t1.x1 << "-. " <<t1. y1 << endl;
				List.pop();
				int x1 = t1.x1;
				int y1 = t1.y1;
				//ConsoleManipulation::gotoXY(x1, y1);
				//ConsoleManipulation::gotoXY(SIZE * 4 + 30 , 31);
				//cout << " " << x1 << "- " << y1<<endl;
				

				ToaDo t2;
				//cout << " ";
				g.XoaNuocCo(x1,y1);
				//List.pop();
				t2 = List.top();
				//ConsoleManipulation::gotoXY(SIZE * 4 + 10, 32);
				//cout << " " << t2.x1 << "- " << t2.y1 << endl;
				List.pop();
				x3 = t2.x1;
				y3 = t2.y1;
				//ConsoleManipulation::gotoXY(x3, y3);
				//ConsoleManipulation::gotoXY(SIZE * 4 + 30, 32);
				//cout << " " << x3 << "- " << y3 << endl;
				//cout << " ";

				g.XoaNuocCo(x3,y3);
				//g.setTurn();
				
				break; }
			case 'H': {
				ToaDo D;
				D = List.top();
				int x = D.x1;
				int y = D.y1;
				g.Display(x, y);
				break; }

			case 13:
			{
				 x2 = g.getXatEnter();
				 y2 = g.getYatEnter();
				t.x1 = x2;
				t.y1 = y2;
				List.push(t);
				if (g.processCheckBoard()) {
					switch (g.processFinish(x2, y2)) {
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsCom(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n - 1);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsCom(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n - 1);
									break;
								}

							}


						}

						break;
					case 0:
						while (k)
						{

							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsCom(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n - 1);
									break;
								}
							}
						}
						break;
					}
					}
				}

			}

		}

	}
}
int PlayerVsCom2(Diem& a, int load, char data[30])
{
	int n = 99;
	int k = 1;
	ToaDo t;
	stack<ToaDo> List;
	HienTroChuot();
	_Game g(SIZE, 0, 0);
	g.setCountXY();
	if (load == -4)
	{
		g.LoadGame(data);
	}
	else
	{
		g.startGame();
		g.setTurn();
	}
	PrintScoreBoard();
	Textcolor(Cyan);
	ConsoleManipulation::gotoXY(SIZE * 4 + 32, 28);
	cout << " PLAYER VS Computer (Veryyyy EASY) ";
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 5);
	cout << a.score1;
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 15);
	cout << a.score2;
	ConsoleManipulation::gotoXY(2, 1);
	int x2, y2, x3, y3;
	while (g.isContinue())
	{
		if (!g.getTurn())
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				g.setX((SIZE * 4 / 2) - 2);
				g.setY((SIZE * 2 / 2) - 1);
				ConsoleManipulation::gotoXY((SIZE * 4 / 2) - 2, (SIZE * 2 / 2) - 1);
				g.setCommand(13);
			}
			else
			{
				g.TimKiemNuocDi2();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				ConsoleManipulation::gotoXY(x, y);
				Sleep(300);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27) {

			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':

				g.moveLeft();
				break;
			case 'D':

				g.moveRight();
				break;
			case 'W':
	
				g.moveUp();
				break;
			case 'S':

				g.moveDown();
				break;
			//case 'L':

			//	g.SaveGame(-4);
			//	break;
			//case 'T':

			//	LoadLoad();
			//	break;
			case 'U': {

				//int a = 31;
				//while (!List.empty()) {
				//	ConsoleManipulation::gotoXY(SIZE * 4 + 30, a++);
				//	cout << " " << List.top().x1 <<"-  "<<List.top().y1 <<endl;
				//	List.pop();

				//}

				ToaDo t1;
				t1 = List.top();
				//ConsoleManipulation::gotoXY(SIZE * 4 + 10, 31);
				//cout << " " << t1.x1 << "-. " <<t1. y1 << endl;
				List.pop();
				int x1 = t1.x1;
				int y1 = t1.y1;
				//ConsoleManipulation::gotoXY(x1, y1);
				//ConsoleManipulation::gotoXY(SIZE * 4 + 30 , 31);
				//cout << " " << x1 << "- " << y1<<endl;


				ToaDo t2;
				//cout << " ";
				g.XoaNuocCo(x1, y1);
				//List.pop();
				t2 = List.top();
				//ConsoleManipulation::gotoXY(SIZE * 4 + 10, 32);
				//cout << " " << t2.x1 << "- " << t2.y1 << endl;
				List.pop();
				x3 = t2.x1;
				y3 = t2.y1;
				//ConsoleManipulation::gotoXY(x3, y3);
				//ConsoleManipulation::gotoXY(SIZE * 4 + 30, 32);
				//cout << " " << x3 << "- " << y3 << endl;
				//cout << " ";

				g.XoaNuocCo(x3, y3);
				//g.setTurn();

				break; }
			case 'H': {
				ToaDo D;
				D = List.top();
				int x = D.x1;
				int y = D.y1;
				g.Display(x, y);
				break; }
			case 13:
;
				x2 = g.getXatEnter();
				y2 = g.getYatEnter();
				t.x1 = x2;
				t.y1 = y2;
				List.push(t);
				if (g.processCheckBoard()) {
					switch (g.processFinish(x2, y2)) {
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsCom2(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}

						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsCom2(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}

						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsCom2(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
}
int PlayerVsPlayer(Diem& a, int load, char data[30])
{
	int k = 1;
	int n = 99;
	int x2, y2, x3, y3;
	ToaDo t;
	stack<ToaDo> List;
	HienTroChuot();
	_Game g(SIZE, 0, 0);
	g.setCountXY();
	if (load == -30)
	{
		g.setTurn();
		g.LoadGame(data);
	}
	else if (load == -31)
	{
		g.LoadGame(data);
	}
	else
		g.startGame();
	PrintScoreBoard();
	Textcolor(Cyan);
	ConsoleManipulation::gotoXY(SIZE * 4 + 32+4, 28);
	cout << " PLAYER VS PLAYER ";
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 5);
	cout << a.score1;
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 15);
	cout << a.score2;
	ConsoleManipulation::gotoXY(2, 1);
	while (g.isContinue())
	{
		g.waitKeyBoard();
		if (g.getCommand() == 27) {

			return 27;
		}

		else
		{
			switch (g.getCommand())
			{
			case 'A':

				g.moveLeft();
				break;
			case 'D':

				g.moveRight();
				break;
			case 'W':

				g.moveUp();
				break;
			case 'S':
	
				g.moveDown();
				break;
			//case 'L':

			//	if (g.getTurn() == 1)
			//		g.SaveGame(-31);
			//	else
			//		g.SaveGame(-30);
			//	break;
			//case 'T':

			//	LoadLoad();
			//	break;
			case 'U': {

				//int a = 31;
				//while (!List.empty()) {
				//	ConsoleManipulation::gotoXY(SIZE * 4 + 30, a++);
				//	cout << " " << List.top().x1 <<"-  "<<List.top().y1 <<endl;
				//	List.pop();

				//}

				ToaDo t1;
				t1 = List.top();
				//ConsoleManipulation::gotoXY(SIZE * 4 + 10, 31);
				//cout << " " << t1.x1 << "-. " <<t1. y1 << endl;
				List.pop();
				int x1 = t1.x1;
				int y1 = t1.y1;
				//ConsoleManipulation::gotoXY(x1, y1);
				//ConsoleManipulation::gotoXY(SIZE * 4 + 30 , 31);
				//cout << " " << x1 << "- " << y1<<endl;


				//ToaDo t2;
				//cout << " ";
				g.XoaNuocCo(x1, y1);
				g.setTurn();
				//List.pop();
				//t2 = List.top();
				//ConsoleManipulation::gotoXY(SIZE * 4 + 10, 32);
				//cout << " " << t2.x1 << "- " << t2.y1 << endl;
				//List.pop();
				//x3 = t2.x1;
				//y3 = t2.y1;
				//ConsoleManipulation::gotoXY(x3, y3);
				//ConsoleManipulation::gotoXY(SIZE * 4 + 30, 32);
				//cout << " " << x3 << "- " << y3 << endl;
				//cout << " ";

				//g.XoaNuocCo(x3, y3);
				//g.setTurn();

				break; }
			case 'H': {
				ToaDo D;
				D = List.top();
				int x = D.x1;
				int y = D.y1;
				g.Display(x, y);
				break; }
			case 13:

				x2 = g.getXatEnter();
				y2 = g.getYatEnter();
				t.x1 = x2;
				t.y1 = y2;
				List.push(t);
				if (g.processCheckBoard()) {
					switch (g.processFinish(x2, y2)) {
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsPlayer(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsPlayer(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':

									load = 0;
									return PlayerVsPlayer(a, load, data);
									break;
								case 27:

									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;

					}
				}
			}
		}
	}
}
//Mode Load Error!!!
