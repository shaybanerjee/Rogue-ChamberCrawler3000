#ifndef _TEXTDISPLAY_H_ 
#define _TEXTDISPLAY_H_
#include <vector>
#include <iostream>
#include <fstream>

class GameSubject; 
class Shade; 
class Vampire; 
class Troll;
class Goblin; 
class Elf; 
class Human;
class Dwarf; 
class Orc;
class Merchant; 
class Dragon; 
class Halfling;

class TextDisplay : Observer {
	std::vector <std::vector <char>> display; 
	const int gridSize; 

	public: 
		TextDisplay(int n, ifstream& f); // ctor of TextDisplay
		void notify(GameSubject& who) override;
		~TextDisplay();
		friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td); 
};

#endif 