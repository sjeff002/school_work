#ifndef GRID_HPP
#define GRID_HPP
#include "ant.hpp"

class Grid{
private:
	char previousColor;
	int numSteps;
	char** grid;
	int numRows;
	int numCols;

public:
	Grid(int, int, int);
	~Grid();
	void start(Ant&);
	void stepRight(Ant&);
	void stepLeft(Ant&);
	void printGrid();
};
#endif