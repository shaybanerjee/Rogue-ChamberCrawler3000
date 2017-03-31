#include "orc.h"
#include <cstdlib>

//Constructor
Orc::Orc(int hp, int atk, int def, bool hostile, bool hasMoved):
Npc{hp, atk, def, hostile, hasMoved}{}

//overriding the attack method so that an Orc does 50% more damage to goblins
bool Orc::attack(Character &c){
    //if random generated number with 50/50 chance of 0 or 1 generates 1,
    //then this indicates the player hit the character c
    if((rand() % 2) == 1){
        if(c.getName() == "Goblin"){
            c.setHp(c.getHp() - (int) (1.5 * damageAgainst(c)));
        }else{
            c.setHp(c.getHp() - damageAgainst(c));
        }
    }
}

//Overriding getSymb method to return the character that represents
//the object
char Orc::getSymb(){
    return 'O';
}
