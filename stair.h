#ifndef _STAIR_H
#define _STAIR_H

class Stair : public Tile {
	const std::string type; 	
	public: 
		Stair(int x, int y); 
		std::string get_type(); 
};

#endif 