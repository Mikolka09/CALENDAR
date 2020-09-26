#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <Windows.h>
#include"MenuCalendar.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	SetColor(12, 0);
	cout << "\n\n\n" << endl;
	cout << "\t\tÏÐÈËÎÆÅÍÈÅ ÊÀËÅÍÄÀÐÜ\n" << endl;
	SetColor(9, 0);
	cout << "\t\t   Èäåò çàãðóçêà" << endl;
	cout << "\t\t   ";
	SetColor(10, 0);
	for (size_t i = 0; i < 13; i++)
	{
		cout << "#";
		Sleep(200);
	}
	CalendarFasade* calendar_ = new CalendarFasade;
	calendar_->menu();

	SetColor(15, 0);
	cout << endl;
	system("pause");
}