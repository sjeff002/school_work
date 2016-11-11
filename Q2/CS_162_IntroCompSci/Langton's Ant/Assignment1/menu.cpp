#include <iostream>
#include <ctime>
#include <cstdlib>
#include "menu.hpp"

void Menu::runMenu() {
	bool isRand;

	promptAssignGrid();
	isRand = promptIsRand();

	if (!isRand)
		promptStartP();
	else {
		unsigned seed;
		seed = time(0);
		srand(seed);
		startRow = rand() % numRows;
		startCol = rand() % numCols;
	}

	promptSteps();
}

int Menu::getNumRows() {
	return numRows;
}

int Menu::getNumCols() {
	return numCols;
}

int Menu::getStartRow() {
	return startRow;
}

int Menu::getStartCol() {
	return startCol;
}

int Menu::getNumSteps() {
	return numSteps;
}

void Menu::promptAssignGrid() {
	int row;
	int col;

	std::cout << "How large would you like the grid\n" <<
		"Please enter number of rows and columns:" << std::endl;

	std::cin >> row >> col;

	numRows = row;
	numCols = col;
}

bool Menu::promptIsRand() {
	bool valid = false;
	bool rand = false;
	char answer;

	while (!valid) {
		std::cout << "Would you like a random starting location? y or n:" << std::endl;
		std::cin >> answer;

		valid = validRand(answer);
	}

	if (tolower(answer) == 'n')
		rand = false;
	else
		rand = true;
	return rand;
}

void Menu::promptStartP() {
	int sr;
	int sc;
	bool valid = false;

	while (!valid) {
		std::cout << "Please enter the starting row and column." <<
			"\nRemember row and column counts start with 0:" << std::endl;
		std::cin >> sr >> sc;

		valid = validStartP(sr, sc);
	}
	startRow = sr;
	startCol = sc;
}

void Menu::promptSteps() {
	int answer;
	bool valid = false;

	while (!valid) {
		std::cout << "How many steps would you like the ant to take? Please choose an option:" << std::endl;
		std::cout << "1.10 Steps\n2. 100 Steps\n3. 1000 Steps\n4. 10000 Steps" << std::endl;
		std::cin >> answer;

		valid = validSteps(answer);
	}
	switch (answer) {
	case 1: numSteps = 10;
		break;
	case 2: numSteps = 100;
		break;
	case 3: numSteps = 1000;
		break;
	case 4: numSteps = 10000;
		break;
	}
}

bool Menu::validRand(char a) {
	bool validity;

	if (tolower(a) == 'y' || tolower(a) == 'n')
		validity = true;
	else {
		validity = false;
		std::cout << "That is not a valid input" << std::endl;
	}
	return validity;
}

bool Menu::validStartP(int r, int c) {
	bool validity;

	if (r >= numRows || r < 0) {
		validity = false;
		std::cout << "That is not a valid input" << std::endl;
	}
	else if (c >= numCols || c < 0) {
		validity = false;
		std::cout << "That is not a valid input" << std::endl;
	}
	else
		validity = true;

	return validity;
}

bool Menu::validSteps(int a) {
	bool validity;
	
	if (a < 1 || a > 4) {
		validity = false;
		std::cout << "That is not a valid input" << std::endl;
	}
	else
		validity = true;
	
	return validity;
}