#include "macros.h"
#include "Move.h"

//-------------------------
class Bulit: public Move {
public:
	Bulit  (float xplace,float yplace,direction dir);
	virtual void move();
	void setPlace(Place newPlace){_place = newPlace;};
protected:
	//virtual int getImageIdx(){return _imageIn;};
private:
	//int _imageIn;
};

#define RIGHT_BULLET_IMAGE "graphix/misc/right_bullet.tga"
#define LEFT_BULLET_IMAGE "graphix/misc/left_bullet.tga"
#define  ENEMY_SIZE 55

