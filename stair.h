#ifndef _STAIR_H
#define _STAIR_H

class Stair : public Tile { 	
	public: 
		Stair(int x, int y); 
		char getSymb() override; 
};

#endif 