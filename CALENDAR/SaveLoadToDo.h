#pragma once

#include<iostream>
#include <fstream>
#include<string>
#include<list>
#include <map>
#include<iomanip>
#include <vector>
#include "SearchToDo.h"
#include "ChangeToDo.h"
#include "MenuCalendar.h"

using namespace std;

class SaveToDo
{

public:
	void save_to_do(map <string, list<vector<ToDoParts*>>> base)
	{
		system("cls");
		cout << "¬ведите название файла: ";
		string name;
		cin >> name;
		name = name + ".bin";
		ofstream out(name, ios::binary | ios::out);
		int len_base = base.size();
		out.write((char*)&len_base, sizeof(int));
		auto it = base.begin();
		for (; it != base.end(); it++)
		{
			int len_list = (*it).second.size();
			out.write((char*)&len_list, sizeof(int));
			auto it2 = (*it).second.begin();
			for (; it2 != (*it).second.end(); it2++)
			{
				int len_vec = (*it2).size();
				out.write((char*)&len_vec, sizeof(int));
				auto it3 = (*it2).begin();
				for (; it3 != (*it2).end(); it3++)
				{
					int len = (*it3)->get().size() + 1;
					out.write((char*)&len, sizeof(int));
					out.write((char*)(*it3)->get().c_str(), len);
				}
			}
		}
		out.close();
		cout << endl;
		cout << "—писок напоминаний календар€ сохранены!!!" << endl;
		Sleep(2000);
	}
};

class LoadToDo
{
public:

	map <string, list<vector<ToDoParts*>>> load_to_do()
	{
		system("cls");
		cout << "¬ведите название файла: ";
		string name;
		cin >> name;
		name = name + ".bin";
		ifstream in(name, ios::binary | ios::in);
		if (in.is_open())
		{
			map <string, list<vector<ToDoParts*>>> base;
			list<vector<ToDoParts*>> list_;
			vector <ToDoParts*> vec;
			int len_base;
			in.read((char*)&len_base, sizeof(int));
			for (int i = 0; i < len_base; i++)
			{
				int len_list;
				in.read((char*)&len_list, sizeof(int));
				for (int j = 0; j < len_list; j++)
				{
					int len_vec;
					in.read((char*)&len_vec, sizeof(int));
					for (int k=0; k<len_vec; k++)
					{
						if (k == 0)
						{
							DateToDo* dt = new DateToDo;
							int len;
							in.read((char*)&len, sizeof(int));
							char* buff = new char[len + 1];
							in.read(buff, len);
							string d = buff;
							dt->set(d);
							vec.push_back(dt);
							delete buff;
						}
						else if(k==1)
						{
							TegToDo* dt = new TegToDo;
							int len;
							in.read((char*)&len, sizeof(int));
							char* buff = new char[len + 1];
							in.read(buff, len);
							string d = buff;
							dt->set(d);
							vec.push_back(dt);
							delete buff;
						}
						else if(k==2)
						{
							PriorityToDo* dt = new PriorityToDo;
							int len;
							in.read((char*)&len, sizeof(int));
							char* buff = new char[len + 1];
							in.read(buff, len);
							string d = buff;
							dt->set(d);
							vec.push_back(dt);
							delete buff;
						}
						else
						{
							NameToDo* dt = new NameToDo;
							int len;
							in.read((char*)&len, sizeof(int));
							char* buff = new char[len + 1];
							in.read(buff, len);
							string d = buff;
							dt->set(d);
							vec.push_back(dt);
							delete buff;
						}

					}
					list_.push_back(vec);
				}
				base.insert(make_pair(list_.front().front()->get().c_str(), list_));
			}
			in.close();
			return base;
		}
		else
		{
			cout << "‘айл не найден!!!" << endl;
			Sleep(2000);
		}

	}
};