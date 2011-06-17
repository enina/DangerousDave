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
	Still( const char* objName,const char* imageFileName,int objValue,float xplace,float yPlace);
	virtual ~Still();
	virtual hitRet_t setHit() {return hitRet_t(getName(),_objValue);}; 
	virtual void display();

protected:
	Image* _image;

private:
	void init(const char* objName,const char* imageFileName=NULL,int objValue=0) ;
};