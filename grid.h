#ifndef _GRID_H_
#define _GRID_H_
#include <vector>
#include <iostream>
#include "gamesubject.h"
#include "direction.h"
#include "position.h"
#include "playerCharacter.h"
#include "chamber.h"
#include "hwall.h"
#include "vwall.h"
#include "floor.h"
#include "passageway.h"
#include "restoreHealth.h"
#include "door.h"
#include "empty.h"
#include "direction.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include "poisonHealth.h"
#include "boostDef.h"
#include "boostAtk.h"
#include "woundAtk.h"
#include "woundDef.h"
#include "smallGold.h"
#include "normalGold.h"
#include "merchantHoard.h"
#include "dragonHoard.h"
#include "chamber.h"
#include <fstream>

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
    std::string filename;
    const int width; // size of width
    const int height; // size of heigth
    PlayerCharacter *PC;
    bool hostile;
    std::vector <Chamber> cham_arr;
    int level;
    std::string floors[5];
public:
    Grid(std::string filename, PlayerCharacter* PC, bool hostile = false); // grid constructor
    ~Grid(); // grid destructor
    void rand_enemy(); // fill up chambers with enemies randomly
    void rand_potion(); // fill up chambers with potions randomly
    void rand_treasure(); // fill up chambers with tresures randomly
    void rand_stair();
    void rand_player();
    bool isWon();
    void clear();
    bool stuckNpc(int x, int y);
    bool isNpc(char gameType);
    bool playerInSight(int x, int y);
    void moveNpcs();
    void move_enemies(); // move all enemies.
    void usePotion(Direction d); // use potion in that direction
    void atkEnemy(Direction d); // attack enemy in that direction
    void atkByEnemy(); // checks radius if enemy should attack
    void move(Direction d); // player Player
    void clearGrid(); // clear the entire grid for a new level
    void restartGrid(PlayerCharacter* p);
    friend std::ostream &operator<<(std::ostream& out,const Grid &gGrid); // output the grid
};


#endif
