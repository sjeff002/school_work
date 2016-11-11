#include "grid.hpp"
#include "menu.hpp"

int main() {

	int row, col, steps, startr, startc;
	Menu m;

	m.runMenu();
	row = m.getNumRows();
	col = m.getNumCols();
	steps = m.getNumSteps();
	startr = m.getStartRow();
	startc = m.getStartCol();
	Grid g(row, row, steps);
	Ant a(startr, startc);


	g.start(a);

	return 0;
}