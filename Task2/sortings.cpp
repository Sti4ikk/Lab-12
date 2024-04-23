#include "structs.h"
#include <vector>

// ���������� �� ������� ���������
void sortingForSurnameUp(std::vector<Human>& people)
{
	for (int i = 1; i < people.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (people.at(j - 1).surName > people.at(j).surName)
			{
				Human tmp = people.at(j - 1);
				people.at(j - 1) = people.at(j);
				people.at(j) = tmp;
			}
			else
				break;
		}
	}
}

// ���������� �� ����� ���������
void sortingForNameUp(std::vector<Human>& people)
{
	for (int i = 1; i < people.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (people.at(j - 1).name > people.at(j).name)
			{
				Human tmp = people.at(j - 1);
				people.at(j - 1) = people.at(j);
				people.at(j) = tmp;
			}
			else
				break;
		}
	}
}

// ���������� �� ���� �������� ���������
void sortingForBirthdateUp(std::vector<Human>& people)
{
	for (int i = 1; i < people.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			// ���������� ���, ����� � ����
			if (people.at(j - 1).birthdate[2] > people.at(j).birthdate[2] or
				(people.at(j - 1).birthdate[2] == people.at(j).birthdate[2] and people.at(j - 1).birthdate[1] > people.at(j).birthdate[1]) or
				(people.at(j - 1).birthdate[2] == people.at(j).birthdate[2] and people.at(j - 1).birthdate[1] == people.at(j).birthdate[1] and people.at(j - 1).birthdate[0] > people.at(j).birthdate[0]))
			{
				// ����� ����������
				Human tmp = people.at(j - 1);
				people.at(j - 1) = people.at(j);
				people.at(j) = tmp;
			}
			else
				break;
		}
	}
}

// ���������� �� ����� ������� ���������
void sortingForZnakUp(std::vector<Human>& people)
{
	for (int i = 0; i < people.size() - 1; i++)
	{
		bool swapped = false;
		int endOfArr = people.size() - i;
		for (int j = 0; j < endOfArr - 1; j++)
		{
			if (people.at(j).znakZodiaka > people.at(j+1).znakZodiaka)
			{
				std::swap(people.at(j), people.at(j+1));
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}