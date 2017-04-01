#ifndef _character_h_
#define _character_h_
#include "direction.h"

class Character{
    
int hp;
int atk;
int def;

public:
    //Constructor
    Character(int hp, int atk, int def);
    
    //Accessors and mutators for hp, atk and def
    int getHp();
    void setHp(int newHp);
    int getAtk();
    void setAtk(int newAtk);
    int getDef();
    void setDef(int newDef);
    
    //isAlive returns true if the character is alive and false otherwise
    bool isAlive();
    
    //damageAgainst returns the amount of damage the current character does against
    //character c
    int damageAgainst(Character &c);
};

#endif
