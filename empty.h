#ifndef _EMPTY_H
#define _EMPTY_H

class Empty : public Tile {
	public: 
		Empty(int x, int y); 
		char getSymb() override; 
};

#endif