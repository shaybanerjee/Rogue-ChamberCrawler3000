#include "empty.h"
#include <string>

using namespace std; 

Empty::Empty(int x, int y) 
	x{x}, y{y} {

}

char Empty::getSymb() {
	return ' '; 
}