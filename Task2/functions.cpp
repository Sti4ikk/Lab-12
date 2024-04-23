#include <iostream>
#include <fstream>
#include <vector>
#include "structs.h"
#include <conio.h>
#include "prototypes.h"
#include <string>


void main_menu(std::vector<Human>& people)
{
	while (true)
	{
		system("cls");
		std::cout << "-------------------------------------ПОИСК-------------------------------------------\n\n";
		std::cout << "1. Последовательный поиск.\n"
			<< "2. Бинарный поиск.\n"
			<< "3. Выход.\n\n";

		int choise;
		std::cout << "Ваш выбор: ";
		std::cin >> choise;
		if (choise == 3)
			return;
		if (choise == 1 or choise == 2)
			menu_Search(people, choise);

		else
			std::cout << "Выберите цифру из списка!";
		_getch();
		system("cls");
	}
}


void menu_Search(std::vector<Human>& people, int choise)
{
	while (true)
	{
		system("cls");
		std::cout << "-------------------------------------ПОИСК-------------------------------------------\n\n";
		std::cout << "1. Поиск по фамилии.\n"
			<< "2. Поиск по имени.\n"
			<< "3. Поиск по знаку зодиака.\n"
			<<"4. Поиск по дате рождения.\n"
			<< "5. Выход.\n\n";

		int choise_search;
		std::cout << "Ваш выбор: ";
		std::cin >> choise_search;

		switch (choise_search)
		{
		case(1): (choise == 1) ? searchWithSurname(people) : searchWithSurnameBinary(people); break;
		case(2): (choise == 1) ? searchWithName(people) : searchWithNameBinary(people); break;
		case(3): (choise == 1) ? searchWithZnakZodiaka(people) : searchWithZnakZodiakaBinary(people); break;
		case(4): (choise == 1) ? searchWithBirthdate(people) : searchWithBirthdateBinary(people); break;
		case(5): return;
		default: system("cls"); break;
		}
	}
}


void readInfo(std::vector<Human>& people)
{
	std::fstream file("C:\\Users\\Matvei\\source\\repos\\Lab - 12\\Task1\\People.txt");
	Human human;
	while (!file.eof())
	{
		file >> human.surName;
		file >> human.name;
		file >> human.znakZodiaka;
		file >> human.birthdate[0] >> human.birthdate[1] >> human.birthdate[2];
		people.push_back(human);
	}
}


std::ostream& operator<<(std::ostream& out, Human& human)
{
	std::string curHuman = human.surName + " " + human.name + "\n" + human.znakZodiaka +
		"\n" + std::to_string(human.birthdate[0]) + "." + std::to_string(human.birthdate[1]) +
		"." + std::to_string(human.birthdate[2]) + "\n\n";
	out << curHuman;
	return out;
}

