#include "potion.h"
#include <string>
using namespace std;
Potion::Potion(string type, int value): type{type}, value{value}{
}

int Potion::getValue(){
	return value;
}

string Potion::getType(){
	return type;
}

char Potion::getSymb() {
	return 'P';

}
