#ifndef _SMALL_GOLD_H
#define _SMALL_GOLD_H
#include "treasure.h"
class SmallGold:public Treasure{
public:
	SmallGold();
    char getSymb() override;
};

#endif
