#ifndef _DRAGON_HOARD_H_
#define _DRAGON_HOARD_H_
#include "dragon.h"
#include "treasure.h"
class DragonHoard: public Treasure{
    Dragon* Drago;
    bool deadDrago;
public:
    DragonHoard();
    //Accessors and mutators for the fields
    void setDragon(Dragon* d);
    Dragon* getDragon();
    bool getDeadDrago();
    void setDeadDrago(bool newDeadDrago);
    ~DragonHoard();
    
};


#endif
