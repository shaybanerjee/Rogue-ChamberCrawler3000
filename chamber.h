#ifndef _CHAMBER_H_
#define _CHAMBER_H_
#include "position.h"
#include <vector>

class Chamber {
    std::vector <Position> cham_pos;
    int numTiles;
    bool isPC;
public:
    Chamber(int i);
    bool isPcPres();
    void setPc();
    Position getRand();
    void update(Position &p);
    void clear();
};

#endif
