#include <iostream>
#include <fstream>
#include <vector>
#include "structs.h"
#include <conio.h>
#include "prototypes.h"


void searchWithSurname(std::vector<Human> &people)
{
	bool isAtLeastOne = false;
	int count = 1;
	std::string surname;
	std::cout << "Введите фамилию: ";
	std::cin >> surname;
	system("cls");


	std::cout << "\tНайденные люди: \n";
	for (int i = 0; i < people.size(); i++)
	{
		if (surname == people.at(i).surName)
		{
			std::cout << count++<< ". "<< people.at(i);
			isAtLeastOne = true;
		}
	}

	if (!isAtLeastOne)
	{
		std::cout << "Не найдено людей с такой фамилией!";
	}
	_getch();
}

void searchWithName(std::vector<Human>& people)
{
	bool isAtLeastOne = false;
	int count = 1;
	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	system("cls");


	std::cout << "\tНайденные люди: \n";
	for (int i = 0; i < people.size(); i++)
	{
		if (name == people.at(i).name)
		{
			std::cout << count++<< ". "<<people.at(i);
			isAtLeastOne = true;
		}
	}

	if (!isAtLeastOne)
	{
		std::cout << "Не найдено людей с таким именем!";
	}
	_getch();
}

void searchWithZnakZodiaka(std::vector<Human>& people)
{
	bool isAtLeastOne = false;
	int count = 1;
	std::string znak;
	std::cout << "Введите знак зодиака: ";
	std::cin >> znak;
	system("cls");


	std::cout << "\tНайденные люди: \n";
	for (int i = 0; i < people.size(); i++)
	{
		if (znak == people.at(i).znakZodiaka)
		{
			std::cout << count++ << ". " << people.at(i);
			isAtLeastOne = true;
		}
	}

	if (!isAtLeastOne)
	{
		std::cout << "Не найдено людей с таким знаком зодиака!";
	}
	_getch();
}

void searchWithBirthdate(std::vector<Human>& people)
{
	bool isAtLeastOne = false;
	int count = 1;
	int date[3]{};
	std::cout << "Введите дату рождения(3 числа через пробел): ";
	std::cin >> date[0];
	std::cin >> date[1];
	std::cin >> date[2];
	system("cls");


	std::cout << "\tНайденные люди: \n";
	for (int i = 0; i < people.size(); i++)
	{
		if (date[0] == people.at(i).birthdate.at(0) and date[1] == people.at(i).birthdate.at(1) and 
			date[2] == people.at(i).birthdate.at(2))
		{
			std::cout << count++ << ". " << people.at(i);
			isAtLeastOne = true;
		}
	}

	if (!isAtLeastOne)
		std::cout << "Не найдено людей с такой датой рождения!";
	_getch();
}

void searchWithSurnameBinary(std::vector<Human>& people)
{
	sortingForSurnameUp(people);

	std::string surname;
	std::cout << "Введите фамилию: ";
	std::cin >> surname;
	system("cls");

	bool isAtLeastOne = false;
	int count = 1;
	int left = 0;
	int right = people.size() - 1;

	std::cout << "\tНайденные люди: \n";

	while (left <= right) 
	{
		int mid = left + (right - left) / 2;

		if (people.at(mid).surName == surname) 
		{
			std::cout << count++ << ". " << people.at(mid);
			isAtLeastOne = true;

		}
		if (people.at(mid).surName < surname) 
		{
			left = mid + 1;
		}
		else 
		{
			right = mid - 1;
		}
	}

	if (!isAtLeastOne)
		std::cout << "Не найдено людей с такой фамилией!";
	_getch();
}

void searchWithNameBinary(std::vector<Human>& people)
{
	sortingForNameUp(people);

	std::string name;
	std::cout << "Введите имя: ";
	std::cin >> name;
	system("cls");

	bool isAtLeastOne = false;
	int count = 1;
	int left = 0;
	int right = people.size() - 1;

	std::cout << "\tНайденные люди: \n";

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (people.at(mid).name == name)
		{
			std::cout << count++ << ". " << people.at(mid);
			isAtLeastOne = true;

		}
		if (people.at(mid).name < name)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (!isAtLeastOne)
		std::cout << "Не найдено людей с таким именем!";
	_getch();
}

void searchWithZnakZodiakaBinary(std::vector<Human>& people)
{
	sortingForZnakUp(people);

	std::string znak;
	std::cout << "Введите знак зодиака: ";
	std::cin >> znak;
	system("cls");

	bool isAtLeastOne = false;
	int count = 1;
	int left = 0;
	int right = people.size() - 1;

	std::cout << "\tНайденные люди: \n";

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (people.at(mid).znakZodiaka == znak)
		{
			std::cout << count++ << ". " << people.at(mid);
			isAtLeastOne = true;

		}
		if (people.at(mid).znakZodiaka < znak)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	if (!isAtLeastOne)
		std::cout << "Не найдено людей с таким знаком зодиака!";
	_getch();
}

void searchWithBirthdateBinary(std::vector<Human>& people)
{
	sortingForZnakUp(people);

	bool isAtLeastOne = false;
	int count = 1;
	int date[3]{};
	std::cout << "Введите дату рождения(3 числа через пробел): ";
	std::cin >> date[0];
	std::cin >> date[1];
	std::cin >> date[2];
	system("cls");


	std::cout << "\tНайденные люди: \n";
	for (int i = 0; i < people.size(); i++)
	{
		if (date[0] == people.at(i).birthdate.at(0) and date[1] == people.at(i).birthdate.at(1) and
			date[2] == people.at(i).birthdate.at(2))
		{
			std::cout << count++ << ". " << people.at(i);
			isAtLeastOne = true;
		}
	}

	if (!isAtLeastOne)
		std::cout << "Не найдено людей с такой датой рождения!";
	_getch();
}