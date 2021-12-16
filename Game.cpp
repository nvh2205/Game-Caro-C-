#include "Game.h"
//#include<istream>
#include<stack>


_Game::_Game(int pSize, int pLeft, int  pTop)
{
	_b = new Map(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1;
	_x = pLeft;
	_y = pTop;
}
_Game::_Game(int x, int y) {
	setX(x);
	setY(y);
}
int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard()
{
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue()
{
	ConsoleManipulation::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
	return waitKeyBoard();
}
void _Game::startGame()
{
	system("cls");
	_b->resetData();
	_b->drawBoard();
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
	if (_turn == 1)
	{

		ConsoleManipulation:: textcolor(Red);
		//ConsoleManipulation::gotoXY(SIZE * 4 + 32, 26);
		//cout << " Den luot PLAYER 1 ";
		Textcolor(Red);
		//ConsoleManipulation::gotoXY(SIZE * 3 + 30, 4);
		Tro2();
	}
	else
	{

		//system("cls");
		Textcolor(Red);
		//ConsoleManipulation::gotoXY(SIZE * 4 + 32, 26);
		//cout << " Den luot PLAYER 2 ";
		Tro1();
	}
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 4);
	cout << _b->CountX;
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 14);
	cout << _b->CountY;
}
void _Game::exitGame()
{
	_loop = false;
}
void _Game::moveRight()
{
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		_x += 4;
		ConsoleManipulation::gotoXY(_x, _y);
	}
}

void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0))
	{
		_x -= 4;
		ConsoleManipulation::gotoXY(_x, _y);
	}
}
void P1WIN()
{
	AnTroChuot();
	int check = 1;
	Box();
	while (check < 30)
	{
		P1();
		Sleep(200);
		check++;
	}
}
void P2WIN()
{
	AnTroChuot();
	int check = 1;
	Box();
	while (check < 30)
	{
		P2();
		Sleep(200);
		check++;
	}
}
void PDraw()
{
	AnTroChuot();
	int check = 1;
	Box();
	while (check < 30)
	{
		Draw();
		Sleep(200);
		check++;
	}
}
void GoodJob();
void Good() {
	AnTroChuot();
	int check = 1;
	Box();
	while (check < 15)
	{
		Textcolor(rand() % 15 + 1);
		GoodJob();
		Sleep(170);
		check++;
	}
}

void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1))
	{
		_y += 2;
		ConsoleManipulation::gotoXY(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0))
	{
		_y -= 2;
		ConsoleManipulation::gotoXY(_x, _y);
	}
}

bool _Game::processCheckBoard()
{
	switch (_b->checkBoard(_x, _y, _turn))
	{
	case -1:
		Textcolor(Pink);
		cout << "X";
		Tro2();
		Textcolor(Red);
		ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 4);
		cout << _b->CountX;
		Textcolor(Red);
		ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 14);
		cout << _b->CountY;
		//ConsoleManipulation::gotoXY(SIZE * 4 + 32, 26);
		//cout << " Den luot PLAYER 2 ";


		ConsoleManipulation::gotoXY(_x, _y);
		break;
	case 1:
		Textcolor(Green);
		//Tro2();
		cout << "O";
		Tro1();
		Textcolor(Red);
		ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 4);
		cout << _b->CountX;
		//ConsoleManipulation::gotoXY(SIZE * 4 + 32, 26);
		//cout << " Den luot PLAYER 1 ";
		Textcolor(Red);
		ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 14);
		cout << _b->CountY;

		break;
	case 0:
		return false;
		break;
	}
	return true;
}

void _Game::XoaNuocCo(int &x,int &y) {
	setX(x);
	setY(y);
	


	ConsoleManipulation::gotoXY(x, y);
	_b->XoaCo(x, y);


	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 14);
	cout << _b->CountY;

	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 4);
	cout << _b->CountX;

	ConsoleManipulation::gotoXY(x, y);
	cout << " ";
	ConsoleManipulation::gotoXY(x, y);
	

	Sleep(100);


}

void _Game::Display(int x, int y) {
	setX(x);
	setY(y);

	_b->DisplayTheMove(x, y);
}

int _Game::DemNuocCoDaDi()
{
	return _b->CountX + _b->CountY;
}

