#ifndef GRID_HPP
#define GRID_HPP
#include "Critter.hpp"
#include <string>
#include <vector>


class Grid {
	friend class Ant;
	friend class Doodlebug;
private:
	Critter ***board;
	Critter ***previousBoard;
	int numSimulations;
public:
	Grid();
	~Grid();
	void placeStarters();
	void moveDoodlebug();
	void moveAnt();
	void resetGrid();
	void runSim();
	void resetMoveFlag();
	void getOptions(std::vector<std::string> &v, int r, int c);
	void displayGrid();
	void displayPrevious();
	void menu();
	int validateIntInput();
};
#endif