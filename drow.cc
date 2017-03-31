#include "drow.h"
const double magnifyEffects = 1.5;

//Constructor
Drow::Drow(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{}

//Overriding the usePotion method to have drows magnify potions
//effects by 1.5
void Drow::usePotion(Potion &p){
    std::string potionType = p.getType();
    
    //boost attack
    if(potionType == "BA"){
        setAtk(getAtk() + (int)(p.getValue() * magnifyEffects));
    }
    //wound attack
    if(potionType == "WA"){
        setAtk(getAtk() - (int)(p.getValue() * magnifyEffects));
    }
    //boost defence
    if(potionType == "BD"){
        setDef(getDef() + (int)(p.getValue() * magnifyEffects));
    }
    //wound defence
    if(potionType == "WD"){
        setDef(getDef() - (int)(p.getValue() * magnifyEffects));
    }
    //Restore health
    if(potionType == "RH"){
        setHp(getHp() + (int)(p.getValue() * magnifyEffects));
    }
    //Potion health
    if(potionType == "PH"){
        setHp(getHp() - (int)(p.getValue() * magnifyEffects));
    }
}


//Overriding getSymb method to return the character that represents
//the object
char Drow::getSymb(){
    return '@';
}
