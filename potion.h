#ifndef _POTION_H_
#define _POTION_H_
#include <string>
#include "gamesubject.h"

class Potion : public GameSubject{
	protected:
    	std::string type;
		int value;
	public:
        Potion(std::string type,int value);
		int getValue();
		std::string getType();
		char getSymb() override; 
};

#endif
