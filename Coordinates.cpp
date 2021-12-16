#include "Coordinates.h"
#include<iostream>

int Coordinates::getX()
{
	return this->_x;
}
int Coordinates::getY()
{
	return _y;
}
int Coordinates::getCheck()
{
	return _check;
}
void Coordinates::setX(int pX)
{
	_x = pX;
}
void Coordinates::setY(int pY)
{
	_y = pY;
}
bool Coordinates::setCheck(int pCheck)
{
	if (pCheck == -1 || pCheck == 1 || pCheck == 0)
	{
		_check = pCheck;
		return true;
	}
	return false;
}
Coordinates::Coordinates()
{
	_x = 0;
	_y = 0;
	_check = 0;
}
Coordinates::Coordinates(int x, int y)
{
	_x = x;
	_y = y;
	_check = 0;
}

Coordinates::~Coordinates()
{
}

