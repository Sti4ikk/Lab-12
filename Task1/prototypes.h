#pragma once
#include <vector>
#include <array>

using numbers = std::array<int, 2>;

void readInfo(std::vector<Human>& people);
numbers sortingForSurnameUp(std::vector<Human>& people);
numbers sortingForSurnameShell(std::vector<Human>& people);
void main_menu(std::vector<Human>& people);
numbers sortingForBirthdateDown(std::vector<Human>& people);
numbers sortingForBirthdateShell(std::vector<Human>& people);

void chooseTypeOfSort(std::vector<Human>& people);
void chooseTypeOfSortShell(std::vector<Human>& people);
void printArr(std::vector<Human>& people);