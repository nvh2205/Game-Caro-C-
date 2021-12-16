#include "ConsoleManipulation.h"
#include<iostream>
using namespace std;

//Cố định 
void ConsoleManipulation::fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void ConsoleManipulation::setConsoleWindow(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}

void ConsoleManipulation::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleManipulation:: DeleConsol()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle

	(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void  ConsoleManipulation :: textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

ConsoleManipulation::ConsoleManipulation() {

}

ConsoleManipulation::~ConsoleManipulation() {

}