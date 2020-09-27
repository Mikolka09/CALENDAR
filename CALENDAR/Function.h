#pragma once

#include <algorithm>
#include<iostream>
#include<string>
#include<list>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <cstdlib>

using namespace std;

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};


enum Uprav { STOP = 0, UP, DOWN, LEFT, RIGHT, EXIT };

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void draw()
{
	SetColor(12, 0);
	gotoxy(10, 2);
	cout << "Ï Ð È Ë Î Æ Å Í È Å   Ê À Ë Å Í Ä À Ð Ü" << endl;
	gotoxy(10, 3);
	cout << "=======================================" << endl;
}