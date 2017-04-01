#include "grid.h"
#include "hwall.h"
#include "vwall.h"
#include "floor.h"
#include "passageway.h"
#include "door.h"
#include "empty.h"
#include "position.h"
#include <iostream>
#include <cstdlib>


using namespace std; 


Grid::Grid(ifstream &f, GameSubject& PC) // constructor for Grid
	:width{79}, height{25}, f{f}, PC{PC}, level{1} { // MIL 
	char curr_char; 
	for (int row = 0; row < height; ++row) { 
		for (int col = 0; col < width; ++col) {
			f >> curr_char; 
			if (curr_char == '-') {
				GameSubject* gameSub = new Hwall(col,row);
				theGrid[col][row] = gameSub;   
			}
			else if (curr_char == '|') {
				GameSubject* gameSub = new Vwall(col, row); 
				theGrid[col][row] = gameSub; 
			}
			else if (curr_char == '.') {
				GameSubject* gameSub = new Floor(col, row);
				theGrid[col][row] = gameSub;  
			}
			else if (curr_char == '#') {
				GameSubject* gameSub = new PassageWay(col, row);
				theGrid[col][row] = gameSub;  
			}
			else if (curr_char == '+') {
				GameSubject* gameSub = new Door(col, row); 
				theGrid[col][row] = gameSub; 
			}
			else if (curr_char == ' ') {
				GameSubject* gameSub = new Empty(col, row);
				theGrid[col][row] = gameSub;  
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		cham_arr[i] = Chamber{i};
	}
}

void Grid::clearGrid() { // method for clear grid after level
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) { 
			GameSubject* currSub = theGrid[col][row]; 
			char symb = currSub->getSymb(); 
			if (symb != '+' && symb != '.' && // if not a tile obj
				symb != ' ' && symb != '-' &&
				symb != '|' && symb != '#') {
				if (symb == '@') { // if player dont delete
					theGrid[col][row] = new Floor(col, row); // place floor tile
				}
				else {
					delete theGrid[row][col]; // return heap mem
					theGrid[col][row] = new Floor(col, row); // place floor tile
				}
			}	
		}
	}
	for (int i = 0; i < 5; ++i) {
		cham_arr[i].clear(); // reinit chambers
	}

}

void Grid::restartGrid(PlayerCharacter *p) { // restarts game
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			GameSubject* currSub = theGrid[col][row]; 
			char symb = currSub->getSymb(); 
			if (symb != '+' && symb != '.' &&
				symb != ' ' && symb != '-' &&
				symb != '|' && symb != '#') {
				delete theGrid[col][row]; 
				theGrid[col][row] = new Floor(col, row); 
			}
		}	
	}
	for (int i = 0; i < 5; ++i) {
		cham_arr[i].clear(); 
	}
	PC = p; 
	level = 1; 
}



ostream &operator<<(ostream &out, const theGrid) { // our grid content
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			GameSubject* curr_sub = theGrid[j][i]; 
			out << curr_sub->get_symb() << endl; 
		}
	}
}

void rand_enemy() { // generate random enemy
	int enmCount = 0; 
	while (enmCount < 20) {
		int enm_val = (rand() % 18) + 1; // get num 1-18
		int chamber_val 
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
			delete theGrid[y][x]; // swap floor tile with new GameSub
			theGrid[y][x] = newSub; 
		} 
		else if (enm_val > 7 && enm_val <= 12) { // 5/18 
			GameSubject* newSub = new Halfling(); 
			Position p = cham_arr[chamber_val].getRand(); // get random pos
			int x = p.getX();
			int y = p.getY();
			delete theGrid[y][x]; // swap floor tile with new GameSub
			theGrid[y][x] = newSub; 

		}
		else if (enm_val > 12 && enm_val <= 14) { // 2/18
			GameSubject* newSub = new Elf(); 
			Position p = cham_arr[chamber_val].getRand(); // get random pos
			int x = p.getX();
			int y = p.getY();
			delete theGrid[y][x]; // swap floor tile with new GameSub
			theGrid[y][x] = newSub; 

		}
		else if (enm_val > 14 && enm_val <= 16) { // 2/18
			GameSubject* newSub = new Orc(); 
			Position p = cham_arr[chamber_val].getRand(); // get random pos
			int x = p.getX();
			int y = p.getY();
			delete theGrid[y][x]; // swap floor tile with new GameSub
			theGrid[y][x] = newSub; 

		}
		else if (enm_val > 16 && enm_val <= 18) { // 2/18
			GameSubject* newSub = new Merchant(); 
			Position p = cham_arr[chamber_val].getRand(); // get random pos
			int x = p.getX();
			int y = p.getY();
			delete theGrid[y][x]; // swap floor tile with new GameSub
			theGrid[y][x] = newSub; 
		}
		enmCount+=1; 
	}
}

