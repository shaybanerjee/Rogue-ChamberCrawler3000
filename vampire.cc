#include "vampire.h"
#include <cstdlib>

//Constructor
Vampire::Vampire(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{}

//overriding the attack method so that vampire also gains 5hp every successful
//attack except if it attacks a dwarf, then it will lose 5hp every successful
//attack
bool Vampire::attack(Character &c){
    if(c.getSymb() == 'L'){
        //if random generated number with 50/50 chance of 0 or 1 generates 0,
        //then this indicates the player missed.
        if((rand() % 2) == 0) return false;
    }
    
    //reduce character c's hp after attacking c
    c.setHp(c.getHp() - damageAgainst(c));
    
    //if the character being attacked is human and it's also killed, we'll increase
    //the current gold by 2
    if(c.getSymb() == 'H' && c.alive() == false){
        numGold += 2;
    }
    
    //If hitting a merchant, the merchants now become hostile
    if(c.getSymb() == 'M'){
        c.turnHostile();
    }
    
    //if a dwarf, this causes vampires to subtract it's hp by 5, otherwise,
    //vampire gains 5hp
    if(c.getSymb() == 'W'){
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
