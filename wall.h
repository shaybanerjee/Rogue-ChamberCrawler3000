#ifndef _WALL_H
#define _WALL_H

class Empty {
	const std::string type; 	
	public: 
		Wall(int x, int y); 
		std::string get_type(); 
};

#endif