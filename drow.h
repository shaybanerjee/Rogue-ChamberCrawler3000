#ifndef _drow_h_
#define _drow_h_
#include "playerCharacter.h"

class Drow: public PlayerCharacter{
    
public:
    //Constructor
    Drow(int hp = 150, int atk = 25, int def = 15, std::string name = "Drow");
    
    //Overriding the usePotion method to have drows magnify potions
    //effects by 1.5
    void usePotion(Potion *p) override;
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};

#endif
