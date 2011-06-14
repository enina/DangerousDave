/*
	This class is a base class for all displayable classes that donut move
*/
#pragma once
#include "macros.h"
#include "display.h"
#include "Image.h"
//---------------------
typedef pair <string,int> hitRet_t;//return value to update flags (value name,second=value to set)
//level will get this and put it a map
//--------------------
class Still : public Display {

public:

	Still(float xplace,float yPlace);//set valid true 
	virtual hitRet_t setHit()=0; //set valid false nothing to return 
	virtual bool isValid (){return _valid;}; // tell if need to free instase
	virtual void display();
	virtual void glide(int dir){_place.moveX(dir);};
protected:
	bool _valid; 
	Image* _image;
};