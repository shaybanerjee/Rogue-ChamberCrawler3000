#include <string>
#include <iostream>
#include "grid.h"
#include "drow.h"
#include "shade.h"
#include "goblin.h"
#include "vampire.h"
#include "troll.h"
#include "direction.h"
using namespace std;
char playerSelect(){ // Player selects race to play as
    char character;
    cout << "Please select a race for you player: "<<endl;
    cout << "Drow: 'd'"<<endl;
    cout << "Goblin: 'g'"<<endl;
    cout << "Shade: 's'"<<endl;
    cout << "Troll: 't'"<<endl;
    cout << "Vampire: 'v'"<<endl;
    
    cin >> character; // reads in selected race
    
    while(character != 'd' && character != 'g' && character != 's'
          && character != 't' && character != 'v'){
        cout << "Invalid Selection. Please try again with one of";
        cout << " the above selections (d, g, s, t, v)"<<endl;
        cin >> character;
    }
    return character;
    
    
}

int main(int argc, const char * argv[]) {
    
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
    
    cout << grid; // print the grid;
    grid.rand_potion();
    cout << grid;
    
    cin >> command;
    while(!cin.eof()){
        if (command =="q"){
            cout << "You have lost the game, try again!"<<endl;
            break;
        }
        else if (command == "r"){
            delete pc;
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
        }
        else if (command == "f"){
            //enemies stop moving
        }
        else if (command[0] == 'a'){ // player attacks enemy
            command.erase(0,1);
            if (command == "no"){
                grid.atkEnemy(Direction::NO);
            }
            else if (command == "so"){
                grid.atkEnemy(Direction::SO);
            }
            else if (command == "ea"){
                grid.atkEnemy(Direction::EA);
            }
            else if (command == "ne"){
                grid.atkEnemy(Direction::WE);
            }
            else if (command == "nw"){
                grid.atkEnemy(Direction::NW);
            }
            else if (command == "se"){
                grid.atkEnemy(Direction::SE);
            }
            else if (command == "sw"){
                grid.atkEnemy(Direction::SW);
            }
            else{
                cout << "Enter a valid command: ";
            }
        }
        else if (command[0] == 'u'){ // use potion
            command.erase(0,1);
            if (command == "no"){
                grid.usePotion(Direction::NO);
            }
            else if (command == "so"){
                grid.usePotion(Direction::SO);
            }
            else if (command == "ea"){
                grid.usePotion(Direction::EA);
            }
            else if (command == "ne"){
                grid.usePotion(Direction::WE);
            }
            else if (command == "nw"){
                grid.usePotion(Direction::NW);
            }
            else if (command == "se"){
                grid.usePotion(Direction::SE);
            }
            else if (command == "sw"){
                grid.usePotion(Direction::SW);
            }
            else{
                cout << "Enter a valid command: ";
            }
        }
        else{
            if (command == "no"){
                grid.move(Direction::NO);
            }
            else if (command == "so"){
                grid.move(Direction::SO);
            }
            else if (command == "ea"){
                grid.move(Direction::EA);
            }
            else if (command == "ne"){
                grid.move(Direction::WE);
            }
            else if (command == "nw"){
                grid.move(Direction::NW);
            }
            else if (command == "se"){
                grid.move(Direction::SE);
            }
            else if (command == "sw"){
                grid.move(Direction::SW);
            }
            else{
                cout << "Enter a valid command: ";
            }
        }
        if (grid.isWon()){ // player reaches stairs on 5th floor
            cout << "Huzzah you have won the game!"<<endl;
            cout << "Press 'r' to restart or 'q' to quit" <<endl;
            cin >> command;
            if (command == "r"){
                    delete pc;
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
            }
            else{
                    break;
                    
            }
        }
        else if (!pc->isAlive()){ // player's health lower than 0
            cout << "You have died"<<endl;
            cout << "press 'r' to restart or 'q' to quit"<<endl;
            cin >> command;
            if (command == "r"){
                delete pc;
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
            }
            else{
                break;
                
            }
        }
        
        cout << grid; // print board
        cin >> command; //reads next command
        
    }
    delete pc;
    return 0;
    
}
