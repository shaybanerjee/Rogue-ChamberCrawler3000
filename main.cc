#include <string>
#include <iostream>
#include "grid.h"
#include "drow.h"
#include "shade.h"
#include "goblin.h"
#include "vampire.h"
#include "troll.h"
#include "direction.h"
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
	if (argc == 1){
		file = argv[1];
	}

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
	}

	Grid g{file,pc} // The map/floorplan of the game

	cout << g; // print the grid;

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
		else if (command[0] == "a"){ // player attacks enemy
			command.erase(0,1);
			switch (command){
				case "no":
					grid.atkEnemy(Direction::NO);
					break;
				case "so":
					grid.atkEnemy(Direction::SO);
					break;
				case "ea":
					grid.atkEnemy(Direction::EA);
					break;
				case "we":
					grid.atkEnemy(Direction::WE);
					break;
				case "ne":
					grid.atkEnemy(Direction::NE);
					break;
				case "nw":
					grid.atkEnemy(Direction::NW);
					break;
				case "se":
					grid.atkEnemy(Direction::SE);
					break;
				case "sw":
					grid.atkEnemy(Direction::SW);
					break;
				default:
					cout << "Enter a valid command: ";
					break;
			}
		}
		else if (command[0] == "u"){ // use potion
			command.erase(0,1);
			switch (command){
				case "no":
					grid.usePotion(Direction::NO);
					break;
				case "so":
					grid.usePotion(Direction::SO);
					break;
				case "ea":
					grid.usePotion(Direction::EA);
					break;
				case "we":
					grid.usePotion(Direction::WE);
					break;
				case "ne":
					grid.usePotion(Direction::NE);
					break;
				case "nw":
					grid.usePotion(Direction::NW);
					break;
				case "se":
					grid.usePotion(Direction::SE);
					break;
				case "sw":
					grid.usePotion(Direction::SW);
					break;
				default:
					cout << "Enter a valid command: ";
					break;
			}
		}
		else{
			switch (command){// move player
				case "no":
					grid.move(Direction::NO);
					break;
				case "so":
					grid.move(Direction::SO);
					break;
				case "ea":
					grid.move(Direction::EA);
					break;
				case "we":
					grid.move(Direction::WE);
					break;
				case "ne":
					grid.move(Direction::NE);
					break;
				case "nw":
					grid.move(Direction::NW);
					break;
				case "se":
					grid.move(Direction::SE);
					break;
				case "sw":
					grid.move(Direction::SW);
					break;
				default:
					cout << "Enter a valid command: ";
					break;
			}
		}
		if (grid.isWon()){ // player reaches stairs on 5th floor
			cout << "Huzzah you have won the game!"<<endl;
			cout << "Press 'r' to restart or 'q' to quit" <<endl;
			cin >> command;
			switch (command){
				case "r":
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

				default: // quits the game
					break;

			}
		}
		else if (grid.isLost()){ // player's health lower than 0
			cout << "You have died"<<endl;
			cout << "press 'r' to restart or 'q' to quit"<<endl;
			cin >> command;
			switch (command){
				case "r":
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

				default: // Quits the game
					break;

		}
	}

		cout << g; // print board
		cin >> command; //reads next command

	}
	delete pc;
	return 0;

}
