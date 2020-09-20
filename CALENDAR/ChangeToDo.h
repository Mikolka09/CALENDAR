#pragma once

#include<iostream>
#include<string>
#include<list>
#include <map>
#include <iomanip>

using namespace std;

class ChangeTo
{
public:
	void change_to(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		cout << "РЕДАКТОР НАПОМИНАНИЙ:\n" << endl;
		cout << "1. Редактировать Дату\n" << "2. Редактировать Тег\n" << "3. Редактировать Приоритет(время)\n"
		<< "4. Редактировать текст напоминания\n" << "5. Выход\n" << endl;
		cout << "Ваш выбор: ";
		int var;
		cin >> var;
		switch (var)
		{
		case 1:
			changeToDate(base);
			system("pause");
			break;
		case 2:
			changeToTeg(base);
			system("pause");
			break;
		case 3:
			changeToPriority(base);
			system("pause");
			break;
		case 4:
			changeToName(base);
			system("pause");
			break;
		case 5:
			return;
			break;
		}
	}

	void changeToDate(map <string, list<vector<ToDoParts*>>> base)
	{
		
	}

	void changeToTeg(map <string, list<vector<ToDoParts*>>> base)
	{
		
	}

	void changeToPriority(map <string, list<vector<ToDoParts*>>> base)
	{
		
	}

	void changeToName(map <string, list<vector<ToDoParts*>>> base)
	{
		
	}
	
};