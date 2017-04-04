#include "grid.h"
#include <iostream>
#include <cstdlib>
#include "stair.h"
#include "npc.h"
#include <sstream>
#include "dragon.h"
#include "dragonHoard.h"

using namespace std;

Grid::Grid(string filename, PlayerCharacter* PC, bool hostile) // constructor for Grid
: width{79}, height{25}, filename{filename}, PC{PC}, hostile{hostile}, level{1} { // MIL
    string read_line;
    ifstream f {filename};
    if (filename == "default.txt") {
        for (int i = 0; i < height; ++i) {
            getline(f,read_line);
            vector<GameSubject *> row;
            for (int j = 0; j < width; ++j) {
                GameSubject* gameSub;
                if (read_line[j] == '-') {
                    gameSub = new Hwall();
                    row.emplace_back(gameSub);
                }
                else if (read_line[j] == '|') {
                    gameSub = new Vwall();
                    row.emplace_back(gameSub);
                }
                else if (read_line[j] == '.') {
                    gameSub = new Floor();
                    row.emplace_back(gameSub);
                }
                else if (read_line[j] == '#') {
                    gameSub = new PassageWay();
                    row.emplace_back(gameSub);
                }
                else if (read_line[j] == '+') {
                    gameSub = new Door();
                    row.emplace_back(gameSub);
                }
                else if (read_line[j] == ' ') {
                    gameSub = new Empty();
                    row.emplace_back(gameSub);
                }
            }
            theGrid.emplace_back(row);
        }
    }
    else {
        for (int i = 0; i < 5; ++i) {
            for (int row = 0; row < height; ++row) {
                getline(f, read_line);
                floors[i].append(read_line);
            }
        }
        string currStr = floors[0];
        for (int i = 0; i < height; ++i) {
            int w = 0;
            vector<GameSubject *> row;
            while (w < 79) {
                GameSubject* gameSub;
                if (currStr[w + (i * 79)] == '-') {
                    gameSub = new Hwall();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == '|') {
                    gameSub = new Vwall();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == '.') {
                    gameSub = new Floor();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == '#') {
                    gameSub = new PassageWay();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == '+') {
                    gameSub = new Door();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == ' ') {
                    gameSub = new Empty();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == '0') {
                    gameSub = new RestoreHealth();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == '1') {
                    gameSub = new BoostAtk();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == '2') {
                    gameSub = new BoostDef();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == '3') {
                    gameSub = new PoisonHealth();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == '4') {
                    gameSub = new WoundAtk();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == '5') {
                    gameSub = new WoundDef();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == '6') {
                    gameSub = new NormalGold();
                    row.emplace_back(gameSub);
                    ++w;
                    
                    
                }
                else if (currStr[w + (i * 79)] == '7') {
                    gameSub = new SmallGold();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == '8') {
                    gameSub = new MerchantHoard();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == '9') {
                    gameSub = new DragonHoard();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == '@') {
                    row.emplace_back(PC);
                    PC->setX(w);
                    PC->setY(i);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == 'M') {
                    gameSub = new Merchant();
                    row.emplace_back(gameSub);
                    ++w;
                    
                }
                else if (currStr[w + (i * 79)] == 'L') {
                    gameSub = new Halfling();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == 'D') {
                    gameSub = new Dragon();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == 'W') {
                    gameSub = new Dwarf();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == 'H') {
                    gameSub = new Human();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == 'E') {
                    gameSub = new Elf();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else if (currStr[w + (i * 79)] == 'O'){
                    gameSub = new Orc();
                    row.emplace_back(gameSub);
                    ++w;
                }
                else {
                    gameSub = new Stair();
                    row.emplace_back(gameSub);
                    ++w;
                }
            }
            theGrid.emplace_back(row);
        }
        //Connect Dragons with DragonHoards
        for(int i = 0; i < height; i++){
            for(int k = 0; k < width; k++){
                bool stop = false;
                if(currStr[k + (i * 79)] == 'D' && static_cast<Dragon * >(theGrid[i][k])->getDhX() == -1){
                    if(theGrid[i][k + 1]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i][k + 1])->getValue() == 6
                       && static_cast<DragonHoard *>(theGrid[i][k + 1])->getDragoX() == -1 && !stop){
                        static_cast<Dragon * >(theGrid[i][k])->setDhX(k + 1);
                        static_cast<Dragon * >(theGrid[i][k])->setDhY(i);
                        static_cast<DragonHoard *>(theGrid[i][k + 1])->setDragoX(k);
                        static_cast<DragonHoard *>(theGrid[i][k + 1])->setDragoY(i);
                        stop = true;
                    }
                    if(theGrid[i + 1][k - 1]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i + 1][k - 1])->getValue() == 6
                       && static_cast<DragonHoard *>(theGrid[i + 1][k - 1])->getDragoX() == -1 && !stop){
                        static_cast<Dragon * >(theGrid[i][k])->setDhX(k - 1);
                        static_cast<Dragon * >(theGrid[i][k])->setDhY(i + 1);
                        static_cast<DragonHoard *>(theGrid[i + 1][k - 1])->setDragoX(k);
                        static_cast<DragonHoard *>(theGrid[i + 1][k - 1])->setDragoY(i);
                        stop = true;
                    }
                    if(theGrid[i - 1][k]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i - 1][k])->getValue() == 6
                       && static_cast<DragonHoard *>(theGrid[i - 1][k])->getDragoX() == -1 && !stop){
                        static_cast<Dragon * >(theGrid[i][k])->setDhX(k);
                        static_cast<Dragon * >(theGrid[i][k])->setDhY(i - 1);
                        static_cast<DragonHoard *>(theGrid[i - 1][k])->setDragoX(k);
                        static_cast<DragonHoard *>(theGrid[i - 1][k])->setDragoY(i);
                        stop = true;
                    }
                    if(theGrid[i + 1][k + 1]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i + 1][k + 1])->getValue() == 6
                       && static_cast<DragonHoard *>(theGrid[i + 1][k + 1])->getDragoX() == -1 && !stop){
                        static_cast<Dragon * >(theGrid[i][k])->setDhX(k + 1);
                        static_cast<Dragon * >(theGrid[i][k])->setDhY(i + 1);
                        static_cast<DragonHoard *>(theGrid[i + 1][k + 1])->setDragoX(k);
                        static_cast<DragonHoard *>(theGrid[i + 1][k + 1])->setDragoY(i);
                        stop = true;
                    }
                }
                
                if(currStr[k + (i * 79)] == '9' && static_cast<DragonHoard *>(theGrid[i][k])->getDragoX() == -1){
                    if(theGrid[i][k + 1]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i][k + 1])->getDhX() == -1 && !stop){
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k + 1);
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i);
                        static_cast<Dragon * >(theGrid[i][k + 1])->setDhX(k);
                        static_cast<Dragon * >(theGrid[i][k + 1])->setDhY(i);
                        stop = true;
                    }
                    if(theGrid[i + 1][k - 1]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i + 1][k - 1])->getDhX() == -1 && !stop){
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k - 1);
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i + 1);
                        static_cast<Dragon * >(theGrid[i + 1][k - 1])->setDhX(k);
                        static_cast<Dragon * >(theGrid[i + 1][k - 1])->setDhY(i);
                        stop = true;
                    }
                    if(theGrid[i - 1][k]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i - 1][k])->getDhX() == -1 && !stop){
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k);
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i - 1);
                        static_cast<Dragon * >(theGrid[i - 1][k])->setDhX(k);
                        static_cast<Dragon * >(theGrid[i - 1][k])->setDhY(i);
                        stop = true;
                    }
                    if(theGrid[i + 1][k + 1]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i + 1][k + 1])->getDhX() == -1 && !stop){
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k + 1);
                        static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i + 1);
                        static_cast<Dragon * >(theGrid[i + 1][k + 1])->setDhX(k);
                        static_cast<Dragon * >(theGrid[i + 1][k + 1])->setDhY(i);
                        stop = true;
                    }
                }
            }
        }
        
    }
    
    for (int i = 0; i < 5; ++i) {
        cham_arr.emplace_back(Chamber{i});
    }
}

