#ifndef _DOOR_H
#define _DOOR_H

class Door : public Tile {	
	public: 
		Door(int x, int y); 
		char getSymb() override; 
};

#endif 