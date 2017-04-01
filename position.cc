#include "position.h"

Position::Position(const int pos_x, const int pos_y):pos_x{pos_x}, pos_y{pos_y}, is_empty{true}{

}

void Position::set_false() {
	is_empty = false;
}

void Position::set_true() { 
	is_empty = true; 
}

int Position::getX() {
    return pos_x;
}

int Position::getY() {
    return pos_y;
    
}

bool Position::isEmpty() {
    return is_empty;
    
}
