#include "davepch.h"
#include "Bullet.h"


Bullet::Bullet  (float xplace,float yplace,direction dir):Move( xplace, yplace) {

	vector<const char*> filenames;

	const char* filename = (dir == LEFT)? LEFT_BULLET_IMAGE : RIGHT_BULLET_IMAGE;

	filenames.insert(filenames.end(),filename); 

	init(filenames);

	setDirection(dir);
}
//--------------------------------------------
