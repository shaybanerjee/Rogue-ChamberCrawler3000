#ifndef GAME_SUBJECT
#define GAME_SUBJECT

class GameSubject {
	int x, y; 
public: 
	int getX() const;
	int getY() const;
    void setX(int newX);
    void setY(int newY);
	virtual char getSymb() = 0; // pv get_symb method
    virtual ~GameSubject();
};

#endif
