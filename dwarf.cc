#include "dwarf.h"

//Constructor
Dwarf::Dwarf(int hp, int atk, int def, bool hasMoved):
Npc{hp, atk, def, hasMoved}{}

//Overriding getSymb method to return the character that represents
//the object
char Dwarf::getSymb(){
    return 'W';
}
