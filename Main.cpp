#include "ConsoleManipulation.h"
#include "Coordinates.h"
#include "Map.h"
#include "Game.h"
#include "Play.h"
#include <string.h>
#include<iostream>


int main()
{
	int n = 100;
	//Map::fixConsoleWindow();
	ConsoleManipulation::setConsoleWindow(1430, 830);
	ScreenStartGame(n);
	system("pause");
}