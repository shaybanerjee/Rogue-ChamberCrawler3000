#ifndef _npc_h_
#define _npc_h_
#include "character.h"
#include "playerCharacter.h"

class PlayerCharacter;

class Npc: public Character{
    bool hasMoved;
    
public:
    //Constructor
    Npc(int hp, int atk, int def, bool hasMoved = false);
    
    //Accessors and mutators
    bool getHasMoved();
    void setHasMoved(bool newHasmoved);
    
    //Creating the attack method to make sure non player characters has a
    //50% chance of missing when attaching humans
    virtual bool attack(PlayerCharacter *pc);
};

#endif
