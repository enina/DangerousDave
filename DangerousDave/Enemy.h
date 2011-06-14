#pragma once

#include "macros.h"
#include "Move.h"

#define MONSTER_IMG "graphix/misc/monstr.tga"


class Enemy: public Move {
public:
	Enemy  (float xplace,float yplace);
	virtual ~Enemy ();
	virtual void move();

	void setPlace(Place newPlace){_place = newPlace;};

private:
	int _curPos;
};

#define  ENEMY_SIZE 55




