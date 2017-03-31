#include "hwall.h"

using namespace std; 

Hwall::Hwall(int x, int y) 
	: x{x}, y{y} {}


char Hwall::getSymb() {
	return '-'; 
}