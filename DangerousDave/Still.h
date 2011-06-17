/*
	This class is a base class for all displayable classes that donut move
*/
#pragma once
#include "macros.h"
#include "display.h"
class Image;
//---------------------

//level will get this and put it a map
//--------------------
class Still : public Display {

public:

	Still(float xplace,float yPlace);//set valid true 
	virtual hitRet_t setHit()=0; //set valid false nothing to return 
	virtual void display();
protected:
	
	Image* _image;
};