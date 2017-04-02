#include "dragonHoard.h"

const int value = 6;

//Constructor
DragonHoard::DragonHoard():Treasure{value}{
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
