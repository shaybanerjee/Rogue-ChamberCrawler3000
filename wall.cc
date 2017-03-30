#include "wall.h"
#include <string>

using namespace std; 

Wall::Wall(int x, int y) 
	x{x}, y{y}, type{"wall"} {

}

string Wall::get_type() {
	return type; 
}