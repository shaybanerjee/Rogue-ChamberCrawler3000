#ifndef _TREASURE_H_
#define _TREASURE_H_
#include "gamesubject.h"
class Treasure: public GameSubject {
	protected:
		int value;
	public:
        int getValue();
        Treasure(int value);
		char getSymb() override;
};

#endif
