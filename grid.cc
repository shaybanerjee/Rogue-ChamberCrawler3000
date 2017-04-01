#include "grid.h"
#include "hwall.h"
#include "vwall.h"
#include "floor.h"
#include "passageway.h"
#include "door.h"
#include "empty.h"
#include <iostream>

using namespace std; 


Grid::Grid(ifstream &f, GameSubject& PC) 
	:width{79}, height{25}, f{f}, PC{PC} {
	char curr_char; 
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			f >> curr_char; 
			if (curr_char == '-') {
				GameSubject* gameSub = new Hwall(i,j);
				theGrid[row][col] = gameSub;   
			}
			else if (curr_char == '|') {
				GameSubject* gameSub = new Vwall(i, j); 
				theGrid[row][col] = gameSub; 
			}
			else if (curr_char == '.') {
				GameSubject* gameSub = new Floor(i, j);
				theGrid[row][col] = gameSub;  
			}
			else if (curr_char == '#') {
				GameSubject* gameSub = new PassageWay(i, j);
				theGrid[row][col] = gameSub;  
			}
			else if (curr_char == '+') {
				GameSubject* gameSub = new Door(i, j); 
				theGrid[row][col] = gameSub; 
			}
			else if (curr_char == ' ') {
				GameSubject* gameSub = new Empty(i, j);
				theGrid[row][col] = gameSub;  
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		cham_arr[i] = Chamber{i};
	}
}

void Grid::clearGrid() {
	for (int row = 0; i < height; ++row) {
		for (int col = 0; col < width; ++col) {
			GameSubject* currSub = theGrid[i][j]; 
			
		}
	}
}



ostream &operator<<(ostream &out, const theGrid) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			GameSubject* curr_sub = theGrid[i][j]; 
			out << curr_sub->get_symb() << endl; 
		}
	}
}



