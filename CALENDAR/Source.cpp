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

	CalendarFasade* calendar_ = new CalendarFasade;
	calendar_->menu();

	cout << endl;
	system("pause");
}