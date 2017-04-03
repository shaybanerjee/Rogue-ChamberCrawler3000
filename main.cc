#include <string>
#include <iostream>
#include "grid.h"
#include "drow.h"
#include "shade.h"
#include "goblin.h"
#include "vampire.h"
#include "troll.h"
#include "direction.h"
#include <ctime>

using namespace std;
char playerSelect(){ // Player selects race to play as
    char character;
    cout << "Welcome to ChamberCrawler3000!" << endl;
    cout << "A CS246 Project:" << endl;
    cout << "Professor Naeem" << endl;
    cout << "Created by Mike Chen, Shayon Banerjee, and William Zhu" << endl;
    cout << endl;
    cout << "Please select a race for you player: " << endl;
    cout << "Drow: 'd'"<<endl;
    cout << "Goblin: 'g'"<<endl;
    cout << "Shade: 's'"<<endl;
    cout << "Troll: 't'"<<endl;
    cout << "Vampire: 'v'" <<endl;
    
    cin >> character; // reads in selected race
    
    while(character != 'd' && character != 'g' && character != 's'
          && character != 't' && character != 'v'){
        cout << "Invalid Selection. Please try again with one of";
        cout << " the above selections (d, g, s, t, v)" << endl;
        cin >> character;
    }
    return character;
    
    
}

