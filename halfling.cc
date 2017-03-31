#include "halfling.h"

//Constructor
Halfling::Halfling(int hp, int atk, int def, bool hostile, bool hasMoved):
Npc{hp, atk, def, hostile, hasMoved}{}

//Overriding getSymb method to return the character that represents
//the object
char Halfling::getSymb(){
    return 'L';
}