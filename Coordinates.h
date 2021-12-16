﻿#pragma once
#include "conio.h"
#include <iostream>
#include "ConsoleManipulation.h"
using namespace std;
class Coordinates
{
	int _x;
	int _y;
	// Tọa độ x y trên bàn cờ
	int _check;
	// Biến nhận biết X và O ( -1 = X , 1 = O, 0 = Ô trống )

public:
	bool setCheck(int);
	// Cài đặt biến _check
	int getX();
	// Lấy giá trị của _x
	int getY();
	// Lấy giá trị của _y
	int getCheck();
	// Lấy giá trị của _check
	void setX(int);
	// Cài đặt biến _x
	void setY(int);
	// Cài đặt biến _y

	Coordinates(int, int);
	Coordinates();
	~Coordinates();
};


