#include "troll.h"

//Constructor
Troll::Troll(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{}

//Overriding getSymb method to return the character that represents
//the object
char Troll::getSymb(){
    return '@';
}