void Grid::rand_player() { // randomly place player
	int rand_cham = rand() % 5; 
	Position p = cham_arr[rand_cham].getRand(); 
	int x = p.getX(); 
	int y = p.getY(); 
	delete theGrid[y][x]; 
	theGrid[y][x] = PC; 
}



void Grid::rand_stair() { // randomly place stair
	int rand_cham = rand() % 5; 
	Position p = cham_arr[rand_cham].getRand(); 
	int x = p.getX();
	int y = p.getY(); 
	GameSubject* newSub = new Stair(x,y); 
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
		else if (rand_val == 6) { // 1/6 prob
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
	
void Grid::rand_tresure() { // randomly place treasure
	int gCount = 0; 
	while (gCount < 10) {
		int rand_int = (rand() % 8) + 1;
		int chamber_val = rand() % 5; 
		if (rand_int == 1) { // 1/8 probability
			GameSubject* newSub = new DragonHoard();
			GameSubject* newSub2 = new Dragon(); 
			newSub->setDragon(newSub2); 
			int x = p.getX();
			int y = p.getY(); 
			delete theGrid[y][x];
			theGrid[y][x] = newSub;
			while(true) { // place dragon appropriately 
				Postion p = cham_arr[chamber_val].getRand();
				if (stuckNpc(p.getX(), p.getY)) {
					int rand_int = (rand() % 8) + 1;
					if (rand_int == 1 && (theGrid[y+1][x-1]->getSymb == '.')) { // place top right
						delete theGrid[y+1][x-1]; 
						theGrid[y+1][x-1] = newSub2;  
						break; 
					}
					else if (rand_int == 2 (theGrid[y][x-1]->getSymb == '.')) { // place above 
						delete theGrid[y][x-1]; 
						theGrid[y][x-1] = newSub2;
						break;  
					}	
					else if (rand_int == 3 && (theGrid[y-1][x-1]->getSymb == '.')) { // place top left
						delete theGrid[y-1][x-1]; 
						theGrid[y-1][x-1] = newSub2; 
						break;
					}
					else if (rand_int == 4 && (theGrid[y-1][x]->getSymb == '.')) { // place left
						delete theGrid[y-1][x]; 
						theGrid[y-1][x] = newSub2; 
						break;
					}	
					else if (rand_int == 5 && (theGrid[y+1][x]->getSymb == '.')) { // place right
						delete theGrid[y+1][x]; 
						theGrid[y+1][x] = newSub2;				 
						break; 
					}
					else if (rand_int == 6 && (theGrid[y-1][x+1]->getSymb == '.')) { //place left below
						delete theGrid[y-1][x+1]; 
						theGrid[y-1][x+1] = newSub2;
						break;  
					}
					else if (rand_int == 7 && (theGrid[y][x+1]->getSymb == '.')) { // place below
						delete theGrid[y][x+1]; 
						theGrid[y][x+1] = newSub2;
						break; 
					}
					else if (rand_int == 8 && (theGrid[y+1][x+1]->getSymb == '.')) { // place right below
						delete theGrid[y+1][x+1]; 
						theGrid[y+1][x+1] = newSub2;
						break;
					}
				}
				else {
					cham_arr[chamber_val].update(p); 
				}
			}
		}
		else if ((rand_int > 1) && (rand_int <= 3)) { // 2/8 probability
			GameSubject* newSub = new SmallGold(); 
			Position p = cham_arr[chamber_val].getRand(); 
			int x = p.getX();
			int y = p.getY(); 
			theGrid[y][x] = newSub;  
		}
		else { // 5/8 probability 1/8 + 2/8 + 5/8 == 1
			GameSubject* newSub = new NormalGold(); 
			Position p = cham_arr[chamber_val].getRand(); 
			int x = p.getX();
			int y = p.getY(); 
			theGrid[y][x] = newSub;  

		}
		gCount += 1; 
	}
}




