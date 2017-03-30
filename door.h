#ifndef _DOOR_H
#define _DOOR_H

class Door : public Tile {
	const std::string type; 	
	public: 
		Door(int x, int y); 
		std::string get_type(); 
};

#endif 