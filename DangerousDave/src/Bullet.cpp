#include "davepch.h"
#include "Bullet.h"


Bullet::Bullet  (float xplace,float yplace,direction dir):Move( xplace, yplace) {


	const char* filename = (dir == LEFT)? LEFT_BULLET_IMAGE : RIGHT_BULLET_IMAGE;

	_images.insert(_images.end(),new Image(filename));


	setDirection(dir);
}
//--------------------------------------------
