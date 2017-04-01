#ifndef _DRAGON_HOARD_H_
#define _DRAGON_HOARD_H_
#include "dragon.h"

class DragonHoard:public Treasure{
	DragonHoard();
	Dragon* Drago; 
public: 
	void setDragon(Dragon* d);
	Dragon* getDragon();  

};


#endif