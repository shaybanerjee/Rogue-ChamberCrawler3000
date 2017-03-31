#ifndef _VWALL_H
#define _VWALL_H

class Vwall : public Tile {	
	public: 
		Vwall(int x, int y); 
		char getSymb() override; 
};

#endif