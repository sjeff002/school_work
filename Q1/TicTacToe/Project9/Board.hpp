/*************************************************************************************
**Author: Shannon Jeffers
**Date: July 30 2016
**Description: header file for board class
**************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

enum Status {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
private:
	char bgame[3][3];
public:
	Board();
	bool makeMove(int, int, char);
	Status gameState();
	void print();
};
#endif