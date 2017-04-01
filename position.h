#ifndef _POSITION_H_
#define _POSITION_H_

class Position {
	int pos_x;
	int pos_y;
	bool is_empty;
public:
	Position(int pos_x, int pos_y);
	bool is_false(); 
	void set_false(); 
	void set_true(); 
};

#endif