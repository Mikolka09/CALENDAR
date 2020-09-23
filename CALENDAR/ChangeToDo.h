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
	map <string, list<vector<ToDoParts*>>> change_to(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		cout << "�������� �����������:\n" << endl;
		cout << "1. ������������� ����\n" << "2. ������������� ���\n" << "3. ������������� ���������(�����)\n"
			<< "4. ������������� ����� �����������\n" << "5. �������� �����������\n" << endl;
		cout << "��� �����: ";
		int var;
		cin >> var;
		switch (var)
		{
		case 1:
			changeToDate(base);
			return base;
		case 2:
			changeToTeg(base);
			return base;

		case 3:
			changeToPriority(base);
			return base;

		case 4:
			changeToName(base);
			return base;
		case 5:
			deleteToDo(base);
			return base;
		default:
			break;
		}
	}

	void static print(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		string S(80, '=');
		cout << "\n\n";
		cout << "\t\t\t\t������ �����������" << endl;
		cout << S << endl;
		cout << setw(15) << "����" << "    =" << setw(15) << "���" << "    =" << setw(15)
			<< "����� �����." << "    =" << setw(15) << "�����������" << "    =" << endl;
		cout << S << endl;
		auto it = base.begin();
		for (; it != base.end(); it++)
		{
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
		}
		cout << S << endl << endl;
	}

	map <string, list<vector<ToDoParts*>>> changeToDate(map <string, list<vector<ToDoParts*>>> base)
	{
		print(base);
		cout << "\n";
		cout << "�������� ���� ����������� ��� ��������������: ";
		string date;
		cin >> date;
		cout << "\n" << endl;
		cout << "������� ���� ����: ";
		string new_date;
		cin >> new_date;
		auto it = base.find(date);
		if (it != base.cend())
			if (base.find(new_date) == base.cend())
			{
				base[new_date] = it->second;
				base.erase(it);
			}
		auto iter = base.find(new_date);
		auto it2 = (*iter).second.begin();
		if ((*iter).second.size() == 1)
		{
			auto it3 = (*it2).begin();
			if ((*it3)->ToString().c_str() == date)
				(*it3)->set(new_date);
		}
		else
		{
			int i = 1;
			auto it = (*iter).second.begin();
			while (i != (*iter).second.size() + 1)
			{
				advance(it, (i - 1));
				(*it)[0]->set(new_date);
				i++;
			}
		}
		cout << "\n" << endl;
		cout << "���� ����������� ��������!!!" << endl;
		Sleep(2000);
		system("cls");
		print(base);
		Sleep(4000);
		return base;

	}

	map <string, list<vector<ToDoParts*>>> changeToTeg(map <string, list<vector<ToDoParts*>>> base)
	{
		print(base);
		cout << "\n";
		cout << "�������� ���� ����������� ��� �������������� ����: ";
		string date;
		cin >> date;
		cout << "\n" << endl;
		cout << "������� ����� ��� (������): ";
		string new_teg;
		cin >> new_teg;
		auto iter = base.find(date);
		auto it2 = (*iter).second.begin();
		if ((*iter).second.size() == 1)
		{
			auto it3 = (*it2).begin();
			if ((*it3)->get() == date)
			{
				advance(it3, 1);
				(*it3)->set(new_teg);
			}

		}
		else
		{
			cout << "\n" << endl;
			cout << "������� ��������� (�����) ��� ��������� ���� (������): ";
			string prio;
			cin >> prio;
			int i = 1;
			auto it = (*iter).second.begin();
			while (i != (*iter).second.size() + 1)
			{
				advance(it, (i - 1));
				auto it3 = (*it).begin();
				if ((*it3)->get() == date)
				{
					advance(it3, 2);
					if ((*it3)->get() == prio)
					{
						advance(it3, -1);
						(*it3)->set(new_teg);
					}

				}
				i++;
			}
		}
		cout << "\n" << endl;
		cout << "��� ����������� �������!!!" << endl;
		Sleep(2000);
		system("cls");
		print(base);
		Sleep(4000);
		return base;
	}

	map <string, list<vector<ToDoParts*>>> changeToPriority(map <string, list<vector<ToDoParts*>>> base)
	{
		print(base);
		cout << "\n";
		cout << "�������� ���� ����������� ��� �������������� ���������� (�������): ";
		string date;
		cin >> date;
		cout << "\n" << endl;
		cout << "������� ����� ��������� (�����): ";
		string new_p;
		cin >> new_p;
		auto iter = base.find(date);
		auto it2 = (*iter).second.begin();
		if ((*iter).second.size() == 1)
		{
			auto it3 = (*it2).begin();
			if ((*it3)->get() == date)
			{
				advance(it3, 2);
				(*it3)->set(new_p);
			}

		}
		else
		{
			cout << "\n" << endl;
			cout << "������� ��������� (�����), ������� ��������� ��������: ";
			string prio;
			cin >> prio;
			int i = 1;
			auto it = (*iter).second.begin();
			while (i != (*iter).second.size() + 1)
			{
				advance(it, (i - 1));
				auto it3 = (*it).begin();
				if ((*it3)->get() == date)
				{
					advance(it3, 2);
					if ((*it3)->get() == prio)
						(*it3)->set(new_p);
				}
				i++;
			}
		}
		cout << "\n" << endl;
		cout << "��������� ����������� �������!!!" << endl;
		Sleep(2000);
		system("cls");
		print(base);
		Sleep(4000);
		return base;
	}

	map <string, list<vector<ToDoParts*>>> changeToName(map <string, list<vector<ToDoParts*>>> base)
	{
		print(base);
		cout << "\n";
		cout << "�������� ���� ����������� ��� �������������� ������ �����������: ";
		string date;
		cin >> date;
		cout << "\n" << endl;
		cout << "������� ����� ����� �����������: ";
		string new_n;
		cin >> new_n;
		auto iter = base.find(date);
		auto it2 = (*iter).second.begin();
		if ((*iter).second.size() == 1)
		{
			auto it3 = (*it2).begin();
			if ((*it3)->get() == date)
			{
				advance(it3, 3);
				(*it3)->set(new_n);
			}

		}
		else
		{
			cout << "\n" << endl;
			cout << "������� ��������� (�����) ��� ��������� ������ �����������: ";
			string prio;
			cin >> prio;
			int i = 1;
			auto it = (*iter).second.begin();
			while (i != (*iter).second.size() + 1)
			{
				advance(it, (i - 1));
				auto it3 = (*it).begin();
				if ((*it3)->get() == date)
				{
					advance(it3, 2);
					if ((*it3)->get() == prio)
					{
						advance(it3, 1);
						(*it3)->set(new_n);
					}

				}
				i++;
			}
		}
		cout << "\n" << endl;
		cout << "����� ����������� �������!!!" << endl;
		Sleep(2000);
		system("cls");
		print(base);
		Sleep(4000);
		return base;
	}

	map <string, list<vector<ToDoParts*>>> deleteToDo(map <string, list<vector<ToDoParts*>>> base)
	{
		print(base);
		cout << "\n";
		cout << "�������� ���� ����������� ��� ��������: ";
		string date;
		cin >> date;
		auto iter = base.find(date);
		auto it2 = (*iter).second.begin();
		if ((*iter).second.size() == 1)
			base.erase(iter);
		else
		{
			cout << "\n" << endl;
			cout << "������� ��������� (�����) ��� �������� �����������: ";
			string prio;
			cin >> prio;
			int i = 1;
			auto it = (*iter).second.begin();
			while (i != (*iter).second.size() + 1)
			{
				advance(it, (i - 1));
				auto it3 = (*it).begin();
				if ((*it3)->get() == date)
				{
					advance(it3, 2);
					if ((*it3)->get() == prio)
					{
						(*iter).second.erase(it);
						i--;
					}
				}
				i++;
			}
		}
		cout << "\n" << endl;
		cout << "����������� �������!!!" << endl;
		Sleep(2000);
		system("cls");
		print(base);
		Sleep(4000);
		return base;
	}

};