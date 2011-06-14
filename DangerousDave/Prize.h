/*
	this is a base class for all the prizes in the game

	All Harris only need to set the value and image
	this base class get the value of the prize so no need
	to inherit the hi func;
*/

#pragma once
//-----------
#include "macros.h"
#include "Still.h"

class Prize : public Still {

public:
	Prize(float xplace,float yplace,int prizeValu);
	virtual int getValu(){return _value;};
	hitRet_t setHit(){_valid= false; return hitRet_t("Prize",getValu());}; //return the Prize  and value NON VIRTUAL!!;

private:

	const int _value;//all Heirs will update;
};