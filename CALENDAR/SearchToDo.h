#pragma once

#include "Function.h"

class SearchTo
{

public:
	void searchToBase(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		gotoxy(10, 5);
		SetColor(12, 0);
		cout << "ÏÎÈÑÊ ÏÎ ÁÀÇÅ ÍÀÏÎÌÈÍÀÍÈÉ:\n" << endl;
		SetColor(9, 0);
		cout << "\t1. Ïîèñê ïî Äàòå\n" << "\t2. Ïîèñê ïî ÒÅÃ\n" << "\t3. Ïîèñê ïî Ïðèîðèòåòó(âðåìÿ)\n" << "\t4. Âûõîä\n" << endl;
		SetColor(12, 0);
		cout << "\tÂàø âûáîð: ";
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

	void shapka()
	{
		system("cls");
		draw();
		string S(80, '=');
		cout << "\n\n";
		SetColor(12, 0);
		cout << "\t\t\t\tÑÏÈÑÎÊ ÍÀÏÎÌÈÍÀÍÈÉ" << endl;
		SetColor(11, 0);
		cout << S << endl;
		cout << setw(15) << "ÄÀÒÀ" << "    =" << setw(15) << "ÒÅÃ" << "    =" << setw(15)
			<< "ÂÐÅÌß ÍÀÏÎÌ." << "    =" << setw(15) << "ÍÀÏÎÌÈÍÀÍÈÅ" << "    =" << endl;
		cout << S << endl;
	}

	void searchToDate(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		string S(80, '=');
		cout << "\n" << endl;
		SetColor(9, 0);
		cout << "\tÂâåäèòå äàòó(ôîðìàò: ää.ìì.ãããã): ";
		string date;
		SetColor(15, 0);
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
						cout << setw(15) << (*it3)->ToString() << "    =";
					}
					cout << endl;
				}
				cout << S << endl << endl;
			}
			SetColor(15, 0);
		}
	}

	void searchToTeg(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		string S(80, '=');
		cout << "\n" << endl;
		SetColor(9, 0);
		cout << "\tÂâåäèòå ÒÅÃ(ôîðìàò: âàæíîå, íåâàæíîå): ";
		string date;
		SetColor(15, 0);
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
		cout << S << endl << endl;
		SetColor(15, 0);
	}

	void searchToPriority(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		draw();
		string S(80, '=');
		cout << "\n" << endl;
		SetColor(9, 0);
		cout << "\tÂâåäèòå Ïðèîðèòåò(ôîðìàò âðåìåíè: ÷÷.ìì): ";
		string date;
		SetColor(15, 0);
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
		cout << S << endl << endl;
		SetColor(15, 0);
	}

};
