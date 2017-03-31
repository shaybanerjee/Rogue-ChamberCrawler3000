#ifndef _npc_h_
#define _npc_h_
#include "character.h"

class Npc: public Character{
    bool hostile;
    bool hasMoved;
    
public:
    //Constructor
    Npc(int hp, int atk, int def, bool hostile = false, bool hasMoved = false);
    
    //Accessors and mutators
    bool getHostile();
    bool getHasMoved();
    void setHasMoved(bool newHasmoved);
    
    //turnHostile turns the current non player character hostile
    void turnHostile();
    
    //Overriding the attack method to make sure non player characters has a
    //50% chance of missing when attaching humans
    bool attack(Character &c) override;
};

#endif
