#include <cstdlib>
#include "npc.h"

//Constructor
Npc::Npc(int hp, int atk, int def, bool hostile, bool hasMoved):
Character{hp, atk, def}, hostile{hostile}, hasMoved{hasMoved}{}

//Accessors and mutators
bool Npc::getHostile(){
    return hostile;
}

bool Npc::getHasMoved(){
    return hasMoved;
}

void Npc::setHasMoved(bool newHasmoved){
    hasMoved = newHasmoved;
}

//turnHostile turns the current non player character hostile
void Npc::turnHostile(){
    hostile = true;
}

//Creating the attack method to make sure non player characters has a
//50% chance of missing when attaching humans
bool Npc::attack(PlayerCharacter *pc){
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character pc
    if((rand() % 2) == 1){
        //reduce character c's hp after attacking pc
        pc->setHp(pc->getHp() - damageAgainst(pc));
        return true;
    }
    return false;
}
