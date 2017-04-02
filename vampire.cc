#include "vampire.h"
#include <cstdlib>
#include <sstream>

//Constructor
Vampire::Vampire(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{
    maxHp = -1;
}

//overriding the attack method so that vampire also gains 5hp every successful
//attack except if it attacks a dwarf, then it will lose 5hp every successful
//attack
void Vampire::attack(Npc *enemy){
    std::string newAction;
    std::stringstream damage;
    std::stringstream npcType;
    std::stringstream enemyHealth;
    npcType << enemy->getSymb();
    damage << damageAgainst(enemy);
    
    //if a player character attacks a halfing
    //if random generated number with 50/50 chance of 0 or 1 generates 0,
    //then this indicates the player missed.
    if(enemy->getSymb() == 'L' && rand() % 2 == 0){
        newAction = "PC attacks L and misses.";
        if(getAction().size() > 0){
            setAction(getAction() + " " + newAction);
        }else{
            setAction(newAction);
        }
        return;
    }
    
    //reduce character c's hp after attacking c
    enemy->setHp(enemy->getHp() - damageAgainst(enemy));
    enemyHealth << enemy->getHp();
    
    //Checks if the enemy is alive after attacking it
    if(enemy->isAlive()){
        newAction = "PC deals " + damage.str() + " damage to " + npcType.str() + " (" + enemyHealth.str() + ").";
    }else{
        newAction = "PC deals " + damage.str() + " damage to " + npcType.str() + "and slains " + npcType.str() + ".";
    }
    
    //if a dwarf, this causes vampires to subtract it's hp by 5, otherwise,
    //vampire gains 5hp
    if(enemy->getSymb() == 'W'){
        if(isAlive()){
            setHp(getHp() - 5);
        }else{
            setHp(0);
        }
        newAction += " PC also loses 5 Hp after attacking W";
    }else{
        setHp(getHp() + 5);
        newAction += " PC also gains 5 Hp after attacking W.";
    }
    
    //Updating Action
    if(getAction().size() > 0){
        setAction(getAction() + " " + newAction);
    }else{
        setAction(newAction);
    }
    
    //If the enemy is dead after the attack and it's not a dragon, merchant or human, gold
    //is automatically added to the player character with 1/2 probability of it being 1 gold
    //or 2 golds
    if(enemy->isAlive() == false && enemy->getSymb() != 'M' && enemy->getSymb() != 'H' && enemy->getSymb() != 'D'){
        if((rand() % 2) == 0){
            numGold += 1;
        }else{
            numGold += 2;
        }
    }
}

//Overriding getSymb method to return the character that represents
//the object
char Vampire::getSymb(){
    return '@';
}