Grid::~Grid(){ // UPDATED
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            delete theGrid[row][col];
        }
    }
}

void Grid::clear() {
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            if (theGrid[row][col]->getSymb() != '@') {
                delete theGrid[row][col];
            }
        }
    }
    for (int i = 0; i < height; ++i) {
        theGrid[i].clear();
    }
    theGrid.clear();
    string currStr = floors[level];
    for (int i = 0; i < height; ++i) {
        int w = 0;
        vector<GameSubject *> row;
        while (w < 79) {
            GameSubject* gameSub;
            if (currStr[w + (i * 79)] == '-') {
                gameSub = new Hwall();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == '|') {
                gameSub = new Vwall();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == '.') {
                gameSub = new Floor();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == '#') {
                gameSub = new PassageWay();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == '+') {
                gameSub = new Door();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == ' ') {
                gameSub = new Empty();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == '0') {
                gameSub = new RestoreHealth();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == '1') {
                gameSub = new BoostAtk();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == '2') {
                gameSub = new BoostDef();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == '3') {
                gameSub = new PoisonHealth();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == '4') {
                gameSub = new WoundAtk();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == '5') {
                gameSub = new WoundDef();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == '6') {
                gameSub = new NormalGold();
                row.emplace_back(gameSub);
                ++w;
                
                
            }
            else if (currStr[w + (i * 79)] == '7') {
                gameSub = new SmallGold();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == '8') {
                gameSub = new MerchantHoard();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == '9') {
                gameSub = new DragonHoard();
                gameSub->setX(w);
                gameSub->setY(i);
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == '@') {
                row.emplace_back(PC);
                PC->setX(w);
                PC->setY(i);
                ++w;
            }
            else if (currStr[w + (i * 79)] == 'M') {
                gameSub = new Merchant();
                row.emplace_back(gameSub);
                ++w;
                
            }
            else if (currStr[w + (i * 79)] == 'L') {
                gameSub = new Halfling();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == 'D') {
                gameSub = new Dragon();
                gameSub->setX(w);
                gameSub->setY(i);
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == 'W') {
                gameSub = new Dwarf();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == 'H') {
                gameSub = new Human();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == 'E') {
                gameSub = new Elf();
                row.emplace_back(gameSub);
                ++w;
            }
            else if (currStr[w + (i * 79)] == 'O') { // 'O'
                gameSub = new Orc();
                row.emplace_back(gameSub);
                ++w;
            }
            else {
                gameSub = new Stair();
                row.emplace_back(gameSub);
                ++w;
            }
        }
        theGrid.emplace_back(row);
    }
    //Connect Dragons with DragonHoards
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            bool stop = false;
            if(currStr[k + (i * 79)] == 'D' && static_cast<Dragon * >(theGrid[i][k])->getDhX() == -1){
                if(theGrid[i][k + 1]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i][k + 1])->getValue() == 6
                   && static_cast<DragonHoard *>(theGrid[i][k + 1])->getDragoX() == -1 && !stop){
                    static_cast<Dragon * >(theGrid[i][k])->setDhX(k + 1);
                    static_cast<Dragon * >(theGrid[i][k])->setDhY(i);
                    static_cast<DragonHoard *>(theGrid[i][k + 1])->setDragoX(k);
                    static_cast<DragonHoard *>(theGrid[i][k + 1])->setDragoY(i);
                    stop = true;
                }
                if(theGrid[i + 1][k - 1]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i + 1][k - 1])->getValue() == 6
                   && static_cast<DragonHoard *>(theGrid[i + 1][k - 1])->getDragoX() == -1 && !stop){
                    static_cast<Dragon * >(theGrid[i][k])->setDhX(k - 1);
                    static_cast<Dragon * >(theGrid[i][k])->setDhY(i + 1);
                    static_cast<DragonHoard *>(theGrid[i + 1][k - 1])->setDragoX(k);
                    static_cast<DragonHoard *>(theGrid[i + 1][k - 1])->setDragoY(i);
                    stop = true;
                }
                if(theGrid[i - 1][k]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i - 1][k])->getValue() == 6
                   && static_cast<DragonHoard *>(theGrid[i - 1][k])->getDragoX() == -1 && !stop){
                    static_cast<Dragon * >(theGrid[i][k])->setDhX(k);
                    static_cast<Dragon * >(theGrid[i][k])->setDhY(i - 1);
                    static_cast<DragonHoard *>(theGrid[i - 1][k])->setDragoX(k);
                    static_cast<DragonHoard *>(theGrid[i - 1][k])->setDragoY(i);
                    stop = true;
                }
                if(theGrid[i + 1][k + 1]->getSymb() == 'G' && static_cast<Treasure * >(theGrid[i + 1][k + 1])->getValue() == 6
                   && static_cast<DragonHoard *>(theGrid[i + 1][k + 1])->getDragoX() == -1 && !stop){
                    static_cast<Dragon * >(theGrid[i][k])->setDhX(k + 1);
                    static_cast<Dragon * >(theGrid[i][k])->setDhY(i + 1);
                    static_cast<DragonHoard *>(theGrid[i + 1][k + 1])->setDragoX(k);
                    static_cast<DragonHoard *>(theGrid[i + 1][k + 1])->setDragoY(i);
                    stop = true;
                }
            }
            
            if(currStr[k + (i * 79)] == '9' && static_cast<DragonHoard *>(theGrid[i][k])->getDragoX() == -1){
                if(theGrid[i][k + 1]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i][k + 1])->getDhX() == -1 && !stop){
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k + 1);
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i);
                    static_cast<Dragon * >(theGrid[i][k + 1])->setDhX(k);
                    static_cast<Dragon * >(theGrid[i][k + 1])->setDhY(i);
                    stop = true;
                }
                if(theGrid[i + 1][k - 1]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i + 1][k - 1])->getDhX() == -1 && !stop){
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k - 1);
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i + 1);
                    static_cast<Dragon * >(theGrid[i + 1][k - 1])->setDhX(k);
                    static_cast<Dragon * >(theGrid[i + 1][k - 1])->setDhY(i);
                    stop = true;
                }
                if(theGrid[i - 1][k]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i - 1][k])->getDhX() == -1 && !stop){
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k);
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i - 1);
                    static_cast<Dragon * >(theGrid[i - 1][k])->setDhX(k);
                    static_cast<Dragon * >(theGrid[i - 1][k])->setDhY(i);
                    stop = true;
                }
                if(theGrid[i + 1][k + 1]->getSymb() == 'D' && static_cast<Dragon * >(theGrid[i + 1][k + 1])->getDhX() == -1 && !stop){
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoX(k + 1);
                    static_cast<DragonHoard *>(theGrid[i][k])->setDragoY(i + 1);
                    static_cast<Dragon * >(theGrid[i + 1][k + 1])->setDhX(k);
                    static_cast<Dragon * >(theGrid[i + 1][k + 1])->setDhY(i);
                    stop = true;
                }
            }
        }
    }
    ++level;
    PC->setAtk(PC->getBaseAtk());
    PC->setDef(PC->getBaseDef());
}


