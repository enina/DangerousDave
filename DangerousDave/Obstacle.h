/*
	base class for all Obstacles in the game;

	donot use the Still setHit() becuse we dont want to set the valid to false!
	becuse all Obstacles stay in the game even afte hit.
*/
#pragma once
#include "Display.h"

class Obstacle :public Display {
public:

	Obstacle(float xplace,float yplace);
	virtual HitResult setHit() =0;
	

};