void P1() {
	int i = 50, j = 13;
	ConsoleManipulation::gotoXY(i, j);    cout << "           __                     ___";
	ConsoleManipulation::gotoXY(i, j + 1); cout << "    ____  / /___ ___  _____  ____<  /";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 2); cout << "   / __ " << char(92) << "/ / __ `/ / / / _ " << char(92) << "/ ___/ / ";
	ConsoleManipulation::gotoXY(i, j + 3); cout << "  / /_/ / / /_/ / /_/ /  __/ /  / /  ";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 4); cout << " / .___/_/" << char(92) << "__,_/" << char(92) << "__, /" << char(92) << "___/_/  /_/ ";
	ConsoleManipulation::gotoXY(i, j + 5);  cout << "/_/            /____/              ";

	i = 40;
	j = 8;
	ConsoleManipulation::gotoXY(i, j + 12); cout << ".----------------.  .----------------.  .---------------- - .";
	ConsoleManipulation::gotoXY(i, j + 13); cout << "| .--------------. || .--------------. || .--------------. |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 14); cout << "| | _____  _____ | || |     _____    | || | ____  _____  | |";
	ConsoleManipulation::gotoXY(i, j + 15); cout << "| ||_   _||_   _|| || |    |_   _|   | || ||_   " << char(92) << "|_   _| | |";
	ConsoleManipulation::gotoXY(i, j + 16); cout << "| |  | | /" << char(92) << " | |  | || |      | |     | || |  |   " << char(92) << " | |   | |";
	ConsoleManipulation::gotoXY(i, j + 17); cout << "| |  | |/  " << char(92) << "| |  | || |      | |     | || |  | |" << char(92) << " " << char(92) << "| |   | |";
	ConsoleManipulation::gotoXY(i, j + 18); cout << "| |  |   /" << char(92) << "   |  | || |     _| |_    | || | _| |_" << char(92) << "   |_  | |";
	ConsoleManipulation::gotoXY(i, j + 19); cout << "| |  |__/  " << char(92) << "__|  | || |    |_____|   | || ||_____|" << char(92) << "____| | |";
	ConsoleManipulation::gotoXY(i, j + 20); cout << "| |              | || |              | || |              | |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 21); cout << "| '--------------' || '--------------' || '--------------' |";
	ConsoleManipulation::gotoXY(i, j + 22); cout << "'----------------'  '----------------'  '----------------'";
}

void P2() {
	int i = 50, j = 13;
	ConsoleManipulation::gotoXY(i, j);    cout << "           __                     ___ ";
	ConsoleManipulation::gotoXY(i, j + 1); cout << "    ____  / /___ ___  _____  ____|__ " << char(92) << "";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 2); cout << "   / __ " << char(92) << "/ / __ `/ / / / _ " << char(92) << "/ ___/_/ /";
	ConsoleManipulation::gotoXY(i, j + 3); cout << "  / /_/ / / /_/ / /_/ /  __/ /  / __/ ";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 4); cout << " / .___/_/" << char(92) << "__,_/" << char(92) << "__, /" << char(92) << "___/_/  /____/";
	ConsoleManipulation::gotoXY(i, j + 5);  cout << "/_/            /____/                ";


	i = 40;
	j = 8;
	ConsoleManipulation::gotoXY(i, j + 12); cout << ".----------------.  .----------------.  .---------------- - .";
	ConsoleManipulation::gotoXY(i, j + 13); cout << "| .--------------. || .--------------. || .--------------. |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 14); cout << "| | _____  _____ | || |     _____    | || | ____  _____  | |";
	ConsoleManipulation::gotoXY(i, j + 15); cout << "| ||_   _||_   _|| || |    |_   _|   | || ||_   " << char(92) << "|_   _| | |";
	ConsoleManipulation::gotoXY(i, j + 16); cout << "| |  | | /" << char(92) << " | |  | || |      | |     | || |  |   " << char(92) << " | |   | |";
	ConsoleManipulation::gotoXY(i, j + 17); cout << "| |  | |/  " << char(92) << "| |  | || |      | |     | || |  | |" << char(92) << " " << char(92) << "| |   | |";
	ConsoleManipulation::gotoXY(i, j + 18); cout << "| |  |   /" << char(92) << "   |  | || |     _| |_    | || | _| |_" << char(92) << "   |_  | |";
	ConsoleManipulation::gotoXY(i, j + 19); cout << "| |  |__/  " << char(92) << "__|  | || |    |_____|   | || ||_____|" << char(92) << "____| | |";
	ConsoleManipulation::gotoXY(i, j + 20); cout << "| |              | || |              | || |              | |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 21); cout << "| '--------------' || '--------------' || '--------------' |";
	ConsoleManipulation::gotoXY(i, j + 22); cout << "'----------------'  '----------------'  '----------------'";
}
void Draw()
{
	int i = 18, j = 10;
	ConsoleManipulation::gotoXY(i, j);     cout << " .----------------.  .----------------.  .----------------.  .----------------. ";
	ConsoleManipulation::gotoXY(i, j + 1); cout << "| .--------------. || .--------------. || .--------------. || .--------------. |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 2); cout << "| |  ________    | || |  _______     | || |      __      | || | _____  _____ | |";
	ConsoleManipulation::gotoXY(i, j + 3); cout << "| | |_   ___ `.  | || | |_   __  " << char(92) << "   | || |     /  " << char(92) << "     | || ||_   _||_   _|| |";
	ConsoleManipulation::gotoXY(i, j + 4); cout << "| |   | |   `. " << char(92) << " | || |   | |__) |   | || |    / /" << char(92) << " " << char(92) << "    | || |  | | /" << char(92) << " | |  | |";
	ConsoleManipulation::gotoXY(i, j + 5); cout << "| |   | |    | | | || |   |  __ /    | || |   / ____ " << char(92) << "   | || |  | |/  " << char(92) << "| |  | |";
	ConsoleManipulation::gotoXY(i, j + 6); cout << "| |  _| |___.' / | || |  _| |  " << char(92) << " " << char(92) << "_  | || | _/ /    " << char(92) << " " << char(92) << "_ | || |  |   /" << char(92) << "   |  | |";
	ConsoleManipulation::gotoXY(i, j + 7); cout << "| | |________.'  | || | |____| |___| | || ||____|  |____|| || |  |__/  " << char(92) << "__|  | |";
	ConsoleManipulation::gotoXY(i, j + 8); cout << "| |              | || |              | || |              | || |              | |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 9); cout << "| '--------------' || '--------------' || '--------------' || '--------------' |";
	ConsoleManipulation::gotoXY(i, j + 10); cout << " '----------------'  '----------------'  '----------------'  '----------------' ";
}

