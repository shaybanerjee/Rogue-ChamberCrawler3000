#ifndef _FLOOR_H_
#define _FLOOR_H_

class Floor : public Tile { 	
public: 
	Floor(int x, int y); 
	char getSymb() override; 
}; 

#endif 