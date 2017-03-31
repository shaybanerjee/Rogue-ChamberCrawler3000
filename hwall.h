#ifndef _H_WALL_H_
#define _H_WALL_H_


class Hwall : public Tile {
	public: 
		Hwall(int x, int y); 
		char getSymb() override; 

};

#endif 