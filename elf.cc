#include "elf.h"
#include <cstdlib>
#include <sstream>

//Constructor
Elf::Elf(int hp, int atk, int def, bool hasMoved):
Npc{hp, atk, def, hasMoved}{}

//override the attack method because elfs gets two attacks against
//every race except drow
void Elf::attack(PlayerCharacter *pc){
    std::string newAction;
    std::stringstream damage;
    std::stringstream npcType;
    npcType << getSymb();
    damage << damageAgainst(pc);
    int hpAfter;
    
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character pc
    if((rand() % 2) == 1){
        if(pc->getName() == "Drow"){
            //reduce character pc's hp after attacking pc
            hpAfter = pc->getHp() - damageAgainst(pc);
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
        }else{
            //reduce character pc's hp after attacking pc
            hpAfter = pc->getHp() - damageAgainst(pc);
            //reduce character pc's hp after being attacked
            if(hpAfter < 0){
                pc->setHp(0);
            }else{
                pc->setHp(hpAfter);
            }
            
            newAction = npcType.str() + " deals " + damage.str() + " damage to PC.";
            
            //If PC dies, elf does not attack again.
            if(hpAfter < 0){
                if(pc->getAction().size() > 0){
                    pc->setAction(pc->getAction() + " " + newAction);
                }else{
                    pc->setAction(newAction);
                }
                return;
            }
            
            //Randomizing hit chances again to see if it hits
            if((rand() % 2) == 1){
                //attacks c again if it hits
                hpAfter = pc->getHp() - damageAgainst(pc);
                //reduce character pc's hp after being attacked
                if(hpAfter < 0){
                    pc->setHp(0);
                }else{
                    pc->setHp(hpAfter);
                }
                newAction += " " + npcType.str() + " hits again and deals " + damage.str() + " damage to PC.";
            }else{
                newAction += " " + npcType.str() + " attacks PC and misses again.";
            }
            if(pc->getAction().size() > 0){
                pc->setAction(pc->getAction() + " " + newAction);
            }else{
                pc->setAction(newAction);
            }
        }
    }else{
        newAction = npcType.str() + " attacks PC and misses the first time.";
        //Randomizing hit chances again to see if it hits
        if((rand() % 2) == 1){
            //attacks pc again if it hits
            hpAfter = pc->getHp() - damageAgainst(pc);
            //reduce character pc's hp after being attacked
            if(hpAfter < 0){
                pc->setHp(0);
            }else{
                pc->setHp(hpAfter);
            }
            newAction += " " + npcType.str() + " hits again and deals " + damage.str() + " damage to PC.";
        }else{
            newAction += " " + npcType.str() + " attacks PC and misses again.";
        }
        if(pc->getAction().size() > 0){
            pc->setAction(pc->getAction() + " " + newAction);
        }else{
            pc->setAction(newAction);
        }
    }
}

//Overriding getSymb method to return the character that represents
//the object
char Elf::getSymb(){
    return 'E';
}
