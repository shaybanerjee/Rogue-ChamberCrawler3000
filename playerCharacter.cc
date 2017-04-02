#include "playerCharacter.h"
#include <algorithm>
#include <cstdlib>
#include <sstream>

//Constructor
PlayerCharacter::PlayerCharacter(int hp, int atk, int def, std::string name):
Character{hp, atk, def}, name{name}{
    maxHp = hp;
    baseAtk = atk;
    baseDef = def;
    numGold = 0;
    curTile = '.';
    action = "";
}

//Creating accessor for name and gold
std::string PlayerCharacter::getName(){
    return name;
}

int PlayerCharacter::getNumGold(){
    return numGold;
}

//accessor and mutator for currPlace and Action;
char PlayerCharacter::getCurTile(){
    return curTile;
}

void PlayerCharacter::setCurTile(char newCurTile){
    curTile = newCurTile;
}

std::string PlayerCharacter::getAction(){
    return action;
}

void PlayerCharacter::setAction(std::string newAction){
    action = newAction;
}

//addGold takes in an integer gold and adds it to the current amount of gold
void PlayerCharacter::addGold(int gold){
    numGold += gold;
}

//usePotion applies the potion p's effects to the current PlayerCharacter
void PlayerCharacter::usePotion(Potion *p){
    std::string potionType = p->getType();
    
    //boost attack
    if(potionType == "BA"){
        setAtk(getAtk() + p->getValue());
        if(isUsed(p) == false) usedPotions.emplace_back("BA");
    }
    //wound attack
    if(potionType == "WA"){
        setAtk(getAtk() - p->getValue());
        if(getAtk() < 0) setAtk(0);
        if(isUsed(p) == false) usedPotions.emplace_back("WA");
    }
    //boost defence
    if(potionType == "BD"){
        setDef(getDef() + p->getValue());
        if(isUsed(p) == false) usedPotions.emplace_back("BD");
    }
    //wound defence
    if(potionType == "WD"){
        setDef(getDef() - p->getValue());
        if(getDef() < 0) setDef(0);
        if(isUsed(p) == false) usedPotions.emplace_back("WD");
    }
    //Restore health
    if(potionType == "RH"){
        setHp(getHp() + p->getValue());
        //Setting hp to maxHp if it's over the maxHp limit and also checking
        //if it's not a vampire
        if(maxHp != -1 && getHp() > maxHp) setHp(maxHp);
        if(isUsed(p) == false) usedPotions.emplace_back("RH");
    }
    //Potion health
    if(potionType == "PH"){
        setHp(getHp() - p->getValue());
        if(isUsed(p) == false) usedPotions.emplace_back("PH");
    }
}

//isUsed returns true if the potion has been used and false otherwise
bool PlayerCharacter::isUsed(Potion *p){
    return (std::find(usedPotions.begin(), usedPotions.end(), p->getType()) != usedPotions.end());
}

//Creating the attack method to account for the fact that theres a 50% chance
//of missing when attacking a halfing and if a human was killed during the
//attack, 2 gold will be added to the current player character
void PlayerCharacter::attack(Npc *enemy){
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
