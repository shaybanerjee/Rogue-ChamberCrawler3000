#ifndef _POTION_H_
#define _POTION_H_
#include <string>
using namespace std;
class Potion{
	protected:
    	string type;
		int value;
	public:
		Potion(string type,int value);
		int getValue();
		string getType();
		virtual ~Potion()=0;
		char getSymb() override; 
};

#endif
