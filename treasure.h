#ifndef _TREASURE_H_
#define _TREASURE_H_
#include "gamesubject.h"
class Treasure: public GameSubject {
	protected:
		int value;
	public:
        virtual int getValue();
        Treasure(int value);
};

#endif
