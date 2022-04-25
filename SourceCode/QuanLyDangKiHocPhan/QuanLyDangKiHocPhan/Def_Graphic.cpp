#include "Graphic.h"

//vi tri con tro x
int whereX() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}

//vi tri con tro y
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

void setConsoleSize(int width, int height)
{
	HANDLE hOut;
	SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DisplayArea.Right = width;
	DisplayArea.Bottom = height;

	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}

//
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

//dua con tro den toa do (x, y) tren console
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//mau chu nen den
void textColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//mau chu nen tuy chon
void textBgColor(int colorText, int colorBG)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (colorBG << 4) | colorText);
}

//ve khung hinh chu nhat
void drawRectangleBorder(int positionX, int positionY, int width, int height, int color)
{
	textBgColor(0, color);
	for (int x = 0; x < width; x++)
	{
		gotoXY(positionX + x, positionY);
		cout << " ";
		gotoXY(positionX + x, positionY + height - 1);
		cout << " ";
	}
	for (int y = 0; y < height; y++)
	{
		gotoXY(positionX, positionY + y);
		cout << " ";
		gotoXY(positionX + width - 1, positionY + y);
		cout << " ";
	}
}

//ve hinh chu nhat
void drawRectangle(int positionX, int positionY, int width, int height, int color)
{
	textBgColor(0, color);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			gotoXY(positionX + x, positionY + y);
			cout << " ";
		}
	}
}

//khung chu can trai
void titleLeft(int PosX, int PosY, string str, int color, int BgColor, int width, int height)
{
	drawRectangle(PosX, PosY, width, height, BgColor);
	gotoXY(PosX + 1, PosY + height / 2);
	textBgColor(color, BgColor);
	cout << str;
}

//khung chu can giua
void titleMid(int PosX, int PosY, string str, int color, int BgColor, int width, int height)
{
	drawRectangle(PosX, PosY, width, height, BgColor);
	gotoXY(PosX + width / 2 - str.length() / 2, PosY + height / 2);
	textBgColor(color, BgColor);
	cout << str;
}

void verticalLine(int PosX, int PosY, int Length, int TextColor, int BgColor)
{
	textBgColor(TextColor, BgColor);
	for (int i = PosY; i < PosY + Length; i++)
	{
		gotoXY(PosX, i);
		cout << char(179);
	}
}

void horizontalLine(int PosX, int PosY, int Length, int TextColor, int BgColor)
{
	textBgColor(TextColor, BgColor);
	for (int i = PosX; i < PosX + Length; i++)
	{
		gotoXY(i, PosY);
		cout << char(196);
	}
}

//an dau nhay
void nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

//hiện dấu nháy
void yescursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

