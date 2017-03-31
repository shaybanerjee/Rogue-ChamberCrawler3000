#ifndef _TREASURE_H_
#define _TREASURE_H_

class Treasure {
	protected:
		int value;
	public:
		int getValue():
		virtual ~Treasure() =0;
		char getSymb() override; 
};

#endif