void Grid::clearGrid() { // method for clear grid after level UPDATED
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            char symb = theGrid[row][col]->getSymb();
            if (symb != '+' && symb != '.' && // if not a tile obj
                symb != ' ' && symb != '-' &&
                symb != '|' && symb != '#') {
                if (symb == '@') { // if player dont delete
                    theGrid[row][col] = new Floor(); // place floor tile
                }
                else {
                    delete theGrid[row][col]; // return heap mem
                    theGrid[row][col] = new Floor(); // place floor tile
                }
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        cham_arr[i].clear(); // reinit chambers
    }
    level++;
    rand_enemy();
    rand_player();
    rand_stair();
    rand_potion();
    rand_treasure();
    PC->setAtk(PC->getBaseAtk());
    PC->setDef(PC->getBaseDef());
}

void Grid::restartGrid(PlayerCharacter *p) { // restarts game UPDATED
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            GameSubject* currSub = theGrid[row][col];
            char symb = currSub->getSymb();
            if (symb != '+' && symb != '.' &&
                symb != ' ' && symb != '-' &&
                symb != '|' && symb != '#') {
                if (symb != '@') {
                    delete theGrid[row][col];
                }
                theGrid[row][col] = new Floor();
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        cham_arr[i].clear();
    }
    delete PC;
    PC = p;
    level = 1;
}