void GoodJob() {

	int i = 1, j = 1;
	ConsoleManipulation::gotoXY(i, j);     cout << "  .----------------. .----------------. .----------------. .----------------.   .----------------. .----------------. .----------------. ";
	ConsoleManipulation::gotoXY(i, j + 1); cout << "| .--------------. | .--------------. | .--------------. | .--------------. | | .--------------. | .--------------. | .--------------. |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 2); cout << "| |    ______    | | |     ____     | | |     ____     | | |  ________    | | | |     _____    | | |     ____     | | |   ______     | |";
	ConsoleManipulation::gotoXY(i, j + 3); cout << "| |  .' ___  |   | | |   .'    `.   | | |   .'    `.   | | | |_   ___ `.  | | | |    |_   _|   | | |   .'    `.   | | |  |_   _ " << char(92) << "    | |";
	ConsoleManipulation::gotoXY(i, j + 4); cout << "| | / .'  " << char(92) << " _|   | | |  /  .--.  " << char(92) << "  | | |  /  .--.  " << char(92) << "  | | |   | |   `. " << char(92) << " | | | |      | |     | | |  /  .--.  " << char(92) << "  | | |    | |_) |   | |";
	ConsoleManipulation::gotoXY(i, j + 5); cout << "| | | |    ____  | | |  | |    | |  | | |  | |    | |  | | |   | |    | | | | | |   _  | |     | | |  | |    | |  | | |    |  __'.   | |";
	ConsoleManipulation::gotoXY(i, j + 6); cout << "| | " << char(92) << " `.___]  _| | | |  " << char(92) << "  `--'  /  | | |  " << char(92) << "  `--'  /  | | |  _| |___.' / | | | |  | |_' |     | | |  " << char(92) << "  `--'  /  | | |   _| |__) |  | |";
	ConsoleManipulation::gotoXY(i, j + 7); cout << "| |  `._____.'   | | |   `.____.'   | | |   `.____.'   | | | |________.'  | | | |  `.___.'     | | |   `.____.'   | | |  |_______/   | |";
	Textcolor(rand() % 15 + 1);
	ConsoleManipulation::gotoXY(i, j + 8); cout << "| |              | | |              | | |              | | |              | | | |              | | |              | | |              | |";
	ConsoleManipulation::gotoXY(i, j + 9); cout << "| '--------------' | '--------------' | '--------------' | '--------------' | | '--------------' | '--------------' | '--------------' |";
	ConsoleManipulation::gotoXY(i, j + 10); cout << " '----------------' '----------------' '----------------' '----------------'   '----------------' '----------------' '----------------' ";



}

