#ifndef _playerCharacter_h_
#define _playerCharacter_h_
#include "character.h"
#include <string>
#include <vector>
#include "npc.h"

class Npc;

class PlayerCharacter: public Character{
    int baseAtk;
    int baseDef;
    char curTile;
    std::string name;
    std::vector<std::string> usedPotions;
    
protected:
    int maxHp;
    int numGold;

public:
    //Constructor
    PlayerCharacter(int hp = 125, int atk = 25, int def = 25, std::string name = "Shade");
    
    //accessor for name;
    std::string getName();
    
    //accessor and mutator for currPlace;
    char getCurTile();
    void setCurTile(char newCurTile);
    
    //addGold takes in an integer gold and adds it to the current amount of gold
    void addGold(int gold);
    
    //usePotion applies the potion p's effects to the current PlayerCharacter
    virtual void usePotion(Potion &p);
    
    //isUsed returns true if the potion has been used and false otherwise
    bool isUsed(Potion &p);
    
    //getStats returns a string which represents the stats of the PlayerCharacter
    std::string getStats();
    
    //Creating the attack method to account for the fact that theres a 50% chance
    //of missing when attacking a halfing and if a human was killed during the
    //attack, 2 gold will be added to the current player character
    virtual bool attack(Npc &enemy);
};

#endif
