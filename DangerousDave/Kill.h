/*
	this is a bse class for all obsicals that kill

*/
#pragma once
#include "Obstacles.h"
//------------
#define  DEAD 1
//--------------
class Kill : public Obstacles{
public:
	Kill(float xplace,float yplace);
	virtual hitRet_t setHit(){return hitRet_t(getName(),DEAD};

private:

};
