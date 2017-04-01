#include "character.h"
#include <math.h>

//Constructor
Character::Character(int hp, int atk, int def):
hp{hp}, atk{atk}, def{def}{}

//Accessors and mutators for hp, atk and def
int Character::getHp(){
    return hp;
}

void Character::setHp(int newHp){
    hp = newHp;
}

int Character::getAtk(){
    return atk;
}

void Character::setAtk(int newAtk){
    atk = newAtk;
}

int Character::getDef(){
    return def;
}

void Character::setDef(int newDef){
    def = newDef;
}

//isAlive returns true if the character is alive and false otherwise
bool Character::isAlive(){
    return hp > 0;
}

//damageAgainst returns the amount of damage the current character does against
//character c
int Character::damageAgainst(Character &c){
    return ceil((100 / 100.0 + c.def) * atk);
}
