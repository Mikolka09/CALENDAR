#pragma once

#include<iostream>
#include<string>
#include<list>
#include <map>
#include "ListToDo.h"
#include "SaveLoadToDo.h"
#include "SearchToDo.h"
#include "ChangeToDo.h"

using namespace std;
class SaveLoadToDo;

class CreateToDo
{
	Create* create_;
	ListToDoBuilder* ltd_;
	ListToDo* list_;
	map <string, list<vector<ToDoParts*>>> base_to_do_;
public:
	CreateToDo(){}
	map <string, list<vector<ToDoParts*>>> get_base_to_do() { return base_to_do_; }
	void set_base_to_do(map <string, list<vector<ToDoParts*>>> base) { base_to_do_= base; }
	CreateToDo (const CreateToDo& obj)
	{
		map <string, list<vector<ToDoParts*>>> base_to_;
		base_to_ = obj.base_to_do_;
		base_to_do_ = base_to_;
	}
	CreateToDo& operator=(const CreateToDo& obj)
	{
		map <string, list<vector<ToDoParts*>>> base_to_;
		base_to_ = obj.base_to_do_;
		base_to_do_ = base_to_;
		return *this;
	}
	void create_to_do()
	{
		system("cls"); 
		create_ = new Create;
		ltd_ = new ListToDoBuilder;
		create_->set_builder(ltd_);
		create_->create();
		list_ = ltd_->get_result();
		string key = list_->get_list_to_do().front().front()->ToString().c_str();
		if (base_to_do_.empty())
			base_to_do_.insert(make_pair(key, list_->get_list_to_do()));
		else if(!base_to_do_.empty())
		{
			if(base_to_do_.count(key))
			{
				auto it = base_to_do_.find(key);
				(*it).second.push_back(list_->get_list_to_do().front());
			}
			else
				base_to_do_.insert(make_pair(key, list_->get_list_to_do()));
		}
		
	}
	
};

class SaveLoadToDo
{
	SaveToDo* save_;
	LoadToDo* load_;
public:
	void save_to_do(map <string, list<vector<ToDoParts*>>> base)
	{
		save_->save_to_do(base);
	}

	void load_to_do()
	{
		map <string, list<vector<ToDoParts*>>> base;
		CreateToDo* cr = new CreateToDo;
		base = load_->load_to_do();
		cr->set_base_to_do(base);
	}
	
};

class SearchToDo
{

};

class ChangeToDo
{

};

class CalendarFasade
{
	CreateToDo* create_to_do_;
	SaveLoadToDo* save_load_to_do_;
	SearchToDo* search_to_do_;
	ChangeToDo* change_to_do_;
public:
	CalendarFasade()
	{
		create_to_do_ = new CreateToDo;
		save_load_to_do_ = new SaveLoadToDo;
		search_to_do_ = new SearchToDo;
		change_to_do_ = new ChangeToDo;
	}

	void menu()
	{
		while (true)
		{
			save_load_to_do_->load_to_do();
			system("cls");
			cout << "МЕНЮ КАЛЕНДАРЯ\n" << endl;
			cout << "1. Создание напоминания\n" << "2. Изменение напоминания\n"
				<< "3. Поиск напоминания\n" << "4. Сохранение напоминания в фаил\n" << "5. Выход" << endl << endl;
			cout << "Ваш выбор: ";
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
				create_to_do_->create_to_do();
				break;
			case 2:
				
				break;
			case 3:
				break;
			case 4:
				save_load_to_do_->save_to_do(create_to_do_->get_base_to_do());
				break;
			case 5:
				break;
			default:
				break;
			}
		}
	}
};
