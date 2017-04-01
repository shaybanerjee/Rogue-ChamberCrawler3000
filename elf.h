#ifndef _elf_h_
#define _elf_h_
#include "npc.h"

class elf : public Npc{
    
public:
    //Constructor
    Elf(int hp = 140, int atk = 30, int def = 10, bool hostile = false, bool hasMoved = false);
    
    //override the attack method because elfs gets two attacks against
    //every race except drow
    bool attack(PlayerCharacter &pc) override;
    //Overriding getSymb method to return the character that represents
    //the object
    char getSymb() override;
};
#endif
