#include "passageway.h"
#include <string>

using namespace std; 

PassageWay::PassageWay(int x, int y) 
	x{x}, y{y}, type{"passageway"} {

}

string PassageWay::get_type() {
	return type; 
}