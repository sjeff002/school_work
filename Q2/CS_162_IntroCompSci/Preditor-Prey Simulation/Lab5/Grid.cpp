#include "Grid.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Grid::Grid() {
	board = new Critter**[20];
	for (int i = 0; i < 20; i++)
		board[i] = new Critter*[20];
	previousBoard = new Critter**[20];
	for (int i = 0; i < 20; i++)
		previousBoard[i] = new Critter*[20];
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			board[r][c] = NULL;
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			previousBoard[r][c] = NULL;
	numSimulations = 0;
}

Grid::~Grid() {
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++) {
			if (board[r][c] != NULL)
				delete board[r][c];
		}
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++) {
			if (previousBoard[r][c] != NULL)
				delete previousBoard[r][c];
		}
	for (int r = 0; r < 20; r++)
			delete board[r];
	for (int r = 0; r < 20; r++)
		delete previousBoard[r];
	delete[] board;
	delete[] previousBoard;
}

void Grid::placeStarters() {
	for (int i = 1; i <= 5; i++) {
		bool occupied = false;
		int randRow;
		int randCol;
		do {
			occupied = false;
			randRow = rand() % 20;
			randCol = rand() % 20;
			if (board[randRow][randCol] != NULL)
				occupied = true;
		} while (occupied);
		board[randRow][randCol] = new Doodlebug(randRow, randCol);
	}

	for (int i = 1; i <= 100; i++) {
		bool occupied = false;
		int randRow;
		int randCol;
		do {
			occupied = false;
			randRow = rand() % 20;
			randCol = rand() % 20;
			if (board[randRow][randCol] != NULL)
				occupied = true;
		} while (occupied);
		board[randRow][randCol] = new Ant(randRow, randCol);
	}
}

void Grid::moveDoodlebug() {
	resetMoveFlag();
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			if (board[r][c] != NULL && board[r][c]->getIcon() == 'X') {
				bool starved = board[r][c]->move(this);
				if (starved) {
					delete board[r][c];
					board[r][c] = NULL;
				}
			}
}

void Grid::moveAnt() {
	resetMoveFlag();
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			if (board[r][c] != NULL && board[r][c]->getIcon() == 'O') {
				board[r][c]->move(this);
			}
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			if (board[r][c] != NULL && board[r][c]->getIcon() == 'O') {
				if (board[r][c]->getStepsToBreed() >= 3)
					board[r][c]->breed(this);
			}
}

void Grid::resetMoveFlag() {
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			if(board[r][c] != NULL)
				board[r][c]->resetHasMoved();
}

void Grid::resetGrid() {
	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			previousBoard[r][c] = board[r][c];

	for (int r = 0; r < 20; r++)
		for (int c = 0; c < 20; c++)
			if (board[r][c] != NULL) {
				board[r][c] = NULL;
			}
			
}

void Grid::getOptions(vector<string> &v, int r, int c) {
	if (r == 0)
		v.erase(v.begin());
	else if (r == 19)
		v.erase(v.begin() + 2);
	if (c == 0)
		v.erase(v.end()-1);
	else if (c == 19) {
		if (v.size() == 4)
			v.erase(v.begin() + 1);
		else
			v.erase(v.begin());
	}

	if (r != 0 && board[r - 1][c] != NULL && v.size() != 0) {
		if (v[0] == "up")
			v.erase(v.begin());
	}
	if (c != 19 && board[r][c + 1] != NULL && v.size() != 0) {
		int loc;
		bool there = false;
		for (int i = 0; i < v.size(); i++)
			if (v[i] == "right") {
				there = true;
				loc = i;
			}
		if (there)
			v.erase(v.begin() + loc);
	}
	if (r != 19 && board[r+1][c] != NULL && v.size() != 0) {
		int loc;
		bool there = false;
		for (int i = 0; i < v.size(); i++)
			if (v[i] == "down") {
				there = true;
				loc = i;
			}
		if (there)
			v.erase(v.begin() + loc);
	}
	if (c != 0 && board[r][c - 1] != NULL && v.size() != 0) {
		if (v[v.size() -1] == "left")
			v.erase(v.end()-1);
	}
}

void Grid::displayGrid() {
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 20; c++) {
			if (board[r][c] == NULL)
				cout << ". ";
			else
				cout << board[r][c]->getIcon() << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Grid::displayPrevious() {
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 20; c++) {
			if (previousBoard[r][c] == NULL)
				cout << "E ";
			else
				cout << previousBoard[r][c]->getIcon() << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Grid::menu() {
	int choice = 0;
	char option;
	while(choice != 3){
		if (numSimulations == 0) {
			cout << "Would you like to start the Simulation? y/n" << endl;
			cin >> option;
			while (tolower(option) != 'y' && tolower(option) != 'n') {
				cout << "That is not proper input, try again:" << endl;
				cin >> option;
			}
			if (tolower(option) == 'y')
				runSim();
		}
		cout << "Please choise from the following menu:" << endl;
		cout << "1. Run new Simulation\n";
		cout << "2. Display previous board\n";
		cout << "3. Exit...\n" << endl;

		choice = validateIntInput();
		cin.ignore();

		switch (choice) {
		case 1: runSim();
			break;
		case 2: displayPrevious();
			break;
		case 3: cout << "Exiting...." << endl;
		}
	}
}

int Grid::validateIntInput() {
	int testInput;
	bool verifying = false;

	while (!verifying) {
		verifying = true;
		std::cin >> testInput;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "The input must be an integer!\n\n Please enter a number:" << std::endl;
			verifying = false;
		}
	}
	return testInput;
}

void Grid::runSim() {
	int steps;
	int stepsTaken = 0;
	numSimulations++;

	cout << "How many time steps would you like to simulate?" << endl;
	steps = validateIntInput();
	cin.ignore();

	placeStarters();
	displayGrid();

	while (stepsTaken < steps) {
		moveDoodlebug();
		moveAnt();
		displayGrid();
		stepsTaken++;
	}

	resetGrid();
}