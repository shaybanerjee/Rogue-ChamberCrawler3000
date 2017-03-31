#include "elf.h"
#include <cstdlib>

//Constructor
Elf::Elf(int hp, int atk, int def, bool hostile, bool hasMoved):
Npc{hp, atk, def, hostile, hasMoved}{}

//override the attack method because elfs gets two attacks against
//every race except drow
bool Elf::attack(Character &c){
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character c
    if((rand() % 2) == 1){
        if(c.getName() == "Drow"){
            //reduce character c's hp after attacking c
            c.setHp(c.getHp() - damageAgainst(c));
            return true;
        }else{
            //reduce character c's hp after attacking c
            c.setHp(c.getHp() - damageAgainst(c));
            
            //Randomizing hit chances again to see if it hits
            if((rand() % 2) == 1){
                //attacks c again if it hits
                c.setHp(c.getHp() - damageAgainst(c));
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
