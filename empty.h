#ifndef _EMPTY_H
#define _EMPTY_H
#include "tile.h"

class Empty : public Tile {
	public: 
		char getSymb() override;
};

#endif
