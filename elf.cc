#include "elf.h"
#include <cstdlib>

//Constructor
Elf::Elf(int hp, int atk, int def, bool hasMoved):
Npc{hp, atk, def, hasMoved}{}

//override the attack method because elfs gets two attacks against
//every race except drow
void Elf::attack(PlayerCharacter *pc){
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character pc
    if((rand() % 2) == 1){
        int hpAfter;
        if(pc->getName() == "Drow"){
            //reduce character c's hp after attacking pc
            hpAfter = pc->getHp() - damageAgainst(pc);
            //reduce character pc's hp after being attacked
            if(hpAfter < 0){
                pc->setHp(0);
            }else{
                pc->setHp(hpAfter);
            }
        }else{
            //reduce character pc's hp after attacking pc
            hpAfter = pc->getHp() - damageAgainst(pc);
            //reduce character pc's hp after being attacked
            if(hpAfter < 0){
                pc->setHp(0);
            }else{
                pc->setHp(hpAfter);
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
            }
        }
    }
}

//Overriding getSymb method to return the character that represents
//the object
char Elf::getSymb(){
    return 'E';
}
