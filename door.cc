#include "door.h"
#include <string>

using namespace std; 

Door::Door(int x, int y) 
	x{x}, y{y} {

}

char Door::getSymb() {
	return '+'; 
}