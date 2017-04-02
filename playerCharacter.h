#ifndef _playerCharacter_h_
#define _playerCharacter_h_
#include "character.h"
#include <string>
#include <vector>
#include "npc.h"
#include "potion.h"
class Npc;

class PlayerCharacter: public Character{
    int baseAtk;
    int baseDef;
    char curTile;
    std::string name;
    std::string action;
    
protected:
    int maxHp;
    int numGold;
    std::vector<std::string> usedPotions;

public:
    //Constructor
    PlayerCharacter(int hp = 125, int atk = 25, int def = 25, std::string name = "Shade");
    
    //accessor for name and Gold;
    std::string getName();
    int getNumGold();
    
    //accessor and mutators for curTile and action
    char getCurTile();
    void setCurTile(char newCurTile);
    std::string getAction();
    void setAction(std::string newAction);
    
    //addGold takes in an integer gold and adds it to the current amount of gold
    void addGold(int gold);
    
    //usePotion applies the potion p's effects to the current PlayerCharacter
    virtual void usePotion(Potion *p);
    
    //isUsed returns true if the potion has been used and false otherwise
    bool isUsed(Potion *p);
    
    //Creating the attack method to account for the fact that theres a 50% chance
    //of missing when attacking a halfing and if a human was killed during the
    //attack, 2 gold will be added to the current player character
    virtual void attack(Npc *enemy);
};

#endif
