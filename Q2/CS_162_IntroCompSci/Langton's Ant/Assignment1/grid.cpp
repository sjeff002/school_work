#include "grid.hpp"
#include <iostream>

Grid::Grid(int r, int c, int s) {
	previousColor = ' ';
	numRows = r;
	numCols = c;
	numSteps = s;

	grid = new char* [numRows];
	for (int r = 0; r < numRows; r++)
		grid[r] = new char [numCols];

	for (int r = 0; r < numRows; r++)
		for (int c = 0; c < numCols; c++)
			grid[r][c] = ' ';
}

Grid::~Grid() {
	for (int r = 0; r < numRows; r++)
		delete[] grid[r];
	delete[] grid;
}

void Grid::start(Ant& a) {
	int startRow = a.getStartRow();
	int startCol = a.getStartCol();


	grid[startRow][startCol] = '*';
	printGrid();

	int stepCount = 1;

	while (stepCount <= numSteps) {
		if (previousColor == ' ')
			stepRight(a);
		else if (previousColor == '#')
			stepLeft(a);
		printGrid();
		stepCount++;
	}
}

void Grid::stepRight(Ant& a) {
	std::string direction = a.getDirection();
	int currentRow = a.getCurrRow();
	int currentCol = a.getCurrCol();
	grid[currentRow][currentCol] = '#';

	if (direction == "up") {
		if ((currentCol + 1) > (numCols - 1))
			currentCol = 0;
		else {
			currentCol += 1;
			a.setDirection("right");
		}
	}
	else if (direction == "right") {
		if ((currentRow + 1) > (numRows - 1))
			currentRow = 0;
		else {
			currentRow += 1;
			a.setDirection("down");
		}
	}
	else if (direction == "down") {
		if (currentCol - 1 < 0)
			currentCol = (numCols - 1);
		else {
			currentCol -= 1;
			a.setDirection("left");
		}
	}
	else {
		if (currentRow - 1 < 0)
			currentRow = (numRows - 1);
		else {
			currentRow -= 1;
			a.setDirection("up");
		}
	}
	previousColor = grid[currentRow][currentCol];
	grid[currentRow][currentCol] = '*';
	a.setPosition(currentRow, currentCol);
}

void Grid::stepLeft(Ant& a) {
	std::string direction = a.getDirection();
	int currentRow = a.getCurrRow();
	int currentCol = a.getCurrCol();
	grid[currentRow][currentCol] = ' ';

	if (direction == "up") {
		if (currentCol - 1 < 0)
			currentCol = (numCols - 1);
		else {
			currentCol -= 1;
			a.setDirection("left");
		}
	}
	else if (direction == "right") {
		if (currentRow - 1 < 0)
			currentRow = (numRows - 1);
		else {
			currentRow -= 1;
			a.setDirection("up");
		}
	}
	else if (direction == "down") {
		if ((currentCol + 1) > (numCols - 1))
			currentCol = 0;
		else {
			currentCol += 1;
			a.setDirection("right");
		}
	}
	else {
		if ((currentRow + 1) > (numRows - 1))
			currentRow = 0;
		else {
			currentRow += 1;
			a.setDirection("down");
		}
	}
	previousColor = grid[currentRow][currentCol];
	grid[currentRow][currentCol] = '*';
	a.setPosition(currentRow, currentCol);
}

void Grid::printGrid() {
	for (int i = 0; i < numCols + 1; i++)
		std::cout << " _";
	std::cout << std::endl;
	for (int r = 0; r < numRows; r++) {
		std::cout << "|";
		for (int c = 0; c < numCols; c++)
			std::cout << grid[r][c] << " ";
		std::cout << "|" << std::endl;
	}
	for (int i = 0; i < numCols + 1; i++)
		std::cout << " _";
	std::cout << std::endl;
}