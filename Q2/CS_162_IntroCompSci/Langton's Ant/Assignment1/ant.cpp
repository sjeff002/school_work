#include "ant.hpp"

Ant::Ant(int r, int c) {
	startRow = r;
	startCol = c;
	direction = "up";
	currRow = startRow;
	currCol = startCol;
}

int Ant::getStartRow() {
	return startRow;
}

int Ant::getStartCol() {
	return startCol;
}

int Ant::getCurrRow() {
	return currRow;
}

int Ant::getCurrCol() {
	return currCol;
}

std::string Ant::getDirection() {
	return direction;
}

void Ant::setDirection(std::string d) {
	direction = d;
}

void Ant::setPosition(int r, int c) {
	currRow = r;
	currCol = c;
}