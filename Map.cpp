#include "Map.h"
#include"ConsoleManipulation.h"
#include"Coordinates.h"
#include<iostream>
#include<vector>
#include<conio.h>
vector<Coordinates>win;
using namespace std;
int Map::getSize() {
	return this->_size;
}
int Map::getLeft() {
	return _left;
}
int Map::getTop(){
	return _top;
}
Map::Map()
{
	for (int i = 0; i < _size; i++)
	{
		delete[] _pArr[i];
	}
	delete[] _pArr;
}

int Map::getXAt(int i,int j) {
	return _pArr[i][j].getX();
}

int Map::getYAt(int i, int j) {
	return _pArr[i][j].getY();
}

void Map::loadData(int k, int i, int j) {
	if (_size == 0) {
		return;
	}
	_pArr[i][j].setX( 4 * j + _left+2 );
	_pArr[i][j].setY(2 * i + _top +1 );
	_pArr[i][j].setCheck(k);
	if (k == 1) {
		ConsoleManipulation::textcolor(13);
		ConsoleManipulation::gotoXY(4 * j + _left+2 , 2 * i + _top +1);
		cout << "X";
		CountX++;
	}
	if (k == 1)
	{
		ConsoleManipulation::textcolor(14);
		ConsoleManipulation::gotoXY(4 * j + _left+2 , 2 * i + _top+1 );
		cout << "O";
		CountY++;
	}
}
Map::Map(int pSize, int pX, int pY)
{
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new Coordinates * [pSize];
	for (int i = 0; i < pSize; i++)
	{
		_pArr[i] = new Coordinates[pSize];
	}
}

void Map::resetData() {
	if (_size == 0) {
		return;
	}
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left +2);
			_pArr[i][j].setY(2 * i + _top +1);
			_pArr[i][j].setCheck(0);
		}
	}
}


//.....................xoa co
void Map::XoaCo(int &x, int &y) {
	//_pArr[i][j].setX(4 * j + _left + 2);
	//_pArr[i][j].setY(2 * i + _top + 1);
	int i, j;
	
	j = (x - _left - 2) / 4;
	i = (y - _top - 1) / 2;
	//ConsoleManipulation::gotoXY(16 * 4 + 25, 31);
	//Sleep(50);
	//cout << " " << i << "- " << j << endl;
	if (_pArr[i][j].getCheck()==1) {
		 CountY--;
		

	}
	else if (_pArr[i][j].getCheck()==-1) {
		CountX--;
		
	}
	_pArr[i][j].setCheck(0);


}

void Map::DisplayTheMove(int x, int y) {
	int i, j;

	j = (x - _left - 2) / 4;
	i = (y - _top - 1) / 2;
	if (_pArr[i][j].getCheck() == 1) {
		for (int i = 1; i <= 15; i++) {
			ConsoleManipulation::textcolor(i);
			ConsoleManipulation::gotoXY(x, y);
			Sleep(80);
			cout << "O";
		}
		ConsoleManipulation::textcolor(10);
		ConsoleManipulation::gotoXY(x, y);
		cout << "O";
		ConsoleManipulation::gotoXY(x, y);
	}
	else if (_pArr[i][j].getCheck() == -1) {
		for (int i = 1; i <= 15; i++) {
			ConsoleManipulation::textcolor(i);
			ConsoleManipulation::gotoXY(x, y);
			Sleep(80);
			cout << "X";
			
		}
		ConsoleManipulation::gotoXY(x, y);
		ConsoleManipulation::textcolor(13);
		cout << "X";
		ConsoleManipulation::gotoXY(x, y);
	}
}

void Map::drawBoard() {
	if (_size == 0) {
		return;
	}
	ConsoleManipulation::textcolor(7);
	for (int i = 0; i < _size; i++) {
		Sleep(21);
		if (i == 0) {
			cout << (char)218;
		}
		else {
			cout << (char)194; // ┬
		}
		cout << (char)196 << (char)196 << (char)196; // ─
		if (i == _size-1) {
			cout << (char)191; // ┐
		}
	}
	//cout << endl;
	for (int i = 0; i < _size * 2; i++) {
		if (i % 2 == 0) {
			Sleep(21);
			//if (i == 0) {
			//	cout << (char)218;
			//}
			for (int j = 0; j < _size; j++) {
				if (i > 0 && i < 2 * _size - 1) {
					if (j == 0) {
						cout << (char)195; // ├
					}
					else if (j > 0 && j < _size) {
						cout << (char)197; // ┼
					}
				}
				if (i > 0) {
					cout << (char)196 << (char)196 << (char)196; // ─
				}
				if (i > 0 && j == _size - 1) {
					cout << (char)180; // ┤
				}
				//if (i==0  && j<10-1) {
				//	cout << (char)194; // ┬
				//}
			}
			//if (i == 0) {
			//	cout << (char)191; // ┐
			//}
			cout << endl;
		}
		else
		{
			Sleep(21);
			for (int j = 0; j < _size; j++) {

				cout << (char)179 << "   ";
			}
			cout << (char)179;
			cout << endl;
		}
	}
	for (int i = 0; i < _size; i++) {
		Sleep(30);
		if (i == 0) {

			cout << (char)192; // └
		}
		else {
			cout << (char)193; // ┴
		}
		cout << (char)196 << (char)196 << (char)196; // ─

	}
	cout << (char)217; // ┘
	cout << endl;
}


