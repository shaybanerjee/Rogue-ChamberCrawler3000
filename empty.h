#ifndef _EMPTY_H
#define _EMPTY_H

class Empty : public Tile {
	const std::string type; 	
	public: 
		Empty(int x, int y); 
		std::string get_type(); 
};

#endif