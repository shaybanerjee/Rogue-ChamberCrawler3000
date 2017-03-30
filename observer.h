#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class GameSubject; 
class Shade; 
class Vampire; 
class Troll;
class Goblin; 
class Elf; 
class Human;
class Dwarf; 
class Orc;
class Merchant; 
class Dragon; 
class Halfling; 

class Observer {
public: 
	virtual void notify(GameSubject& who) = 0; 
	virtual ~Observer() = 0; 
}

#endif 