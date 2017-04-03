#include "dragon.h"

//Constructor
Dragon::Dragon(int hp, int atk, int def, bool hasMoved):
Npc{hp, atk, def, hasMoved}{}

//Overriding getSymb method to return the character that represents
//the object
char Dragon::getSymb(){
    return 'D';
}

void Dragon::setDhX(int newDhX){
    dhX = newDhX;
}
void Dragon::setDhY(int newDhY){
    dhY = newDhY;
}
int Dragon::getDhX(){
    return dhX;
}
int Dragon::getDhY(){
    return dhY;
}
