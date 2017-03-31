#ifndef GAME_SUBJECT
#define GAME_SUBJECT
#include <vector>

class Observer; 

class GameSubject {
	std::vector <Observer *> observers; // observers of GameSubject
	int x, y; 
public: 
	int get_x() const; 
	int get_y() const; 
	virtual char getSymb() = 0; // pv get_symb method
};

#endif