#pragma once

#include<iostream>
#include<string>
#include<list>
#include <map>
#include <iomanip>

using namespace std;

class SearchTo
{

public:
	void searchToBase(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		cout << "����� �� ���� �����������:\n" << endl;
		cout << "1. ����� �� ����\n" << "2. ����� �� ���\n" << "3. ����� �� ����������(�����)\n" << "4. �����\n" << endl;
		cout << "��� �����: ";
		int var;
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

	void shapka()
	{
		system("cls");
		string S(80, '=');
		cout << "\n\n";
		cout << "\t\t\t\t������ �����������" << endl;
		cout << S << endl;
		cout << setw(15) << "����" << "    =" << setw(15) << "���" << "    =" << setw(15)
			<< "����� �����." << "    =" << setw(15) << "�����������" << "    =" << endl;
		cout << S << endl;
	}

	void searchToDate(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		string S(80, '=');
		cout << "\n" << endl;
		cout << "������� ����(������: ��.��.����): ";
		string date;
		cin >> date;
		if (base.count(date))
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
							cout << setw(15) << (*it3)->ToString() << "    =";
						}
						cout << endl;
					}
				}
				cout << S << endl;
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
						cout << setw(15) << (*it3)->ToString() << "    =";
					}
					cout << endl;
				}
				cout << S << endl;
			}
		}
	}

	void searchToTeg(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		string S(80, '=');
		cout << "\n" << endl;
		cout << "������� ���(������: ������): ";
		string date;
		cin >> date;
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
							cout << setw(15) << (*it4)->ToString() << "    =";
						}
						cout << endl;
					}
				}
			}
		}
		cout << S << endl;
	}

	void searchToPriority(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		string S(80, '=');
		cout << "\n" << endl;
		cout << "������� ���������(������ �������: ��.��): ";
		string date;
		cin >> date;
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
							cout << setw(15) << (*it4)->ToString() << "    =";
						}
						cout << endl;
					}
				}
			}
		}
		cout << S << endl;
	}

};
