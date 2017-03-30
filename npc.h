#ifndef _npc_h_
#define _npc_h_
#include "character.h"

class Npc: public Character{
    bool hostile;
    bool hasMoved; //This lets you know if a character has been moved each turn so a npc doesn't get moved twice
    
public:

};

#endif
