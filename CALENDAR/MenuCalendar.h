#pragma once


#include "ListToDo.h"
#include "SaveLoadToDo.h"
#include "SearchToDo.h"
#include "ChangeToDo.h"
#include "Function.h"

static map <string, list<vector<ToDoParts*>>> base_to_do_;

class CreateToDo
{
	Create* create_;
	ListToDoBuilder* ltd_;
	ListToDo* list_;
	SaveToDo save_;
	LoadToDo load_;

public:

	map <string, list<vector<ToDoParts*>>> get_base_to_do() { return base_to_do_; }
	void set_base_to_do(map <string, list<vector<ToDoParts*>>> base) { base_to_do_ = base; }

	void create_to_do()
	{
		if (!base_to_do_.empty())
			load_to_do();
		system("cls");
		draw();
		cout << endl;
		gotoxy(10, 4);
		SetColor(12, 0);
		cout << "\tÑÎÇÄÀÍÈÅ ÍÀÏÎÌÈÍÀÍÈß\n" << endl;
		SetColor(9, 0);
		create_ = new Create;
		ltd_ = new ListToDoBuilder;
		create_->set_builder(ltd_);
		create_->create();
		list_ = ltd_->get_result();
		string key = list_->get_list_to_do().front().front()->ToString().c_str();
		if (base_to_do_.empty())
			base_to_do_.insert(make_pair(key, list_->get_list_to_do()));
		else if (!base_to_do_.empty())
		{
			if (base_to_do_.count(key))
			{
				auto it = base_to_do_.find(key);
				bool good = true;
				while (good)
				{
					int count = 0;
					auto it2 = (*it).second.begin();
					for (; it2 != (*it).second.end(); it2++)
					{
						if ((*it2)[2]->get() == list_->get_list_to_do().front()[2]->get())
							count++;
					}
					if (count > 0)
					{
						system("cls");
						cout << "\n\n" << endl;
						SetColor(12, 0);
						cout << "\tÒàêîå Ïðèîðèòåò óæå óñòàíîâëåí! Ïîïðîáóéòå åùå ðàç!" << endl;
						Sleep(2000);
						system("cls");
						string p;
						cout << "\n\n" << endl;
						SetColor(9, 0);
						cout << "\tÂâåäèòå íîâûé Ïðèîðèòåò (ôîðìàò âðåìåíè: ÷÷.ìì): ";
						cin >> p;
						list_->get_list_to_do().front()[2]->set(p);
						good = true;
					}
					else if (count == 0)
					{
						(*it).second.push_back(list_->get_list_to_do().front());
						good = false;
					}
				}
			}
			else
				base_to_do_.insert(make_pair(key, list_->get_list_to_do()));
		}
		sort_base(base_to_do_);
		save_to_do();
	}
	void save_to_do()
	{
		save_.save_to_do(base_to_do_);
	}
	void load_to_do()
	{
		base_to_do_ = load_.load_to_do();
	}
	void sort_base(map <string, list<vector<ToDoParts*>>>& base)
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
						if ((*it2).at(2)->get() > (*it3).at(2)->get())
							iter_swap(it2, it3);
					}
				}
			}
		}
	}
	void print()
	{
		load_to_do();
		sort_base(base_to_do_);
		string D(80, '-');
		auto it = base_to_do_.begin();
		for (; it != base_to_do_.end(); it++)
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
		SetColor(15, 0);
		cout << endl;
	}
	void print_file()
	{
		load_to_do();
		system("cls");
		draw();
		cout << "\n\n" << endl;
		SetColor(9, 0);
		cout << "\tÂâåäèòå èìÿ ôàéëà: ";
		string name;
		SetColor(15, 0);
		cin >> name;
		name += ".txt";
		ofstream out(name, ios::out);
		string S(80, '=');
		out << "\n\n";
		out << "\t\t\t\tÑÏÈÑÎÊ ÍÀÏÎÌÈÍÀÍÈÉ" << endl;
		out << S << endl;
		out << setw(15) << "ÄÀÒÀ" << "    =" << setw(15) << "ÒÅÃ" << "    =" << setw(15)
			<< "ÂÐÅÌß ÍÀÏÎÌ." << "    =" << setw(15) << "ÍÀÏÎÌÈÍÀÍÈÅ" << "    =" << endl;
		out << S << endl;
		string D(80, '-');
		auto it = base_to_do_.begin();
		for (; it != base_to_do_.end(); it++)
		{
			auto it2 = (*it).second.begin();
			for (; it2 != (*it).second.end(); it2++)
			{
				auto it3 = (*it2).begin();
				for (; it3 != (*it2).end(); it3++)
				{
					out << setw(15) << (*it3)->ToString() << "    =";
				}
				out << endl;
			}
			out << D << endl;
		}
		out.close();
		cout << "\n\n" << endl;
		SetColor(12, 0);
		cout << "\tÍàïîìèíàíèÿ íàïå÷àòàíû â ôàéë!!!" << endl;
		Sleep(2000);
	}
};


