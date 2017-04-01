#include "elf.h"
#include <cstdlib>

//Constructor
Elf::Elf(int hp, int atk, int def, bool hostile, bool hasMoved):
Npc{hp, atk, def, hostile, hasMoved}{}

//override the attack method because elfs gets two attacks against
//every race except drow
bool Elf::attack(PlayerCharacter *pc){
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character pc
    if((rand() % 2) == 1){
        if(pc->getName() == "Drow"){
            //reduce character c's hp after attacking pc
            pc->setHp(pc->getHp() - damageAgainst(pc));
            return true;
        }else{
            //reduce character pc's hp after attacking pc
            pc->setHp(pc->getHp() - damageAgainst(pc));
            
            //Randomizing hit chances again to see if it hits
            if((rand() % 2) == 1){
                //attacks c again if it hits
                pc->setHp(pc->getHp() - damageAgainst(pc));
                return true;
            }
        }
    }
    return false;
}

//Overriding getSymb method to return the character that represents
//the object
char Elf::getSymb(){
    return 'E';
}
