#include "orc.h"
#include <cstdlib>
#include <sstream>

//Constructor
Orc::Orc(int hp, int atk, int def, bool hasMoved):
Npc{hp, atk, def, hasMoved}{}

//overriding the attack method so that an Orc does 50% more damage to goblins
void Orc::attack(PlayerCharacter *pc){
    std::string newAction;
    std::stringstream damage;
    std::stringstream npcType;
    npcType << getSymb();
    
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character pc
    if((rand() % 2) == 1){
        int hpAfter;
        damage << damageAgainst(pc);
        if(pc->getName() == "Goblin"){
            hpAfter = pc->getHp() - (int) (1.5 * damageAgainst(pc));
            damage << (int)(damageAgainst(pc) * 1.5);
        }else{
            hpAfter = pc->getHp() - damageAgainst(pc);
            damage << damageAgainst(pc);
        }
        
        //reduce character pc's hp after being attacked
        if(hpAfter < 0){
            pc->setHp(0);
        }else{
            pc->setHp(hpAfter);
        }
        newAction = npcType.str() + " deals " + damage.str() + " damage to PC.";
        if(pc->getAction().size() > 0){
            pc->setAction(pc->getAction() + " " + newAction);
        }else{
            pc->setAction(newAction);
        }
        return;
    }
    newAction = npcType.str() + " attacked PC and missed.";
    if(pc->getAction().size() > 0){
        pc->setAction(pc->getAction() + " " + newAction);
    }else{
        pc->setAction(newAction);
    }
}

//Overriding getSymb method to return the character that represents
//the object
char Orc::getSymb(){
    return 'O';
}
