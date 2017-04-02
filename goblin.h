#ifndef _goblin_h_
#define _goblin_h_
#include "playerCharacter.h"

class Goblin: public PlayerCharacter{
    
public:
    //Constructor
    Goblin(int hp = 110, int atk = 15, int def = 20, std::string name = "Goblin");
    
    //overriding the attack method so that Goblin will gain 5 golds if the
    //character enemy being attack dies after the attack
    void attack(Npc *enemy) override;
    
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};

#endif 
