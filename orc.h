#ifndef _orc_h_
#define _orc_h_

#include "npc.h"

class Orc: public Npc{
    
public:
    //Constructor
    Orc(int hp = 180, int atk = 30, int def = 25, bool hasMoved = false);
    
    //overriding the attack method so that an Orc does 50% more damage to goblins
    void attack(PlayerCharacter *pc) override;
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};

#endif
