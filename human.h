#ifndef _human_h_
#define _human_h_
#include "npc.h"

class Human: public Npc{
    
public:
    //Constructor
    Human(int hp = 140, int atk = 20, int def = 20, bool hostile = true, bool hasMoved = false);
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};


#endif 
