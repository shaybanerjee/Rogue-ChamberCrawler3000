#include "shade.h"
//Constructor
Shade::Shade(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{}

//Overriding getSymb method to return the character that represents
//the object
char Shade::getSymb(){
    return '@';
}
