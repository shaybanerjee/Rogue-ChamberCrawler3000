#include "drow.h"
const double magnifyEffects = 1.5;

//Constructor
Drow::Drow(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{}

//Overriding the usePotion method to have drows magnify potions
//effects by 1.5
void Drow::usePotion(Potion *p){
    std::string potionType = p->getType();
    
    //boost attack
    if(potionType == "BA"){
        setAtk(getAtk() + (int)(p->getValue() * magnifyEffects));
        if(isUsed(p) == false) usedPotions.emplace_back("BA");
    }
    //wound attack
    if(potionType == "WA"){
        setAtk(getAtk() - (int)(p->getValue() * magnifyEffects));
        if(getAtk() < 0) setAtk(0);
        if(isUsed(p) == false) usedPotions.emplace_back("WA");
    }
    //boost defence
    if(potionType == "BD"){
        setDef(getDef() + (int)(p->getValue() * magnifyEffects));
        if(isUsed(p) == false) usedPotions.emplace_back("BD");
    }
    //wound defence
    if(potionType == "WD"){
        setDef(getDef() - (int)(p->getValue() * magnifyEffects));
        if(getDef() < 0) setDef(0);
        if(isUsed(p) == false) usedPotions.emplace_back("WD");
    }
    //Restore health
    if(potionType == "RH"){
        setHp(getHp() + (int)(p->getValue() * magnifyEffects));
        if(isUsed(p) == false) usedPotions.emplace_back("RH");
    }
    //Potion health
    if(potionType == "PH"){
        setHp(getHp() - (int)(p->getValue() * magnifyEffects));
        //Setting hp to maxHp if it's over the maxHp limit and also checking
        //if it's not a vampire
        if(maxHp != -1 && getHp() > maxHp) setHp(maxHp);
        if(isUsed(p) == false) usedPotions.emplace_back("PH");
    }
}


//Overriding getSymb method to return the character that represents
//the object
char Drow::getSymb(){
    return '@';
}
