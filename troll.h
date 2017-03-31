#ifndef _troll_h_
#define _troll_h_
#include "playerCharacter.h"

class Troll: public PlayerCharacter{
    
public:
    //Constructor
    Troll(int hp = 120, int atk = 25, int def = 15, std::string name = "Troll");
    
    //in grid, add 5hp to troll everytime the troll moves
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};

#endif 
