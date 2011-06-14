#pragma once

#include "macros.h"
#include "Move.h"

#define MONSTER_IMG			"graphix/misc/monster.tga"
#define MONSTER_BULLET_IMG "graphix/misc/monster_bullet.tga"

class Bullet;

class Enemy: public Move {
public:
	Enemy  (float xplace,float yplace);
	virtual ~Enemy ();
	virtual void move();
	virtual void display();
	void setPlace(Place newPlace){_place = newPlace;};
	void kill(){_valid= false;};//temprry
	Bullet* getBullet();
	void destroyBullet();
private:
	void createBullet(direction dir);
private:
	int _curPos;
	Bullet* _bullet;

};

#define  ENEMY_SIZE 55