int Map::checkBoard(int pX, int pY, bool pTurn) 
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn)
				{
					_pArr[i][j].setCheck(-1);
					CountX++;
				}	// X
				else
				{
					_pArr[i][j].setCheck(1);
					CountY++;
				}	// O	
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}

//Hàng ngang
int Map::checkWinRow(int x, int y, int value)
{
	int dong, cot;
	int loop = 1;
	int test = -1;
	//int check2dau = 0;
	int countRowLeft = 0, countRowRight = 0;
	dong = (x - _left -2) / 4;
	cot = (y - _top -1) / 2;
	int dongtrai, dongphai; // Xet dem X ve phia trai, va ve phia phai
	dongtrai = dongphai = dong;
	// Xet X chien thang
	// Xet hang ngang
	while (_pArr[cot][dongtrai].getCheck() == value)
	{
		win.push_back(_pArr[cot][dongtrai]);
		countRowLeft++;
		if (dongtrai == 0)
			break;
		dongtrai--;
	}
	while (_pArr[cot][dongphai].getCheck() == value)
	{
		win.push_back(_pArr[cot][dongphai]);
		countRowRight++;
		if (dongphai == _size - 1)
			break;
		dongphai++;
	}
	/*if (_pArr[cot][dongtrai].getCheck() == -value && _pArr[cot][dongphai].getCheck() == -value)
		check2dau = 1;*/
	if ((countRowLeft + countRowRight - 1) == 5)
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		while (loop < 30)
		{
			ConsoleManipulation :: textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				ConsoleManipulation::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}

//hàng d?c
int Map::checkWinCol(int x, int y, int value) // Xet chien thang theo hang doc
{
	int dong, cot;
	int test = -1, loop = 1;

	int countColTop = 0, countColBot = 0;
	dong = (x - _left-2 ) / 4;
	cot = (y - _top -1) / 2;
	int cottren, cotduoi; // Xet bien dem ve phia tren, va ve phia duoi
	cottren = cotduoi = cot;
	// Xet chien thang
	// Xet hang doc
	while (_pArr[cottren][dong].getCheck() == value)
	{
		countColTop++;
		win.push_back(_pArr[cottren][dong]);
		if (cottren == 0)
			break;
		cottren--;
	}
	while (_pArr[cotduoi][dong].getCheck() == value)
	{
		countColBot++;
		win.push_back(_pArr[cotduoi][dong]);
		if (cotduoi == _size - 1)
			break;
		cotduoi++;
	}

	if ((countColTop + countColBot - 1) == 5 )
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		while (loop < 30)
		{
			ConsoleManipulation:: textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				ConsoleManipulation::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}

//???ng chéo 2
int Map::checksecondDiagonal(int x, int y, int value)
{
	int dong, cot;
	int test = -1, loop = 1;

	int countDiaTop = 0, countDiaBot = 0;
	dong = (x - _left-2 ) / 4;
	cot = (y - _top -1) / 2;
	int cottren, cotduoi;// Xet dem X ve phia tren, va ve phia duoi
	int dongphai, dongtrai;
	cottren = cotduoi = cot;
	dongphai = dongtrai = dong;
	// Xet X chien thang
	// Xet hang ngang
	while (_pArr[cottren][dongtrai].getCheck() == value)
	{
		win.push_back(_pArr[cottren][dongtrai]);
		countDiaTop++;
		if (cottren == 0 || dongtrai == 0)
			break;
		cottren--;
		dongtrai--;
	}

	while (_pArr[cotduoi][dongphai].getCheck() == value)
	{
		win.push_back(_pArr[cotduoi][dongphai]);
		countDiaBot++;
		if (cotduoi == _size - 1 || dongphai == _size - 1)
			break;
		cotduoi++;
		dongphai++;
	}

	if ((countDiaTop + countDiaBot - 1) == 5)
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{

		while (loop < 30)
		{
			ConsoleManipulation:: textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				ConsoleManipulation::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}

//???ng chéo 1
int Map::checkfirstDiagonal(int x, int y, int value)
{
	int dong, cot;
	int test = -1, loop = 1;

	int countDiaTop = 0, countDiaBot = 0;
	dong = (x - _left-2 ) / 4;
	cot = (y - _top -1) / 2;
	int cottren, cotduoi;// Xet dem X ve phia tren, va ve phia duoi
	int dongphai, dongtrai;
	cottren = cotduoi = cot;
	dongphai = dongtrai = dong;
	// Xet X chien thang
	// Xet hang ngang
	while (_pArr[cottren][dongphai].getCheck() == value)
	{
		countDiaTop++;
		win.push_back(_pArr[cottren][dongphai]);
		if (cottren == 0 || dongphai == _size - 1)
			break;
		cottren--;
		dongphai++;
	}
	while (_pArr[cotduoi][dongtrai].getCheck() == value)
	{
		win.push_back(_pArr[cotduoi][dongtrai]);
		countDiaBot++;
		if (cotduoi == _size - 1 || dongtrai == 0)
			break;
		cotduoi++;
		dongtrai--;
	}

	if ((countDiaTop + countDiaBot - 1) == 5 )
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		while (loop < 30)
		{
			ConsoleManipulation:: textcolor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				ConsoleManipulation::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}


int Map::testBoard(int x, int y)
{
	// X chien thang
	if (checkWinRow(x, y, -1) == 1)
		return -1;
	if (checkWinCol(x, y, -1) == 1)
		return -1;
	if (checkfirstDiagonal(x, y, -1) == 1)
		return -1;
	if (checksecondDiagonal(x, y, -1) == 1)
		return -1;
	// O chien thang
	if (checkWinRow(x, y, 1) == 1)
		return 1;
	if (checkWinCol(x, y, 1) == 1)
		return 1;
	if (checkfirstDiagonal(x, y, 1) == 1)
		return 1;
	if (checksecondDiagonal(x, y, 1) == 1)
		return 1;
	if (CountX + CountY == _size * _size)
		return 0;
	return 2;
}

// Xu li AI
long Map::SoDiemTanCong_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempNgang = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size; iDem++)
	{
		if (_pArr[Dong][Cot + iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong][Cot + iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong][Cot + iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong][Cot + iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (_pArr[Dong][Cot - iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong][Cot - iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong][Cot - iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong][Cot - iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempNgang += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempNgang += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempNgang += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempNgang += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanTa == 4)
		iScoreTempNgang *= 2;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich2];
	return iScoreTempNgang;
}
long Map::SoDiemTanCong_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempDoc = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong + iDem][Cot].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong + iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}

	}
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong - iDem][Cot].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong - iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}

	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempDoc += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempDoc += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempDoc += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempDoc += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempDoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich2];
	return iScoreTempDoc;
}

