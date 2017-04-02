#ifndef _merchant_h_
#define _merchant_h_
#include "npc.h"

class Merchant: public Npc{
    
public:
    //Constructor
    Merchant(int hp = 30, int atk = 70, int def = 5, bool hasMoved = false);
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};

#endif
