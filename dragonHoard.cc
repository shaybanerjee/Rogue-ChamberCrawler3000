#include "dragonHoard.h"


//Constructor
DragonHoard::DragonHoard():Treasure{6}, deadDrago{false}{
}

void DragonHoard::setDragon(Dragon* d) {
    Drago = d;
}

Dragon* DragonHoard::getDragon() {
    return Drago;
}

bool DragonHoard::getDeadDrago(){
    return deadDrago;
}
void DragonHoard::setDeadDrago(bool newDeadDrago){
    deadDrago = newDeadDrago;
}
