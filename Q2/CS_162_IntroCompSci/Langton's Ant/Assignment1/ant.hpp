#ifndef ANT_HPP
#define ANT_HPP
#include <string>

class Ant {
private:
	int startRow;
	int startCol;
	int currRow;
	int currCol;
	std::string direction;

public:
	Ant(int r, int c);
	int getStartRow();
	int getStartCol();
	int getCurrRow();
	int getCurrCol();
	std::string getDirection();
	void setPosition(int, int);
	void setDirection(std::string);
};
#endif