long Map::SoDiemTanCong_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempCheoNguoc = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoNguoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2];
	return iScoreTempCheoNguoc;
}
long Map::SoDiemTanCong_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempCheoXuoi = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 1)
			iSoQuanTa++;
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 1)
					iSoQuanTa2++;
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoXuoi *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2];
	return iScoreTempCheoXuoi;
}

long Map::SoDiemPhongThu_DuyetDoc(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempDoc = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong + iDem][Cot].getCheck() == -1)
			iSoQuanDich++;
		if (_pArr[Dong + iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot].getCheck() == -1)
					iSoQuanDich2++;
				if (_pArr[Dong + iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}
	}
	//iScoreDefend += Defend_Score[iSoQuanDich];
	//iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong - iDem][Cot].getCheck() == -1)
			iSoQuanDich++;
		if (_pArr[Dong - iDem][Cot].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot].getCheck() == -1)
					iSoQuanDich2++;
				if (_pArr[Dong - iDem2][Cot].getCheck() == 0)
					break;
			}
			break;
		}
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich];
	/*
	if (iSoQuanTa == 0)
	iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
	iScoreTempDoc += Defend_Score[iSoQuanDich2];
	*/
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempDoc *= 2;
	return iScoreTempDoc;
}

long Map::SoDiemPhongThu_DuyetNgang(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempNgang = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size; iDem++)
	{
		if (_pArr[Dong][Cot + iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong][Cot + iDem].getCheck() == -1)
			iSoQuanDich++;
		if (_pArr[Dong][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong][Cot + iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong][Cot + iDem2].getCheck() == -1)
					iSoQuanDich2++;
				if (_pArr[Dong][Cot + iDem2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	//iScoreDefend += Defend_Score[iSoQuanDich];
	//iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (_pArr[Dong][Cot - iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong][Cot - iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong][Cot - iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong][Cot - iDem].getCheck() == -1)
			iSoQuanDich++;
	}

	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];
	/*
	if (iSoQuanTa == 0)
	iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
	iScoreTempDoc += Defend_Score[iSoQuanDich2];
	*/
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanDich == 4)
		iScoreTempNgang *= 2;
	return iScoreTempNgang;
}



