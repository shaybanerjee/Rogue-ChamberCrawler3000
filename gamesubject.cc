#include "gamesubject.h"

using namespace std; 

int GameSubject::getX() const {
	return x; 
}

int GameSubject::getY() const {
	return y; 
}

void GameSubject::setX(int newX){
    x = newX;
}

void GameSubject::setY(int newY){
    y = newY;
}
