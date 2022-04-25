#ifndef GRAPHIC_H
#define GRAPHIC_H

#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

#define KEY_NONE -1

int whereX();
int whereY();
void setConsoleSize(int width, int height);
void resizeConsole(int width, int height);
void gotoXY(int x, int y);
void textColor(int color);
void textBgColor(int colorText, int colorBG);
void drawRectangleBorder(int positionX, int positionY, int width, int height, int color);
void drawRectangle(int positionX, int positionY, int width, int height, int color);
void titleLeft(int PosX, int PosY, string str, int color, int BgColor, int width, int height);
void titleMid(int PosX, int PosY, string str, int color, int BgColor, int width, int height);
void verticalLine(int PosX, int PosY, int Length, int TextColor, int BgColor);
void horizontalLine(int PosX, int PosY, int Length, int TextColor, int BgColor);
void nocursortype();
void yescursortype();

#endif
