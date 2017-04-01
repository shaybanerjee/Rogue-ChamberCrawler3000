#ifndef _GRID_H_
#define _GRID_H_
#include <vector>
#include "gamesubject.h"
#include "direction.h"
#include "position.h"
#include "playerCharacter.h"
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
	// what we could do instead is loop through theGrid check if something is enemy and move accordingly. 
	const int width; // size of width
	const int hight; // size of heigth 
	GameSubject &PC; 
	int level; 
public: 
	Grid(ifstream &f, GameSubject& PC); // grid constructor 
	~Grid(); // grid destructor
	void rand_enemy(); // fill up chambers with enemies randomly
	void rand_potion(); // fill up chambers with potions randomly
	void rand_tresure(); // fill up chambers with tresures randomly
	void move_enemies(); // move all enemies. 
	void usePotion(Direction d); // use potion in that direction
	void atkEnemy(Direction d); // attack enemy in that direction
	void atkByEnemy(); // checks radius if enemy should attack
	void move(Direction d); // player Player 
	void clear_grid(); // clear the entire grid for a new level 
	std::ostream &operator<<(std::ostream& out, const theGrid); // output the grid
};

#endif