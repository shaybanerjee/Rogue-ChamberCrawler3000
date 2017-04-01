#include "treasure.h"


int Treasure::getValue(){
	return value;
}

Treasure::Treasure(const int value): value{value}{
}

char Treasure::getSymb() {
	return 'G'; 
}