ostream &operator<<(ostream &out,const Grid &gGrid) {
    for (int i = 0; i < gGrid.height; ++i) {
        for (int j = 0; j < gGrid.width; ++j) {
            out << gGrid.theGrid[i][j]->getSymb();
        }
        out << endl;
    }
    
    //Counting the number of characters till gold
    int index = 14;
    index += gGrid.PC->getName().size();
    //Printing out race and gold
    out << "Race: " << gGrid.PC->getName() << " Gold: " << gGrid.PC->getNumGold();
    //Printing out spaces before outputting stairs
    for(int i = index; i < gGrid.width - 8; i++){
        out << " ";
    }
    out << "Floor: " << gGrid.level << endl;
    
    //Printing out HP, Atk and Def and the action
    out << "HP: " << gGrid.PC->getHp() << endl;
    out << "Atk: " << gGrid.PC->getAtk() << endl;
    out << "Def: " << gGrid.PC->getDef() << endl;
    out << "Action: " << gGrid.PC->getAction() << endl;
    
    return out;
}

void Grid::rand_enemy() { // generate random enemy
    int enmCount = 0;
    
    while (enmCount < 20) {
        int enm_val = (rand() % 18) + 1; // get num 1-18
        int chamber_val = rand() % 5;
        if (enm_val >= 1 && enm_val <= 4) { // 4/18
            GameSubject* newSub = new Human();
            Position p = cham_arr[chamber_val].getRand(); // get random pos
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else if (enm_val > 4 && enm_val <= 7) { // 3/18
            GameSubject* newSub = new Dwarf();
            Position p = cham_arr[chamber_val].getRand(); // get random pos
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else if (enm_val > 7 && enm_val <= 12) { // 5/18
            GameSubject* newSub = new Halfling();
            Position p = cham_arr[chamber_val].getRand(); // get random pos
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
            
        }
        else if (enm_val > 12 && enm_val <= 14) { // 2/18
            GameSubject* newSub = new Elf();
            Position p = cham_arr[chamber_val].getRand(); // get random pos
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
            
        }
        else if (enm_val > 14 && enm_val <= 16) { // 2/18
            GameSubject* newSub = new Orc();
            Position p = cham_arr[chamber_val].getRand(); // get random pos
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
            
        }
        else if (enm_val > 16 && enm_val <= 18) { // 2/18
            GameSubject* newSub = new Merchant();
            Position p = cham_arr[chamber_val].getRand(); // get random pos
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        enmCount+=1;
    }
}

void Grid::rand_player() { // randomly place player
    int rand_cham = rand() % 5;
    Position p = cham_arr[rand_cham].getRand();
    for (int i = 0; i < 5; ++i) {
        cham_arr[i].setPcFalse();
    }
    cham_arr[rand_cham].setPc();
    int x = p.getX();
    int y = p.getY();
    delete theGrid[y][x];
    PC->setX(x);
    PC->setY(y);
    theGrid[y][x] = PC;
    PC->setAction("Player character has spawned.");
}

void Grid::rand_stair() { // randomly place stair
    int rand_cham;
    while(true){
        rand_cham = rand() % 5;
        if(!cham_arr[rand_cham].isPcPres()){
            break;
        }
    }
    Position p = cham_arr[rand_cham].getRand();
    int x = p.getX();
    int y = p.getY();
    GameSubject* newSub = new Stair();
    delete theGrid[y][x];
    theGrid[y][x] = newSub;
}

void Grid::rand_potion() { // randomly place potion
    int potCount = 0;
    while (potCount < 10) {
        int pot_val = (rand() % 6) + 1;
        int chamber_val = (rand() % 5);
        if (pot_val == 1) { // 1/6 prob
            GameSubject* newSub = new RestoreHealth();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else if (pot_val == 2) { // 1/6 prob
            GameSubject* newSub = new BoostAtk();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else if (pot_val == 3) { // 1/6 prob
            GameSubject* newSub = new BoostDef();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else if (pot_val == 4) { // 1/6 prob
            GameSubject* newSub = new PoisonHealth();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else if (pot_val == 5) { // 1/6 prob
            GameSubject* newSub = new WoundAtk();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else if (pot_val == 6) { // 1/6 prob
            GameSubject* newSub = new WoundDef();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        potCount += 1;
    }
}


//stuckNpc returns true if the npc has no where to move and false otherwise
bool Grid::stuckNpc(int x, int y){
    if(theGrid[y + 1][x]->getSymb() != '.' && theGrid[y - 1][x]->getSymb() != '.' && theGrid[y][x + 1]->getSymb() != '.'
       && theGrid[y][x - 1]->getSymb() != '.' && theGrid[y + 1][x + 1]->getSymb() != '.' &&
       theGrid[y + 1][x - 1]->getSymb() != '.' && theGrid[y - 1][x + 1]->getSymb() != '.' && theGrid[y - 1][x - 1]->getSymb() != '.'){
        return true;
    }else{
        return false;
    }
}

void Grid::rand_treasure() { // randomly place treasure
    int gCount = 0;
    while (gCount < 10) {
        int rand_int = (rand() % 8) + 1;
        int chamber_val = rand() % 5;
        if (rand_int == 1) { // 1/8 probability
            GameSubject* newSub = new DragonHoard();
            GameSubject* newSub2 = new Dragon();
            bool exit = true;
            while(exit) { // place dragon appropriately
                Position p = cham_arr[chamber_val].getRand();
                int x = p.getX();
                int y = p.getY();
                if (!stuckNpc(x, y)) {
                    delete theGrid[y][x];
                    theGrid[y][x] = newSub;
                    while(true){
                        int rand_int = (rand() % 8) + 1;
                        if (rand_int == 1 && (theGrid[y+1][x-1]->getSymb() == '.')) { // place top right
                            delete theGrid[y+1][x-1];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x-1);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y+1);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y+1][x-1] = newSub2;
                            exit = false;
                            break;
                        }
                        else if (rand_int == 2 && (theGrid[y][x-1]->getSymb() == '.')) { // place above
                            delete theGrid[y][x-1];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x-1);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y][x-1] = newSub2;
                            exit = false;
                            break;
                        }
                        else if (rand_int == 3 && (theGrid[y-1][x-1]->getSymb() == '.')) { // place top left
                            delete theGrid[y-1][x-1];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x-1);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y-1);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y-1][x-1] = newSub2;
                            exit = false;
                            break;
                        }
                        else if (rand_int == 4 && (theGrid[y-1][x]->getSymb() == '.')) { // place left
                            delete theGrid[y-1][x];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y-1);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y-1][x] = newSub2;
                            exit = false;
                            break;
                        }
                        else if (rand_int == 5 && (theGrid[y+1][x]->getSymb() == '.')) { // place right
                            delete theGrid[y+1][x];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y+1);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y+1][x] = newSub2;
                            exit = false;
                            break;
                        }
                        else if (rand_int == 6 && (theGrid[y-1][x+1]->getSymb() == '.')) { //place left below
                            delete theGrid[y-1][x+1];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x+1);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y-1);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y-1][x+1] = newSub2;
                            exit = false;
                            break;
                        }
                        else if (rand_int == 7 && (theGrid[y][x+1]->getSymb() == '.')) { // place below
                            delete theGrid[y][x+1];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x+1);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y][x+1] = newSub2;
                            exit = false;
                            break;
                        }
                        else if (rand_int == 8 && (theGrid[y+1][x+1]->getSymb() == '.')) { // place right below
                            delete theGrid[y+1][x+1];
                            static_cast<DragonHoard*>(newSub)->setDragoX(x+1);
                            static_cast<DragonHoard*>(newSub)->setDragoY(y+1);
                            static_cast<Dragon*>(newSub2)->setDhX(x);
                            static_cast<Dragon*>(newSub2)->setDhY(y);
                            theGrid[y+1][x+1] = newSub2;
                            exit = false;
                            break;
                        }
                    }
                }
                else {
                    cham_arr[chamber_val].update(p);
                }
            }
        }
        if ((rand_int > 1) && (rand_int <= 3)) { // 2/8 probability
            GameSubject* newSub = new SmallGold();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
        }
        else { // 5/8 probability 1/8 + 2/8 + 5/8 == 1
            GameSubject* newSub = new NormalGold();
            Position p = cham_arr[chamber_val].getRand();
            int x = p.getX();
            int y = p.getY();
            delete theGrid[y][x];
            theGrid[y][x] = newSub;
            
        }
        gCount += 1;
    }
}

