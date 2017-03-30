#include "textdisplay.h"

using namespace std; 


TextDisplay::TextDisplay {int n, ifstream& f} { 
	display.resize(n); 
	for (int i = 0; i < n; ++i) {
		display[i].resize(n);  
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char curr_char; 
		  	f >> curr_char; 
		  	display[i][j] = curr_char; 
		}
	}
}

void notify(GameSubject& who) { 
	int curr_x = who.get_x(); 
	int curr_y = who.get_y(); 
	if (who.what_is() == "item") { // item has been steped on 
		display[curr_x, curr_y] = '.'; 
	} 
	else {
		if (who.dir() == direction::NO) {
			display[curr_x + 1, curr_y] = '.';
			display[curr_x, curr_y] = who.get_char();  
		}
		else if (who.dir() == direction::SO) {
			display[curr_x - 1, curr_y] = '.'; 
			display[curr_x, curr_y] = who.get_char(); 
		}
		else if (who.dir() == direction::EO) { // hmm 
			display[curr_x, curr_y - 1] = '.'; 
			display[curr_x, curr_y] = who.get_char(); 
		}
		else if (who.dir() == direction::WO) {
			display[curr_x, curr_y+1] = '.'; 
			display[curr_x, curr_y] = who.get_char(); 
		}
		else if (who.dir() == direction::NE) { 
			display[curr_x + 1, curr_y - 1] = '.'; 
			display[curr_x, curr_y] = who.get_char(); 
		}
		else if (who.dir() == direction::NW) {
			display[curr_x + 1, curr_y + 1] = '.'; 
			display[curr_x, curr_y] = who.get_char(); 
		}
		else if (who.dir() == direction::SE) {
			display[curr_x - 1, curr_y - 1] = '.'; 
			display[curr_x, curr_y] = who.get_char();
		}
		else if (who.dir() == direction::SW) {
			display[curr_x - 1, curr_y + 1] = '.';
			display[curr_x, curr_y] = who.get_char(); 
		}
	}
}

TextDisplay::~TextDisplay() {}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int i = 0; i < td.gridSize; ++i) {
		for (int j = 0; j < td.gridSize; ++j) {
			out << td.display[i][j]; 
		}
		out << endl; 
	}
	return out; 
}


