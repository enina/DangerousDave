#include "davepch.h"
# include "Wall.h"


//------------------
Wall::Wall(float xplace,float yplace):Obstacles(xplace,yplace){
	_className ="Wall";
	_image= new Image(WALL_IMAGE);
}
//-----------------------------------------------
