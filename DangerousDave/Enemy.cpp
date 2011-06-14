#include "Enemy.h"


Enemy::Enemy  (float xplace,float yplace):Move( xplace, yplace) {

	vector<char*> filenames;

	filenames.insert(filenames.end(),MONSTER_IMG);   

	init(filenames);

	_curPos = 0;

}
Enemy::~Enemy () {

}

void Enemy::move() {

	int factor = 7;

	int curDirection = _curPos / factor;

	switch(curDirection) {
		case 0:
			setDirection(NONE);
			setDirection(UP);
			break;
		case 1:
			setDirection(NONE);
			setDirection(RIGHT);
			break;
		case 2:
			setDirection(NONE);
			setDirection(DOWN);
			break;
		case 3:
			setDirection(NONE);
			setDirection(LEFT);
			break;
	}
	Move::move();
	_curPos = ++_curPos % (factor*4);
}
