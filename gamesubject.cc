#include "gamesubject.h"
#include "observer.h" 

using namespace std; 

GameSubject::~GameSubject() {

}

GameSubject::get_x() const {
	return x; 
}

GameSubject::get_y() const {
	return y; 
}

GameSubject::set_false() const {
	is_init = false; 
}


GameSubject::attach(Observer* o) {
	observers.emplace_back(o); 
}

GameSubject::notifyObservers(SubscriptionType t) {
	for (auto ob : observers) {
		if (ob->subtype() == t) {
			ob->notify(*this); 
		}
	}
}