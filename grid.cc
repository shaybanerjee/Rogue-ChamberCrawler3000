/*
class Grid {
	std::vector <std::vector <GameSubject*>> theGrid; // vector of vector of GameSubjects
	Chamber cham_arr[5]; 
//	std::vector <Position> allPositions; // all positions in chamber (for moving enemies etc) optimization
	// what we could do instead is loop through theGrid check if something is enemy and move accordingly. 
	int gridSize; // size of grid
	GameSubject *PC; 
public: 
	Grid(int n, ifstream &f); // grid constructor 
	~Grid(); // grid destructor
	void rand_fill(); // fill up chambers randomly
	void check_radius(); // should be called before and after move()
	void move_enemies(); // move all enemies. 
	void move(Direction d); 
	std::ostream &operator<<(std::ostream& out, const theGrid); // output the grid
};
*/

#include "grid.h"
#include <iostream>

using namespace std; 


Grid::Grid(int n, ifstream &f) 
	: gridSize{n}, f{f} {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {

		}

	}

}

ostream &operator<<(ostream &out, const theGrid) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			GameSubject* curr_sub = theGrid[i][j]; 
			out << curr_sub->get_symb() << endl; 
		}
	}
}