int main(int argc, const char * argv[]) {
    bool isF = false;
    srand(time(NULL));
    string command; // commands to move/attack/use items
    char race = playerSelect(); // selects players race
    string file = "cc3kfloor.txt";
    //    if (argc == 1){
    //        file = argv[1];
    //    }
    
    PlayerCharacter *pc; // main character
    
    switch(race){
        case 'd':
            pc = new Drow();
            break;
        case 'g':
            pc = new Goblin();
            break;
        case 's':
            pc = new Shade();
            break;
        case 't':
            pc = new Troll();
            break;
        case 'v':
            pc = new Vampire();
            break;
        default:
            pc = new Shade();
    }
    
    Grid grid{file,pc}; // The map/floorplan of the game
    
    //grid.rand_player();
    //grid.rand_potion();
    //grid.rand_stair();
    //grid.rand_enemy();
    grid.rand_treasure();
    cout << grid;
    grid.clearGrid();
    
    cin >> command;
    while(!cin.eof()){
        pc->setAction("");
        if (command =="q"){
            cout << "You have lost the game, try again!"<<endl;
            break;
        }
        else if (command == "r"){
            race = playerSelect(); // select new race
            switch(race){
                case 'd':
                    pc = new Drow();
                    break;
                case 'g':
                    pc = new Goblin();
                    break;
                case 's':
                    pc = new Shade();
                    break;
                case 't':
                    pc = new Troll();
                    break;
                case 'v':
                    pc = new Vampire();
                    break;
            }
            grid.restartGrid(pc);
            grid.rand_player();
            grid.rand_potion();
            grid.rand_stair();
            grid.rand_enemy();
            grid.rand_treasure();
        }
        else if (command == "f"){
            if (isF == false) {
                isF = true;
            }
            else {
                isF = false;
            }
        }
        else if (command == "a"){ // player attacks enemy
            while (true) {
                cin >> command;
                if (command != "no" && command != "so" && command != "ea"
                    && command != "we" && command != "ne" && command != "nw"
                    && command != "se" && command != "sw") {
                    cout << "Invalid Selection. Please try again with one of";
                    cout << " the above selections (no, so, ea, we, ne, nw, se, sw)"<<endl;
                    cin >> command;
                }
                else {
                    break;
                }
            }
            if (command == "no"){
                try {
                    grid.atkEnemy(Direction::NO);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
            }
            else if (command == "so"){
                try {
                    grid.atkEnemy(Direction::SO);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
            }
            else if (command == "ea"){
                try {
                    grid.atkEnemy(Direction::EA);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
            }
            else if (command == "we"){
                try {
                    grid.atkEnemy(Direction::WE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
                
            }else if(command == "ne"){
                try {
                    grid.atkEnemy(Direction::NE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
                
            }
            else if (command == "nw"){
                try {
                    grid.atkEnemy(Direction::NW);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
                
            }
            else if (command == "se"){
                try {
                    grid.atkEnemy(Direction::SE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
            }
            else {
                try {
                    grid.atkEnemy(Direction::SW);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                grid.moveNpcs();
                grid.atkByEnemy();
            }
        }
        else if (command == "u"){ // use potion
            while (true) {
                cin >> command;
                if (command != "no" && command != "so" && command != "ea"
                    && command != "we" && command != "ne" && command != "nw"
                    && command != "se" && command != "sw") {
                    cout << "Invalid Selection. Please try again with one of";
                    cout << " the above selections (no, so, ea, we, ne, nw, se, sw)"<<endl;
                    cin >> command;
                }
                else {
                    break;
                }
            }
            if (command == "no"){
                try {
                    grid.usePotion(Direction::NO);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }
            else if (command == "so"){
                try {
                    grid.usePotion(Direction::SO);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }
            else if (command == "ea"){
                try {
                    grid.usePotion(Direction::EA);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }
            else if (command == "we"){
                try {
                    grid.usePotion(Direction::WE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }else if(command == "ne"){
                try {
                    grid.usePotion(Direction::NE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }
            else if (command == "nw"){
                try {
                    grid.usePotion(Direction::NW);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }
            else if (command == "se"){
                try {
                    grid.usePotion(Direction::SE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }
            else {
                try {
                    grid.usePotion(Direction::SW);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
            }
        }
        else{
            while (true) {
                if (command != "no" && command != "so" && command != "ea"
                    && command != "we" && command != "ne" && command != "nw"
                    && command != "se" && command != "sw") {
                    cout << "Invalid Selection. Please try again with one of";
                    cout << " the above selections (no, so, ea, we, ne, nw, se, sw)"<<endl;
                    cin >> command;
                }
                else {
                    break;
                }
            }
            if (command == "no") {
                try {
                    grid.move(Direction::NO);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
            }
            else if (command == "so"){
                try {
                    grid.move(Direction::SO);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
            }
            else if (command == "ea"){
                try {
                    grid.move(Direction::EA);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
            }
            else if (command == "we"){
                try {
                    grid.move(Direction::WE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
            }
            else if(command == "ne"){
                try {
                    grid.move(Direction::NE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
                
            }
            else if (command == "nw"){
                try {
                    grid.move(Direction::NW);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
            }
            else if (command == "se"){
                try {
                    grid.move(Direction::SE);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
            }
            else {
                try {
                    grid.move(Direction::SW);
                }
                catch (const char* error) {
                    pc->setAction(error + pc->getAction());
                }
                if (!isF) {
                    grid.moveNpcs();
                    grid.atkByEnemy();
                }
            }
        }
        if (grid.isWon()){ // player reaches stairs on 5th floor
            cout << "Huzzah, you have won the game!" << endl;
            cout << "Press 'r' to restart or 'q' to quit" << endl;
            cin >> command;
            if (command == "r"){
                race = playerSelect(); // select new race
                switch(race){
                    case 'd':
                        pc = new Drow();
                        break;
                    case 'g':
                        pc = new Goblin();
                        break;
                    case 's':
                        pc = new Shade();
                        break;
                    case 't':
                        pc = new Troll();
                        break;
                    case 'v':
                        pc = new Vampire();
                        break;
                }
                grid.restartGrid(pc);
                grid.rand_player();
                grid.rand_potion();
                grid.rand_stair();
                grid.rand_enemy();
                grid.rand_treasure();
            }
            else{
                break;
                
            }
        }
        else if (!pc->isAlive()){ // player's health lower than or equal to 0
            cout << "You have died" << endl;
            cout << "press 'r' to restart or 'q' to quit" << endl;
            cin >> command;
            if (command == "r"){
                race = playerSelect(); // select new race
                switch(race){
                    case 'd':
                        pc = new Drow();
                        break;
                    case 'g':
                        pc = new Goblin();
                        break;
                    case 's':
                        pc = new Shade();
                        break;
                    case 't':
                        pc = new Troll();
                        break;
                    case 'v':
                        pc = new Vampire();
                        break;
                }
                grid.restartGrid(pc);
                grid.rand_player();
                grid.rand_potion();
                grid.rand_stair();
                grid.rand_enemy();
                grid.rand_treasure();
            }
            else{
                break;
                
            }
        }
        cout << grid; // print board
        cin >> command; //reads next command
        
    }
    return 0;
    
}
