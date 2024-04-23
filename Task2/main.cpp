#include <iostream>
#include <vector>
#include "structs.h"
#include "prototypes.h"

int main()
{
	setlocale(0, "rus");

	std::vector<Human> people;
	people.reserve(10);
	readInfo(people);

	main_menu(people);

	return 0;
}