long Map::SoDiemPhongThu_DuyetCheo1(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{

	long iScoreTempCheoNguoc = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < _size && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong + iDem2][Cot + iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong + iDem][Cot + iDem].getCheck() == -1)
			iSoQuanDich++;
	}
	//iScoreDefend += Defend_Score[iSoQuanDich];
	//iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}

		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}

				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong - iDem2][Cot - iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong - iDem][Cot - iDem].getCheck() == -1)
			iSoQuanDich++;
	}
	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
	/*
	if (iSoQuanTa == 0)
	iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
	iScoreTempDoc += Defend_Score[iSoQuanDich2];
	*/
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoNguoc *= 2;
	return iScoreTempCheoNguoc;
}


long Map::SoDiemPhongThu_DuyetCheo2(long Dong, long Cot, const long Defend_Score[], const long Attack_Score[])
{
	long iScoreTempCheoXuoi = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < _size; iDem++)
	{
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < _size; iDem2++)
			{
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong + iDem2][Cot - iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong + iDem][Cot - iDem].getCheck() == -1)
			iSoQuanDich++;
	}
	//iScoreDefend += Defend_Score[iSoQuanDich];
	//iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot + iDem < _size && Dong - iDem >= 0; iDem++)
	{
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == 0)
		{
			for (int iDem2 = 2; iDem < 7 && Cot + iDem2 < _size && Dong - iDem2 >= 0; iDem2++)
			{
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == 0)
					break;
				if (_pArr[Dong - iDem2][Cot + iDem2].getCheck() == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_pArr[Dong - iDem][Cot + iDem].getCheck() == -1)
			iSoQuanDich++;
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];

	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoXuoi *= 2;
	return iScoreTempCheoXuoi;
}

 Coordinates Map::Tim_Kiem_NuocDi_1()
{
	Coordinates Oco;
	int dong = 0, cot = 0;
	long Diem = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
	Oco.setX(cot * 4 + 2);
	Oco.setY(dong * 2 + 1);
	return Oco;
}


Coordinates Map::Tim_Kiem_NuocDi_2()
{
	Coordinates Oco;
	int dong = 0, cot = 0;
	long Diem = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_pArr[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
	Oco.setX(cot * 4 + 2);
	Oco.setY(dong * 2 + 1);
	return Oco;
}

//void Map::PlayerVsCom(int &x ,int &y) {
//
//	 x = 0, y = 0;
//	_pArr[x][y];
//	int i, j;
//	int k;
//	
//	//ConsoleManipulation::gotoXY(i, y);
//	//ConsoleManipulation::gotoXY(6, 1);//y=2*i+y0
//	//ConsoleManipulation::gotoXY(2, 5);//x=4*j+x0
//
//	while (true) {
//		if (_kbhit()) // nhận biết được có tương tác từ bàn phím
//		{
//			i = getXAt(x, y);
//			j = getYAt(x, y);
//			char c = _getch(); // chờ nhận vào 1 phím từ bàn phím
//			if (c == 'a' || c == 'A' || c == 'd' || c == 'D' || c == 'w' || c == 'W' || c == 's' || c == 'S') // Đây là những phím điều hướng con trỏ chuột
//						//if(GetAsyncKeyState(0x41) || GetAsyncKeyState(0x44) || GetAsyncKeyState(0x57) || GetAsyncKeyState(0x53))
//			{
//
//				if (c == 'a' || c == 'A') // Left
//				//if(GetAsyncKeyState(0x41))
//				{
//					if (y > 0)
//						y--;
//					ConsoleManipulation::gotoXY(i, j);
//				}
//				else if (c == 'd' || c == 'D') // Right
//				//else if(GetAsyncKeyState(0x44))
//				{
//					if (y < _size - 1) {
//						y++;
//						ConsoleManipulation::gotoXY(i, j);
//					}
//				}
//				else if (c == 'w' || c == 'W') // Up
//				//else if(GetAsyncKeyState(0x57))
//				{
//					if (x> 0)
//						x--;
//					ConsoleManipulation::gotoXY(i, j);
//				}
//				else if (c == 's' || c == 'S') // Down
//				//else if(GetAsyncKeyState(0x53))
//				{
//					if (x < _size - 1)
//						x++;
//					ConsoleManipulation::gotoXY(i, j);
//				}
//
//				ConsoleManipulation::gotoXY(i, j);
//			}
//			else if (c == 32 || c == 13) {
//				i = getXAt(x, y);
//				j = getYAt(x, y);
//				//ConsoleManipulation::gotoXY(i, j);
//				k = get_Check(x, y);
//					if (k == 0) {
//						k = 1;
//						loadData(k,x, y);
//					}
//
//			}
//			Sleep(200);
//
//
//			
//		}
//	}
//	
//}


Map::~Map()
{
}

