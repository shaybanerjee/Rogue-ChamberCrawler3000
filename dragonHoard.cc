#include "dragonHoard.h"

const int value = 6;
DragonHoard::DragonHoard():Treasure{value}{
}

void DragonHoard::setDragon(Dragon* d) {
	Drago = d; 
}

Dragon* DragonHoard::getDragon() {
	return Drago; 
}