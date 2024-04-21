#include <iostream>
#include <fstream>
#include <Windows.h>
#include "structs.h"
#include "prototypes.h";
#include "Timer.h"
#include <conio.h>
#include "termcolor.hpp"


void main_menu(std::vector<Human> &people)
{
	while (true)
	{
		// ������ ��� ������ ������
		people = {};
		readInfo(people);

		system("cls");
		std::cout << "---------------------------------��������� ����������-------------------------------------------\n\n";
		std::cout << "1. ���������� ���������.\n"
			<< "2. ���������� �����.\n"
			<< "3. �����.\n\n";

		int choise;
		std::cout << "��� �����: ";
		std::cin >> choise;

		switch (choise)
		{
		case(1): chooseTypeOfSort(people); break;
		case(2): chooseTypeOfSortShell(people); break;
		case(3): return;
		default: system("cls"); break;
		}
	}

}

void printArr(std::vector<Human>& people)
{
	for (int i = 0; i < people.size(); i++)
	{
		std::cout << people.at(i).surName << " " << people.at(i).name << " " << people.at(i).znakZodiaka << " " <<
			people.at(i).birthdate[0] << "." << people.at(i).birthdate[1] << "." << people.at(i).birthdate[2] << std::endl;

	}
	std::cout << std::endl;
}

void chooseTypeOfSort(std::vector<Human>& people)
{
	int choise;
	do
	{
		system("cls");
		std::cout << "1. ���������� �� �������.\n"
			<< "2. ���������� �� ���� ��������.\n"
			<< "3. �����.\n\n";

		std::cout << "��� �����: ";
		std::cin >> choise;
		std::cout << std::endl;

		std::array<int, 2> numbers;
		Timer t;
		switch (choise)
		{
		case(1):
		{
			numbers = sortingForSurnameUp(people);
			printArr(people);
			std::cout << termcolor::green << "���������� ������ �������!\n" << termcolor::reset << "����������� �����: " << t.elapsed(); 
			std::cout << "\n���������� ������������: " << numbers.at(0) << "\n����������� ���������: " << numbers.at(1);
			_getch(); 
			break;
		}
		case(2):
		{
			numbers = sortingForBirthdateDown(people); 
			printArr(people);
			std::cout << termcolor::green << "���������� ������ �������!\n" << termcolor::reset << "����������� �����: " << t.elapsed(); 
			std::cout << "\n���������� ������������: " << numbers.at(0) << "\n����������� ���������: " << numbers.at(1);
			_getch(); 
			break;
		}
		case(3): return;
		default: std::cout << termcolor::red << "\n�������� ����� �� ����!" << termcolor::reset; _getch(); system("cls");
		}
	} while (choise != 1 and choise != 2);
}

void chooseTypeOfSortShell(std::vector<Human>& people)
{
	int choise;
	do
	{
		system("cls");
		std::cout << "1. ���������� �� �������.\n"
			<< "2. ���������� �� ���� ��������.\n"
			<< "3. �����.\n\n";

		std::cout << "��� �����: ";
		std::cin >> choise;
		std::cout << std::endl;

		std::array<int, 2> numbers;
		Timer t;
		switch (choise)
		{
		case(1):
		{
			numbers = sortingForSurnameShell(people);
			printArr(people);
			std::cout << termcolor::green << "���������� ������ �������!\n" << termcolor::reset << "����������� �����: " << t.elapsed(); 
			std::cout << "\n���������� ������������: " << numbers.at(0) << "\n����������� ���������: " << numbers.at(1);
			_getch(); 
			break;
		}
		case(2): 
		{
			numbers = sortingForBirthdateShell(people);
			printArr(people);
			std::cout << termcolor::green << "���������� ������ �������!\n" << termcolor::reset << "����������� �����: " << t.elapsed();  
			std::cout << "\n���������� ������������: " << numbers.at(0) << "\n����������� ���������: " << numbers.at(1);
			_getch(); 
			break;
		}
		case(3): return;
		default: std::cout << termcolor::red << "\n�������� ����� �� ����!" << termcolor::reset; _getch(); system("cls");
		}
	} while (choise != 1 and choise != 2);
}


void readInfo(std::vector<Human>& people)
{
	std::fstream file("People.txt");
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