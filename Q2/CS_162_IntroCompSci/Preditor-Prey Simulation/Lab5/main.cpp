#include "Grid.hpp"
#include <ctime>
#include <cstdlib>

int main() {

	unsigned seed;
	seed = time(0);
	srand(seed);
	Grid g1;

	g1.menu();

	system("pause");
	return 0;
}