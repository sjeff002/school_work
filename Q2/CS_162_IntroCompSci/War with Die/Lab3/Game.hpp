#ifndef GAME_HPP
#define GAME_HPP
#include "Menu.hpp"
#include <string>
class Menu;

class Game {
private:
	int numRounds;
	Menu m1;
	int plyr1Score, plyr2Score, plyr1Sides, plyr2Sides; 
	std::string plyr1Type, plyr2Type; //keep track of what type of die player has
public:
	Game();
	void playGame();
	void printRoll(int, int); //function to show player each roll
	void printWinner(); 
};

#endif