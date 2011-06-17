#include "davepch.h"
#include "Door.h"

//-----------
Door::Door(float xplace,float yplace):Keys(xplace,yplace){

	_className ="Door";
//	_image = new Image(DOOR_IMAGE);
}
//-------------------
hitRet_t Door::setHit(){

	return hitRet_t(getName(),GUT_KEY) ;
}
