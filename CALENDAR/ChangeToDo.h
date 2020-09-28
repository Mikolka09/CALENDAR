#pragma once

#include "Function.h"

//�������������� �����������
class ChangeTo
{

public:
	map <string, list<vector<ToDoParts*>>> change_to(map <string, list<vector<ToDoParts*>>>& base)
	{
		system("cls");
		draw();
		gotoxy(10, 5);
		SetColor(13, 0);
		cout << "�������� �����������:\n" << endl;
		SetColor(9, 0);
		cout << "\t1. ������������� ����\n" << "\t2. ������������� ����\n" << "\t3. ������������� ���������(�����)\n"
			<< "\t4. ������������� ����� �����������\n" << "\t5. �������� �����������\n" << "\t6. �����\n" << endl;
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
		case 6:
			return base;
		default:
			break;
		}
		return base;
	}

	void static sort_base(map <string, list<vector<ToDoParts*>>>& base)
	{
		auto it = base.begin();
		for (; it != base.end(); it++)
		{
			auto it2 = (*it).second.begin();
			if ((*it).second.size() > 1)
			{
				for (; it2 != (*it).second.end(); it2++)
				{
					for (auto it3 = it2; it3 != (*it).second.end(); it3++)
					{
						setlocale(LC_NUMERIC, "C");
						if (atof((*it2).at(2)->get().c_str()) > atof((*it3).at(2)->get().c_str()))
						{
							iter_swap(it2, it3);
						}
					}
				}
			}
		}
	}

	//����� ���� ����������� �� �����
	void static print(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		sort_base(base);
		string S(92, '=');
		string D(92, '-');
		cout << "\n\n";
		SetColor(13, 0);
		cout << "\t\t\t\t������ �����������" << endl;
		SetColor(11, 0);
		cout << S << endl;
		cout << setw(18) << "���� (��.��.����)" << "    =" << setw(18) << "���" << "    =" << setw(18)
			<< "����� �����." << "    =" << setw(18) << "�����������" << "    =" << endl;
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
					cout << setw(18) << (*it3)->ToString() << "    =";
				}
				cout << endl;
			}
			cout << D << endl;
		}
		cout << endl << endl;
		SetColor(15, 0);
	}

	//�������������� ���� �����������
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
		else if (base.count(date))
		{
			cout << "\n" << endl;
			SetColor(9, 0);
			cout << "\t������� ���� ���� (������: ��.��.����): ";
			string new_date;
			SetColor(15, 0);
			cin >> new_date;
			list<vector<ToDoParts*>> list_to;
			if (base.count(new_date))
			{
				auto iter = base.find(date);
				if ((*iter).second.size() == 1)
				{
					auto it = (*iter).second.begin();
					list_to.push_back(*it);
					if (iter != base.cend())
						base.erase(iter);
					list_to.front()[0]->set(new_date);
					auto iter = base.find(new_date);
					bool good = true;
					while (good)
					{
						int count = 0;
						auto it = (*iter).second.begin();
						for (; it != (*iter).second.end(); it++)
						{
							if ((*it)[2]->get() == list_to.front()[2]->get())
								count++;
						}
						if (count > 0)
						{
							system("cls");
							draw();
							cout << endl;
							cout << "\n\n" << endl;
							SetColor(12, 0);
							cout << "\t����� ��������� ��� ����������! ���������� ��� ���!" << endl;
							Sleep(2000);
							system("cls");
							draw();
							cout << endl;
							gotoxy(10, 5);
							string p;
							cout << "\n\n" << endl;
							SetColor(9, 0);
							cout << "\t������� ����� ��������� (������ �������: ��.��): ";
							SetColor(15, 0);
							cin >> p;
							list_to.front()[2]->set(p);
							good = true;
						}
						else if (count == 0)
						{
							(*iter).second.push_back(list_to.front());
							good = false;
						}
					}
				}
				else
				{
					cout << "\n" << endl;
					SetColor(9, 0);
					cout << "\t������� ��������� (�����) ��� ��������� ����: ";
					string prio;
					SetColor(15, 0);
					cin >> prio;
					auto iter = base.find(date);
					auto it = (*iter).second.begin();
					for (; it != (*iter).second.end(); it++)
					{
						if ((*it)[0]->get() == date)
						{
							if ((*it)[2]->get() == prio)
							{
								list_to.push_back((*it));
								if (it != (*iter).second.end())
								{
									it = (*iter).second.erase(it);
									if (it == (*iter).second.end())
										advance(it, -1);
								}
							}
						}
					}
					auto iter1 = base.find(new_date);
					bool good = true;
					while (good)
					{
						int count = 0;
						auto it = (*iter1).second.begin();
						for (; it != (*iter1).second.end(); it++)
						{
							if ((*it)[2]->get() == list_to.front()[2]->get())
								count++;
						}
						if (count > 0)
						{
							system("cls");
							draw();
							cout << endl;
							cout << "\n\n" << endl;
							SetColor(12, 0);
							cout << "\t����� ��������� ��� ����������! ���������� ��� ���!" << endl;
							Sleep(2000);
							system("cls");
							draw();
							cout << endl;
							gotoxy(10, 5);
							string p;
							cout << "\n\n" << endl;
							SetColor(9, 0);
							cout << "\t������� ����� ��������� (������ �������: ��.��): ";
							SetColor(15, 0);
							cin >> p;
							list_to.front()[2]->set(p);
							good = true;
						}
						else if (count == 0)
						{
							list_to.front()[0]->set(new_date);
							(*iter1).second.push_back(list_to.front());
							good = false;
						}
					}
					
				}
			}
			else
			{

				auto iter = base.find(date);
				if ((*iter).second.size() == 1)
				{
					if (iter != base.cend())
					{
						if (base.find(new_date) == base.cend())
						{
							base[new_date] = iter->second;
							base.erase(iter);
						}
					}
					auto iter = base.find(new_date);
					auto it2 = (*iter).second.begin();
					if ((*it2)[0]->get() == date)
						(*it2)[0]->set(new_date);
				}
				else
				{
					cout << "\n" << endl;
					SetColor(9, 0);
					cout << "\t������� ��������� (�����) ��� ��������� ����: ";
					string prio;
					SetColor(15, 0);
					cin >> prio;
					auto iter = base.find(date);
					auto it = (*iter).second.begin();
					for (; it != (*iter).second.end(); it++)
					{
						if ((*it)[0]->get() == date)
						{
							if ((*it)[2]->get() == prio)
							{
								list_to.push_back((*it));
								if (it != (*iter).second.end())
								{
									it = (*iter).second.erase(it);
									if (it == (*iter).second.end())
										advance(it, -1);
								}
							}
						}
					}
					list_to.front()[0]->set(new_date);
					base.insert(make_pair(list_to.front()[0]->get(), list_to));
				}
			}
			cout << "\n" << endl;
			SetColor(12, 0);
			cout << "\t���� ����������� ��������!!!" << endl;
			Sleep(2000);
			system("cls");
			print(base);
			SetColor(15, 0);
			Sleep(4000);
			return base;
		}
		return base;
	}

	//�������������� ���� �����������
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

	//�������������� ���������� �����������
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

	//�������������� ������ �����������
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
			cout << "\t����� ���� ���!!! ���������� ��� ���!" << endl;
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

	//�������� �����������
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