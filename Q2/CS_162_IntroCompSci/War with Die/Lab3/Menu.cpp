#include "Menu.hpp"
#include <limits>
#include <iostream>

/*****************************************************************************
**function that prompts user to enter number of die sides
**takes a string to indicate wich player it is prompting for.
**returns the number of sides
******************************************************************************/
int Menu::getNumSides(std::string player) {
	int numSides;
	std::cout << "How many sided die does " << player << " have?" << std::endl;
	numSides = verifyInputInt();
	return numSides;
}

/*****************************************************************************
**Function to ask player if the die is loaded
**takes a string to indicate wich player it is prompting for.
**returns bool value to tell the play function if the die is loaded or not
******************************************************************************/
bool Menu::isItLoaded(std::string player) {
	char isLoaded;
	bool itsLoaded; //bool to return to the game class
	bool verify = false;
	while (!verify) {
		std::cout << "Is " << player << " die loaded? y or n" << std::endl;
		std::cin >> isLoaded;
		verify = verifyLoaded(isLoaded);
	}
	if (tolower(isLoaded) == 'y')
		itsLoaded = true;
	else
		itsLoaded = false;
	return itsLoaded;
}
/*****************************************************************************
**function that prompts user to enter number of turns
**returns the number of rounds
******************************************************************************/
int Menu::howManyTurns() {
	int turns;
	std::cout << "How many turns should the game go on?" << std::endl;
	turns = verifyInputInt();
	return turns;
}
/*****************************************************************************
**function verifies the input for the function that asks if die is loaded
**takes in the char that the user entered in isItLoaded
**returns a bool value for if the input was valid or not
******************************************************************************/
bool Menu::verifyLoaded(char l) { 
	bool verified;
	if (tolower(l) == 'y' || tolower(l) == 'n')
		verified = true;
	else
		verified = false;
	return verified;
}
/*****************************************************************************
**function to verify that the integer input is valid
**If something other than an int is entered it loeps until valid input is entered
**returns the value of the valid input
******************************************************************************/
int Menu::verifyInputInt() {
	int testInput;
	bool verifying = false;

	while (!verifying) {
		verifying = true;
		std::cin >> testInput;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "The input must be an integer!\n\n Please enter a number:" << std::endl;
			verifying = false;
		}
	}
	return testInput;
}