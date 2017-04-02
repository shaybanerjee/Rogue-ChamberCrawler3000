#include "human.h"

//Constructor
Human::Human(int hp, int atk, int def, bool hasMoved):
Npc{hp, atk, def, hasMoved}{}

//Overriding getSymb method to return the character that represents
//the object
char Human::getSymb(){
    return 'H';
}
