#ifndef _character_h_
#define _character_h_
#include "direction.h"

class Character{
    int maxHp;
    int hp;
    int atk;
    int def;
    int numGold;
    
public:
    virtual bool isAlive();
    virtual bool move(Direction d);
    virtual void attack(Character &c);
    virtual int damageAgainst(Character &c);
    virtual ~Character() = 0;
};

#endif