// randomly moves Npcs in either of the 8 directions
void Grid::moveNpcs(){
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            //If the current grid is an npc and has not been moved before and a player is not in sight
            if(isNpc(theGrid[i][k]->getSymb()) && theGrid[i][k]->getSymb() != 'D' && static_cast<Npc *>(theGrid[i][k])->getHasMoved() == false
               && playerInSight(k, i) == false && stuckNpc(k, i) == false){
                //Randomly moving the npc by one floortile
                bool toMove = true;
                while(toMove){
                    int ranDir = rand() % 8;
                    
                    //Seeing if the randomized square is free to move to and move to the square if
                    //it is free
                    if(ranDir == 0 && theGrid[i + 1][k]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i + 1][k];
                        theGrid[i + 1][k] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 1 && theGrid[i - 1][k]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i - 1][k];
                        theGrid[i - 1][k] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 2 && theGrid[i][k + 1]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i][k + 1];
                        theGrid[i][k + 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 3 && theGrid[i][k - 1]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i][k - 1];
                        theGrid[i][k - 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 4 && theGrid[i + 1][k + 1]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i + 1][k + 1];
                        theGrid[i + 1][k + 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 5 && theGrid[i + 1][k - 1]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i + 1][k - 1];
                        theGrid[i + 1][k - 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 6 && theGrid[i - 1][k + 1]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i - 1][k + 1];
                        theGrid[i - 1][k + 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 7 && theGrid[i - 1][k - 1]->getSymb() == '.'){
                        static_cast<Npc *>(theGrid[i][k])->setHasMoved(true);
                        delete theGrid[i - 1][k - 1];
                        theGrid[i - 1][k - 1] = theGrid[i][k];
                        toMove = false;
                    }
                }
                GameSubject* gameSub = new Floor();
                theGrid[i][k] = gameSub;
            }
        }
    }
    
    //Reseting all Npcs to indicate that they haven't moved yet
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            if(isNpc(theGrid[i][k]->getSymb())){
                static_cast<Npc *>(theGrid[i][k])->setHasMoved(false);
            }
        }
    }
}

