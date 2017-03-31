#include "wall.h"

using namespace std; 

Vwall::Vwall(int x, int y) 
	x{x}, y{y} {}

char Vwall::getSymb() {
	return '|'; 
}