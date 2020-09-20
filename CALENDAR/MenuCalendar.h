#pragma once

#include<iostream>
#include<string>
#include<list>
#include <map>
#include <iomanip>
#include "ListToDo.h"
#include "SaveLoadToDo.h"
#include "SearchToDo.h"
#include "ChangeToDo.h"

using namespace std;

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
		load_to_do();
		system("cls");
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
				(*it).second.push_back(list_->get_list_to_do().front());
			}
			else
				base_to_do_.insert(make_pair(key, list_->get_list_to_do()));
		}
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
	void print()
	{
		load_to_do();
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
		}
		string S(80, '=');
		cout << S << endl << endl;
	}
	void print_file()
	{
		load_to_do();
		system("cls");
		cout << "Ââåäèòå èìÿ ôàéëà: ";
		string name;
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
		}
		out << S << endl << endl;
		out.close();
		cout << "\n\n";
		cout << "Íàïîìèíàíèÿ íàïå÷àòàíû â ôàéë!!!" << endl;
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
		string S(80, '=');
		cout << "\n\n";
		cout << "\t\t\t\tÑÏÈÑÎÊ ÍÀÏÎÌÈÍÀÍÈÉ" << endl;
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
	void change_to()
	{
		cr.load_to_do();
		ch.change_to(base_to_do_);
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
			system("cls");
			cout << "ÌÅÍÞ ÊÀËÅÍÄÀÐß\n" << endl;
			cout << "1. Ñîçäàíèå íàïîìèíàíèÿ\n" << "2. Èçìåíåíèå íàïîìèíàíèÿ\n"
				<< "3. Ïîèñê íàïîìèíàíèÿ\n" << "4. Ïå÷àòü íàïîìèíàíèÿ\n" << "5. Âûõîä" << endl << endl;
			cout << "Âàø âûáîð: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				create_to_do_->create_to_do();
				break;
			case 2:
				change_to_do_->change_to();
				break;
			case 3:
				search_to_do_->search_to();
				break;
			case 4:
			{
				system("cls");
				cout << "ÏÅ×ÀÒÀÒÜ ÍÀÏÎÌÈÍÀÍÈß:\n" << endl;
				cout << "1. Â ÔÀÉË\n" << "2. ÍÀ ÝÊÐÀÍ\n" << endl;
				cout << "Âàø âàðèàíò: ";
				int var1;
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
