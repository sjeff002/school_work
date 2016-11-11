#ifndef MENU_HPP
#define MENU_HPP

class Menu {
private:
	int numRows, numCols, startRow, startCol, numSteps;
public:
	void runMenu();
	int getNumRows();
	int getNumCols();
	int getStartRow();
	int getStartCol();
	int getNumSteps();
	void promptAssignGrid();
	bool promptIsRand();
	void promptStartP();
	void promptSteps();
	bool validRand(char);
	bool validStartP(int, int);
	bool validSteps(int);
};
#endif
