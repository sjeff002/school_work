#include "Ant.hpp"
#include "Grid.hpp"
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

Ant::Ant(int r, int c) {
	icon = 'O';
	row = r;
	col = c;
	stepsToBreed = 0;
	hasMoved = false;
}

bool Ant::move(Grid *g) {
	if (!hasMoved) {
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
			swap(g->board[row][col], g->board[row+1][col]);
			row++;
		}
		else if (d == LEFT && col != 0 && g->board[row][col - 1]) {
			swap(g->board[row][col], g->board[row][col - 1]);
			col--;
		}

		stepsToBreed++;
		hasMoved = true;
	
	}
	return 0;
}

void Ant::breed(Grid *g) {
	vector <string> check = { "up", "right", "down", "left" };
	int randChoice;
	g->getOptions(check, row, col);

	if (check.size() >= 1) {
		if (check.size() == 1)
			randChoice = 0;
		else
			randChoice = rand() % check.size();

		if (check[randChoice] == "up") {
			g->board[row - 1][col] == new Ant(row - 1, col);
			stepsToBreed = 0;
		}
		else if (check[randChoice] == "right") {
			g->board[row][col + 1] == new Ant(row, col + 1);
			stepsToBreed = 0;
		}
		else if (check[randChoice] == "down") {
			g->board[row + 1][col] == new Ant(row + 1, col);
			stepsToBreed = 0;
		}
		else {
			g->board[row][col - 1] == new Ant(row, col - 1);
			stepsToBreed = 0;
		}
	}
}