#ifndef _dragon_h_
#define _dragon_h_
#include "npc.h"

class Dragon: public Npc{
    int dhX;
    int dhY;
public:
    //Constructor
    Dragon(int hp = 150, int atk = 20, int def = 20, bool hasMoved = false);
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
    void setDhX(int newDhX);
    void setDhY(int newDhY);
    int getDhX();
    int getDhY();
};

#endif
