#ifndef _dwarf_h_
#define _dwarf_h_

#include "npc.h"

class Dwarf: public Npc{
    
public:
    //Constructor
    Dwarf(int hp = 100, int atk = 20, int def = 30, bool hostile = false, bool hasMoved = false);
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};

#endif 
