#pragma once
#include <vector>
#include "structs.h"


std::ostream& operator<<(std::ostream& out, Human& human);

void main_menu(std::vector<Human>& people);
void menu_Search(std::vector<Human>& people, int choise);
void readInfo(std::vector<Human>& people);

void searchWithSurname(std::vector<Human>& people);
void searchWithName(std::vector<Human>& people);
void searchWithZnakZodiaka(std::vector<Human>& people);
void searchWithBirthdate(std::vector<Human>& people);

//—Œ–“»–Œ¬ »
void sortingForSurnameUp(std::vector<Human>& people);
void sortingForBirthdateUp(std::vector<Human>& people);
void sortingForZnakUp(std::vector<Human>& people);
void sortingForNameUp(std::vector<Human>& people);

void searchWithSurnameBinary(std::vector<Human>& people);
void searchWithNameBinary(std::vector<Human>& people);
void searchWithZnakZodiakaBinary(std::vector<Human>& people);
void searchWithBirthdateBinary(std::vector<Human>& people);