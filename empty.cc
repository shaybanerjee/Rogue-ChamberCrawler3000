#include "empty.h"
#include <string>

using namespace std; 

Empty::Empty(int x, int y) 
	x{x}, y{y}, type{"empty"} {

}

string Empty::get_type() {
	return type; 
}