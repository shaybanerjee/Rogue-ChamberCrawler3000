#ifndef _PASSAGEWAY_H
#define _PASSAGEWAY_H

class PassageWay : public Tile {
	const std::string type; 	
	public: 
		PassageWay(int x, int y); 
		std::string get_type(); 
};

#endif 