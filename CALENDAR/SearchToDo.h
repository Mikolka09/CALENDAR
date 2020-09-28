#pragma once

#include "Function.h"

//поиск по базе напоминаний
class SearchTo
{

public:
	void searchToBase(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		gotoxy(10, 5);
		SetColor(12, 0);
		cout << "ПОИСК ПО БАЗЕ НАПОМИНАНИЙ:\n" << endl;
		SetColor(9, 0);
		cout << "\t1. Поиск по Дате\n" << "\t2. Поиск по ТЕГ\n" << "\t3. Поиск по Приоритету(время)\n" << "\t4. Выход\n" << endl;
		SetColor(12, 0);
		cout << "\tВаш выбор: ";
		int var;
		SetColor(15, 0);
		cin >> var;
		switch (var)
		{
		case 1:
			searchToDate(base);
			system("pause");
			break;
		case 2:
			searchToTeg(base);
			system("pause");
			break;
		case 3:
			searchToPriority(base);
			system("pause");
			break;
		case 4:
			return;
			break;
		}
	}

	//шапка вывода базы напоминаний
	void shapka()
	{
		system("cls");
		draw();
		string S(92, '=');
		cout << "\n\n";
		SetColor(13, 0);
		cout << "\t\t\t\tСПИСОК НАПОМИНАНИЙ" << endl;
		SetColor(11, 0);
		cout << S << endl;
		cout << setw(18) << "ДАТА (мм.дд.гггг)" << "    =" << setw(18) << "ТЕГ" << "    =" << setw(18)
			<< "ВРЕМЯ НАПОМ." << "    =" << setw(18) << "НАПОМИНАНИЕ" << "    =" << endl;
		cout << S << endl;
	}

	//поиск по Дате
	void searchToDate(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		string S(92, '=');
		gotoxy(10, 5);
		SetColor(13, 0);
		cout << "\tПОИСК ПО ДАТЕ\n" << endl;
		SetColor(9, 0);
		cout << "\tВведите дату (формат: мм.дд.гггг): ";
		string date;
		SetColor(15, 0);
		cin >> date;
		if (!base.count(date))
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\tТакой Даты НЕТ!!! Попробуйте еще раз!\n" << endl;
			Sleep(2000);
			SetColor(15, 0);
		}
		else
		{
			auto it = base.find(date);
			if ((*it).second.size() > 1)
			{
				shapka();
				auto it2 = (*it).second.begin();
				for (; it2 != (*it).second.end(); it2++)
				{
					auto it3 = (*it2).begin();
					if ((*it3)->ToString().c_str() == date)
					{
						for (; it3 != (*it2).end(); it3++)
						{
							cout << setw(18) << (*it3)->ToString() << "    =";
						}
						cout << endl;
					}
				}
				cout << S << endl << endl;
				SetColor(15, 0);
			}
			else
			{
				shapka();
				auto it2 = (*it).second.begin();
				for (; it2 != (*it).second.end(); it2++)
				{
					auto it3 = (*it2).begin();
					for (; it3 != (*it2).end(); it3++)
					{
						cout << setw(18) << (*it3)->ToString() << "    =";
					}
					cout << endl;
				}
				cout << S << endl << endl;
			}
			SetColor(15, 0);
		}
	}

	//посик по ТЕГ
	void searchToTeg(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		string S(92, '=');
		gotoxy(10, 5);
		SetColor(13, 0);
		cout << "\tПОИСК ПО ТЕГ\n" << endl;
		SetColor(9, 0);
		cout << "\tВведите ТЕГ (формат: важное, неважное): ";
		string date;
		SetColor(15, 0);
		cin >> date;
		int count = 0;
		auto it = base.begin();
		for (; it != base.end(); it++)
		{
			auto it2 = (*it).second.begin();
			for (; it2 != (*it).second.end(); it2++)
			{
				if ((*it2)[1]->get() == date)
					count++;
			}
		}
		if(count==0)
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\tТакого ТЕГА НЕТ!!! Попробуйте еще раз!\n" << endl;
			Sleep(2000);
			SetColor(15, 0);
		}
		else
		{
			shapka();
			auto it = base.begin();
			for (; it != base.end(); it++)
			{
				auto it2 = (*it).second.begin();
				for (; it2 != (*it).second.end(); it2++)
				{
					auto it3 = (*it2).begin();
					for (; it3 != (*it2).end(); it3++)
					{
						if ((*it3)->ToString().c_str() == date)
						{
							auto it4 = (*it2).begin();
							for (; it4 != (*it2).end(); it4++)
							{
								cout << setw(18) << (*it4)->ToString() << "    =";
							}
							cout << endl;
						}
					}
				}
			}
			cout << S << endl << endl;
			SetColor(15, 0);
		}
	}

	//поиск по Приоритету
	void searchToPriority(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		string S(92, '=');
		gotoxy(10, 5);
		SetColor(13, 0);
		cout << "\tПОИСК ПО ПРИОРИТЕТУ\n" << endl;
		SetColor(9, 0);
		cout << "\tВведите Приоритет (формат времени: чч.мм): ";
		string date;
		SetColor(15, 0);
		cin >> date;
		int count = 0;
		auto it = base.begin();
		for (; it != base.end(); it++)
		{
			auto it2 = (*it).second.begin();
			for (; it2 != (*it).second.end(); it2++)
			{
				if ((*it2)[2]->get() == date)
					count++;
			}
		}
		if (count == 0)
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\tТакого Приоритета НЕТ!!! Попробуйте еще раз!\n" << endl;
			Sleep(2000);
			SetColor(15, 0);
		}
		else
		{
			shapka();
			auto it = base.begin();
			for (; it != base.end(); it++)
			{
				auto it2 = (*it).second.begin();
				for (; it2 != (*it).second.end(); it2++)
				{
					auto it3 = (*it2).begin();
					for (; it3 != (*it2).end(); it3++)
					{
						if ((*it3)->ToString().c_str() == date)
						{
							auto it4 = (*it2).begin();
							for (; it4 != (*it2).end(); it4++)
							{
								cout << setw(18) << (*it4)->ToString() << "    =";
							}
							cout << endl;
						}
					}
				}
			}
			cout << S << endl << endl;
			SetColor(15, 0);
		}
	}

};