class PrintToFile
{
	CreateToDo* cr_to_;
public:
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
	void print()
	{
		shapka();
		cr_to_->print();
	}
	void print_file()
	{
		cr_to_->print_file();
	}
};

class SearchToDo
{
	SearchTo sr;
	CreateToDo cr;
public:
	void search_to()
	{
		cr.load_to_do();
		sr.searchToBase(base_to_do_);
	}
};

class ChangeToDo
{
	ChangeTo ch;
	CreateToDo cr;
public:
	void change_to_do()
	{
		ch.change_to(base_to_do_);
		cr.save_to_do();
	}
};

class CalendarFasade
{
	CreateToDo* create_to_do_;
	PrintToFile* print_to_file_;
	SearchToDo* search_to_do_;
	ChangeToDo* change_to_do_;
public:
	CalendarFasade()
	{
		create_to_do_ = new CreateToDo;
		print_to_file_ = new PrintToFile;
		search_to_do_ = new SearchToDo;
		change_to_do_ = new ChangeToDo;
	}

	void menu()
	{
		while (true)
		{
			create_to_do_->load_to_do();
			system("cls");
			draw();
			gotoxy(13, 5);
			SetColor(12, 0);
			cout << "ÌÅÍÞ ÊÀËÅÍÄÀÐß\n" << endl;
			SetColor(9, 0);
			cout << "\t1. Ñîçäàíèå íàïîìèíàíèÿ\n" << "\t2. Èçìåíåíèå íàïîìèíàíèÿ\n"
				<< "\t3. Ïîèñê íàïîìèíàíèÿ\n" << "\t4. Ïå÷àòü íàïîìèíàíèÿ\n" << "\t5. Âûõîä" << endl << endl;
			SetColor(12, 0);
			cout << "\tÂàø âûáîð: ";
			int var;
			SetColor(15, 0);
			cin >> var;
			switch (var)
			{
			case 1:
				create_to_do_->create_to_do();
				break;
			case 2:
				change_to_do_->change_to_do();
				break;
			case 3:
				search_to_do_->search_to();
				break;
			case 4:
			{
				system("cls");
				draw();
				gotoxy(8, 5);
				SetColor(12, 0);
				cout << "ÏÅ×ÀÒÀÒÜ ÍÀÏÎÌÈÍÀÍÈß:\n" << endl;
				SetColor(9, 0);
				cout << "\t1. Â ÔÀÉË\n" << "\t2. ÍÀ ÝÊÐÀÍ\n" << endl;
				SetColor(12, 0);
				cout << "\tÂàø âàðèàíò: ";
				int var1;
				SetColor(15, 0);
				cin >> var1;
				switch (var1)
				{
				case 1:
					print_to_file_->print_file();
					break;
				case 2:
					print_to_file_->print();
					system("pause");
					break;
				default:
					break;
				}
				break;
			}
			case 5:
				return;
			default:
				break;
			}
		}
	}
};
