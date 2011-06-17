/*
	this is a base class for all the prizes in the game

	All Harris only need to set the value and image
	this base class get the value of the prize so no need
	to inherit the hi func;
*/

#pragma once
//-----------
#include "macros.h"
#include "Display.h"

class Prize : public Display {

public:
	Prize(ObjInfoHandle infoHandle,float xplace,float yplace):Display(infoHandle,xplace,yplace){};
	HitResult setHit(){_valid= false; return Display::setHit();}; 
};