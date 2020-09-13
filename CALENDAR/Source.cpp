#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"ListToDo.h"

using namespace std;


int main()
{
	setlocale(0, "");

	Create* create = new Create;
	ListToDoBuilder* ltd = new ListToDoBuilder;
	create->set_builder(ltd);
	create->create();
	ListToDo* list = ltd->get_result();
	//list->print();


	system("pause");
}