/*
	base class for all Obstacles in the game;

	donot use the Still setHit() becuse we dont want to set the valid to false!
	becuse all Obstacles stay in the game even afte hit.
*/
#pragma once
#include "Still.h"
class Obstacles :public Still {
public:

	Obstacles(float xplace,float yplace);
	virtual hitRet_t setHit() =0;
	

};