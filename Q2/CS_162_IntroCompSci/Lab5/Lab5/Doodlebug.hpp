#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Grid;

class Doodlebug : public Critter {
private:
	int stepsToStarve;
public:
	Doodlebug(int r, int c);
	bool move(Grid *g);
	void breed(Grid *g);
};
#endif