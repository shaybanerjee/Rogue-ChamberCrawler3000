#ifndef _DRAGON_HOARD_H_
#define _DRAGON_HOARD_H_
#include "treasure.h"

class DragonHoard: public Treasure{
    bool deadDrago;
    int dragoX;
    int dragoY;
public:
    DragonHoard();
    bool getDeadDrago();
    void setDeadDrago(bool newDeadDrago);
    void setDragoX(int newDragoX);
    void setDragoY(int newDragoY);
    int getDragoX();
    int getDragoY();
    ~DragonHoard();
};


#endif
