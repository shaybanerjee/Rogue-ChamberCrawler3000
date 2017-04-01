#include <string>
#include <iostream>
#include "grid.h"
#include "drow.h"
#include "shade.h"
#include "goblin.h"
#include "vampire.h"
#include "troll.h"
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

	char race = playerSelect(); // selects players race
	string file = "cc3kfloor.txt";
	if (argc == 1){
		file = argv[1];
	}

	Grid g{file};
	PlayerCharacter *pc;

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

}
