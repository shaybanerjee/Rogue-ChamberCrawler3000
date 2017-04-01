#include "position.h"

Position::Position(const int pos_x, const int pos_y):pos_x{pos_x}, pos_y{pos_y}, is_empty{false}{

}

void Position::set_false(){
	is_empty = false;
}