#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant : public Critter {
public:
	Ant(int r, int c);
	bool move(Grid *g);
	void breed(Grid *g);
};
#endif