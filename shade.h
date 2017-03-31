#ifndef _shade_h_
#define _shade_h_
#include "playerCharacter.h"

class Shade: public PlayerCharacter{
    
public:
    //Constructor
    Shade(int hp = 125, int atk = 25, int def = 25, std::string name = "Shade");
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};
#endif
