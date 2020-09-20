#pragma once

#include<iostream>
#include<string>
#include<list>
#include <vector>

using namespace std;

class ToDoParts
{
	
public:
	virtual string get() = 0;
	virtual void set(string st) = 0;
	virtual string ToString() = 0;
};

class DateToDo : public ToDoParts
{
	string date_;
public:
	string get() override { return date_; }
	void set(string st) override { date_ = st; }
	string ToString() override { return date_; }
};

class TegToDo : public ToDoParts
{
	string teg_;
public:
	string get() override { return teg_; }
	void set(string st) override { teg_ = st; }
	string ToString() override { return teg_; }
};

class PriorityToDo : public ToDoParts
{
	string priority_;
public:
	string get() override { return priority_; }
	void set(string st) override { priority_ = st; }
	string ToString() override { return priority_; }
};

class NameToDo : public ToDoParts
{
	string name_;
public:
	string get() override { return name_; }
	void set(string st) override { name_ = st; }
	string ToString() override { return name_; }
};


class ListToDo
{
	list<vector<ToDoParts*>> list_to_do_;

public:

	ListToDo() {}
	list<vector<ToDoParts*>> get_list_to_do() { return list_to_do_; }
	void set_list_to_do(list<vector<ToDoParts*>> l) { list_to_do_ = l; }
	ListToDo(const ListToDo& obj)
	{
		list<vector<ToDoParts*>> list_to;
		list_to = obj.list_to_do_;
		list_to_do_ = list_to;
	}
	ListToDo& operator=(const ListToDo& obj)
	{
		list<vector<ToDoParts*>> list_to;
		list_to = obj.list_to_do_;
		list_to_do_ = list_to;
		return *this;
	}
	void print()
	{
		system("cls");
		auto it = list_to_do_.begin();
		for (; it != list_to_do_.end(); it++)
		{
			auto it2 = (*it).begin();
			for(; it2!=(*it).end(); it2++)
			{
				cout << (*it2)->ToString() << "  ";
			}
		}
	}

};

class Builder
{
public:
	virtual ~Builder() {}
	virtual void create_date_to_do() = 0;
	virtual void create_teg_to_do() = 0;
	virtual void create_priority_to_do() = 0;
	virtual void create_name_to_do() = 0;

};

class ListToDoBuilder : public Builder
{
	vector<ToDoParts*> parts_;
	ListToDo* list_;
	list<vector<ToDoParts*>> list_to;
public:

	ListToDoBuilder() { reset(); }

	void reset()
	{
		if (list_)
			delete list_;
		list_ = new ListToDo;
	}
	void create_date_to_do() override
	{
		DateToDo* date = new DateToDo;
		string d;
		cout << " Введите дату выполнения дела: ";
		cin >> d;
		date->set(d);
		parts_.push_back(date);
	}
	void create_teg_to_do() override
	{
		TegToDo* teg = new TegToDo;
		string t;
		cout << " Введите Тег (символ): ";
		cin >> t;
		teg->set(t);
		parts_.push_back(teg);
	}
	void create_priority_to_do()  override
	{
		PriorityToDo* prior = new PriorityToDo;
		string p;
		cout << " Введите приоритет (время выполнения): ";
		cin >> p;
		prior->set(p);
		parts_.push_back(prior);
	}
	void create_name_to_do()  override
	{
		NameToDo* name_to = new NameToDo;
		string nm;
		cin.ignore();
		cout << " Введите наименование дела: ";
		char buff[1200];
		cin.getline(buff, 1200);
		char* name = new char[strlen(buff) + 1];
		strcpy(name, buff);
		nm = name;
		delete[] name;
		name_to->set(nm);
		parts_.push_back(name_to);
	}
	
	ListToDo* get_result()
	{
		list_to.push_back(parts_);
		list_->set_list_to_do(list_to);
		ListToDo* result = list_;
		list_ = nullptr;
		return result;
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
		builder->create_teg_to_do();
		builder->create_priority_to_do();
		builder->create_name_to_do();

	}
};
