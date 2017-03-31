#ifndef _GRID_H_
#define _GRID_H_
#include <vector>
#include "gamesubject.h"
#include "direction.h"
#include "position.h"
#include "chamber.h"

class GameSubject; 
class Chamber; 
class Shade; 
class Vampire;
class Troll;
class Goblin;
class Elf;
class Human; 
class Dwarf;
class Orc;
class Merchant;
class Dragon; 
class Halfling; 


class Grid {
	std::vector <std::vector <GameSubject*>> theGrid; // vector of vector of GameSubjects
	Chamber cham_arr[5]; 
	ifstream &f; 
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

#endif