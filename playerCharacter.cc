#include "playerCharacter.h"
#include <algorithm>
#include <cstdlib>

//Constructor
PlayerCharacter::PlayerCharacter(int hp, int atk, int def, std::string name):
Character{hp, atk, def}, name{name}{
    maxHp = hp;
    baseAtk = atk;
    baseDef = def;
    numGold = 0;
    curTile = '.';
}

//Creating accessor for name
std::string PlayerCharacter::getName(){
    return name;
}

//accessor and mutator for currPlace;
char PlayerCharacter::getCurTile(){
    return curTile;
}

void PlayerCharacter::setCurTile(char newCurTile){
    curTile = newCurTile;
}

//addGold takes in an integer gold and adds it to the current amount of gold
void PlayerCharacter::addGold(int gold){
    numGold += gold;
}

//usePotion applies the potion p's effects to the current PlayerCharacter
void PlayerCharacter::usePotion(Potion &p){
    std::string potionType = p.getType();
    
    //boost attack
    if(potionType == "BA"){
        setAtk(getAtk() + p.getValue());
    }
    //wound attack
    if(potionType == "WA"){
        setAtk(getAtk() - p.getValue());
        if(getAtk() < 0) setAtk(0);
    }
    //boost defence
    if(potionType == "BD"){
        setDef(getDef() + p.getValue());
    }
    //wound defence
    if(potionType == "WD"){
        setDef(getDef() - p.getValue());
        if(getDef() < 0) setDef(0);
    }
    //Restore health
    if(potionType == "RH"){
        setHp(getHp() + p.getValue());
        //Setting hp to maxHp if it's over the maxHp limit and also checking
        //if it's not a vampire
        if(maxHp != -1 && getHp() > maxHp) setHp(maxHp);
    }
    //Potion health
    if(potionType == "PH"){
        setHp(getHp() - p.getValue());
    }
}

//isUsed returns true if the potion has been used and false otherwise
bool isUsed(Potion &p){
    return (std::find(usedPotions.begin(), usedPotions.end(), p.getType()) != usedPotions.end());
}

//getStats returns a string which represents the stats of the PlayerCharacter
std::string getStats();

//Creating the attack method to account for the fact that theres a 50% chance
//of missing when attacking a halfing and if a human was killed during the
//attack, 2 gold will be added to the current player character
bool PlayerCharacter::attack(Npc &enemy){
    //if a player character attacks a halfing
    if(enemy.getSymb() == 'L'){
        //if random generated number with 50/50 chance of 0 or 1 generates 0,
        //then this indicates the player missed.
        if((rand() % 2) == 0) return false;
    }
    //If hitting a merchant, the merchants now become hostile
    if(enemy.getSymb() == 'M'){
        enemy.turnHostile();
    }
    
    //reduce character c's hp after attacking c
    enemy.setHp(enemy.getHp() - damageAgainst(enemy));
    
    //if the character being attacked is human and it's also killed, we'll increase
    //the current gold by 2
    if(enemy.getSymb() == 'H' && c.alive() == false){
        numGold += 2;
    }
    return true;
}
