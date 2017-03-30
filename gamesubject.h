#ifndef GAME_SUBJECT
#define GAME_SUBJECT
#include <vector>

class Observer; 

class GameSubject {
	std::vector <Observer *> observers; // observers of GameSubject
	int x, y; 
	bool is_init; 
public: 
	int get_x() const; 
	int get_y() const; 
	void attach(Observer *);
	void set_false(); 
	void notifyObservers(); // add parameter
	virtual ~GameSubject() = 0; // pv method
};

#endif