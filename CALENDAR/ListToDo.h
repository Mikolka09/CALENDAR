#pragma once

#include<iostream>
#include<string>
#include<map>
#include<list>

using namespace std;

class ToDoParts
{
public:
	virtual string ToString() = 0;
};

class DateToDo : public ToDoParts
{
	string date_;
public:
	string getData() { return date_; }
	string ToString() override
	{
		cout << " ¬ведите дату выполнени€ дела: ";
		cin >> date_;
		return date_;
	}
};

class PriorityToDo : public ToDoParts
{
	string priority_;
public:
	string ToString() override
	{
		cout << " ¬ведите приоритет (врем€ выполнени€): ";
		cin >> priority_;
		return priority_;
	}
};

class NameToDo : public ToDoParts
{
	string name_;
public:
	string ToString() override
	{
		cout << " ¬ведите наименование дела: ";
		char buff[1200];
		cin.getline(buff, 1200);
		char* name = new char[strlen(buff) + 1];
		strcpy(name, buff);
		name_ = name;
		delete[] name;
		return name_;
	}
};

class ListToDoBuilder;

class ListToDo
{
	list<ToDoParts*> list_to_do_;
	
public:
	list<ToDoParts*> get_list_to_do() { return list_to_do_; }
	void set_list_to_do(list<ToDoParts*> l) { list_to_do_ = l; }

	/*void print()
	{
		ListToDoBuilder ltd;
		auto it = ltd.get_base_to_do().begin();
		for (; it != ltd.get_base_to_do().end(); it++)
		{
			auto iter = (*it).second.begin();
			for (; iter != (*it).second.end(); iter++)
			{
				cout << (*iter)->ToString();
			}
		}
	}*/
	
};

class Builder
{
public:
	virtual ~Builder(){}
	virtual void create_date_to_do() const  = 0;
	virtual void create_priority_to_do() const = 0;
	virtual void create_name_to_do() const = 0;
	virtual void create_base_to_do() = 0;
};

class ListToDoBuilder : public Builder
{
	ListToDo* list_;
	map<string, list<ToDoParts*>> base_to_do_;
public:
	
	ListToDoBuilder() { reset(); }
	map<string, list<ToDoParts*>> get_base_to_do(){return base_to_do_;}
	void reset()
	{
		if (list_)
			delete list_;
		list_ = new ListToDo;
	}
	void create_date_to_do() const override
	{
		list_->get_list_to_do().push_back(new DateToDo);
	}
	void create_priority_to_do() const override
	{
		list_->get_list_to_do().push_back(new PriorityToDo);
	}
	void create_name_to_do() const override
	{
		list_->get_list_to_do().push_back(new NameToDo);
	}
	ListToDo* get_result()
	{
		ListToDo* result = list_;
		list_ = nullptr;
		return result;
	}
	void create_base_to_do() override
	{
		list<ToDoParts*> td = get_result()->get_list_to_do();
		ToDoParts* tdp;
		tdp = td.front();
		string data = get_result()->get_list_to_do().front()->ToString().c_str();
		if (base_to_do_.count(data))
		{
			auto it = base_to_do_.find(data);
			(*it).second.push_back(tdp);
		}
		else
		{
			list_->get_list_to_do().push_back(tdp);
			base_to_do_.insert(make_pair(data, list_->get_list_to_do()));
		}
	}
};

class Create
{
	Builder* builder;
public:
	void set_builder(Builder* builder) { this->builder = builder; }
	void create()
	{
		builder->create_date_to_do();
		builder->create_priority_to_do();
		builder->create_name_to_do();
		builder->create_base_to_do();
	}
};
