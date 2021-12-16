#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;
class ConsoleManipulation{
	public:
		static void fixConsoleWindow();
		// Cố định màn hình Console
		static void gotoXY(int, int);
		// Di chuyển đến tọa độ (x,y) trong màn hình Console
		static void setConsoleWindow(int w, int h);
		// Chỉnh size của màn hình Console 
		static void DeleConsol();

		static void textcolor(int);

		ConsoleManipulation();
		~ConsoleManipulation();
	
};

