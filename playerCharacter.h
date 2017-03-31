#ifndef _playerCharacter_h_
#define _playerCharacter_h_
#include "character.h"
#include <string>
#include <vector>

class PlayerCharacter: public Character{
    int maxHp;
    int baseAtk;
    int baseDef;
    std::string name;
    std::vector<std::string> usedPotions;
    //Vector to store all the potions used
    //Used to check whether a potion has been used to output
    
protected:
    int numGold;

public:
    //Constructor
    PlayerCharacter(int hp = 125, int atk = 25, int def = 25, std::string name = "Shade");
    
    //accessor for name;
    std::string getName();
    
    //usePotion applies the potion p's effects to the current PlayerCharacter
    virtual void usePotion(Potion &p);
    
    //isUsed returns true if the potion has been used and false otherwise
    bool isUsed(Potion &p);
    
    //getStats returns a string which represents the stats of the PlayerCharacter
    std::string getStats();
    
    //Overriding the attack method to account for the fact that theres a 50% chance
    //of missing when attacking a halfing and if a human was killed during the
    //attack, 2 gold will be added to the current player character
    bool attack(Character &c) override;
};

#endif
