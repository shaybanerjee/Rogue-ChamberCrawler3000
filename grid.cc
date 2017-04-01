#include "grid.h"
#include "hwall.h"
#include "vwall.h"
#include "floor.h"
#include "passageway.h"
#include "door.h"
#include "empty.h"
#include "direction.h"
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
int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1; // remove this line if '-' counts as a digit
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
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

ostream &operator<<(ostream &out, const theGrid) {

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            GameSubject* curr_sub = theGrid[i][j];
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

void Grid::rand_treasure() { // randomly place treasure
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






// randomly moves Npcs in either of the 8 directions
void moveNpcs(){
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            //If the current grid is an npc and has not been moved before and a player is not in sight
            if(isNpc(theGrid[i][k]) && theGrid[i][k].getHasMoved() == false && playerInSight(k, i) == false
               && stuckNpc(k, i) == false){
                //Randomly moving the npc by one floortile
                bool toMove = true;
                while(toMove){
                    int ranDir = rand() % 8;
                    
                    //Seeing if the randomized square is free to move to and move to the square if
                    //it is free
                    if(ranDir == 0 && theGrid[i + 1][k]->getSymb() == '.'){
                        delete theGrid[i + 1][k];
                        theGrid[i + 1][k] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 1 && theGrid[i - 1][k]->getSymb() == '.'){
                        delete theGrid[i - 1][k];
                        theGrid[i - 1][k] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 2 && theGrid[i][k + 1]->getSymb() == '.'){
                        delete theGrid[i][k + 1];
                        theGrid[i][k + 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 3 && theGrid[i][k - 1]->getSymb() == '.'){
                        delete theGrid[i][k - 1];
                        theGrid[i][k - 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 4 && theGrid[i + 1][k + 1]->getSymb() == '.'){
                        delete theGrid[i + 1][k + 1];
                        theGrid[i + 1][k + 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 5 && theGrid[i + 1][k - 1]->getSymb() == '.'){
                        delete theGrid[i + 1][k - 1];
                        theGrid[i + 1][k - 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 6 && theGrid[i - 1][k + 1]->getSymb() == '.'){
                        delete theGrid[i - 1][k + 1];
                        theGrid[i - 1][k + 1] = theGrid[i][k];
                        toMove = false;
                    }
                    if(ranDir == 7 && theGrid[i - 1][k - 1]->getSymb() == '.'){
                        delete theGrid[i - 1][k - 1];
                        theGrid[i - 1][k - 1] = theGrid[i][k];
                        toMove = false;
                    }
                }
                GameSubject* gameSub = new Floor(k, i);
                theGrid[i][k] = gameSub;
                theGrid[i][k]->setHasMoved(true);
            }
        }
    }
    
    //Reseting all Npcs to indicate that they haven't moved yet
    for(int i = 0; i < height; i++){
        for(int k = 0; k < width; k++){
            if(isNpc(theGrid[i][k]){
                theGrid[i][k]->setHasMoved(false);
            }
        }
    }
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			GameSubject* curr_sub = theGrid[i][j]; 
			out << curr_sub->get_symb() << endl; 
		}
	}
	cout << "Race: " << PC->getName();
    cout << " Gold: " << PC->getGold();
    cout.width(63 - PC->getRace().length() - numDigits(PC->getGold()) - 1);
    cout << right << "Floor: " << right << floor << endl;

    cout << left;
    cout << "HP: " << PC->getHp() << endl;
    cout << "Atk: " << PC->getAtk() << endl;
    cout << "Def: " << PC->getDef() << endl;
    //cout << "Action: " << PC->getAction() << endl;
}

// use potion in that direction
void Grid::usePotion(Direction d){
    int x = PC->getX();
    int y = PC->getY();
    
    //Update x and y depending on which direction the potion is in
    if(d == Direction::NO){
        y++;
    }else if(d == Direction::SO){
        y--;
    }else if(d == Direction::EA){
        x++;
    }else if(d == Direction::WE){
        x--;
    }else if(d == Direction::NW){
        y++;
        x--;
    }else if(d == Direction::NE){
        y++;
        x++;
    }else if(d == Direction::SW){
        y--;
        x--;
    }else{
        y--;
        x++;
    }
    
    if(theGrid[y][x]->getSymb() == 'P'){
        //Using the potion
        PC.usePotion(theGrid[y][x]);
        
        //Removing the potion and replacing it with a floor
        delete theGrid[y][x];
        GameSubject* gameSub = new Floor(x, y);
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
    
    //Update x and y depending on which direction the potion is in
    if(d == Direction::NO){
        y++;
    }else if(d == Direction::SO){
        y--;
    }else if(d == Direction::EA){
        x++;
    }else if(d == Direction::WE){
        x--;
    }else if(d == Direction::NW){
        y++;
        x--;
    }else if(d == Direction::NE){
        y++;
        x++;
    }else if(d == Direction::SW){
        y--;
        x--;
    }else{
        y--;
        x++;
    }
    
    char npcType = theGrid[y][x]->getSymb();
    if(npcType == 'H' || npcType == 'W' || npcType == 'E' || npcType == 'O'
       || npcType == 'M' || npcType == 'D' || npcType == 'L'){
        //Attack the npc
        PC.attack(theGrid[y][x]);
        
        //Removing the npc and replacing it with a floor if npc is dead after attack
        if(theGrid[y][x]->isAlive() == false){
            delete theGrid[y][x];
            GameSubject* gameSub = new Floor(x, y);
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
    if((isNpc(theGrid[y + 1][x]->getSymb()) && theGrid[y + 1][x]->getHostile()) || theGrid[y + 1][x]->getSymb() == 'G'){
        if(theGrid[y + 1][x]->getSymb() == 'G' && theGrid[y + 1][x]->getValue == 6){
            theGrid[y + 1][x]->getDragon->attack(PC);
        }else{
            theGrid[y + 1][x]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
    
    //Check south
    if((isNpc(theGrid[y - 1][x]->getSymb()) && theGrid[y - 1][x]->getHostile()) || theGrid[y - 1][x]->getSymb() == 'G'){
        if(theGrid[y - 1][x]->getSymb() == 'G' && theGrid[y - 1][x]->getValue == 6){
            theGrid[y - 1][x]->getDragon->attack(PC);
        }else{
            theGrid[y - 1][x]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
    
    //Check east
    if((isNpc(theGrid[y][x + 1]->getSymb()) && theGrid[y][x + 1]->getHostile()) || theGrid[y][x + 1]->getSymb() == 'G'){
        if(theGrid[y][x + 1]->getSymb() == 'G' && theGrid[y][x + 1]->getValue == 6){
            theGrid[y][x + 1]->getDragon->attack(PC);
        }else{
            theGrid[y + 1][x]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
    
    //Check west
    if((isNpc(theGrid[y][x - 1]->getSymb()) && theGrid[y][x - 1]->getHostile()) || theGrid[y][x - 1]->getSymb() == 'G'){
        if(theGrid[y][x - 1]->getSymb() == 'G' && theGrid[y][x - 1]->getValue == 6){
            theGrid[y][x - 1]->getDragon->attack(PC);
        }else{
            theGrid[y + 1][x]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
    
    //Check north west
    if((isNpc(theGrid[y + 1][x - 1]->getSymb()) && theGrid[y + 1][x - 1]->getHostile()) || theGrid[y + 1][x - 1]->getSymb() == 'G'){
        if(theGrid[y + 1][x - 1]->getSymb() == 'G' && theGrid[y + 1][x - 1]->getValue == 6){
            theGrid[y + 1][x - 1]->getDragon->attack(PC);
        }else{
            theGrid[y + 1][x - 1]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
    
    //Check north east
    if((isNpc(theGrid[y + 1][x + 1]->getSymb()) && theGrid[y + 1][x + 1]->getHostile()) || theGrid[y + 1][x + 1]->getSymb() == 'G'){
        if(theGrid[y + 1][x + 1]->getSymb() == 'G' && theGrid[y + 1][x + 1]->getValue == 6){
            theGrid[y + 1][x + 1]->getDragon->attack(PC);
        }else{
            theGrid[y + 1][x + 1]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
    
    //Check south west
    if((isNpc(theGrid[y - 1][x - 1]->getSymb()) && theGrid[y - 1][x - 1]->getHostile()) || theGrid[y - 1][x - 1]->getSymb() == 'G'){
        if(theGrid[y - 1][x - 1]->getSymb() == 'G' && theGrid[y - 1][x - 1]->getValue == 6){
            theGrid[y - 1][x - 1]->getDragon->attack(PC);
        }else{
            theGrid[y - 1][x - 1]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
    
    //Check south east
    if((isNpc(theGrid[y - 1][x + 1]->getSymb()) && theGrid[y - 1][x + 1]->getHostile()) || theGrid[y - 1][x + 1]->getSymb() == 'G'){
        if(theGrid[y - 1][x + 1]->getSymb() == 'G' && theGrid[y - 1][x + 1]->getValue == 6){
            theGrid[y - 1][x + 1]->getDragon->attack(PC);
        }else{
            theGrid[y - 1][x + 1]->attack(PC);
        }
    }
    if(PC->isAlive() == false){
        //call game over method
    }
}

// move player in that direction
void Grid::move(Direction d){
    int x = PC->getX();
    int y = PC->getY();
    
    //Update x and y depending on which direction the potion is in
    if(d == Direction::NO){
        y++;
    }else if(d == Direction::SO){
        y--;
    }else if(d == Direction::EA){
        x++;
    }else if(d == Direction::WE){
        x--;
    }else if(d == Direction::NW){
        y++;
        x--;
    }else if(d == Direction::NE){
        y++;
        x++;
    }else if(d == Direction::SW){
        y--;
        x--;
    }else{
        y--;
        x++;
    }
    
    char floorType = theGrid[y][x]->getSymb();
    if(floorType == '.' || floorType == '+' || floorType == '#'){
        //Removing floorType and replacing it with PC
        delete theGrid[y][x];
        theGrid[y][x] = PC;
        
        //Replacing current tile with the tile the PC was on before
        if(PC->getCurTile() == '.'){
            GameSubject* gameSub = new Floor(PC.getX(), PC.getY());
        }else if(PC->getCurTile() == '+'){
            GameSubject* gameSub = new Door(PC.getX(), PC.getY());
        }else{
            GameSubject* gameSub = new PassageWay(PC.getX(), PC.getY());
        }
        
        theGrid[PC.getY()][PC.getX()] = gameSub;
        PC.setX(x);
        PC.setY(y);
        
        //Setting the PC's current floor tile after moving it in the direction d
        PC->setCurTile(floorType);
    }else if(floorType == 'G'){
        //Adding gold to PC
        PC.addGold(theGrid[y][x]->getValue());
        //Removing Gold object and replacing it with the PC
        delete theGrid[y][x];
        theGrid[y][x] = PC;
        //Replacing the current cell with a floor and updating PC's x and y coordinates
        GameSubject* gameSub = new Floor(PC.getX(), PC.getY());
        theGrid[PC.getY()][PC.getX()] = gameSub;
        PC.setX(x);
        PC.setY(y);
    }else if(floorType == '/'){
        //Clears grid, and starts on the next floor
        clear_grid();
    }else{
        throw("Invalid direction to move");
    }
}

//isNpc returns true is gameType is a Npc type and false otherwise
bool isNpc(char gameType){
    if(gameType == 'H' || gameType == 'W' || gameType == 'E' || gameType == 'O'
       || gameType == 'M' || gameType == 'D' || gameType == 'L'){
        return true;
    }else{
        return false;
    }
}

//playerInSight returns true if the player is within a block of an enemy and false otherwise
bool playerInSight(int x, int y){
    if(abs(PC->getX() - x) <= 1 && abs(PC->getY() - Y)){
        return true;
    }else{
        return false;
    }
}

//stuckNpc returns true if the npc has no where to move and false otherwise
bool stuckNpc(int x, int y){
    if(theGrid[y + 1][x].getSymb() != '.' && theGrid[y - 1][x].getSymb() != '.' && theGrid[y][x + 1].getSymb() != '.'
       && theGrid[y][x - 1].getSymb() != '.' && theGrid[y + 1][x + 1].getSymb() != '.' &&
       theGrid[y + 1][x - 1].getSymb() != '.' && theGrid[y - 1][x + 1].getSymb() != '.' && theGrid[y - 1][x - 1].getSymb() != '.'){
        return true;
    }else{
        return false;
    }
}