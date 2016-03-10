#include "UserInterface.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

UserInterface::UserInterface()
{
}

void UserInterface::gotoxy(short x, short y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void UserInterface::setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void UserInterface::resolution()
{
	// 콘솔창 설정
	system("title New World v1.0");
	system("mode con:cols=152 lines=42");

	gotoxy(1, 1); cout << "◎";
	gotoxy(149, 1); cout << "◎";
	gotoxy(1, 40); cout << "◎";
	gotoxy(149, 40); cout << "◎";
	for (int i = 2; i < 40; i++) {
		gotoxy(1, i); cout << "┃";
		gotoxy(149, i); cout << "┃";
	}
	for (int i = 3; i < 148; i += 2) {
		gotoxy(i, 1); cout << "━";
		gotoxy(i, 40); cout << "━";
	}
}

void UserInterface::copyright()
{
	setcolor(8, 0);
	gotoxy(4, 37); cout << "Created by LeeSangHyun on 16-03-10.";
	gotoxy(4, 38); cout << "Copyright Devnuri. All rights reserved.";
}

void UserInterface::gametitle()
{
	setcolor(8, 0);
	gotoxy(60, 4); cout << "┏";
	for (int i = 62; i < 89; i += 2) {
		gotoxy(i, 4); cout << "─";
		gotoxy(i, 10); cout << "─";
	}
	gotoxy(90, 4); cout << "┓";
	for (int i = 5; i < 10; i++) {
		gotoxy(60, i); cout << "│";
		gotoxy(90, i); cout << "│";
	}
	gotoxy(60, 10); cout << "┗";
	gotoxy(90, 10); cout << "┛";
	setcolor(10, 0);
	gotoxy(73, 6); cout << "N E W";
	setcolor(14, 0);
	gotoxy(71, 8); cout << "W O R L D";
}

void UserInterface::gamebutton()
{
	setcolor(8, 0);
	gotoxy(55, 15); cout << "┏";
	for (int i = 57; i < 96; i += 2) {
		gotoxy(i, 15); cout << "─";
		gotoxy(i, 24); cout << "─";
	}
	gotoxy(95, 15); cout << "┓";
	for (int i = 16; i < 24; i++) {
		gotoxy(55, i); cout << "│";
		gotoxy(95, i); cout << "│";
	}
	gotoxy(55, 24); cout << "┗";
	gotoxy(95, 24); cout << "┛";
	setcolor(15, 0);
	gotoxy(70, 18); cout << "게  임  시  작";
	gotoxy(70, 21); cout << "게  임  종  료";
}

void UserInterface::controlcursor()
{
	int key;

	setcolor(11, 0);
	gotoxy(65, 18); cout << "▶";

	while (1) {
		if (_kbhit()) {
			if (_getch() == 224) {
				key = _getch();
				if (key == UP) {
					gotoxy(65, 21); cout << " ";
					gotoxy(65, 18); cout << "▶";
					if (_getch() == ENTER) {
						system("cls");
						createview();
					}
					else
						key = DOWN;
				}
				if (key == DOWN) {
					gotoxy(65, 18); cout << " ";
					gotoxy(65, 21); cout << "▶";
					if (_getch() == ENTER)
						exit(-1);
					else
						key = UP;
				}
			}
		}
	}
}

void UserInterface::mainView()
{
	resolution();
	gametitle();
	gamebutton();
	copyright();
	controlcursor();
}

void UserInterface::createview()
{
	setcolor(7, 0);
	resolution();
}
