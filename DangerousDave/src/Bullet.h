#include "macros.h"
#include "Move.h"

#define RIGHT_BULLET_IMAGE "graphix/misc/right_bullet.tga"
#define LEFT_BULLET_IMAGE "graphix/misc/left_bullet.tga"
#define  ENEMY_SIZE 55

//-------------------------
class Bullet: public Move {
public:
	Bullet  (float xplace,float yplace,direction dir);
};


