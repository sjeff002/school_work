/************************************************************************************
**Author: Shannon Jeffers
**Date: July 30 2016
**Description: implimentation and main for tictactoe class
*************************************************************************************/

#include "TicTacToe.hpp"
#include <iostream>
#include <cctype>
using namespace std;


//contructor to set current player to user entered player
TicTacToe::TicTacToe(char p)
{
	currentPlayer = tolower(p);
}


/***************************************************************************************
**Description: function that loops through the game play
***************************************************************************************/
void TicTacToe::play()
{
	int x, y;
	bool check;
	Status state;
	do
	{
		cout << "Player " << currentPlayer << " make your move." << endl;
		cin >> x >> y;
		check = g1.makeMove(x, y, currentPlayer);
		if (!check)
		{
			while (!check)
			{
				cout << "That spot is taken, please enter another." << endl;
				cin >> x >> y;
				check = g1.makeMove(x, y, currentPlayer);
			}
		}
		if (currentPlayer == 'x')
			currentPlayer = 'o';
		else
			currentPlayer = 'x';
		g1.print();
		state = g1.gameState();
	} while (state == UNFINISHED);
	if (state == X_WON)
		cout << "x is the winner!" << endl;
	if (state == O_WON)
		cout << "o is the winner!" << endl;
	else if(state == DRAW)
		cout << "It's a draw!" << endl;
}


/*********************************************************************
**Description: main function to play the game
*********************************************************************/
int main()
{
	char player;
	cout << "Which player starts the game?" << endl;
	cin >> player;

	TicTacToe game1(player);

	game1.play();


	return 0;

}