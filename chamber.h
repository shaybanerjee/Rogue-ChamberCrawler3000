#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include "position.h"
#include <vector>

class Chamber {
    std::vector <Position> cham_pos;
    int numTiles;
public:
    Chamber(int i);
    Position getRand();
    void update(Position &p);
    void clear();
};

#endif
