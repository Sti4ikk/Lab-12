#include <iostream>
#include <fstream>
#include <Windows.h>
#include "structs.h"
#include "prototypes.h";
#include <vector>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<Human> people;
	people.reserve(10);

	main_menu(people);

	return 0;
}