//void GoodJob() {
//	ifstream Good;
//	Good.open("Good.txt", ios::in);
//	//ConsoleManipulation::gotoXY(SIZE * 3 + 10, 4);
//	int i = 1,j=1;
//	while (!Good.eof())
//	{
//		Textcolor(rand() % 15 + 1);
//		ConsoleManipulation::gotoXY(i, j++);
//		string str1;
//		getline(Good, str1);
//
//		cout << str1 << endl;
//		Sleep(200);
//	}
//	Good.close();
//
//}


void Box()
{
	int i = 8, j = 8;
	ConsoleManipulation::gotoXY(i, j);
	//for (int i = 0; i < 110; i++) {
	//	Textcolor(rand() % 15 + 1);
	//	Sleep(1);
	//	cout << char(178);
	//}
	//ConsoleManipulation::gotoXY(i, j + 14);
	//for (int i = 0; i < 110; i++) {
	//	Textcolor(rand() % 15 + 1);
	//	Sleep(1);
	//	cout << char(178);
	//}
	Textcolor(Cyan);
	ConsoleManipulation::gotoXY(50+5, j + 20+5);
	cout << "Y   : Play Again";
	ConsoleManipulation::gotoXY(50+5, j + 21+5);
	cout << "ESC : BACK";
}
int _Game::processFinish(int x, int y)
{
	ConsoleManipulation::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int pWhoWin = _b->testBoard(x, y);
	switch (pWhoWin)
	{
	case -1:
		system("cls");
		//GoodJob();
		Good();
		P1WIN();
		break;
	case 1:
		system("cls");
		//GoodJob();
		Good();
		P2WIN();
		break;
	case 0:
		system("cls");
		PDraw();
		break;
	case 2:
		_turn = !_turn;
	}
	ConsoleManipulation::gotoXY(_x, _y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
int _Game::getXatEnter()
{
	return _x;
}
int _Game::getYatEnter()
{
	return _y;
}
void _Game::TimKiemNuocDi()
{
	_x = _b->Tim_Kiem_NuocDi_1().getX();
	_y = _b->Tim_Kiem_NuocDi_1().getY();
}
void _Game::TimKiemNuocDi2()
{
	_x = _b->Tim_Kiem_NuocDi_2().getX();
	_y = _b->Tim_Kiem_NuocDi_2().getY();
}
_Game::~_Game()
{
	delete _b;
}

//void _Game::SaveGame(int n)
//{
//	char data[30];
//	ofstream f1;
//	ofstream f2;
//	ConsoleManipulation::gotoXY(35, SIZE * 2 + 1);
//	cout << "ENTER FILE NAME: ";
//	Textcolor(Cyan);
//	cin.getline(data, 30);
//	f1.open(data, ios::out);
//	f2.open("Name.txt", ios::app);
//	f2 << data << " " << endl;
//	//thong tin
//	f1 << scorep1 << " " << scorep2 << " " << n << endl;
//	for (int i = 0; i < 16; i++)
//	{
//		for (int j = 0; j < 16; j++)
//		{
//			f1 << _b->get_Check(i, j) << " ";
//		}
//		f1 << endl;
//	}
//	f1.close();
//	f2.close();
//	ConsoleManipulation::gotoXY(35, SIZE * 2 + 2);
//	cout << "ESC : BACK";
//	int t = 1;
//	while (t)
//	{
//		if (_kbhit())
//		{
//			switch (_getch())
//			{
//			case 27:
//
//				t = 0;
//				system("cls");
//				ScreenStartGame(99);
//				break;
//			}
//		}
//	}
//}
void _Game::LoadGame(char data[30])
{

	//NHAP FILE
	ifstream f;
	//ifstream Tro1;
	f.open(data, ios::in);
	if (!f) {
		ConsoleManipulation::gotoXY(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
	}
	else
	{
		f >> scorep1 >> scorep2 >> chedo;
		system("cls");
		//thong tin
		//ban co
		int k;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				f >> k;
				_b->loadData(i, j, k);
			}
		}
		_x = _b->getXAt(0, 0);
		_y = _b->getYAt(0, 0);
		_b->drawBoard();
		f.close();
	}
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 4);
	cout << _b->CountX;
	Textcolor(Red);
	ConsoleManipulation::gotoXY(SIZE * 4 + 30 + 33, 14);
	cout << _b->CountY;
	if (_turn == 1)
	{
		Textcolor(Red);
		ConsoleManipulation::gotoXY(SIZE * 3 + 30, 4);
		Tro1();

	}
	else
	{
		Textcolor(Red);
		ConsoleManipulation::gotoXY(SIZE * 3 + 32, 26);
		Tro2();
		//cout << " Den luot PLAYER 2 ";
	}
	
}


