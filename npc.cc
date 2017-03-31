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

//Overriding the attack method to make sure non player characters has a
//50% chance of missing when attaching humans
bool Npc::attack(Character &c){
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character c
    if((rand() % 2) == 1){
        //reduce character c's hp after attacking c
        c.setHp(c.getHp() - damageAgainst(c));
        return true;
    }
    return false;
}
