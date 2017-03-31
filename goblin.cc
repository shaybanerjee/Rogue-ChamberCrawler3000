#include "goblin.h"
#include <cstdlib>

//Constructor
Goblin::Goblin(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{}

//overriding the attack method so that Goblin will gain 5 golds if the
//character c being attack dies after the attack
bool Goblin::attack(Character &c){
    if(c.getSymb() == 'L'){
        //if random generated number with 50/50 chance of 0 or 1 generates 0,
        //then this indicates the player missed.
        if((rand() % 2) == 0) return false;
    }
    
    //reduce character c's hp after attacking c
    c.setHp(c.getHp() - damageAgainst(c));
    
    //If hitting a merchant, the merchants now become hostile
    if(c.getSymb() == 'M'){
        c.turnHostile();
    }
    
    //if the character being attacked is human and it's also killed, we'll increase
    //the current gold by 2, also since we also add 5 golds if the enemy is killed
    if(c.alive() == false){
        numGold += 5;
        if(c.getSymb() == 'H'){
            numGold += 2;
        }
    }
    
    return true;
}

//Overriding getSymb method to return the character that represents
//the object
char Goblin::getSymb(){
    return '@';
}
