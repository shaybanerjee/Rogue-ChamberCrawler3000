#include "door.h"
#include <string>

using namespace std; 

Door::Door(int x, int y) 
	x{x}, y{y}, type{"door"} {

}

string Door::get_type() {
	return type; 
}