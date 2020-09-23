#pragma once

#include<iostream>
#include <fstream>
#include<string>
#include<list>
#include <map>
#include <vector>
#include "SearchToDo.h"
#include "ChangeToDo.h"


using namespace std;

class SaveToDo
{

public:
	void static save_to_do(map <string, list<vector<ToDoParts*>>> base)
	{
		ofstream out("Base.bin", ios::binary | ios::out);
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
		cout << "Список напоминаний календаря сохранены!!!" << endl;
		Sleep(2000);
	}

	
};

class LoadToDo
{

public:
	
	map<string, list<vector<ToDoParts*>>> load_to_do()
	{
		ifstream in("Base.bin", ios::binary | ios::in);
		if (in.is_open())
		{
			map <string, list<vector<ToDoParts*>>> base;
			list<vector<ToDoParts*>> list;
			vector <ToDoParts*> vec;
			int len_base;
			in.read((char*)&len_base, sizeof(int));
			for (int i = 0; i < len_base; i++)
			{
				int len_list;
				in.read((char*)&len_list, sizeof(int));
				list.clear();
				for (int j = 0; j < len_list; j++)
				{
					int len_vec;
					in.read((char*)&len_vec, sizeof(int));
					vec.clear();
					for (int k = 0; k < len_vec; k++)
					{
						int len;
						in.read((char*)&len, sizeof(int));
						char* buff = new char[len + 1];
						in.read(buff, len);
						string d = buff;
						if (k == 0)
						{
							DateToDo* dt = new DateToDo;
							dt->set(d);
							vec.push_back(dt);
						}
						else if (k == 1)
						{
							TegToDo* dt = new TegToDo;
							dt->set(d);
							vec.push_back(dt);
						}
						else if (k == 2)
						{
							PriorityToDo* dt = new PriorityToDo;
							dt->set(d);
							vec.push_back(dt);
						}
						else
						{
							NameToDo* dt = new NameToDo;
							dt->set(d);
							vec.push_back(dt);
						}
						delete buff;
					}
					list.push_back(vec);
				}
				if (base.empty())
					base.insert(make_pair(list.front().front()->get().c_str(), list));
				else if (!base.empty())
				{
					string key = list.front().front()->ToString().c_str();
					if (base.count(key))
					{
						auto it = base.find(key);
						(*it).second.push_back(list.front());
					}
					else
						base.insert(make_pair(list.front().front()->get().c_str(), list));
				}
			}
			in.close();
			return base;
		}
		else
		{
			cout << "Файл не найден!!!" << endl;
			Sleep(2000);
			map <string, list<vector<ToDoParts*>>> base;
			return base;
			//exit(0);
		}

	}
	
};