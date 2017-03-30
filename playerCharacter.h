#ifndef _playerCharacter_h_
#define _playerCharacter_h_
#include "character.h"

class PlayerCharacter: public Character{
    int score;
    
public:
    virtual void usePotion();
};

#endif
