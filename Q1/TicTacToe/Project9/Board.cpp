/****************************************************************************
**Author: Shannon Jeffers
**Date: July 30 2016
**Description: implimentation code for board class
*****************************************************************************/

#include "Board.hpp"
#include <iostream>
using namespace std;

/****************************************************************************
**Descriotion: constructor to set all spots in array to empty
****************************************************************************/
Board::Board()
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
			bgame[r][c] = '.';
	}
}

/****************************************************************************
**Description: function to set a move the user enters in the board
****************************************************************************/
bool Board::makeMove(int r, int c, char p)
{
	if (bgame[r][c] == 'x' || bgame[r][c] == 'o')
		return false;
	else
	{
		bgame[r][c] = p;
		return true;
	}
}

/*******************************************************************************
**Descirption: function to determine the the state the game is in every turn
*******************************************************************************/
Status Board::gameState()
{
	Status state;
	char temp = 'q';
	if (bgame[0][0] == bgame[0][1] && bgame[0][1] == bgame[0][2] && bgame[0][0] != '.')
		temp = bgame[0][0];
	else if (bgame[1][0] == bgame[1][1] && bgame[1][1] == bgame[1][2] && bgame [1][0] != '.')
		temp = bgame[1][0];
	else if (bgame[2][0] == bgame[2][1] && bgame[2][1] == bgame[2][2] && bgame[2][0] != '.')
		temp = bgame[2][0];
	else if (bgame[0][0] == bgame[1][0] && bgame[1][0] == bgame[2][0] && bgame[0][0] != '.')
		temp = bgame[0][0];
	else if (bgame[0][1] == bgame[1][1] && bgame[1][1] == bgame[2][1] && bgame[0][1] != '.')
		temp = bgame[0][1];
	else if (bgame[0][2] == bgame[1][2] && bgame[1][2] == bgame[2][2] && bgame[0][2] != '.')
		temp = bgame[0][2];
	else if (bgame[0][0] == bgame[1][1] && bgame[1][1] == bgame[2][2] && bgame[0][0] != '.')
		temp = bgame[0][0];
	else if (bgame[2][0] == bgame[1][1] && bgame[1][1] == bgame[0][2] && bgame[2][0] != '.')
		temp = bgame[2][0];
	else if (bgame[0][0] != '.' && bgame[0][1] != '.' && bgame[0][2] != '.')
	{
		if (bgame[1][0] != '.' && bgame[1][1] != '.' && bgame[1][2] != '.')
		{
			if (bgame[2][0] != '.' && bgame[2][1] != '.' && bgame[2][2] != '.')
				state = DRAW;
			else
				state = UNFINISHED;
		}
		else
			state = UNFINISHED;
	}
	else
		state = UNFINISHED;

	if (temp == 'x')
		state = X_WON;
	else if (temp == 'o')
		state = O_WON;
	return state;
}

/*****************************************************************************************
**Description: function to print the game board every turn
*****************************************************************************************/
void Board::print()
{
	cout << "  0 1 2" << endl;
	cout << "0 " << bgame[0][0] << " " << bgame[0][1] << " " << bgame[0][2] << endl;
	cout << "1 " << bgame[1][0] << " " << bgame[1][1] << " " << bgame[1][2] << endl;
	cout << "2 " << bgame[2][0] << " " << bgame[2][1] << " " << bgame[2][2] << endl;
}