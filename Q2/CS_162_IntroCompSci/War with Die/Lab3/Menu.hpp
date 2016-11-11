#ifndef MENU_HPP
#define MENU_HPP
#include <string>

class Menu {
public:
	int getNumSides(std::string);
	bool isItLoaded(std::string);
	int howManyTurns();
	bool verifyLoaded(char);
	int verifyInputInt();
};

#endif