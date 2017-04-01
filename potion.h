#ifndef _POTION_H_
#define _POTION_H_
#include <string>

class Potion:{
	protected:
    	std::string type;
		int value;
	public:
		Potion(string type,int value);
		int getValue();
		std::string getType();
		virtual ~Potion()=0;
		char getSymb() override; 
};

#endif
