# include "Wall.h"
#include "Image.h"
//------------------
 Image Wall :: _image(WALL_IMAGE); 

//------------------
Wall::Wall(float xplace,float yplace):Obstacles(xplace,yplace){
	_className ="Wall";
	Still::_image=&_image;
}
//-----------------------------------------------
