/*
	this class is a type of still will serve as beck graound patern
*/
#pragma once
#include "Still.h"
//-----------------------
# define NO_VAL -1
//-----------------------
class Soil_bg : public Still{
public:
	Soil_bg (float xplace,float yplace);
	virtual hitRet_t setHit(){return hitRet_t(getName(),NO_VAL);};
private:

	static Image _image ;
};
//-----------------------------
#define SOIL_IMAGE "graphix/world/soil_bg.tga" 