#ifndef _FLOOR_H_
#define _FLOOR_H_

class Floor : public Tile {
	const std::string type; 	
public: 
	Floor(int x, int y); 
	std::string get_type(); 
}; 

#endif 