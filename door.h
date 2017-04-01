#ifndef _DOOR_H
#define _DOOR_H
#include "tile.h"
class Door : public Tile {	
	public: 
		char getSymb() override;
};

#endif 
