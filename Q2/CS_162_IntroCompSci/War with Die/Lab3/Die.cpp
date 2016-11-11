#include "Die.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
//constructor, takes in an int sets numSides to that int
Die::Die(int s) {
	numSides = s;
}

/*****************************************************************************
**Funtion to roll die
**Randomly generates a number and returns that number
******************************************************************************/
int Die::roll() {
	int numberRolled;
	return rand() % numSides + 1; 
}
//constructor
LoadedDie::LoadedDie(int s) : Die(s){}
/*****************************************************************************
**Funtion to roll loaded die
**calls die roll function, generates another random number
**returns highest value or die roll value dependong on value from second random
**number.
******************************************************************************/
int LoadedDie::roll() {
	int numberRolled = Die::roll(); 
	bool temp = rand() % 2; 
	if (temp)
		return numSides;
	else
		return numberRolled;
}
