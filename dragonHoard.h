#ifndef _DRAGON_HOARD_H_
#define _DRAGON_HOARD_H_
#include "dragon.h"
#include "treasure.h"
class DragonHoard: public Treasure{
    Dragon* Drago;
public:
    DragonHoard();
    void setDragon(Dragon* d);
    Dragon* getDragon();
    
};


#endif
