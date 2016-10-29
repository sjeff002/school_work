#include "Doodlebug.hpp"
#include "Grid.hpp"
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

Doodlebug::Doodlebug(int r, int c) {
	icon = 'X';
	row = r;
	col = c;
	stepsToBreed = 0;
	stepsToStarve = 0;
	hasMoved = false;
}

bool Doodlebug::move(Grid *g) {
	bool starved = false;
	if (!hasMoved) {
		if (row != 0 && g->board[row - 1][col] != NULL &&
			g->board[row - 1][col]->getIcon() == 'O') {
			delete g->board[row - 1][col];
			g->board[row - 1][col] = NULL;
			swap(g->board[row][col], g->board[row - 1][col]);
			stepsToStarve = 0;
		}
		else if (col != 19 && g->board[row][col + 1] != NULL &&
			g->board[row][col+1]->getIcon() == 'O') {
			delete g->board[row][col + 1];
			g->board[row][col + 1] = NULL;
			swap(g->board[row][col], g->board[row][col + 1]);
			stepsToStarve = 0;
		}
		else if (row != 19 && g->board[row + 1][col] != NULL &&
			g->board[row + 1][col]->getIcon() == 'O') {
			delete g->board[row + 1][col];
			g->board[row + 1][col] = NULL;
			swap(g->board[row][col], g->board[row + 1][col]);
			stepsToStarve = 0;
		}
		else if (col != 0 && g->board[row][col -1] != NULL &&
			g->board[row][col - 1]->getIcon() == 'O') {
			delete g->board[row][col - 1];
			g->board[row][col - 1] = NULL;
			swap(g->board[row][col], g->board[row][col - 1]);
			stepsToStarve = 0;
		}
		else {
			Direction d = Direction(rand() % 4);

			if (d == UP && row != 0 && g->board[row - 1][col] == NULL) {
				swap(g->board[row][col], g->board[row - 1][col]);
				row--;
			}
			else if (d == RIGHT && col != 19 && g->board[row][col + 1] == NULL) {
				swap(g->board[row][col], g->board[row][col + 1]);
				col++;
			}
			else if (d == DOWN && row != 19 && g->board[row + 1][col] == NULL) {
				swap(g->board[row][col], g->board[row + 1][col]);
				row++;
			}
			else if (d == LEFT && col != 0 && g->board[row][col - 1]) {
				swap(g->board[row][col], g->board[row][col - 1]);
				col--;
			}
			stepsToStarve++;
		}
		stepsToBreed++;
		hasMoved = true;

		if (stepsToBreed == 8)
			breed(g);
		if (stepsToStarve == 3)
			starved = true;
	}
	return starved;
}

void Doodlebug::breed(Grid *g) {
	vector <string> check = { "up", "right", "down", "left" };
	int randChoice;
	g->getOptions(check, row, col);

	if (check.size() >= 1) {
		if (check.size() == 1)
			randChoice = 0;
		else
			randChoice = rand() % check.size();

		if (check[randChoice] == "up") {
			g->board[row - 1][col] == new Doodlebug(row - 1, col);
			stepsToBreed = 0;
		}
		else if (check[randChoice] == "right") {
			g->board[row][col + 1] == new Doodlebug(row, col + 1);
			stepsToBreed = 0;
		}
		else if (check[randChoice] == "down") {
			g->board[row + 1][col] == new Doodlebug(row + 1, col);
			stepsToBreed = 0;
		}
		else {
			g->board[row][col - 1] == new Doodlebug(row, col - 1);
			stepsToBreed = 0;
		}
	}
}