#ifndef CRITTER_HPP
#define CRITTER_HPP

class Grid;

enum Direction {UP, RIGHT, DOWN, LEFT};

class Critter {
protected: 
	char icon;
	int stepsToBreed;
	int row;
	int col;
	bool hasMoved;
public: 
	virtual bool move(Grid *g) = 0;
	void virtual breed(Grid *g) = 0;
	void resetHasMoved() { hasMoved = false; }
	char getIcon() {return icon; }
	int getStepsToBreed() { return stepsToBreed; }
};
#endif