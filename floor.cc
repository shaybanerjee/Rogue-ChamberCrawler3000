#include "floor.h"
#include <string>

using namespace std; 

Floor::Floor(int x, int y) 
	x{x}, y{y} {

}

char Floor::getSymb() {
	return '.'; 
}

