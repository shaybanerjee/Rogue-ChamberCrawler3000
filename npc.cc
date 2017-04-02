#include <cstdlib>
#include "npc.h"
#include <sstream>

//Constructor
Npc::Npc(int hp, int atk, int def, bool hasMoved):
Character{hp, atk, def}, hasMoved{hasMoved}{}

bool Npc::getHasMoved(){
    return hasMoved;
}

void Npc::setHasMoved(bool newHasmoved){
    hasMoved = newHasmoved;
}

//Creating the attack method to make sure non player characters has a
//50% chance of missing when attaching humans
void Npc::attack(PlayerCharacter *pc){
    std::string newAction;
    std::stringstream damage;
    std::stringstream npcType;
    npcType << getSymb();
    
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character pc
    if((rand() % 2) == 1){
        damage << damageAgainst(pc);
        
        //reduce character pc's hp after being attacked
        int hpAfter = pc->getHp() - damageAgainst(pc);
        if(hpAfter < 0){
            pc->setHp(0);
        }else{
            pc->setHp(hpAfter);
        }
        
        newAction = npcType.str() + " deals " + damage.str() + " damage to PC.";
    }
    newAction = npcType.str() + " attacked PC and missed.";
    if(pc->getAction().size() > 0){
        pc->setAction(pc->getAction() + " " + newAction);
    }else{
        pc->setAction(newAction);
    }
}
