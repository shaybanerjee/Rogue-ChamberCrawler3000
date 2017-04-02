#include "goblin.h"
#include <cstdlib>
#include <sstream>

//Constructor
Goblin::Goblin(int hp, int atk, int def, std::string name):
PlayerCharacter{hp, atk, def, name}{}

//overriding the attack method so that Goblin will gain 5 golds if the
//character c being attack dies after the attack
void Goblin::attack(Npc *enemy){
    std::string newAction;
    std::stringstream damage;
    std::stringstream npcType;
    std::stringstream enemyHealth;
    npcType << enemy->getSymb();
    damage << damageAgainst(enemy);
    
    //if a player character attacks a halfing
    //if random generated number with 50/50 chance of 0 or 1 generates 0,
    //then this indicates the player missed.
    if(enemy->getSymb() == 'L' && rand() % 2 == 0){
        newAction = "PC attacks L and misses.";
        if(getAction().size() > 0){
            setAction(getAction() + " " + newAction);
        }else{
            setAction(newAction);
        }
        return;
    }
    
    //reduce enemy's hp after attacking enemy
    enemy->setHp(enemy->getHp() - damageAgainst(enemy));
    enemyHealth << enemy->getHp();
    
    //Checks if the enemy is alive after attacking it
    if(enemy->isAlive()){
        newAction = "PC deals " + damage.str() + " damage to " + npcType.str() + " (" + enemyHealth.str() + ").";
    }else{
        newAction = "PC deals " + damage.str() + " damage to " + npcType.str() + "and slains " + npcType.str() + ".";
    }
    
    //Updating Action
    if(getAction().size() > 0){
        setAction(getAction() + " " + newAction);
    }else{
        setAction(newAction);
    }
    
    //we will add 5 golds if the enemy is killed
    if(enemy->isAlive() == false){
        numGold += 5;
        
        //If the enemy is dead after the attack and it's not a dragon, merchant or human, gold
        //is automatically added to the player character with 1/2 probability of it being 1 gold
        //or 2 golds
        if(enemy->getSymb() != 'M' && enemy->getSymb() != 'H' && enemy->getSymb() != 'D'){
            if((rand() % 2) == 0){
                numGold += 1;
            }else{
                numGold += 2;
            }
        }

    }
}

//Overriding getSymb method to return the character that represents
//the object
char Goblin::getSymb(){
    return '@';
}
