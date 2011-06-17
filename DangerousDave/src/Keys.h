/*
	base class for all keys in the game 
	All Harris only need to set name and image;
*/
#pragma once
//----------
#include "Still.h"
//-----------------
#define GUT_KEY 1
//-----------------
class Keys : public Still {
public:
	Keys(float xplace,float yplace);
	virtual hitRet_t setHit();

};