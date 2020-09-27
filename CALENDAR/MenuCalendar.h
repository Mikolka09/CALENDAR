#pragma once


#include "ListToDo.h"
#include "SaveLoadToDo.h"
#include "SearchToDo.h"
#include "ChangeToDo.h"
#include "Function.h"

static map <string, list<vector<ToDoParts*>>> base_to_do_;  //база данных напоминаний

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

	//создание напоминания
	void create_to_do()
	{
		if (!base_to_do_.empty())
			load_to_do();
		system("cls");
		draw();
		cout << endl;
		gotoxy(10, 5);
		SetColor(13, 0);
		cout << "\tСОЗДАНИЕ НАПОМИНАНИЯ\n" << endl;
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
						cout << "\tТакое Приоритет уже установлен! Попробуйте еще раз!" << endl;
						Sleep(2000);
						system("cls");
						string p;
						cout << "\n\n" << endl;
						SetColor(9, 0);
						cout << "\tВведите новый Приоритет (формат времени: чч.мм): ";
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

	//сохранение напоминания в файл
	void save_to_do()
	{
		save_.save_to_do(base_to_do_);
	}

	//загрузка напоминания из файла
	void load_to_do()
	{
		base_to_do_ = load_.load_to_do();
	}

	//сортировка списков напоминаний по Приоритету
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

	//вывод напоминания на экран
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

	//вывод напоминаия в файл
	void print_file()
	{
		load_to_do();
		system("cls");
		draw();
		gotoxy(10, 5);
		SetColor(13, 0);
		cout << "\tВЫВОД БАЗЫ В ФАЙЛ\n" << endl;
		SetColor(9, 0);
		cout << "\tВведите имя файла: ";
		string name;
		SetColor(15, 0);
		cin >> name;
		name += ".txt";
		ofstream out(name, ios::out);
		string S(80, '=');
		out << "\n\n";
		out << "\t\t\t\tСПИСОК НАПОМИНАНИЙ" << endl;
		out << S << endl;
		out << setw(15) << "ДАТА" << "    =" << setw(15) << "ТЕГ" << "    =" << setw(15)
			<< "ВРЕМЯ НАПОМ." << "    =" << setw(15) << "НАПОМИНАНИЕ" << "    =" << endl;
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
		cout << "\tНапоминания напечатаны в файл!!!" << endl;
		Sleep(2000);
	}
};

//вывод напоминания в файл
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
		SetColor(13, 0);
		cout << "\t\t\t\tСПИСОК НАПОМИНАНИЙ" << endl;
		SetColor(11, 0);
		cout << S << endl;
		cout << setw(15) << "ДАТА" << "    =" << setw(15) << "ТЕГ" << "    =" << setw(15)
			<< "ВРЕМЯ НАПОМ." << "    =" << setw(15) << "НАПОМИНАНИЕ" << "    =" << endl;
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

//посик напоминания
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

//редактирование напоминания
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

//фасад базы напоминаний
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

	//меню календаря
	void menu()
	{
		while (true)
		{
			create_to_do_->load_to_do();
			system("cls");
			draw();
			gotoxy(13, 5);
			SetColor(13, 0);
			cout << "МЕНЮ КАЛЕНДАРЯ\n" << endl;
			SetColor(9, 0);
			cout << "\t1. Создание напоминания\n" << "\t2. Изменение напоминания\n"
				<< "\t3. Поиск напоминания\n" << "\t4. Печать напоминания\n" << "\t5. Выход" << endl << endl;
			SetColor(12, 0);
			cout << "\tВаш выбор: ";
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
				SetColor(13, 0);
				cout << "ПЕЧАТАТЬ НАПОМИНАНИЯ:\n" << endl;
				SetColor(9, 0);
				cout << "\t1. В ФАЙЛ\n" << "\t2. НА ЭКРАН\n" << "\t3. Выход\n" << endl;
				SetColor(12, 0);
				cout << "\tВаш вариант: ";
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
				case 3:
					menu();
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
