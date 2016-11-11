/**********************************************************************
**Author: Shannon Jeffers
**Date: July 30th 2016
**Description: header file for the tictactoe class
*********************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include "Board.hpp"

class TicTacToe
{
private:
	Board g1;
	char currentPlayer;
public:
	TicTacToe(char);
	void play();
};
#endif