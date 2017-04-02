#include "chamber.h"
#include <cstdlib>
#include <ctime>

Chamber::Chamber(const int i){
    switch(i){
        case 0:
            for (int i = 3; i < 7; ++i){
                for (int j = 3; j < 29; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
            break;
        case 1:
            for (int i = 15; i < 22; ++i ){
                for (int j = 4; j < 25; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
            break;
        case 2:
            for (int i = 10; i < 13; ++i){
                for (int j = 38; j < 50; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
            break;
        case 3:
            for (int i = 3; i < 7; ++i){
                for (int j = 39; j < 62; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
            for (int i = 5; i < 7; ++i){
                for (int j = 62; j<70; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
            cham_pos.emplace_back(Position{70,6});
            cham_pos.emplace_back(Position{71,6});
            cham_pos.emplace_back(Position{72,6});
            for (int i = 7; i < 13; ++i){
                for (int j = 61; j < 76; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
            break;
        case 4:
            for (int i = 16; i < 19; ++i){
                for (int j = 65; j < 76; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
            for (int i = 19; i < 22; ++i){
                for (int j = 37; j < 76; ++j){
                    cham_pos.emplace_back(Position{j,i});
                }
            }
    }
}

Position Chamber::getRand() {
    int sizeOfVec = cham_pos.size();
    srand(time(NULL)); 
    int randVal = rand() % sizeOfVec;
    while(!cham_pos[randVal].isEmpty()) {
        randVal = rand() % sizeOfVec;
    }
    cham_pos[randVal].set_false();
    return cham_pos[randVal];
} 

void Chamber::update(Position &p) {
    p.set_true(); 
}

void Chamber::clear() {
    for (auto pos : cham_pos) {
        pos.set_true(); 
    }
}
