#include "Door.h"
#include "Image.h"
//---------------
Image Door:: _image(DOOR_IMAGE); 
//-----------
Door::Door(float xplace,float yplace):Keys(xplace,yplace){

	_className ="Door";
	Still::_image=&_image;
}
//-------------------
hitRet_t Door::setHit(){

	return hitRet_t(getName(),GUT_KEY) ;
}
