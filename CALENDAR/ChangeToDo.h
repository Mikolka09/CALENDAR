#pragma once

#include "Function.h"

class ChangeTo
{

public:
	map <string, list<vector<ToDoParts*>>> change_to(map <string, list<vector<ToDoParts*>>>& base)
	{
		system("cls");
		draw();
		gotoxy(10, 5);
		SetColor(12, 0);
		cout << "�������� �����������:\n" << endl;
		SetColor(9, 0);
		cout << "\t1. ������������� ����\n" << "\t2. ������������� ����\n" << "\t3. ������������� ���������(�����)\n"
			<< "\t4. ������������� ����� �����������\n" << "\t5. �������� �����������\n" << endl;
		SetColor(12, 0);
		cout << "\t��� �����: ";
		int var;
		SetColor(15, 0);
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
		draw();
		string S(80, '=');
		string D(80, '-');
		cout << "\n\n";
		SetColor(12, 0);
		cout << "\t\t\t\t������ �����������" << endl;
		SetColor(11, 0);
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
			cout << D << endl;
		}
		cout << endl << endl;
		SetColor(15, 0);
	}

	map <string, list<vector<ToDoParts*>>> changeToDate(map <string, list<vector<ToDoParts*>>>& base)
	{
		print(base);
		cout << "\n";
		SetColor(9, 0);
		cout << "\t�������� ���� ����������� ��� ��������������: ";
		string date;
		SetColor(15, 0);
		cin >> date;
		if (!base.count(date))
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\t����� ���� ���!!! ���������� ��� ���!" << endl;
			Sleep(2000);
			return base;
		}
		else
		{
			cout << "\n" << endl;
			SetColor(9, 0);
			cout << "\t������� ���� ���� (������: ��.��.����): ";
			string new_date;
			SetColor(15, 0);
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
				auto it = (*iter).second.begin();
				for (; it != (*iter).second.end(); it++)
				{
					(*it)[0]->set(new_date);
				}
			}
			cout << "\n" << endl;
			SetColor(15, 0);
			cout << "\t���� ����������� ��������!!!" << endl;
			Sleep(2000);
			system("cls");
			print(base);
			SetColor(15, 0);
			Sleep(4000);
			return base;
		}
	}

	map <string, list<vector<ToDoParts*>>> changeToTeg(map <string, list<vector<ToDoParts*>>>& base)
	{
		print(base);
		cout << "\n";
		SetColor(9, 0);
		cout << "\t�������� ���� ����������� ��� �������������� ����: ";
		string date;
		SetColor(15, 0);
		cin >> date;
		if (!base.count(date))
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\t����� ���� ���!!! ���������� ��� ���!" << endl;
			Sleep(2000);
			return base;
		}
		else
		{
			cout << "\n" << endl;
			SetColor(9, 0);
			cout << "\t������� ����� ��� (������, ��������): ";
			string new_teg;
			SetColor(15, 0);
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
				SetColor(9, 0);
				cout << "\t������� ��������� (�����) ��� ��������� ���� (������, ��������): ";
				string prio;
				SetColor(15, 0);
				cin >> prio;
				auto it = (*iter).second.begin();
				for (; it != (*iter).second.end(); it++)
				{
					if ((*it)[0]->get() == date)
					{
						if ((*it)[2]->get() == prio)
							(*it)[1]->set(new_teg);
					}
				}
			}
			cout << "\n" << endl;
			SetColor(12, 0);
			cout << "\t��� ����������� �������!!!" << endl;
			Sleep(2000);
			system("cls");
			print(base);
			SetColor(15, 0);
			Sleep(4000);
			return base;
		}
	}

	map <string, list<vector<ToDoParts*>>> changeToPriority(map <string, list<vector<ToDoParts*>>>& base)
	{
		print(base);
		cout << "\n";
		SetColor(9, 0);
		cout << "\t�������� ���� ����������� ��� �������������� ���������� (�������): ";
		string date;
		SetColor(15, 0);
		cin >> date;
		if (!base.count(date))
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\t����� ���� ���!!! ���������� ��� ���!" << endl;
			Sleep(2000);
			return base;
		}
		else
		{
			cout << "\n" << endl;
			SetColor(9, 0);
			cout << "\t������� ����� ��������� (������ �������: ��.��): ";
			string new_p;
			SetColor(15, 0);
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
				SetColor(9, 0);
				cout << "\t������� ��������� (�����), ������� ��������� ��������: ";
				string prio;
				SetColor(15, 0);
				cin >> prio;
				auto it = (*iter).second.begin();
				for (; it != (*iter).second.end(); it++)
				{
					if ((*it)[0]->get() == date)
					{
						if ((*it)[2]->get() == prio)
							(*it)[2]->set(new_p);
					}
				}
			}
			cout << "\n" << endl;
			SetColor(12, 0);
			cout << "\t��������� ����������� �������!!!" << endl;
			Sleep(2000);
			system("cls");
			print(base);
			SetColor(15, 0);
			Sleep(4000);
			return base;
		}
	}

	map <string, list<vector<ToDoParts*>>> changeToName(map <string, list<vector<ToDoParts*>>>& base)
	{
		print(base);
		cout << "\n";
		SetColor(9, 0);
		cout << "\t�������� ���� ����������� ��� �������������� ������ �����������: ";
		string date;
		SetColor(15, 0);
		cin >> date;
		if (!base.count(date))
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\t���� ���� ���!!! ���������� ��� ���!" << endl;
			Sleep(2000);
			return base;
		}
		else
		{
			cout << "\n" << endl;
			cin.ignore();
			SetColor(9, 0);
			cout << "\t������� ����� ����� �����������: ";
			string new_n;
			char buff[1200];
			SetColor(15, 0);
			cin.getline(buff, 1200);
			char* name = new char[strlen(buff) + 1];
			strcpy(name, buff);
			new_n = name;
			delete[] name;
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
				SetColor(9, 0);
				cout << "\t������� ��������� (�����) ��� ��������� ������ �����������: ";
				string prio;
				SetColor(15, 0);
				cin >> prio;
				auto it = (*iter).second.begin();

				for (; it != (*iter).second.end(); it++)
				{
					if ((*it)[0]->get() == date)
					{
						if ((*it)[2]->get() == prio)
							(*it)[3]->set(new_n);
					}
				}
			}
			cout << "\n" << endl;
			SetColor(12, 0);
			cout << "\t����� ����������� �������!!!" << endl;
			Sleep(2000);
			system("cls");
			print(base);
			SetColor(15, 0);
			Sleep(4000);
			return base;
		}
	}

	map <string, list<vector<ToDoParts*>>> deleteToDo(map <string, list<vector<ToDoParts*>>>& base)
	{
		print(base);
		cout << "\n";
		SetColor(9, 0);
		cout << "\t�������� ���� ����������� ��� ��������: ";
		string date;
		SetColor(15, 0);
		cin >> date;
		if (!base.count(date))
		{
			cout << endl;
			SetColor(12, 0);
			cout << "\t����� ���� ���!!! ���������� ��� ���!" << endl;
			Sleep(2000);
			return base;
		}
		else
		{
			auto iter = base.find(date);
			auto it2 = (*iter).second.begin();
			if ((*iter).second.size() == 1)
				base.erase(iter);
			else
			{
				cout << "\n" << endl;
				SetColor(9, 0);
				cout << "\t������� ��������� (�����) ��� �������� �����������: ";
				string prio;
				SetColor(15, 0);
				cin >> prio;
				auto it = (*iter).second.begin();
				for (; it != (*iter).second.end(); it++)
				{
					if ((*it)[0]->get() == date)
					{
						if ((*it)[2]->get() == prio)
						{
							if (it != (*iter).second.end())
							{
								it = (*iter).second.erase(it);
								if (it == (*iter).second.end())
									advance(it, -1);
							}
							
						}
					}
					
				}
			}
			cout << "\n" << endl;
			SetColor(12, 0);
			cout << "\t����������� �������!!!" << endl;
			Sleep(2000);
			system("cls");
			print(base);
			SetColor(15, 0);
			Sleep(4000);
			return base;
		}
	}

};