// use potion in that direction
void Grid::usePotion(Direction d){
    int x = PC->getX();
    int y = PC->getY();
    
    //Update x and y depending on which direction the potion is in
    if(d == Direction::NO){
        y--;
    }else if(d == Direction::SO){
        y++;
    }else if(d == Direction::EA){
        x++;
    }else if(d == Direction::WE){
        x--;
    }else if(d == Direction::NW){
        y--;
        x--;
    }else if(d == Direction::NE){
        y--;
        x++;
    }else if(d == Direction::SW){
        y++;
        x--;
    }else{
        y++;
        x++;
    }
    
    if(theGrid[y][x]->getSymb() == 'P'){
        //Using the potion
        PC->usePotion(static_cast<Potion *>(theGrid[y][x]));
        
        //Update action
        std::string newAction = "PC uses " + static_cast<Potion *>(theGrid[y][x])->getType() + ".";
        if(PC->getAction().size() > 0){
            PC->setAction(PC->getAction() + " " + newAction);
        }else{
            PC->setAction(newAction);
        }
        
        //Removing the potion and replacing it with a floor
        delete theGrid[y][x];
        GameSubject* gameSub = new Floor();
        theGrid[y][x] = gameSub;
    }else{
        throw("Not a potion");
    }
    
    //Check if the player is alive after using the potion
    if(PC->isAlive() == false){
        //Call the game over method.
    }
}

// attack enemy in that direction
void Grid::atkEnemy(Direction d){
    int x = PC->getX();
    int y = PC->getY();
    
    //Update x and y depending on which direction the enemy is in
    if(d == Direction::NO){
        y--;
    }else if(d == Direction::SO){
        y++;
    }else if(d == Direction::EA){
        x++;
    }else if(d == Direction::WE){
        x--;
    }else if(d == Direction::NW){
        y--;
        x--;
    }else if(d == Direction::NE){
        y--;
        x++;
    }else if(d == Direction::SW){
        y++;
        x--;
    }else{
        y++;
        x++;
    }
    
    char npcType = theGrid[y][x]->getSymb();
    if(isNpc(npcType)){
        //Turning merchants hostile
        if(npcType == 'M') hostile = true;
        
        //Attack the npc
        PC->attack(static_cast<Npc *>(theGrid[y][x]));
        
        std::string newAction;
        
        //Removing the npc and replacing it with a floor if npc is dead after attack
        if(static_cast<Npc *>(theGrid[y][x])->isAlive() == false){
            GameSubject* gameSub;
            
            if(npcType == 'H'){
                delete theGrid[y][x];
                gameSub = new NormalGold();
                //Update action to output drop normal gold
                newAction = "Normal Gold was dropped.";
                if(PC->getAction().size() > 0){
                    PC->setAction(PC->getAction() + " " + newAction);
                }else{
                    PC->setAction(newAction);
                }
            }else if(npcType == 'M'){
                delete theGrid[y][x];
                gameSub = new MerchantHoard();
                //Update action to output drop MerchantHoard
                newAction = "MerchantHoard was dropped.";
                if(PC->getAction().size() > 0){
                    PC->setAction(PC->getAction() + " " + newAction);
                }else{
                    PC->setAction(newAction);
                }
            }else if(npcType == 'D'){
                //Setting the dragon hoard to be able to be picked up when the dragon dies
                int dragonHx = static_cast<Dragon*>(theGrid[y][x])->getDhX();
                int dragonHy = static_cast<Dragon*>(theGrid[y][x])->getDhY();
                static_cast<DragonHoard*>(theGrid[dragonHy][dragonHx])->setDeadDrago(true);
                delete theGrid[y][x];
                gameSub = new Floor();
                
                //Update action to output dragonHoard is now available
                newAction = "DragonHoard can now be picked up.";
                if(PC->getAction().size() > 0){
                    PC->setAction(PC->getAction() + " " + newAction);
                }else{
                    PC->setAction(newAction);
                }
            }else{
                gameSub = new Floor();
            }
            theGrid[y][x] = gameSub;
        }
    }else{
        throw("Cannot attack, not an enemy");
    }
}

