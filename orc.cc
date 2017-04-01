#include "orc.h"
#include <cstdlib>

//Constructor
Orc::Orc(int hp, int atk, int def, bool hostile, bool hasMoved):
Npc{hp, atk, def, hostile, hasMoved}{}

//overriding the attack method so that an Orc does 50% more damage to goblins
bool Orc::attack(PlayerCharacter *pc){
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character pc
    if((rand() % 2) == 1){
        if(pc->getName() == "Goblin"){
            pc->setHp(pc->getHp() - (int) (1.5 * damageAgainst(pc)));
        }else{
            pc->setHp(pc->getHp() - damageAgainst(pc));
        }
        return true;
    }
    return false;
}

//Overriding getSymb method to return the character that represents
//the object
char Orc::getSymb(){
    return 'O';
}
