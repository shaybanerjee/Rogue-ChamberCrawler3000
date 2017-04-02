#ifndef _halfling_h_
#define _halfling_h_
#include "npc.h"

class Halfling: public Npc{
    
public:
    //Constructor
    Halfling(int hp = 100, int atk = 15, int def = 20, bool hasMoved = false);
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb()override;
};

#endif