// checks Pc's radius to see if there are enimies around it and attacks the PC if there are
void Grid::atkByEnemy(){
    int x = PC->getX();
    int y = PC->getY();
    
    //Check north
    if((isNpc(theGrid[y - 1][x]->getSymb()) && theGrid[y - 1][x]->getSymb() != 'D') || theGrid[y - 1][x]->getSymb() == 'G'){
        if(theGrid[y - 1][x]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y - 1][x])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y - 1][x])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y - 1][x])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y - 1][x])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y - 1][x]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y - 1][x])->attack(PC);
        }
    }
    
    //Check south
    if((isNpc(theGrid[y + 1][x]->getSymb()) && theGrid[y + 1][x]->getSymb() != 'D') || theGrid[y + 1][x]->getSymb() == 'G'){
        if(theGrid[y + 1][x]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y + 1][x])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y + 1][x])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y + 1][x])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y + 1][x])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y + 1][x]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y + 1][x])->attack(PC);
        }
    }
    
    //Check east
    if((isNpc(theGrid[y][x + 1]->getSymb()) && theGrid[y][x + 1]->getSymb() != 'D') || theGrid[y][x + 1]->getSymb() == 'G'){
        if(theGrid[y][x + 1]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y][x + 1])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y][x + 1])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y][x + 1])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y][x + 1])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y][x + 1]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y][x + 1])->attack(PC);
        }
    }
    
    //Check west
    if((isNpc(theGrid[y][x - 1]->getSymb()) && theGrid[y][x - 1]->getSymb() != 'D') || theGrid[y][x - 1]->getSymb() == 'G'){
        if(theGrid[y][x - 1]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y][x - 1])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y][x - 1])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y][x - 1])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y][x - 1])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y][x - 1]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y][x - 1])->attack(PC);
        }
    }
    
    //Check north west
    if((isNpc(theGrid[y - 1][x - 1]->getSymb()) && theGrid[y - 1][x - 1]->getSymb() != 'D') || theGrid[y - 1][x - 1]->getSymb() == 'G'){
        if(theGrid[y - 1][x - 1]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y - 1][x - 1])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y - 1][x - 1])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y - 1][x - 1])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y - 1][x - 1])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y - 1][x - 1]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y - 1][x - 1])->attack(PC);
        }
    }
    
    //Check north east
    if((isNpc(theGrid[y - 1][x + 1]->getSymb()) && theGrid[y - 1][x + 1]->getSymb() != 'D') || theGrid[y - 1][x + 1]->getSymb() == 'G'){
        if(theGrid[y - 1][x + 1]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y - 1][x + 1])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y - 1][x + 1])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y - 1][x + 1])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y - 1][x + 1])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y - 1][x + 1]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y - 1][x + 1])->attack(PC);
        }
    }
    
    //Check south west
    if((isNpc(theGrid[y + 1][x - 1]->getSymb()) && theGrid[y + 1][x - 1]->getSymb() != 'D') || theGrid[y + 1][x - 1]->getSymb() == 'G'){
        if(theGrid[y + 1][x - 1]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y + 1][x - 1])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y + 1][x - 1])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y + 1][x - 1])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y + 1][x - 1])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y + 1][x - 1]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y + 1][x - 1])->attack(PC);
        }
    }
    
    //Check south east
    if((isNpc(theGrid[y + 1][x + 1]->getSymb()) && theGrid[y + 1][x + 1]->getSymb() != 'D') || theGrid[y + 1][x + 1]->getSymb() == 'G'){
        if(theGrid[y + 1][x + 1]->getSymb() == 'G' && static_cast<Treasure *>(theGrid[y + 1][x + 1])->getValue() == 6){
            if(static_cast<DragonHoard *>(theGrid[y + 1][x + 1])->getDeadDrago() == false){
                int dx = static_cast<DragonHoard *>(theGrid[y + 1][x + 1])->getDragoX();
                int dy = static_cast<DragonHoard *>(theGrid[y + 1][x + 1])->getDragoY();
                static_cast<Dragon *>(theGrid[dy][dx])->attack(PC);
            }
        }else{
            if(theGrid[y + 1][x + 1]->getSymb() == 'M' && hostile == false) return;
            static_cast<Npc *>(theGrid[y + 1][x + 1])->attack(PC);
        }
    }
}

