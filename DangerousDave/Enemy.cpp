#include "davepch.h"
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy  (float xplace,float yplace):Move( xplace, yplace) {

	vector<const char*> filenames;

	filenames.insert(filenames.end(),MONSTER_IMG); 

	init(filenames);

	_curPos = 0;

	_bullet = NULL;

}
Enemy::~Enemy () {

}

void Enemy::move() {

	//number of moves in each direction
	int factor = 20;

	int curDirection = _curPos / factor;

	switch(curDirection) {
		case 0:
			setDirection(NONE);
			setDirection(UP);
			createBullet(LEFT);
			break;
		case 1:
			setDirection(NONE);
			setDirection(RIGHT);
			break;
		case 2:
			setDirection(NONE);
			setDirection(DOWN);
			createBullet(RIGHT);
			break;
		case 3:
			setDirection(NONE);
			setDirection(LEFT);
			break;
	}
	Move::move();

	_curPos = ++_curPos % (factor*4);
}

void Enemy::display() {
	Move::display();
	if (_bullet)
		_bullet->display();
}

Bullet* Enemy::getBullet() {
	return _bullet;
}

void Enemy::createBullet(direction dir) {

	int dx=20;

	if (dir==LEFT)
		dx*=-1;

	if (!_bullet) {
		_bullet = new Bullet(getPlace().getX()+dx,getPlace().getY(),dir);
	}
}

void Enemy::destroyBullet() {

	if (_bullet) {
		delete _bullet;
		_bullet = NULL;
	}

}