#include "dragonHoard.h"


//Constructor
DragonHoard::DragonHoard():Treasure{6}, deadDrago{false}{
}

bool DragonHoard::getDeadDrago(){
    return deadDrago;
}
void DragonHoard::setDeadDrago(bool newDeadDrago){
    deadDrago = newDeadDrago;
}

void DragonHoard::setDragoX(int newDragoX){
    dragoX = newDragoX;
}
void DragonHoard::setDragoY(int newDragoY){
    dragoY = newDragoY;
}
int DragonHoard::getDragoX(){
    return dragoX;
}
int DragonHoard::getDragoY(){
    return dragoY;
}
char DragonHoard::getSymb(){
    return 'G';
}
