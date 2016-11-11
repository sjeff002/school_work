#include "Game.hpp"
#include "Die.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
//constructor
Game::Game() {
	plyr1Score = 0;
	plyr2Score = 0;
}
/*****************************************************************************
**Play game function
**Function makes all the function calls required for the game to run. 
**Uses menu to get user input
**Uses user input to create die and run game.
******************************************************************************/
void Game::playGame() {
	bool isLoaded1, isLoaded2;
	int turns = 1;
	//code below creates the seed for random functions
	unsigned seed;
	seed = time(0);
	srand(seed);
	plyr1Sides = m1.getNumSides("Player 1");
	plyr2Sides = m1.getNumSides("Player 2");
	isLoaded1 = m1.isItLoaded("Player 1");
	isLoaded2 = m1.isItLoaded("Player 2");
	numRounds = m1.howManyTurns();

	//plays the game with a loaded player 1 die
	if (isLoaded1) {
		plyr1Type = "Loaded";
		LoadedDie player1(plyr1Sides);
		//plays game with loaded layer 2 die
		if (isLoaded2) {
			plyr2Type = "Loaded";
			LoadedDie player2(plyr2Sides);
			int plyr1Roll, plyr2Roll;
			while (turns <= numRounds) {
				plyr1Roll = player1.roll();
				plyr2Roll = player2.roll();
				printRoll(plyr1Roll, plyr2Roll);
				turns++;
			}
		}
		//plays game with regular player 2 die
		else {
			plyr2Type = "Regular";
			Die player2(plyr2Sides);
			int plyr1Roll, plyr2Roll;
			while (turns <= numRounds) {
				plyr1Roll = player1.roll();
				plyr2Roll = player2.roll();
				printRoll(plyr1Roll, plyr2Roll);
				turns++;
			}
		}
	}
	//plays game with regular player 1 die
	else {
		plyr1Type = "Regular";
		Die player1(plyr1Sides);
		//plays game with loaded player 2 die
		if (isLoaded2) {
			plyr2Type = "Loaded";
			LoadedDie player2(plyr2Sides);
			int plyr1Roll, plyr2Roll;
			while (turns <= numRounds) {
				plyr1Roll = player1.roll();
				plyr2Roll = player2.roll();
				printRoll(plyr1Roll, plyr2Roll);
				turns++;
			}
			}
		//plays game with regular player 2 die
		else {
			plyr2Type = "Regular";
			Die player2(plyr2Sides);
			int plyr1Roll, plyr2Roll;
			while (turns <= numRounds) {
				plyr1Roll = player1.roll();
				plyr2Roll = player2.roll();
				printRoll(plyr1Roll, plyr2Roll);
				turns++;
			}
		}
	}
	printWinner();
}

/*****************************************************************************
**Prints each round of the game.
** takes in the value each player rolled to determin who won the round. 
**Adds to the player score of the player who won the round
******************************************************************************/
void Game::printRoll(int p1, int p2) {
	cout << "Player 1 rolled: " << p1 << endl;
	cout << "Player 2 rolled: " << p2 << endl;
	if (p1 > p2) {
		cout << "Player 1 wins the round.\n" << endl;
		plyr1Score++;
	}
	else if (p2 > p1) {
		cout << "Player 2 wins the round.\n" << endl;
		plyr2Score++;
	}
	else {
		cout << "This round was a draw\n" << endl;
		plyr1Score++;
		plyr2Score++;
	}
}
/*****************************************************************************
**Prints a statement about who won the game.
**Compares the scores of each player to decide. Also tells what type of die
**each player was using
******************************************************************************/
void Game::printWinner() { 
	if (plyr1Score > plyr2Score) 
		cout << "Player 1 wins the game!!" << endl;
	else if (plyr2Score > plyr1Score)
		cout << "Player 2 wins the game!!" << endl;
	else
		cout << "There was a draw!" << endl;
	cout << "Player one used a " << plyr1Type << " " << plyr1Sides << " sided die." << endl;
	cout << "Player two used a " << plyr2Type << " " << plyr2Sides << " sided die." << endl;
}