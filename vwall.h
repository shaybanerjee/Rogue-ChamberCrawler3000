#ifndef _VWALL_H
#define _VWALL_H
#include "tile.h"

class Vwall : public Tile {	
	public: 
		char getSymb() override;
};

#endif
