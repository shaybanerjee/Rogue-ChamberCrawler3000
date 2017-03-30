#include "potion.h"
#include <string.h>
using namespace std;
Potion::Potion(string type, int value): type{type}, value{value}{
}

int Potion::getValue(){
	return value;
}

string Potion::getType(){
	return type;
}

Potion::~Potion(){
}