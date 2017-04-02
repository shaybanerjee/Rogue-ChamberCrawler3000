#ifndef _vampire_h_
#define _vampire_h_
#include "playerCharacter.h"

class Vampire: public PlayerCharacter{
    
public:
    //Constructor
    Vampire(int hp = 50, int atk = 25, int def = 25, std::string name = "Vampire");
    
    //overriding the attack method so that vampire also gains 5hp every successful
    //attack except if it attacks a dwarf, then it will lose 5hp every successful
    //attack
    void attack(Npc *enemy) override;
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};


#endif 
