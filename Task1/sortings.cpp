#include <array>
#include <vector>
#include "structs.h"
#include "Timer.h"

using numbers = std::array<int, 2>;

// ñîğòèğîâêà ïî ÔÀÌÈËÈÈ ÂÑÒÀÂÊÀÌÈ
numbers sortingForSurnameUp(std::vector<Human>& people)
{
	int counterOfSwaps = 0;
	int counterOfComparisons = 0;
	numbers arr;

	for (int i = 1; i < people.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			counterOfComparisons++;
			if (people.at(j - 1).surName > people.at(j).surName)
			{
				counterOfSwaps++;
				Human tmp = people.at(j - 1);
				people.at(j - 1) = people.at(j);
				people.at(j) = tmp;
			}
			else
				break;
		}
	}

	arr.at(0) = counterOfSwaps;
	arr.at(1) = counterOfComparisons;
	return arr;
}

// ñîğòèğîâêà ïî ÔÀÌÈËÈÈ ØÅËËÀ
numbers sortingForSurnameShell(std::vector<Human>& people)
{
	int i, j, step;
	int counterOfSwaps = 0;
	int counterOfÑomparisons = 0;
	numbers arr;
	std::string tmp;

	for (step = people.size() / 2; step > 0; step /= 2)
		for (i = step; i < people.size(); i++)
		{
			tmp = people.at(i).surName;
			for (j = i; j >= step; j -= step)
			{
				counterOfÑomparisons++;
				if (tmp < people.at(j - step).surName)
				{
					counterOfSwaps++;
					people.at(j) = people.at(j - step);
				}
				else
					break;
			}
			people.at(j).surName = tmp;
		}

	arr.at(0) = counterOfSwaps;
	arr.at(1) = counterOfÑomparisons;
	return arr;
}

// Ñîğòèğîâêà ïî äàòå ğîæäåíèÿ âñòàâêàìè
numbers sortingForBirthdateDown(std::vector<Human>& people)
{
	int counterOfSwaps = 0;
	int counterOfÑomparisons = 0;
	numbers arr;

	for (int i = 1; i < people.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			counterOfÑomparisons++;
			// Ñğàâíèâàåì ãîä, ìåñÿö è äåíü
			if (people.at(j - 1).birthdate[2] < people.at(j).birthdate[2] or
				(people.at(j - 1).birthdate[2] == people.at(j).birthdate[2] and people.at(j - 1).birthdate[1] < people.at(j).birthdate[1]) or
				(people.at(j - 1).birthdate[2] == people.at(j).birthdate[2] and people.at(j - 1).birthdate[1] == people.at(j).birthdate[1] and people.at(j - 1).birthdate[0] < people.at(j).birthdate[0]))
			{
				// Îáìåí çíà÷åíèÿìè
				Human tmp = people.at(j - 1);
				people.at(j - 1) = people.at(j);
				people.at(j) = tmp;
			}
			else
				break;
		}
	}

	arr.at(0) = counterOfSwaps;
	arr.at(1) = counterOfÑomparisons;
	return arr;
}

// Ñîğòèğîâêà ïî äàòå ğîæäåíèÿ Øåëëà
numbers sortingForBirthdateShell(std::vector<Human>& people)
{
	int i, j, step;
	int counterOfSwaps = 0;
	int counterOfÑomparisons = 0;
	numbers arr;

	for (step = people.size() / 2; step > 0; step /= 2)
		for (i = step; i < people.size(); i++)
		{
			std::array<int, 3> tmp = people.at(i).birthdate;
			for (j = i; j >= step; j -= step)
			{
				counterOfÑomparisons++;
				// Ñğàâíèâàåì ãîä, ìåñÿö è äåíü
				if (people.at(j - step).birthdate[2] < tmp[2] or
					(people.at(j - step).birthdate[2] == tmp[2] and people.at(j - step).birthdate[1] < tmp[1]) or
					(people.at(j - step).birthdate[2] == tmp[2] and people.at(j - step).birthdate[1] == tmp[1] and people.at(j - step).birthdate[0] < tmp[0]))
				{
					people.at(j).birthdate = people.at(j - step).birthdate;
				}
				else
					break;
			}
			people.at(j).birthdate = tmp;
		}

	arr.at(0) = counterOfSwaps;
	arr.at(1) = counterOfÑomparisons;
	return arr;
}