// move player in that direction
void Grid::move(Direction d){
    int x = PC->getX();
    int y = PC->getY();
    std::string newAction = "PC moves ";
    
    //Update x and y depending on which direction the potion is in
    if(d == Direction::NO){
        y--;
        newAction += "North";
    }else if(d == Direction::SO){
        y++;
        newAction += "South";
    }else if(d == Direction::EA){
        x++;
        newAction += "East";
    }else if(d == Direction::WE){
        x--;
        newAction += "West";
    }else if(d == Direction::NW){
        y--;
        x--;
        newAction += "North West";
    }else if(d == Direction::NE){
        y--;
        x++;
        newAction += "North East";
    }else if(d == Direction::SW){
        y++;
        x--;
        newAction += "South West";
    }else{
        y++;
        x++;
        newAction += "South East";
    }
    
    char floorType = theGrid[y][x]->getSymb();
    if(floorType != ' ' && floorType != '-' && floorType != '|'){
        //Updates the trolls HP by 5 everytime it moves
        if(PC->getName() == "Troll"){
            if(PC->getHp() + 5 > 120){
                PC->setHp(120);
            }else{
                PC->setHp(PC->getHp() + 5);
            }
        }
    }
    
    if(floorType == '.' || floorType == '+' || floorType == '#'){
        //Removing floorType and replacing it with PC
        delete theGrid[y][x];
        theGrid[y][x] = PC;
        
        //Replacing current tile with the tile the PC was on before
        GameSubject* gameSub;
        if(PC->getCurTile() == '.'){
            gameSub = new Floor();
        }else if(PC->getCurTile() == '+'){
            gameSub = new Door();
        }else{
            gameSub = new PassageWay();
        }
        
        theGrid[PC->getY()][PC->getX()] = gameSub;
        PC->setX(x);
        PC->setY(y);
        
        //Setting the PC's current floor tile after moving it in the direction d
        PC->setCurTile(floorType);
    }else if(floorType == 'G'){
        if(static_cast<Treasure *>(theGrid[y][x])->getValue() == 6 && static_cast<DragonHoard *>(theGrid[y][x])->getDeadDrago() == false){
            throw("Invalid direction to move, dragon is not dead yet");
        }else{
            //Adding gold to PC
            int gold = static_cast<Treasure *>(theGrid[y][x])->getValue();
            PC->addGold(gold);
            //Removing Gold object and replacing it with the PC
            delete theGrid[y][x];
            theGrid[y][x] = PC;
            //Replacing the current cell with a floor and updating PC's x and y coordinates
            GameSubject* gameSub = new Floor();
            theGrid[PC->getY()][PC->getX()] = gameSub;
            PC->setX(x);
            PC->setY(y);
            newAction += " and picks up a ";
            
            //update action to output which gold it picks up
            if(gold == 1){
                newAction += "small gold";
            }else if(gold == 2){
                newAction += "normal gold";
            }else if(gold == 4){
                newAction += "merchant hoard";
            }else{
                newAction += "dragon hoard";
            }
        }
    }else if(floorType == '\\'){
        //Clears grid, and starts on the next floor
        newAction += " and advances to the next floor";
        if (filename == "default.txt") {
            clearGrid();
        }
        else {
            clear();
        }
    }else{
        throw("Invalid direction to move");
    }
    
    //Check all 8 directions to update action
    int numEnemies = 0;
    bool seen = false;
    if(theGrid[y - 1][x]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y - 1][x]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y - 1][x])->getType() + " to the north";
            }else{
                newAction += " and sees an unknown potion to the north";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y - 1][x]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y - 1][x])->getType() + " to the north";
            }else{
                newAction += ", an unknown potion to the north";
            }
        }
    }
    if(isNpc(theGrid[y - 1][x]->getSymb())){
        numEnemies++;
    }
    if(theGrid[y + 1][x]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y + 1][x]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y + 1][x])->getType() + " to the south";
            }else{
                newAction += " and sees an unknown potion to the south";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y + 1][x]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y + 1][x])->getType() + " to the south";
            }else{
                newAction += ", an unknown potion to the south";
            }
        }
    }
    if(isNpc(theGrid[y + 1][x]->getSymb())){
        numEnemies++;
    }
    if(theGrid[y][x + 1]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y][x + 1]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y][x + 1])->getType() + " to the east";
            }else{
                newAction += " and sees an unknown potion to the east";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y][x + 1]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y][x + 1])->getType() + " to the east";
            }else{
                newAction += ", an unknown potion to the east";
            }
        }
    }
    if(isNpc(theGrid[y][x + 1]->getSymb())){
        numEnemies++;
    }
    if(theGrid[y][x - 1]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y][x - 1]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y][x - 1])->getType() + " to the west";
            }else{
                newAction += " and sees an unknown potion to the west";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y][x - 1]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y][x - 1])->getType() + " to the west";
            }else{
                newAction += ", an unknown potion to the west";
            }
        }
    }
    if(isNpc(theGrid[y][x - 1]->getSymb())){
        numEnemies++;
    }
    if(theGrid[y - 1][x + 1]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y - 1][x + 1]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y - 1][x + 1])->getType() + " to the north east";
            }else{
                newAction += " and sees an unknown potion to the north east";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y - 1][x + 1]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y - 1][x + 1])->getType() + " to the north east";
            }else{
                newAction += ", an unknown potion to the north east";
            }
        }
    }
    if(isNpc(theGrid[y - 1][x + 1]->getSymb())){
        numEnemies++;
    }
    if(theGrid[y - 1][x - 1]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y - 1][x - 1]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y - 1][x - 1])->getType() + " to the north west";
            }else{
                newAction += " and sees an unknown potion to the north west";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y - 1][x - 1]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y - 1][x - 1])->getType() + " to the north west";
            }else{
                newAction += ", an unknown potion to the north west";
            }
        }
    }
    if(isNpc(theGrid[y - 1][x - 1]->getSymb())){
        numEnemies++;
    }
    if(theGrid[y + 1][x + 1]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y + 1][x + 1]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y + 1][x + 1])->getType() + " to the south east";
            }else{
                newAction += " and sees an unknown potion to the south east";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y + 1][x + 1]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y + 1][x + 1])->getType() + " to the south east";
            }else{
                newAction += ", an unknown potion to the south east";
            }
        }
    }
    if(isNpc(theGrid[y + 1][x + 1]->getSymb())){
        numEnemies++;
    }
    if(theGrid[y + 1][x - 1]->getSymb() == 'P'){
        if(!seen){
            if(PC->isUsed(static_cast<Potion *>(theGrid[y + 1][x - 1]))){
                newAction += " and sees " + static_cast<Potion *>(theGrid[y + 1][x - 1])->getType() + " to the south west";
            }else{
                newAction += " and sees an unknown potion to the south west";
            }
            seen = true;
        }else{
            if(PC->isUsed(static_cast<Potion *>(theGrid[y + 1][x - 1]))){
                newAction += ", " + static_cast<Potion *>(theGrid[y + 1][x - 1])->getType() + " to the south west";
            }else{
                newAction += ", an unknown potion to the south west";
            }
        }
    }
    if(isNpc(theGrid[y + 1][x - 1]->getSymb())){
        numEnemies++;
    }
    
    stringstream enemies;
    enemies << numEnemies;
    
    if(numEnemies > 0){
        if(seen){
            if(numEnemies > 1){
                newAction += ", " + enemies.str() + " enemies";
            }else{
                newAction += ", an enemy";
            }
        }else{
            if(numEnemies > 1){
                newAction += " and sees " + enemies.str() + " enemies";
            }else{
                newAction += " and sees an enemy";
            }
        }
    }
    
    //Update action
    if(PC->getAction().size() > 0){
        PC->setAction(PC->getAction() + " " + newAction + ".");
    }else{
        PC->setAction(newAction + ".");
    }
}

//isNpc returns true is gameType is a Npc type and false otherwise
bool Grid::isNpc(char gameType){
    if(gameType == 'H' || gameType == 'W' || gameType == 'E' || gameType == 'O'
       || gameType == 'M' || gameType == 'D' || gameType == 'L'){
        return true;
    }else{
        return false;
    }
}

//playerInSight returns true if the player is within a block of an enemy and false otherwise
bool Grid::playerInSight(int x, int y){
    if(abs(PC->getX() - x) <= 1 && abs(PC->getY() - y) <= 1){
        return true;
    }else{
        return false;
    }
}

bool Grid::isWon() {
    return level == 6;
}
