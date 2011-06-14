/*
	this class will implement the walls in the game 
	alloc the wall image and init all base classes 
	
	when hit will return the y value for testing
*/
#pragma  once 
#include "Obstacles.h"
#include "Image.h"
//-------------------------
class Wall :public Obstacles {
public:

	Wall(float xplace,float yplace);
	virtual hitRet_t setHit(){return hitRet_t(getName(),_place.getY());};
private:
	static Image _image ;
};

#define WALL_IMAGE "graphix/world/blue_wall.tga"