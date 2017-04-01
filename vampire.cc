#include "vampire.h"
#include <cstdlib>

//Constructor
Vampire::Vampire(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{
    maxHp = -1;
}

//overriding the attack method so that vampire also gains 5hp every successful
//attack except if it attacks a dwarf, then it will lose 5hp every successful
//attack
bool Vampire::attack(Npc &enemy){
    if(c.getSymb() == 'L'){
        //if random generated number with 50/50 chance of 0 or 1 generates 0,
        //then this indicates the player missed.
        if((rand() % 2) == 0) return false;
    }
    
    //reduce character c's hp after attacking c
    enemy.setHp(enemy.getHp() - damageAgainst(enemy));
    
    //if the enemy being attacked is human and it's also killed, we'll increase
    //the current gold by 2
    if(enemy.getSymb() == 'H' && enemy.alive() == false){
        numGold += 2;
    }
    
    //If hitting a merchant, the merchants now become hostile
    if(enemy.getSymb() == 'M'){
        enemy.turnHostile();
    }
    
    //if a dwarf, this causes vampires to subtract it's hp by 5, otherwise,
    //vampire gains 5hp
    if(enemy.getSymb() == 'W'){
        setHp(getHp() - 5);
    }else{
        setHp(getHp() + 5);
    }
    
    return true;
}

//Overriding getSymb method to return the character that represents
//the object
char Vampire::getSymb(){
    return '@';
}
