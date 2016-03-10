#pragma once
class UserInterface
{
#define ENTER 13
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

public:
	UserInterface();

	void gotoxy(short x, short y);
	void setcolor(int color, int bgcolor);
	void mainView();
	void resolution();
	void copyright();
	void gametitle();
	void gamebutton();
	void controlcursor();
	void createview();
};

