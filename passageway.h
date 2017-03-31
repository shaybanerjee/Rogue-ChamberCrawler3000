#ifndef _PASSAGEWAY_H
#define _PASSAGEWAY_H

class PassageWay : public Tile { 	
	public: 
		PassageWay(int x, int y); 
		char getSymb() override; 
};

#endif 